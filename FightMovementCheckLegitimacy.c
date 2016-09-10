uint8 FightMovementCheckLegitimacyX(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, float PositionX, float StagePositionZ){
uint8 ReturnValue;
uint8 CurrentObject, CurrentInstance;

ReturnValue = LogicActive;
if(PositionX >= FightData->Loadable.Stage->BackGround.StageSizeX){
ReturnValue = LogicActiveNot;
}
else if(PositionX < 0){
ReturnValue = LogicActiveNot;
}
else{
for(CurrentObject = 0; (CurrentObject < FightData->LogicData.General.ObjectAmount && ReturnValue); CurrentObject++){
for(CurrentInstance = 0; (CurrentInstance < FightData->ObjectData[CurrentObject].Loadable->InstanceAmount && ReturnValue); CurrentInstance++){
ReturnValue = LogicInvertSimple(FightObjectsSingleObjectSingleInstanceBlockage(FightData, CurrentObject, CurrentInstance, PositionX, StagePositionZ));
}
}
}

return(ReturnValue);
}


uint8 FightMovementCheckLegitimacyZ(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, float PositionX, float StagePositionZ){
uint8 ReturnValue;
uint8 CurrentObject, CurrentInstance;

ReturnValue = LogicActive;
if(StagePositionZ >= FightData->Loadable.Stage->BackGround.StageSizeZ){
ReturnValue = LogicActiveNot;
}
else if(StagePositionZ < 0){
ReturnValue = LogicActiveNot;
}
else{
for(CurrentObject = 0; (CurrentObject < FightData->LogicData.General.ObjectAmount && ReturnValue); CurrentObject++){
for(CurrentInstance = 0; (CurrentInstance < FightData->ObjectData[CurrentObject].Loadable->InstanceAmount && ReturnValue); CurrentInstance++){
ReturnValue = LogicInvertSimple(FightObjectsSingleObjectSingleInstanceBlockage(FightData, CurrentObject, CurrentInstance, PositionX, StagePositionZ));
}
}
}

return(ReturnValue);
}