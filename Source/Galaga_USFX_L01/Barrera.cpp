// Fill out your copyright notice in the Description page of Project Settings.


#include "Barrera.h"

ABarrera::ABarrera()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));
	MovimientoVertical = CreateDefaultSubobject<UMovimientoVertical>(TEXT("MovimientoVertical"));
	ObstaculoMesh->SetStaticMesh(ShipMesh.Object);
	GetActorRelativeScale3D();
	SetActorScale3D(FVector(3.0f, 10.0f, 3.0f));
}
