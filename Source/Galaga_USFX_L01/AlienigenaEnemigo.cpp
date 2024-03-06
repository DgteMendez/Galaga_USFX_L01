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

	static ConstructorHelpers::FObjectFinder<UStaticMesh> AlienigenaEnemigo(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	// Create the mesh component
	AlienigenaEnemigoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AlienigenaEnemigo"));
	AlienigenaEnemigoMesh->SetStaticMesh(AlienigenaEnemigo.Object);
	AlienigenaEnemigoMesh->SetupAttachment(RootComponent);
	RootComponent = AlienigenaEnemigoMesh;
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

