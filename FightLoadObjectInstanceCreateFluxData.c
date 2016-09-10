uint32 FightLoadObjectInstanceCreateFluxDataPlayer(FightStruct* FightData, uint32 CurrentPointerPosition, uint8 WhichObject, uint8 WhichInstance, uint8 WhichCrewMember){
FightLoadObjectInstanceCreateFluxDataIntelligencePlayer(FightData, WhichObject, WhichInstance, WhichCrewMember);
CurrentPointerPosition = (*FightLoadObjectInstanceCreateFluxDataBlockageDispatch[FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->Blockage.Type])(FightData, CurrentPointerPosition, WhichObject, WhichInstance);
return(CurrentPointerPosition);
}

void FightLoadObjectInstanceCreateFluxDataCrew(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichCrewMember){
printf("FightLoadObjectInstanceCreateFluxDataCrew called!\n");
}

uint32 FightLoadObjectInstanceCreateFluxDataEnemy(FightStruct* FightData, FightEnemyGivenStruct* FightEnemyGivenData, uint32 CurrentPointerPosition, uint8 WhichObject, uint8 WhichInstance, uint8 WhichEnemy){
CurrentPointerPosition = FightLoadObjectInstanceCreateFluxDataIntelligenceEnemy(FightData, FightEnemyGivenData, CurrentPointerPosition, WhichObject, WhichInstance, WhichEnemy);
CurrentPointerPosition = (*FightLoadObjectInstanceCreateFluxDataBlockageDispatch[FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->Blockage.Type])(FightData, CurrentPointerPosition, WhichObject, WhichInstance);

return(CurrentPointerPosition);
}

uint32 FightLoadObjectInstanceCreateFluxDataObject(FightStruct* FightData, uint32 CurrentPointerPosition, uint8 WhichObject, uint8 WhichInstance, uint8 CurrentObject){
CurrentPointerPosition = (*FightLoadObjectInstanceCreateFluxDataBlockageDispatch[FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->Blockage.Type])(FightData, CurrentPointerPosition, WhichObject, WhichInstance);
return(CurrentPointerPosition);
}