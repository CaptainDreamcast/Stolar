float TileLoadCreateNewStagePositionFromPlayerStartPositionX(TileStruct* TileData, OverWorldStruct* OverWorldData, uint8 WhichPlayer){
float ReturnValue;

ReturnValue = TileData->ObjectData[TileData->PlayerData[WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[WhichPlayer].LogicData.WhichInstance].Loadable->PositionX-(ScreenSizeX/2);
if(ReturnValue < 0.0f) ReturnValue = 0.0f;
else if((ReturnValue+ScreenSizeX) > TileData->TileHeaderData->TileAbsoluteSizeX) ReturnValue = TileData->TileHeaderData->TileAbsoluteSizeX-ScreenSizeX;

return ReturnValue;
}

float TileLoadCreateNewStagePositionFromPlayerStartPositionY(TileStruct* TileData, OverWorldStruct* OverWorldData, uint8 WhichPlayer){
float ReturnValue;

ReturnValue =  TileData->ObjectData[TileData->PlayerData[WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[WhichPlayer].LogicData.WhichInstance].LogicData.PositionY-(ScreenSizeY/2);
if(ReturnValue < 0.0f) ReturnValue = 0.0f;
else if((ReturnValue+ScreenSizeY) > TileData->TileHeaderData->TileAbsoluteSizeY) ReturnValue = TileData->TileHeaderData->TileAbsoluteSizeY-ScreenSizeY;

return ReturnValue;
}