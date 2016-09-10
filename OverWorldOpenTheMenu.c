void OverWorldOpenTheMenu(TileStruct* TileData, StolarOverWorldStruct* StolarOverWorldData, OverWorldMenuStruct* OverWorldMenuData){

OverWorldMenuStartUp(OverWorldMenuData, TileData);

while(OverWorldMenuData->LogicData.Stage != OverWorldMenuStageFinished){

OverWorldMenuDraw(TileData, StolarOverWorldData, OverWorldMenuData);
OverWorldMenuLogic(TileData, StolarOverWorldData, OverWorldMenuData);
OverWorldMenuInput(TileData, StolarOverWorldData, OverWorldMenuData);

}

OverWorldMenuPipeDown(OverWorldMenuData);

}
