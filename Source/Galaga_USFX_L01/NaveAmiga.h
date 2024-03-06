// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveAmiga.generated.h"

class UStaticMeshComponent;

UCLASS()
class GALAGA_USFX_L01_API ANaveAmiga : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere);
	UStaticMeshComponent* NaveAmigaMesh;
	float resistencia;
	float velocidad;
	float danoProducido;
	float tiempoDisparo;
	FVector posicion;
	FString nombre;

public:

	FORCEINLINE	float GetResistencia() const { return resistencia; }
	FORCEINLINE float GetVelocidad() const { return velocidad; }
	FORCEINLINE float GetDanoProducido() const { return danoProducido; }
	FORCEINLINE float GetTiempoDisparo() const { return tiempoDisparo; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }
	FORCEINLINE FString GetNombre() const { return nombre; }

	FORCEINLINE void SetResistencia(float _resistencia) { resistencia = _resistencia; }
	FORCEINLINE void SetVelocidad(float _danoProducido) { danoProducido = _danoProducido; }
	FORCEINLINE void SetTiempoDisparo(float _tiempoDisparo) { tiempoDisparo = _tiempoDisparo; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void SetNombre(FString _nombre) { nombre = _nombre; }
	
public:	
	// Sets default values for this actor's properties
	ANaveAmiga();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
