// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01Pawn.h"
#include "Galaga_USFX_L01Projectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

const FName AGalaga_USFX_L01Pawn::MoveForwardBinding("MoveForward");
const FName AGalaga_USFX_L01Pawn::MoveRightBinding("MoveRight");

const FName AGalaga_USFX_L01Pawn::MoveDiagonalNOBinding("MoveDiagonalNO");
const FName AGalaga_USFX_L01Pawn::MoveDiagonalNEBinding("MoveDiagonalNE");
const FName AGalaga_USFX_L01Pawn::MoveDiagonalSOBinding("MoveDiagonalSO");
const FName AGalaga_USFX_L01Pawn::MoveDiagonalSEBinding("MoveDiagonalSE");

const FName AGalaga_USFX_L01Pawn::FireForwardBinding("FireForward");
const FName AGalaga_USFX_L01Pawn::FireRightBinding("FireRight");


void AGalaga_USFX_L01Pawn::DropItem()
{
	if (MyInventoryEnergy->CurrentInventoryEnergy.Num() == 0)
	{
		return;
	}
	AInventoryActor* Item = MyInventoryEnergy->CurrentInventoryEnergy.Last();
	MyInventoryEnergy->RemoveFromInventory(Item);
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);
}

void AGalaga_USFX_L01Pawn::TakeItem(AInventoryActor* InventoryItemEnergy)
{
	InventoryItemEnergy->SetOwner(this);  // Establecer el pawn como propietario
	InventoryItemEnergy->PickUp();
	MyInventoryEnergy->AddToInventory(InventoryItemEnergy);
}

void AGalaga_USFX_L01Pawn::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AInventoryActor* InventoryItem = Cast<AInventoryActor>(Other);
	if (InventoryItem != nullptr)
	{
		TakeItem(InventoryItem);
	}

	AInventoryGun* InventoryItemGun = Cast<AInventoryGun>(Other);
	if (InventoryItemGun != nullptr) 
	{
		TakeItemGun(InventoryItemGun);
	}
}

void AGalaga_USFX_L01Pawn::DropItemGun()
{
	if (MyInventoryEnergy->CurrentInventoryGun.Num() == 0)
	{
		return;
	}
	AInventoryGun* Item = MyInventoryEnergy->CurrentInventoryGun.Last();
	MyInventoryEnergy->RemoveFromInventoryGun(Item);
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);
}

void AGalaga_USFX_L01Pawn::TakeItemGun(AInventoryGun* InventoryItemGun)
{
	InventoryItemGun->PickUp();
	MyInventoryEnergy->AddToInventoryGun(InventoryItemGun);
}

AGalaga_USFX_L01Pawn::AGalaga_USFX_L01Pawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;

	MyInventoryEnergy = CreateDefaultSubobject<UInventoryComponent>("MyInventory");
}

void AGalaga_USFX_L01Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
	
	FInputAxisKeyMapping DiagonalNO("MoveDiagonalUpLeft", EKeys::E, 1);
	FInputAxisKeyMapping DiagonalNE("MoveDiagonalUpLeft", EKeys::Q, 1);
	FInputAxisKeyMapping DiagonalSO("MoveDiagonalUpLeft", EKeys::Z, 1);
	FInputAxisKeyMapping DiagonalSE("MoveDiagonalUpLeft", EKeys::C, 1);

	UPlayerInput::AddEngineDefinedAxisMapping(DiagonalNO);
	UPlayerInput::AddEngineDefinedAxisMapping(DiagonalNE);
	UPlayerInput::AddEngineDefinedAxisMapping(DiagonalSO);
	UPlayerInput::AddEngineDefinedAxisMapping(DiagonalSE);

	PlayerInputComponent->BindAxis("MoveDiagonalNO", this, &AGalaga_USFX_L01Pawn::MoveDiagonalNO);
	PlayerInputComponent->BindAxis("MoveDiagonalNE", this, &AGalaga_USFX_L01Pawn::MoveDiagonalNE);
	PlayerInputComponent->BindAxis("MoveDiagonalSO", this, &AGalaga_USFX_L01Pawn::MoveDiagonalSO);
	PlayerInputComponent->BindAxis("MoveDiagonalSE", this, &AGalaga_USFX_L01Pawn::MoveDiagonalSE);

	PlayerInputComponent->BindAction("AbrirInventario", EInputEvent::IE_Pressed, this, &AGalaga_USFX_L01Pawn::DropItem);
	PlayerInputComponent->BindAction("AbrirInventario", EInputEvent::IE_Pressed, this, &AGalaga_USFX_L01Pawn::DropItemGun);
}

void AGalaga_USFX_L01Pawn::MoveDiagonalNO(float Value)
{
	const FVector Movement = FVector(1.0f, 1.0f, 0.f) * MoveSpeed * Value * GetWorld()->GetDeltaSeconds();
	MoveActor(Movement);
}

void AGalaga_USFX_L01Pawn::MoveDiagonalNE(float Value)
{
	const FVector Movement = FVector(1.0f, -1.0f, 0.f) * MoveSpeed * Value * GetWorld()->GetDeltaSeconds();
	MoveActor(Movement);
}

void AGalaga_USFX_L01Pawn::MoveDiagonalSO(float Value)
{
	const FVector Movement = FVector(-1.0f, 1.0f, 0.f) * MoveSpeed * Value * GetWorld()->GetDeltaSeconds();
	MoveActor(Movement);
}

void AGalaga_USFX_L01Pawn::MoveDiagonalSE(float Value)
{
	const FVector Movement = FVector(-1.0f, -1.0f, 0.f) * MoveSpeed * Value * GetWorld()->GetDeltaSeconds();
	MoveActor(Movement);
}

void AGalaga_USFX_L01Pawn::MoveActor(const FVector& Movement)
{
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
}

void AGalaga_USFX_L01Pawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);
}

void AGalaga_USFX_L01Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalaga_USFX_L01Pawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AGalaga_USFX_L01Pawn::ShotTimerExpired()
{
	bCanFire = true;
}