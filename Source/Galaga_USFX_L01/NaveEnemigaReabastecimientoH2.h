// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaReabastecimientoH2.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaReabastecimientoH2 : public ANaveEnemigaReabastecimiento
{
	GENERATED_BODY()

private:

	int cantHabilidades;

public:

	ANaveEnemigaReabastecimientoH2();

	FORCEINLINE float GetCantHabilidades() const { return cantHabilidades; }

	FORCEINLINE void SetCantHabilidades(float _cantHabilidades) { cantHabilidades = _cantHabilidades; }

public:

	virtual void Tick(float DeltaTime)override;

protected:

	virtual void Mover(float DeltaTime);
	virtual void Destruirse();
	
};
