void FightBackGroundsSingleObject(FightStruct* FightData, uint8 WhichObject){

uint8 WhichInstance;

FightBackGroundsSingleObjectFunctions(FightData, WhichObject);
for(WhichInstance = 0; WhichInstance < FightData->BackGroundData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
FightBackGroundsSingleObjectSingleInstance(FightData, WhichObject, WhichInstance);
}

}