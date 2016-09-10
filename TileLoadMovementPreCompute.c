void TileLoadMovementPreCompute(TileStruct* TileData, 
TileMovementLoadableStruct* TileMovementLoadableData, TileMovementLogicStruct* TileMovementLogicData
){

TileMovementPreComputeLinearInterPolation((&TileMovementLoadableData->PositionY), (&TileMovementLogicData->PositionY));
TileMovementPreComputeLinearInterPolation((&TileMovementLoadableData->ScreenPositionZ), (&TileMovementLogicData->ScreenPositionZ));
TileMovementPreComputeQuadraticInterPolation((&TileMovementLoadableData->SizeFactorX), (&TileMovementLogicData->SizeFactorX));
TileMovementPreComputeQuadraticInterPolation((&TileMovementLoadableData->SizeFactorY), (&TileMovementLogicData->SizeFactorY));
TileMovementPreComputeQuadraticInterPolation((&TileMovementLoadableData->SpeedFactorX), (&TileMovementLogicData->SpeedFactorX));

}