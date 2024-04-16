// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "MovimientoHorizontal.h"
#include "Bomba.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ABomba : public AProyectil
{
	GENERATED_BODY()
	
private:
	int radioExplosion;
	float tiempoExplosion;
	int tipoBomba;
	int tipoExplosion;

public:

	ABomba();

	FORCEINLINE int GetRadioExplosion() const { return radioExplosion; }
	FORCEINLINE float GetTiempoExplosion() const { return tiempoExplosion; }
	FORCEINLINE int GetTipoBomba() const { return tipoBomba; }
	FORCEINLINE int GetTipoExplosion() const { return tipoExplosion; }

	FORCEINLINE void SetRadioExplosion(int _radioExplosion) { radioExplosion = _radioExplosion; }
	FORCEINLINE void SetTiempoExplosion(float _tiempoExplosion) { tiempoExplosion = _tiempoExplosion; }
	FORCEINLINE void SetTipoBomba(int _tipoBomba) { tipoBomba = _tipoBomba; }
	FORCEINLINE void SetTipoExplosion(int _tipoExplosion) { tipoExplosion = _tipoExplosion; }

	//UMovimientoHorizontal* MovimientoHorizontal;

public:

	virtual void Tick(float DeltaTime) override;

	void Mover(float DeltaTime);

public:
	bool controlador;

};
