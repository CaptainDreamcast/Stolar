uint8 FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineDead(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){
uint8 ReturnValue;

if(FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Health == FightHealthEmpty) ReturnValue = LogicActive;
else ReturnValue = LogicActiveNot;

return(ReturnValue);
}