void FightObjectsSingleObjectSingleInstanceIntelligenceAccumulatedDamage(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichIntelligence){

if(FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Health >= FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Damage){
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Health -= FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Damage;
}
else{
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Health = FightHealthEmpty;
}

FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Damage = MinimumByteValue;

}