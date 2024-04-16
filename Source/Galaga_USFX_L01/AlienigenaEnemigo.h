// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovimientoHorizontal.h"
#include "AlienigenaEnemigo.generated.h"

class UStaticMeshComponent;

UCLASS()
class GALAGA_USFX_L01_API AAlienigenaEnemigo : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* AlienigenaEnemigoMesh;
	float resistencia;
	float velocidad;
	float danoImpacto;
	float posicionX;
	float posicionY;
	float posicionZ;
	FString nombre;

public:
	FORCEINLINE float GetResistencia() const { return resistencia; }
	FORCEINLINE float GetVelocidad() const { return velocidad; }
	FORCEINLINE float GetDanoImpacto() const { return danoImpacto; }
	FORCEINLINE float GetPosicionX() const { return posicionX; }
	FORCEINLINE float GetPosicionY() const { return posicionY; }
	FORCEINLINE float GetPosicionZ() const { return posicionZ; }
	FORCEINLINE FString GetNombre() const { return nombre; }

	FORCEINLINE void SetResistencia(float _resistencia) { resistencia = _resistencia; }
	FORCEINLINE void SetVelocidad(float _velocidad) { velocidad = _velocidad; }
	FORCEINLINE void SetDanoImpacto(float _danoImpacto) { danoImpacto = _danoImpacto; }
	FORCEINLINE void SetPosicionX(float _posicionX) { posicionX = _posicionX; }
	FORCEINLINE void SetPosicionY(float _posicionY) { posicionY = _posicionY; }
	FORCEINLINE void SetPosicionZ(float _posicionZ) { posicionZ = _posicionZ; }
	FORCEINLINE void SetNombre(FString _nombre) { nombre = _nombre; }

	UMovimientoHorizontal* MovimientoHorizontal;
public:	
	// Sets default values for this actor's properties
	AAlienigenaEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
