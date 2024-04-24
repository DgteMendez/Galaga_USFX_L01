// Fill out your copyright notice in the Description page of Project Settings.


#include "Planeta.h"

APlaneta::APlaneta()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	MovimientoVertical = CreateDefaultSubobject<UMovimientoVertical>(TEXT("MovimientoVertical"));
	ObstaculoMesh->SetStaticMesh(ShipMesh.Object);
}
