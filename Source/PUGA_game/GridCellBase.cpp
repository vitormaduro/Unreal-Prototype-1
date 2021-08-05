// Fill out your copyright notice in the Description page of Project Settings.


#include "GridCellBase.h"

// Sets default values
AGridCellBase::AGridCellBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGridCellBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridCellBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGridCellBase::SetId(TArray<int> newId) {
	if (newId.Num() != 2)	return;

	id.Add(newId[0]);
	id.Add(newId[1]);
}

TArray<int> AGridCellBase::GetId() {
	if (id.Num() != 2) {
		TArray<int> tempId;
		tempId.Init(-100, 2);
		return tempId;
	}

	return id;
}

bool AGridCellBase::GetIsFree() {
	return isFree;
}

bool AGridCellBase::GetHasCoin() {
	return hasCoin;
}