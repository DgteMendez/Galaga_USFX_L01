// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroide.h"

AAsteroide::AAsteroide()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	ObstaculoMesh->SetStaticMesh(ShipMesh.Object);
}
