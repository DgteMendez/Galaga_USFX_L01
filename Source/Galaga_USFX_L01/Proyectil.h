// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Proyectil.generated.h"

class UStaticMeshComponent;

UCLASS()
class GALAGA_USFX_L01_API AProyectil : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere);
	UStaticMeshComponent* ProyectilMesh;
	float posicionX;
	float posicionY;
	float posicionZ;
	float velocidad;
	float dano;
	float volumen;
	FString nombre;

public:

	FORCEINLINE float GetPosicionX() const { return posicionX; }
	FORCEINLINE float GetPosicionY() const { return posicionY; }
	FORCEINLINE float GetPosicionZ() const { return posicionZ; }
	FORCEINLINE float GetVelocidad() const { return velocidad; }
	FORCEINLINE float GetDano() const { return dano; }
	FORCEINLINE float GetVolumen() const { return volumen; }
	FORCEINLINE FString GetNombre() const { return nombre; }

	FORCEINLINE void SetPosicionX(float _posicionX) { posicionX = posicionX; }
	FORCEINLINE void SetPosicionY(float _posicionY) { posicionY = posicionY; }
	FORCEINLINE void SetPosicionZ(float _posicionZ) { posicionZ = posicionZ; }
	FORCEINLINE void SetVelocidad(float _velocidad) { velocidad = velocidad; }
	FORCEINLINE void SetDano(float _dano) { dano = dano; }
	FORCEINLINE void SetVolumen(float _volumen) { volumen = volumen; }
	FORCEINLINE void SetNombre(FString _nombre) { nombre = nombre; }

	
public:	
	// Sets default values for this actor's properties
	AProyectil();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
