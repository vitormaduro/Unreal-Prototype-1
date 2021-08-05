// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridCellBase.generated.h"

UCLASS(Blueprintable)
class PUGA_GAME_API AGridCellBase : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
		TArray<int> id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isFree;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool hasCoin;

	// Sets default values for this actor's properties
	AGridCellBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void SetId(TArray<int> newId);

	UFUNCTION(BlueprintCallable)
		TArray<int> GetId();

	UFUNCTION(BlueprintCallable)
		bool GetIsFree();

	UFUNCTION(BlueprintCallable)
		bool GetHasCoin();
};
