uint8 FightMovementX(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, float SpeedX){
uint8 ReturnValue;
sint8 Direction;

Direction = SignFloat(SpeedX);
SpeedX = AbsoluteFloat(SpeedX);

ReturnValue = LogicActiveNot;
while(SpeedX >= 1.0f){

if(
FightMovementCheckLegitimacyX(FightData, WhichObject, WhichInstance, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX+Direction*1.0f, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ)
){
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX += Direction*1.0f;
SpeedX -= 1.0f;
ReturnValue = LogicActive;
}
else SpeedX = 0.0f;
}

if(SpeedX != 0.0f &&
FightMovementCheckLegitimacyX(FightData, WhichObject, WhichInstance, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX+Direction*SpeedX, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ)
){
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX += Direction*SpeedX;
ReturnValue = LogicActive;
}


return(ReturnValue);
}


uint8 FightMovementZ(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, float SpeedZ){
uint8 ReturnValue;
sint8 Direction;

Direction = SignFloat(SpeedZ);
SpeedZ = AbsoluteFloat(SpeedZ);

ReturnValue = LogicActiveNot;
while(SpeedZ >= 1.0f){

if(
FightMovementCheckLegitimacyZ(FightData, WhichObject, WhichInstance, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ+Direction*1.0f)
){
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ += Direction*1.0f;
SpeedZ -= 1.0f;
ReturnValue = LogicActive;
}
else SpeedZ = 0.0f;
}

if(SpeedZ != 0.0f &&
FightMovementCheckLegitimacyZ(FightData, WhichObject, WhichInstance, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ+Direction*SpeedZ)
){
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ += Direction*SpeedZ;
ReturnValue = LogicActive;
}


FightStagePositionParseZ(FightData, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ, 
&FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->ScreenPositionZ, 
&FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionY);

return(ReturnValue);
}