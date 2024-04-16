// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryGun.h"
#include "Galaga_USFX_L01Pawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/CollisionProfile.h"

AInventoryGun::AInventoryGun()
{
	PrimaryActorTick.bCanEverTick = true;
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> InventoryGun(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	// Create the mesh component
	InventoryGunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InventoryGun"));
	//InventoryActorMesh->SetupAttachment(RootComponent);
	InventoryGunMesh->SetStaticMesh(InventoryGun.Object);
	RootComponent = InventoryGunMesh;

			if (InventoryGun.Object != nullptr)
			{
				GetStaticMeshComponent()->SetStaticMesh(InventoryGun.Object);
				GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
			}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);
}

void AInventoryGun::PickUp()
{
	SetActorTickEnabled(false);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Se agrego una mejora de arma al inventario"));
}

void AInventoryGun::PutDown(FTransform TargetLocation)
{
	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorLocation(TargetLocation.GetLocation());
	// Obtener una referencia al pawn propietario
	AGalaga_USFX_L01Pawn* NaveJugador = Cast<AGalaga_USFX_L01Pawn>(GetOwner());
	if (NaveJugador) {
		NaveJugador->FireRate *= 0.5f;
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Cadencia de disparo aumentada a: %f"), NaveJugador->FireRate));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Propietario no encontrado"));
	}
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Se retiro del inventario"));
}
