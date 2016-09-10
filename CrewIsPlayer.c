uint8 CrewIsPlayer(OverWorldStruct* OverWorldData, uint8 WhichCrewMember){
uint8 ReturnValue, WhichPlayer;

ReturnValue = LogicActiveNot;
for(WhichPlayer = 0; WhichPlayer < OverWorldData->LogicData.General.PlayerAmount; WhichPlayer++){
if(OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember == WhichCrewMember){
ReturnValue = LogicActive;
WhichPlayer = OverWorldData->LogicData.General.PlayerAmount;
}
}

return(ReturnValue);
}

uint8 CrewIsPlayerValueGet(OverWorldStruct* OverWorldData, uint8 WhichCrewMember){
uint8 ReturnValue, WhichPlayer;

ReturnValue = LogicActiveNot;
for(WhichPlayer = 0; WhichPlayer < OverWorldData->LogicData.General.PlayerAmount; WhichPlayer++){
if(OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember == WhichCrewMember){
ReturnValue = WhichPlayer;
WhichPlayer = OverWorldData->LogicData.General.PlayerAmount;
}
}

return(ReturnValue);
}
