// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaNodrizaC1.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodrizaC1 : public ANaveEnemigaNodriza
{
	GENERATED_BODY()

private:

	int cantMuniciones;

public:

	ANaveEnemigaNodrizaC1();

	FORCEINLINE int GetCantMuniciones() const { return cantMuniciones; }

	FORCEINLINE void SetCantidadMuniciones(int _cantidadMuniciones) { cantMuniciones = _cantidadMuniciones; }

public:

	virtual void Tick(float DeltaTime)override;

protected:

	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();
	virtual void Esconderse();
	
};
