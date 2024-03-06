// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveAmiga.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
ANaveAmiga::ANaveAmiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> NaveAmiga(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	// Create the mesh component
	NaveAmigaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NaveAmiga"));
	NaveAmigaMesh->SetStaticMesh(NaveAmiga.Object);
	NaveAmigaMesh->SetupAttachment(RootComponent);
	RootComponent = NaveAmigaMesh;
}

// Called when the game starts or when spawned
void ANaveAmiga::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveAmiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

