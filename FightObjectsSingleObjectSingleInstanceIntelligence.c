void FightObjectsSingleObjectSingleInstanceIntelligence(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

uint8 WhichIntelligence;

for(WhichIntelligence = 0; WhichIntelligence < FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->IntelligenceAmount; WhichIntelligence++){
if(!FightData->ObjectData[WhichObject].Instance[WhichInstance].Intelligence[WhichIntelligence].LogicData.Semaphore){
(*FightObjectsSingleObjectSingleInstanceIntelligenceFunction[FightData->ObjectData[WhichObject].Instance[WhichInstance].Intelligence[WhichIntelligence].LogicData.IntelligenceType])(FightData, WhichObject, WhichInstance, WhichIntelligence);
}
}

}