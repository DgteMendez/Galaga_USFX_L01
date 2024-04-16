// Fill out your copyright notice in the Description page of Project Settings.

#include "AlienigenaEnemigo.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"	

// Sets default values
AAlienigenaEnemigo::AAlienigenaEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> AlienigenaEnemigo(TEXT("StaticMesh'/Game/ASETS/8f7a580042f9_iridescent_small_al.8f7a580042f9_iridescent_small_al'"));
	// Create the mesh component
	AlienigenaEnemigoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AlienigenaEnemigo"));
	MovimientoHorizontal = CreateDefaultSubobject<UMovimientoHorizontal>(TEXT("MovimientoHorizontal"));
	AlienigenaEnemigoMesh->SetStaticMesh(AlienigenaEnemigo.Object);
	AlienigenaEnemigoMesh->SetupAttachment(RootComponent);
	RootComponent = AlienigenaEnemigoMesh;
	SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
}

// Called when the game starts or when spawned
void AAlienigenaEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAlienigenaEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

