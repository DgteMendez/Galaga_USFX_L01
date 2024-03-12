// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaReabastecimiento.generated.h"

/**
 *
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaReabastecimiento : public ANaveEnemiga
{
	GENERATED_BODY()

private:

	int cantMunicionAlmacenada;
	FString tipoMunicionAlmacenada;

public:

	ANaveEnemigaReabastecimiento();

	FORCEINLINE int GetCantMunicionAlmacenada() const { return cantMunicionAlmacenada; }
	FORCEINLINE FString GetTipoMunicionAlmacenada() const { return tipoMunicionAlmacenada; }

	FORCEINLINE void SetCantMunicionAlmacenada(int _cantMunicionAlmacenada) { cantMunicionAlmacenada = _cantMunicionAlmacenada; }
	FORCEINLINE void SetTipoMunicionAlmacenada(FString _tipoMunicionAlmacenada) { tipoMunicionAlmacenada = _tipoMunicionAlmacenada; }

public:

	virtual void Tick(float DeltaTime);

protected:

	virtual void Mover(float DeltaTime);
	virtual void Destruirse();
	
};
