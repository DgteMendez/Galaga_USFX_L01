// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaCazaG2.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaCazaG2 : public ANaveEnemigaCaza
{
	GENERATED_BODY()

private:

	int duracionLaser;
	float volumenLaser;

public:

	ANaveEnemigaCazaG2();

	FORCEINLINE int GetDuracionLaser() const { return duracionLaser; }
	FORCEINLINE float GetVolumenLaser() const { return volumenLaser; }

	FORCEINLINE void SetDuracionLaser(int _duracionLaser) { duracionLaser = _duracionLaser; }
	FORCEINLINE void SetVolumenLaser(float _volumenLaser) { volumenLaser = _volumenLaser; }

public:

	virtual void Tick(float DeltaTime)override;

protected:

	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();
	virtual void Atacar();
	
};
