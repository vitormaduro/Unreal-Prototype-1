// Fill out your copyright notice in the Description page of Project Settings.


#include "gameController.h"

UPROPERTY(EditAnywhere, BlueprintReadWrite)
int gridHeight;

UPROPERTY(EditAnywhere, BlueprintReadWrite)
int gridWidth;

// Sets default values for this component's properties
UgameController::UgameController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	gridHeight = 5;
	gridWidth = 10;
}


// Called when the game starts
void UgameController::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UgameController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}