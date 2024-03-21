// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemiga.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"	

// Sets default values
ANaveEnemiga::ANaveEnemiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// static ConstructorHelpers::FObjectFinder<UStaticMesh> NaveEnemiga(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	// Create the mesh component
	NaveEnemigaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NaveEnemiga"));
	//NaveEnemigaMesh->SetStaticMesh(NaveEnemiga.Object);
	NaveEnemigaMesh->SetupAttachment(RootComponent);
	RootComponent = NaveEnemigaMesh;

	limiteInferiorX = -1800.0f;
	limiteSuperiorX = 1800.0f;
	limiteIzquierdaY = -1800.0f;
	limiteDerechaY = 1800.0f;
}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

