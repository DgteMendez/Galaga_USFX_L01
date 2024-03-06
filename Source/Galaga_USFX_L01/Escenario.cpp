// Fill out your copyright notice in the Description page of Project Settings.

#include "Escenario.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
AEscenario::AEscenario()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Escenario(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));
	// Create the mesh component
	EscenarioMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Escenario"));
	EscenarioMesh->SetStaticMesh(Escenario.Object);
	EscenarioMesh->SetupAttachment(RootComponent);
	RootComponent = EscenarioMesh;
}

// Called when the game starts or when spawned
void AEscenario::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscenario::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

