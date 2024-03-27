// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InventoryGun.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API AInventoryGun : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AInventoryGun();
	virtual void PickUp();
	virtual void PutDown(FTransform TargetLocation);
	
};
