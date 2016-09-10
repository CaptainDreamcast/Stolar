void FightStagePositionParseZ(FightStruct* FightData, float StagePositionZ, float* ScreenPositionZ, float* PositionY){

(*ScreenPositionZ) = FightData->Loadable.Stage->BackGround.ScreenPositionStartZ+((FightData->Loadable.Stage->BackGround.ScreenPositionEndZ-FightData->Loadable.Stage->BackGround.ScreenPositionStartZ)*((StagePositionZ)/(FightData->Loadable.Stage->BackGround.StageSizeZ)));
(*PositionY) = FightFromStagePositionReturnPositionY(FightData, StagePositionZ);

}