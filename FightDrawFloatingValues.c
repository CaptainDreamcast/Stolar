#define FightDrawFloatingValuesTransformationDataAmount	2

void FightDrawFloatingValues(FightStruct* FightData, OverWorldStruct* OverWorldData){

TransformationStruct TransformationData;
FightFloatingValueStruct* FloatingValueData;
uint8 DirtyDeedsDoneDirtCheap;

TransformationData = CombineMultipleTransformationData(FightDrawFloatingValuesTransformationDataAmount, &FightData->LogicData.General.TransformationData, &FightData->LogicData.UserInterFace.TransformationData);

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<FightData->LogicData.FloatingValues.Amount; DirtyDeedsDoneDirtCheap++){
FloatingValueData = (FightFloatingValueStruct*)ListGet(FightData->FloatingValueData, DirtyDeedsDoneDirtCheap);


if(FloatingValueData->LogicData.Stage == FightFloatingValueStageBuildUp){
LogicAlphaBuildUp(FloatingValueData->LogicData.AlphaValue, 
OverWorldData->Loadable->Fight.UserInterFace.FloatingValues.TimeInSecondsBuildUp, 
{
LogicCounterInitiate(FloatingValueData->LogicData.Ticks);
FloatingValueData->LogicData.Stage = FightFloatingValueStageNormal;
}
);
}
else if(FloatingValueData->LogicData.Stage == FightFloatingValueStageNormal){
LogicCounter(FloatingValueData->LogicData.Ticks, OverWorldData->Loadable->Fight.UserInterFace.FloatingValues.TimeInSecondsNormal, 
{
FloatingValueData->LogicData.Stage = FightFloatingValueStageBuildDown;
}
);
}
else if(FloatingValueData->LogicData.Stage == FightFloatingValueStageBuildDown){
LogicAlphaBuildDown(FloatingValueData->LogicData.AlphaValue, 
OverWorldData->Loadable->Fight.UserInterFace.FloatingValues.TimeInSecondsBuildDown, 
{
FloatingValueData->LogicData.Stage = FightFloatingValueStageOver;
}
);
}

DrawArrayToScreen(FloatingValueData->FluxData.Array, 
FloatingValueData->LogicData.PositionX, FloatingValueData->LogicData.PositionY, 
FloatingValueData->LogicData.ScreenPositionZ,  
FloatingValueData->LogicData.FontSizeX, FloatingValueData->LogicData.FontSizeY, 
FloatingValueData->LogicData.Color, OverWorldData->Loadable->Fight.UserInterFace.FloatingValues.WhichFont, &TransformationData);

}
}
