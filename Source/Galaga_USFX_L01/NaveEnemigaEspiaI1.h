// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaEspiaI1.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaEspiaI1 : public ANaveEnemigaEspia
{
	GENERATED_BODY()
private:

	int tiempoInvisibilidad;

public:

	ANaveEnemigaEspiaI1();

	FORCEINLINE int GetTiempoInvisibilidad() const { return tiempoInvisibilidad; }

	FORCEINLINE void SetTiempoInvisibilidad(int _tiempoInvisibilidad) { tiempoInvisibilidad = _tiempoInvisibilidad; }

public:

	virtual void Tick(float DeltaTime)override;

protected:

	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();
	virtual void Atacar();
	virtual void Esconderse();
	
};
