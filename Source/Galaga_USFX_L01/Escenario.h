// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Escenario.generated.h"

class UStaticMeshComponent;

UCLASS()
class GALAGA_USFX_L01_API AEscenario : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere);
	UStaticMeshComponent* EscenarioMesh;
	FString tipoEscenario;
	FString nombreEscenario;
	FString dificultad;
	int nivel;

public:

	FORCEINLINE FString GetTipoEscenario() const { return tipoEscenario; }
	FORCEINLINE FString GetNombreEscenario() const { return nombreEscenario; }
	FORCEINLINE FString GetDificultad() const { return dificultad; }
	FORCEINLINE int GetNivel() const { return nivel; }

	FORCEINLINE void SetTipoEscenario(FString _tipoEscenario) { tipoEscenario = tipoEscenario; }
	FORCEINLINE void SetNombreEscenario(FString _nombreEscebario) { nombreEscenario = nombreEscenario; }
	FORCEINLINE void SetDificultad(FString _dificultad) { dificultad = dificultad; }
	FORCEINLINE void SetNivel(int _nivel) { nivel = nivel; }

public:	
	// Sets default values for this actor's properties
	AEscenario();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
