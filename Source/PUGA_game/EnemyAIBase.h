// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyAIBase.generated.h"


UCLASS( Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class PUGA_GAME_API UEnemyAIBase : public UActorComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
		AActor* GetNextCellInPath(TArray<AActor*> adjacentCells, AActor* obj, TArray<AActor*> coins);
		
};
