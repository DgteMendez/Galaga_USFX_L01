// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InventoryActor.h"
#include "InventoryGun.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_L01_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	//Inventario de Energia
	UPROPERTY()
	TArray<AInventoryActor*> CurrentInventoryEnergy;
	UFUNCTION()
	int32 AddToInventory(AInventoryActor* ActorToAdd);
	UFUNCTION()
	void RemoveFromInventory(AInventoryActor* ActorToRemove);

	//Inventario de Armas
	UPROPERTY()
	TArray<AInventoryGun*> CurrentInventoryGun;
	UFUNCTION()
	int32 AddToInventoryGun(AInventoryGun* ActorToAddGun);
	UFUNCTION()
	void RemoveFromInventoryGun(AInventoryGun* ActorToRemoveGun);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
