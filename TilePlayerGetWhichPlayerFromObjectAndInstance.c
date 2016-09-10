uint8 TilePlayerGetWhichPlayerFromObjectAndInstance(TileStruct* TileData, OverWorldStruct* OverWorldData, uint8 WhichObject, uint8 WhichInstance){

uint8 WhichPlayer, ReturnPlayer;

ReturnPlayer = PlayerMain;
for(WhichPlayer=0; WhichPlayer < OverWorldData->LogicData.General.PlayerAmount; WhichPlayer++){
if(
TileData->PlayerData[WhichPlayer].LogicData.WhichObject == WhichObject &&
TileData->PlayerData[WhichPlayer].LogicData.WhichInstance == WhichInstance
){
ReturnPlayer = WhichPlayer;
WhichPlayer = OverWorldData->LogicData.General.PlayerAmount;
}
}


return(ReturnPlayer);
}