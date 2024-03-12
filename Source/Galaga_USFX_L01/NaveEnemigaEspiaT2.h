// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaEspiaT2.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaEspiaT2 : public ANaveEnemigaEspia
{
	GENERATED_BODY()

private:
	int tiempoTeleTransportacion;

public:

	ANaveEnemigaEspiaT2();

	FORCEINLINE int GetTiempoTeleTransportacion() const { return tiempoTeleTransportacion; }

	FORCEINLINE void SetTiempoTeleTransportacion(int _tiempoTeleTransportacion) { tiempoTeleTransportacion = _tiempoTeleTransportacion; }

public:

	virtual void Tick(float DeltaTime)override;

protected:

	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();
	virtual void Atacar();
	virtual void Escaparse();
	
};
