#define TileDrawBackGroundTransformationDataGeneralAmount		2
#define TileDrawBackGroundTransformationDataPersonalAmount		2

void TileDrawBackGround(TileStruct* TileData, OverWorldStruct* OverWorldData){

TransformationStruct GeneralTransformationData, PersonalTransformationData;
vector_t FinalVector[PolygonCornerAmount];
float PositionX, PositionY;
uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;

if((TileData->LogicData.General.DrawFlags & TileDrawFlagBackGround)){
GeneralTransformationData = CombineMultipleTransformationData(TileDrawBackGroundTransformationDataGeneralAmount, &TileData->LogicData.General.TransformationData, &TileData->LogicData.BackGround.TransformationData); 

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->AnimationAmount; DirtyDeedsDoneDirtCheap++){
for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->InstanceAmount; BurningDownTheHouse++){

if(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Active && TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Draw){

if(TileData->TileHeaderData->TileAbsoluteSizeX > ScreenSizeX) PositionX = TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->PositionX-TileData->LogicData.BackGround.StagePositionX*(((float)(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->LayerSizeX-ScreenSizeX))/(TileData->TileHeaderData->TileAbsoluteSizeX-ScreenSizeX));
else PositionX = TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->PositionX;

if(TileData->TileHeaderData->TileAbsoluteSizeY > ScreenSizeY) PositionY = TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->PositionY-TileData->LogicData.BackGround.StagePositionY*(((float)(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->LayerSizeY-ScreenSizeY))/(TileData->TileHeaderData->TileAbsoluteSizeY-ScreenSizeY));
else PositionY = TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->PositionY;

PersonalTransformationData = CombineMultipleTransformationData(TileDrawBackGroundTransformationDataPersonalAmount, &GeneralTransformationData, &TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.TransformationData);
SetupTransformAndDrawSimplest(FinalVector, 
&PersonalTransformationData,
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Texture[TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->CurrentFrame], 
PositionX, PositionY, TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->PositionZ, 
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeX, TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeY, 
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeX, TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);
}
}
}
}

if((TileData->LogicData.General.AnimationFlags & TileAnimationFlagBackGround)){
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->AnimationAmount; DirtyDeedsDoneDirtCheap++){
for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->InstanceAmount; BurningDownTheHouse++){

if(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Active && TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Animate){
TileAnimateWithAnimationFactor(
(&TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->AnimationData), 
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Ticks, 
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->AnimationFactor, 
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->CurrentFrame, 
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.CurrentAnimation 
);
}
}
}
}

}