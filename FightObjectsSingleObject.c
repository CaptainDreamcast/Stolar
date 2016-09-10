void FightObjectsSingleObject(FightStruct* FightData, uint8 WhichObject){

uint8 WhichInstance;

FightObjectsSingleObjectFunctions(FightData, WhichObject);

for(WhichInstance = 0; WhichInstance < FightData->ObjectData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
FightObjectsSingleObjectSingleInstance(FightData, WhichObject, WhichInstance);
}

}