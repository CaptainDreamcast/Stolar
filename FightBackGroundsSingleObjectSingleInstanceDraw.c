#define FightBackGroundsSingleObjectSingleInstanceDrawTransformationDataPersonalAmount	2

void FightBackGroundsSingleObjectSingleInstanceDraw(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

vector_t FinalVector[PolygonCornerAmount];

float PositionX, PositionY;
TransformationStruct PersonalTransformationData;

if(FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.Draw){

if(FightData->Loadable.Stage->BackGround.StageSizeX > ScreenSizeX) PositionX = FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable->PositionX-FightData->LogicData.Stage.StagePositionX*(((float)(FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable->LayerSizeX-ScreenSizeX))/(FightData->Loadable.Stage->BackGround.StageSizeX-ScreenSizeX));
else PositionX = FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable->PositionX;

if(FightData->Loadable.Stage->BackGround.StageSizeY > ScreenSizeY) PositionY = FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable->PositionY-FightData->LogicData.Stage.StagePositionY*(((float)(FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable->LayerSizeY-ScreenSizeY))/(FightData->Loadable.Stage->BackGround.StageSizeY-ScreenSizeY));
else PositionY = FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable->PositionY;


PersonalTransformationData = CombineMultipleTransformationData(FightBackGroundsSingleObjectSingleInstanceDrawTransformationDataPersonalAmount, &FightData->LogicData.BackGround.GeneralTransformationData, &FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.TransformationData);
SetupTransformAndDrawSimplest(FinalVector, 
&PersonalTransformationData,
FightData->BackGroundData[WhichObject].Texture[FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable->CurrentFrame], 
PositionX, PositionY, FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable->PositionZ, 
FightData->BackGroundData[WhichObject].Loadable->TextureSizeX, FightData->BackGroundData[WhichObject].Loadable->TextureSizeY, 
FightData->BackGroundData[WhichObject].Loadable->TextureSizeX, FightData->BackGroundData[WhichObject].Loadable->TextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);
}

}