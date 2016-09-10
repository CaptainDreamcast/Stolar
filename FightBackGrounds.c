void FightBackGrounds(FightStruct* FightData){

uint8 WhichObject;

for(WhichObject = 0; WhichObject < FightData->Loadable.Stage->General.BackGroundObjectAmount; WhichObject++){
FightBackGroundsSingleObject(FightData, WhichObject);
}

}