// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIBase.h"


AActor* UEnemyAIBase::GetNextCellInPath(TArray<AActor*> adjacentCells, AActor* obj, TArray<AActor*> coins) {
	FVector objPosition = obj->GetActorLocation();
	FVector coinPosition;
	FVector cellPosition;
	AActor* closestCoin = nullptr;
	AActor* nextCellInPath = nullptr;
	float shortestPath = 10000.0f;
	float shortestCellToCoin = 10000.0f;

	for (auto& coin : coins) {
		if (!coin)	continue;

		coinPosition = coin->GetActorLocation();

		if (FVector::Dist(objPosition, coinPosition) < shortestPath) {
			shortestPath = FVector::Dist(objPosition, coinPosition);
			closestCoin = coin;
		}
	}

	if (!closestCoin) return nullptr;

	for (auto& cell : adjacentCells) {
		if (!cell)	continue;

		cellPosition = cell->GetActorLocation();

		if (FVector::Dist(cellPosition, closestCoin->GetActorLocation()) < shortestCellToCoin) {
			shortestCellToCoin = FVector::Dist(cellPosition, closestCoin->GetActorLocation());
			nextCellInPath = cell;
		}
	}

	return nextCellInPath;
}