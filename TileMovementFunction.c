void TileMovementFunction(TileStruct* TileData, float NewStagePositionZ, float BaseSpeedX, float* SpeedX, float* PositionY, float* ScreenPositionZ, float BaseSizeX, float* SizeX, float BaseSizeY, float* SizeY, TileMovementLogicStruct* TileMovementLogicData)	{ 

(*SpeedX) = BaseSpeedX*TileMovementComputeQuadraticInterPolation(NewStagePositionZ, (&TileMovementLogicData->SpeedFactorX)); 
(*PositionY) = TileMovementComputeLinearInterPolation(NewStagePositionZ, (&TileMovementLogicData->PositionY)); 
(*ScreenPositionZ) = TileMovementComputeLinearInterPolation(NewStagePositionZ, (&TileMovementLogicData->ScreenPositionZ)); 
(*SizeX) = BaseSizeX*TileMovementComputeQuadraticInterPolation(NewStagePositionZ, (&TileMovementLogicData->SizeFactorX)); 
(*SizeY) = BaseSizeY*TileMovementComputeQuadraticInterPolation(NewStagePositionZ, (&TileMovementLogicData->SizeFactorY)); 

} 