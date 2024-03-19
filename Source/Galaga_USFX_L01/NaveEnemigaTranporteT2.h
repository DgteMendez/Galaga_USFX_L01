// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaTranporte.h"
#include "NaveEnemigaTranporteT2.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaTranporteT2 : public ANaveEnemigaTranporte
{
	GENERATED_BODY()

private:

	int cantAlienigenas;

public:

	ANaveEnemigaTranporteT2();

	FORCEINLINE int GetCantAlienigenas() const { return cantAlienigenas; }

	FORCEINLINE void SetCantAlienigenas(int _cantAlienigenas) { cantAlienigenas = _cantAlienigenas; }

	FORCEINLINE void SetVelocidad(float _velocidad) override{ velocidad = _velocidad; }


public:

	virtual void Tick(float DeltaTime)override;



protected:

	virtual void Mover(float DeltaTime);
	virtual void Destruirse();
	
};
