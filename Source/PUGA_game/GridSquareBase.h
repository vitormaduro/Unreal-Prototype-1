// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GridSquareBase.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PUGA_GAME_API UGridSquareBase : public UActorComponent
{
	GENERATED_BODY()

public:
	int id[2];
};
