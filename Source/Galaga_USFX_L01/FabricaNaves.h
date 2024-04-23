// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fabrica.h"
#include "FabricaNaves.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API AFabricaNaves : public AFabrica
{
	GENERATED_BODY()

public:
	virtual ANaveEnemiga* FabricarNaves(FString NaveKTM, FVector UbicacionNave) override;
	
};
