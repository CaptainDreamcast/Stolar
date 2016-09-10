uint8 FightPlayerGetWhichPlayerFromObjectAndInstance(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

uint8 WhichPlayer, ReturnPlayer;

ReturnPlayer = PlayerMain;
for(WhichPlayer=0; WhichPlayer < FightData->OverWorldData->LogicData.General.PlayerAmount; WhichPlayer++){
if(
FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject == WhichObject &&
FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance == WhichInstance
){
ReturnPlayer = WhichPlayer;
WhichPlayer = FightData->OverWorldData->LogicData.General.PlayerAmount;
}
}


return(ReturnPlayer);
}