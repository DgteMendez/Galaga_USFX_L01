// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaCazaG1.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaCazaG1 : public ANaveEnemigaCaza
{
	GENERATED_BODY()

private:

	int cantArmas;

public:

	ANaveEnemigaCazaG1();

	FORCEINLINE int GetCantArmas() const { return cantArmas; }

	FORCEINLINE void SetCantArmas(int _cantArmas) { cantArmas = _cantArmas; }

public:

	virtual void Tick(float DeltaTime)override;

protected:

	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();
	virtual void Atacar();
	
};
