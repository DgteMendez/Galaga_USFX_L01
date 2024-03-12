// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaTranporte.h"
#include "NaveEnemigaTranporteT1.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaTranporteT1 : public ANaveEnemigaTranporte
{
	GENERATED_BODY()

private:

	int cantNaves;

public:

	ANaveEnemigaTranporteT1();

	FORCEINLINE int GetCantNaves() const { return cantNaves; }

	FORCEINLINE void SetCantNaves(int _cantNaves) { cantNaves = _cantNaves; }

public:

	virtual void Tick(float DeltaTime)override;

protected:

	virtual void Mover(float DeltaTime);
	virtual void Destruirse();
	virtual void Escapar();
	
};
