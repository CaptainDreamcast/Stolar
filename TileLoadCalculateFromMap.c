void TileLoadCalculateFromMap(TileStruct* TileData, 
float StagePositionZ, float* PositionY, float* ScreenPositionZ, float BaseSizeX, float* SizeX, float BaseSizeY, float* SizeY, float BaseSpeedX, float* SpeedX, 
TileMovementLoadableStruct* TileMovementLoadableData, TileMovementLogicStruct* TileMovementLogicData
){

TileMovementFunction(TileData, StagePositionZ, BaseSpeedX, SpeedX, PositionY, ScreenPositionZ, BaseSizeX, SizeX, BaseSizeY, SizeY, TileMovementLogicData);

}