// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_L01GameMode.generated.h"

class ANaveEnemiga;
class AAlienigenaEnemigo;
class AProyectil;
class AEscenario;
class ANaveAmiga;
class AObstaculo;

UCLASS(MinimalAPI)
class AGalaga_USFX_L01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_L01GameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ANaveEnemiga* NaveEnemiga01;
	AAlienigenaEnemigo* AlienigenaEnemigo01;
	AProyectil* Proyectil01;
	AEscenario* Escenario01;
	ANaveAmiga* NaveAmiga01;
	AObstaculo* Obstaculo01;
};



