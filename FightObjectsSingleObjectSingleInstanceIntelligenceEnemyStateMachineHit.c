uint8 FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineHit(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){
uint8 ReturnValue;

if(
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX || 
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityY ||
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ
){
ReturnValue = LogicActive;
}
else ReturnValue = LogicActiveNot;

return(ReturnValue);
}