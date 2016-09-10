float FightFromStagePositionReturnPositionY(FightStruct* FightData, float StagePositionZ){
return(FightData->Loadable.Stage->BackGround.PositionStartY+((FightData->Loadable.Stage->BackGround.PositionEndY-FightData->Loadable.Stage->BackGround.PositionStartY)*((StagePositionZ)/(FightData->Loadable.Stage->BackGround.StageSizeZ))));
}