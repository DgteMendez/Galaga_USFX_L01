// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"	

// Sets default values
AProyectil::AProyectil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Proyectil(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
	// Create the mesh component
	ProyectilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Proyectil"));
	ProyectilMesh->SetStaticMesh(Proyectil.Object);
	ProyectilMesh->SetupAttachment(RootComponent);
	RootComponent = ProyectilMesh;
}

// Called when the game starts or when spawned
void AProyectil::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProyectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

