// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaNodriza.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodriza : public ANaveEnemiga
{
	GENERATED_BODY()

private:

	int cantNaves;

public:

	ANaveEnemigaNodriza();

	FORCEINLINE int GetCantNaves() const { return cantNaves; }

	FORCEINLINE void SetCantNaves(int _cantNaves) { cantNaves = _cantNaves; }

public:

	virtual void Tick(float DeltaTime)override;

protected:

	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();
	virtual void Esconderse();
};
