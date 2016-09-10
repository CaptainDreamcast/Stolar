uint8 FightObjectsSingleObjectSingleInstanceBlockage(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, float PositionX, float StagePositionZ){
return((*FightObjectsSingleObjectSingleInstanceBlockageFunction[FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->Blockage.Type])(FightData, WhichObject, WhichInstance, PositionX, StagePositionZ));
}