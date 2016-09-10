#define FightUserInterFaceHealthTransformationDataAmount	2

#define FightUserInterFaceHealthFactorBelowIsRed				0.1f
#define FightUserInterFaceHealthFactorBelowIsColorChange	0.2f

void FightUserInterFaceHealthSinglePlayerDraw(FightStruct* FightData, uint8 WhichPlayer){

vector_t FinalVector[PolygonCornerAmount];
TransformationStruct TransformationData;
float Red, Green;
float SizeX;
float Right;
uint16 HealthNow, HealthMax;


HealthNow = FightData->ObjectData[FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject].Instance[FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance].LogicData.Health;
HealthMax = FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].LogicData.Fight.HealthMax;

Right = FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.General.FilePositionLeft+(FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.General.FilePositionRight-FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.General.FilePositionLeft)*((float)HealthNow/HealthMax);
SizeX = Right*FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.General.TextureSizeX;

if(HealthNow < (HealthMax*FightUserInterFaceHealthFactorBelowIsRed)) Red = FullColorFloatValue;
else if(HealthNow < (HealthMax*FightUserInterFaceHealthFactorBelowIsColorChange)){ 
Red = ((HealthNow-(HealthMax*FightUserInterFaceHealthFactorBelowIsRed))/((HealthMax*FightUserInterFaceHealthFactorBelowIsColorChange)-(HealthMax*FightUserInterFaceHealthFactorBelowIsRed)));
}
else Red = NoColorFloatValue;
Green = FullColorFloatValue-Red;


TransformationData = CombineMultipleTransformationData(FightUserInterFaceHealthTransformationDataAmount, &FightData->LogicData.General.TransformationData, &FightData->LogicData.UserInterFace.TransformationData);
SetupTransformAndDrawSimplest(FinalVector, &TransformationData, FightData->OverWorldData->TextureData.Fight.UserInterFace.HealthBackGround, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.PositionX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.PositionY, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.ScreenPositionZ, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.TextureSizeX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.TextureSizeY, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.TextureSizeX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.BackGround.TextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY);


SetupTransformAndDrawPlus(FinalVector, &TransformationData, FightData->OverWorldData->TextureData.Fight.UserInterFace.Health, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.General.PositionX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.General.PositionY, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.General.ScreenPositionZ, 
SizeX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.General.TextureSizeY, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.General.TextureSizeX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Health.General.TextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY, FullColorFloatValue, Red, Green, NoColorFloatValue, 
FullLeftTexturePosition, Right, FullLeftTexturePosition, FullRightTexturePosition);


}