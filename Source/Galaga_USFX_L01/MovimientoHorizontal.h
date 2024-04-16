// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovimientoHorizontal.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_L01_API UMovimientoHorizontal : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovimientoHorizontal();

	UPROPERTY(EditAnywhere)
	float Velocidad;
	UPROPERTY(EditAnywhere)
	float LimiteIzquierda;
	UPROPERTY(EditAnywhere)
	float LimiteDerecha;
	UPROPERTY(EditAnywhere)
	bool verificacion;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
