// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaEspia.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaEspia : public ANaveEnemiga
{
	GENERATED_BODY()

private:

	int tiempoInvulnerabilidad;

public:

	ANaveEnemigaEspia();

	FORCEINLINE int GetTiempoInvulnerabilidad() const { return tiempoInvulnerabilidad; }

	FORCEINLINE void SetTiempoInvulnerabilidad(int _tiempoInvulnerabilidad) { tiempoInvulnerabilidad = _tiempoInvulnerabilidad; }

public:

	virtual void Tick(float DeltaTime)override;

protected:

	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();
	virtual void Atacar();
	virtual void Esconderse();
	virtual void Escapar();
	
};
