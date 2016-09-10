#define FightDrawBackGroundTransformationDataGeneralAmount			2
#define FightDrawBackGroundTransformationDataPersonalAmount		2

void FightDrawBackGround(FightStruct* FightData, OverWorldStruct*OverWorldData){


TransformationStruct GeneralTransformationData, PersonalTransformationData;
vector_t FinalVector[PolygonCornerAmount];
float PositionX, PositionY;
uint8 DirtyDeedsDoneDirtCheap;

if((FightData->LogicData.General.DrawFlags & FightDrawFlagBackGround)){

GeneralTransformationData = CombineMultipleTransformationData(FightDrawBackGroundTransformationDataGeneralAmount, &FightData->LogicData.General.TransformationData, &FightData->LogicData.BackGround.TransformationData); 

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<FightData->Loadable.Stage->General.BackGroundAmount; DirtyDeedsDoneDirtCheap++){
if(FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.Draw){

if(FightData->Loadable.Stage->BackGround.StageSizeX > ScreenSizeX) PositionX = FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->PositionX-FightData->LogicData.BackGround.StagePositionX*(((float)(FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->LayerSizeX-ScreenSizeX))/(FightData->Loadable.Stage->BackGround.StageSizeX-ScreenSizeX));
else PositionX = FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->PositionX;

if(FightData->Loadable.Stage->BackGround.StageSizeY > ScreenSizeY) PositionY = FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->PositionY-FightData->LogicData.BackGround.StagePositionY*(((float)(FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->LayerSizeY-ScreenSizeY))/(FightData->Loadable.Stage->BackGround.StageSizeY-ScreenSizeY));
else PositionY = FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->PositionY;


PersonalTransformationData = CombineMultipleTransformationData(FightDrawBackGroundTransformationDataPersonalAmount, &GeneralTransformationData, &FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.TransformationData);
SetupTransformAndDrawSimplest(FinalVector, 
&PersonalTransformationData,
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Texture[FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.CurrentFrame], 
PositionX, PositionY, FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->ScreenPositionZ, 
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeX, FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeY, 
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeX, FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);
}
}

if((FightData->LogicData.General.AnimationFlags & FightAnimationFlagBackGround)){
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<FightData->Loadable.Stage->General.BackGroundAmount; DirtyDeedsDoneDirtCheap++){
if(FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.Animate){
AnimateWithAnimationFactorLoop(FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.Ticks, 
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->AnimationDurationInSeconds, 
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.AnimationFactor, 
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.CurrentFrame, 
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable->FrameAmount);
}
}
}
}
}
