#define FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineAttackMeleeRange 	32

uint8 FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachinePlayerIsInAttackMeleeRange(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){
uint8 ReturnValue, WhichPlayer;

ReturnValue = LogicActiveNot;
for(WhichPlayer=0; WhichPlayer < FightData->OverWorldData->LogicData.General.PlayerAmount; WhichPlayer++){
if(FightDistanceSquaredCompareInstances(&FightData->ObjectData[WhichObject].Instance[WhichInstance], &FightData->ObjectData[FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject].Instance[FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance]) < Square(FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineAttackMeleeRange)){
ReturnValue = LogicActive;
}
}


return(ReturnValue);
}