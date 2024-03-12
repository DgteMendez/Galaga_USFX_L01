// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaReabastecimientoE1.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaReabastecimientoE1 : public ANaveEnemigaReabastecimiento
{
	GENERATED_BODY()

private:

	float almacenEnergia;

public:

	ANaveEnemigaReabastecimientoE1();

	FORCEINLINE float GetAlmacenEnergia() const { return almacenEnergia; }

	FORCEINLINE void SetAlmacenEnergia(float _almacenEnergia) { almacenEnergia = _almacenEnergia; }

public:

	virtual void Tick(float DeltaTime)override;

protected:

	virtual void Mover(float DeltaTime);
	virtual void Destruirse();
	
};
