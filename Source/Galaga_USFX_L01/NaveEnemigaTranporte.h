// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTranporte.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaTranporte : public ANaveEnemiga
{
	GENERATED_BODY()

private:

	int almacenamiento;

public:

	ANaveEnemigaTranporte();

	FORCEINLINE int GetAlmacenamiento() const { return almacenamiento; }

	FORCEINLINE void SetAlmacenamiento(int _almacenamiento) { almacenamiento = _almacenamiento; }

public:
	virtual void Tick(float DeltaTime)override;
	
protected:

	virtual void Mover(float DeltaTime);
	virtual void Destruirse();
	virtual void Escapar();
};
