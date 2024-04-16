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
class ANaveEnemigaCaza;
class ANaveEnemigaTranporte;
class ANaveEnemigaEspia;
class ANaveEnemigaReabastecimiento;
class ANaveEnemigaNodriza;
class ANaveEnemigaCazaG1;
class ANaveEnemigaCazaG2;
class ANaveEnemigaTranporteT1;
class ANaveEnemigaTranporteT2;
class ANaveEnemigaEspiaI1;
class ANaveEnemigaEspiaT2;
class ANaveEnemigaReabastecimientoE1;
class ANaveEnemigaReabastecimientoH2;
class ANaveEnemigaNodrizaC1;
class ANaveEnemigaNodrizaC2;
class AInventoryActor;
class AInventoryGun;
class UInvisibilidadComponente;

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
	ANaveEnemigaCaza* NaveEnemigaCaza01;
	ANaveEnemigaTranporte* NaveEnemigaTranporte01;
	ANaveEnemigaEspia* NaveEnemigaEspia01;
	ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimiento01;
	ANaveEnemigaNodriza* NaveEnemigaNodriza01;
	ANaveEnemigaCazaG1* NaveEnemigaCazaG102;
	ANaveEnemigaCazaG2* NaveEnemigaCazaG202;
	ANaveEnemigaTranporteT1* NaveEnemigaTranporteT102;
	ANaveEnemigaTranporteT2* NaveEnemigaTranporteT202;
	ANaveEnemigaEspiaI1* NaveEnemigaEspiaI102;
	ANaveEnemigaEspiaT2* NaveEnemigaEspiaT202;
	ANaveEnemigaReabastecimientoE1* NaveEnemigaReabastecimientoE102;
	ANaveEnemigaReabastecimientoH2* NaveEnemigaReabastecimientoH202;
	ANaveEnemigaNodrizaC1* NaveEnemigaNodrizaC102;
	ANaveEnemigaNodrizaC2* NaveEnemigaNodrizaC202;
	AInventoryActor* InventoryActor01;
	AInventoryGun* InventoryGun01;

public:

	TArray<ANaveEnemiga*> NavesEnemigas;
	TMap<float, ANaveEnemiga*> TMNavesEnemigas;
	FString NombreNavesEnemigas;

private:
	
	float tiempoTranscurrido = 0;

	virtual void Tick(float DeltaTime)override;

public:
	
	TMap<FVector, AActor*> TMObstaculosYAlienigenas;

};