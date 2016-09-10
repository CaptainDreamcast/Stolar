void FightObjects(FightStruct* FightData){

uint8 WhichObject;

for(WhichObject = 0; WhichObject < FightData->LogicData.General.ObjectAmount; WhichObject++){
FightObjectsSingleObject(FightData, WhichObject);
}

}