// Fill out your copyright notice in the Description page of Project Settings.


#include "GameControllerBase.h"

bool AGameControllerBase::CompareArrays(const TArray<int> &array1, const TArray<int> &array2) {
	// If the arrays have different sizes, they are not equal
	if (array1.Num() != array2.Num())	return false;

	// For every element, checks if the element on the other array is equal
	for (int i = 0; i < array1.Num(); i++) {
		if (array1[i] != array2[i])	return false;
	}

	return true;
}

TArray<AGridCellBase*> AGameControllerBase::GetValidCells(TArray<int> playerPosition) {
	TArray<AGridCellBase*> validCells;
	TArray<int> cellId;

	for (TObjectIterator<AGridCellBase> Itr; Itr; ++Itr) {
		if (Itr->IsA(AGridCellBase::StaticClass())) {
			cellId.Empty();
			cellId.Add(Itr->GetId()[0]);
			cellId.Add(Itr->GetId()[1]);

			if (cellId.Num() != 2 || playerPosition.Num() != 2) {
				validCells.Init(nullptr, 1);
				return validCells;
			}

			if ((cellId[0] == playerPosition[0] - 1 || cellId[0] == playerPosition[0] + 1 || cellId[0] == playerPosition[0]) &&
				(cellId[1] == playerPosition[1] - 1 || cellId[1] == playerPosition[1] + 1 || cellId[1] == playerPosition[1])) {
				validCells.Add(*Itr);
			}
		}
	}

	return validCells;
}

AGridCellBase* AGameControllerBase::GetFreeCell() {
	TArray<AGridCellBase*> cells;
	AGridCellBase* selectedCell;

	for (TObjectIterator<AGridCellBase> Itr; Itr; ++Itr) {
		if (Itr->IsA(AGridCellBase::StaticClass())) {
			cells.Add(*Itr);
		}
	}

	if (cells.Num() == 0) return nullptr;

	do {
		selectedCell = cells[FMath::RandRange(0, cells.Num() - 1)];
	} while (!selectedCell->GetIsFree() || selectedCell->GetHasCoin());

	return selectedCell;
}