// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <PUGA_game/GridCellBase.h>
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameStateBase.h"
#include "GameControllerBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PUGA_GAME_API AGameControllerBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Grid")
		int gridWidth;
	UPROPERTY(BlueprintReadWrite, Category = "Grid")
		int gridHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		AActor* grid;

	UFUNCTION(BlueprintCallable)
		bool CompareArrays(const TArray<int> &array1, const TArray<int> &array2);
	UFUNCTION(BlueprintCallable)
		TArray<AGridCellBase*> GetValidCells(TArray<int> playerPosition);
	UFUNCTION(BlueprintCallable)
		AGridCellBase* GetFreeCell();
};