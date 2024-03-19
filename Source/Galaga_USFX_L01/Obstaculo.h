// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstaculo.generated.h"

class UStaticMeshComponent;

UCLASS()
class GALAGA_USFX_L01_API AObstaculo : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ObstaculoMesh;
	FString nombreObstaculo;
	FString tipoObstaculo;
	FVector posicion;
	float volumen;

public:

	FORCEINLINE FString GetNombreObstaculo() const { return nombreObstaculo; }
	FORCEINLINE FString GetTipoObstaculo() const { return tipoObstaculo; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }
	FORCEINLINE float GetVolumen() const { return volumen; }

	FORCEINLINE void SetNombreObstaculo(FString _nombreObstaculo) { nombreObstaculo = _nombreObstaculo; }
	FORCEINLINE void SetTipoObstaculo(FString _tipoObstaculo) { tipoObstaculo = _tipoObstaculo; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void SetVolumen(float _volumen) { volumen = _volumen; }

public:	
	// Sets default values for this actor's properties
	AObstaculo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	void Mover(float DeltaTime) PURE_VIRTUAL(AObstaculo::Mover, );

};
