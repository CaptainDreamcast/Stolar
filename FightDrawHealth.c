#define FightDrawHealthTransformationDataAmount	2

#define FightDrawHealthFactorBelowIsRed				0.1f
#define FightDrawHealthFactorBelowIsColorChange	0.2f

void FightDrawHealth(FightStruct* FightData, OverWorldStruct* OverWorldData){

vector_t FinalVector[PolygonCornerAmount];
TransformationStruct TransformationData;
float Red, Green;
float SizeX;

SizeX = ((float)FightData->LogicData.Stolar.HealthNow/FightData->LogicData.Stolar.HealthMax)*OverWorldData->Loadable->Fight.UserInterFace.Health.General.TextureSizeX;

if(FightData->LogicData.Stolar.HealthNow < (FightData->LogicData.Stolar.HealthMax*FightDrawHealthFactorBelowIsRed)) Red = FullColorFloatValue;
else if(FightData->LogicData.Stolar.HealthNow < (FightData->LogicData.Stolar.HealthMax*FightDrawHealthFactorBelowIsColorChange)){ 
Red = ((FightData->LogicData.Stolar.HealthNow-(FightData->LogicData.Stolar.HealthMax*FightDrawHealthFactorBelowIsRed))/((FightData->LogicData.Stolar.HealthMax*FightDrawHealthFactorBelowIsColorChange)-(FightData->LogicData.Stolar.HealthMax*FightDrawHealthFactorBelowIsRed)));
}
else Red = NoColorFloatValue;
Green = FullColorFloatValue-Red;

TransformationData = CombineMultipleTransformationData(FightDrawHealthTransformationDataAmount, &FightData->LogicData.General.TransformationData, &FightData->LogicData.UserInterFace.TransformationData);
SetupTransformAndDrawSimplest(FinalVector, &TransformationData, OverWorldData->TextureData.Fight.UserInterFace.HealthBackGround, 
OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.PositionX, OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.PositionY, 
OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.ScreenPositionZ, 
OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.TextureSizeX, OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.TextureSizeY, 
OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.TextureSizeX, OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.TextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY);

SetupTransformAndDraw(FinalVector, &TransformationData, OverWorldData->TextureData.Fight.UserInterFace.Health, 
OverWorldData->Loadable->Fight.UserInterFace.Health.General.PositionX, OverWorldData->Loadable->Fight.UserInterFace.Health.General.PositionY, 
OverWorldData->Loadable->Fight.UserInterFace.Health.General.ScreenPositionZ, 
SizeX, OverWorldData->Loadable->Fight.UserInterFace.Health.General.TextureSizeY, 
OverWorldData->Loadable->Fight.UserInterFace.Health.General.TextureSizeX, OverWorldData->Loadable->Fight.UserInterFace.Health.General.TextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY, FullColorFloatValue, Red, Green, FullColorFloatValue);


}