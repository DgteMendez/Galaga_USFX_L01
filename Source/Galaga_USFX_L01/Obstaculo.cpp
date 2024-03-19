// Fill out your copyright notice in the Description page of Project Settings.

#include "Obstaculo.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
AObstaculo::AObstaculo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Obstaculo(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	// Create the mesh component
	ObstaculoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obstaculo"));
	ObstaculoMesh->SetStaticMesh(Obstaculo.Object);
	ObstaculoMesh->SetupAttachment(RootComponent);
	RootComponent = ObstaculoMesh;
}

// Called when the game starts or when spawned
void AObstaculo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

