#define YellowAbilityPositionX	10
#define YellowAbilityPositionY	10

#define GreenAbilityPositionX	10
#define GreenAbilityPositionY	10

#define BlueAbilityPositionX	10
#define BlueAbilityPositionY	10

#define AbilityPositionZ	7

void DrawFightAbilities(GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, TransformationStruct* TransformationData){

vector_t FinalVectorYellow[PolygonCornerAmount];
vector_t FinalVectorGreen[PolygonCornerAmount];
vector_t FinalVectorBlue[PolygonCornerAmount];

short Red, Green, Blue;

SetupVectors(FinalVectorYellow, YellowAbilityPositionX, YellowAbilityPositionY, AbilityPositionZ, GraphicalUserInterFaceData->AbilityData[YellowAbility].TextureSizeX, GraphicalUserInterFaceData->AbilityData[YellowAbility].TextureSizeY);
SetupVectors(FinalVectorGreen, GreenAbilityPositionX, GreenAbilityPositionY, AbilityPositionZ, GraphicalUserInterFaceData->AbilityData[GreenAbility].TextureSizeX, GraphicalUserInterFaceData->AbilityData[GreenAbility].TextureSizeY);
SetupVectors(FinalVectorBlue, BlueAbilityPositionX, BlueAbilityPositionY, AbilityPositionZ, GraphicalUserInterFaceData->AbilityData[BlueAbility].TextureSizeX, GraphicalUserInterFaceData->AbilityData[BlueAbility].TextureSizeY);

if(GraphicalUserInterFaceData->AbilityData[YellowAbility].Active){Red = Green = 255; Blue = 0;}
else {Red = Green = (((float)GraphicalUserInterFaceData->AbilityData[YellowAbility].FilledNow/GraphicalUserInterFaceData->AbilityData[YellowAbility].FilledMax))*255; Blue = 0;}
ThresholdToTexture(GraphicalUserInterFaceData->ThresholdTexture, GraphicalUserInterFaceData->FinalBarTexture[YellowAbility], (((short)(254*((float)GraphicalUserInterFaceData->AbilityData[YellowAbility].FilledNow/GraphicalUserInterFaceData->AbilityData[YellowAbility].FilledMax))) << 4), 64*64*2, Red, Green, Blue);

if(GraphicalUserInterFaceData->AbilityData[GreenAbility].Active){Red = 0; Green = 255; Blue = 0;}
else {Red = 0; Green = (((float)GraphicalUserInterFaceData->AbilityData[GreenAbility].FilledNow/GraphicalUserInterFaceData->AbilityData[GreenAbility].FilledMax))*255; Blue = 0;}
ThresholdToTexture(GraphicalUserInterFaceData->ThresholdTexture, GraphicalUserInterFaceData->FinalBarTexture[GreenAbility], (((short)(254*((float)GraphicalUserInterFaceData->AbilityData[GreenAbility].FilledNow/GraphicalUserInterFaceData->AbilityData[GreenAbility].FilledMax))) << 4), 64*64*2, Red, Green, Blue);

if(GraphicalUserInterFaceData->AbilityData[BlueAbility].Active){Red = 0; Green = 0; Blue = 255;}
else {Red = 0; Green = 0; Blue = (((float)GraphicalUserInterFaceData->AbilityData[BlueAbility].FilledNow/GraphicalUserInterFaceData->AbilityData[BlueAbility].FilledMax))*255;}
ThresholdToTexture(GraphicalUserInterFaceData->ThresholdTexture, GraphicalUserInterFaceData->FinalBarTexture[BlueAbility], (((short)(254*((float)GraphicalUserInterFaceData->AbilityData[BlueAbility].FilledNow/GraphicalUserInterFaceData->AbilityData[BlueAbility].FilledMax))) << 4), 64*64*2, Red, Green, Blue);


if(TransformationData != NULL && TransformationData->Active){ 
Transformation(FinalVectorYellow, TransformationData);
Transformation(FinalVectorGreen, TransformationData);
Transformation(FinalVectorBlue, TransformationData);
}

DrawVectorTexture(
FinalVectorYellow, GraphicalUserInterFaceData->AbilityTexture[YellowAbility], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
GraphicalUserInterFaceData->AbilityData[YellowAbility].TextureSizeX, 
GraphicalUserInterFaceData->AbilityData[YellowAbility].TextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

DrawVectorTexture(
FinalVectorYellow, GraphicalUserInterFaceData->FinalBarTexture[YellowAbility], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
GraphicalUserInterFaceData->AbilityData[YellowAbility].TextureSizeX, 
GraphicalUserInterFaceData->AbilityData[YellowAbility].TextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

DrawVectorTexture(
FinalVectorGreen, GraphicalUserInterFaceData->AbilityTexture[GreenAbility], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
GraphicalUserInterFaceData->AbilityData[GreenAbility].TextureSizeX, 
GraphicalUserInterFaceData->AbilityData[GreenAbility].TextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

DrawVectorTexture(
FinalVectorGreen, GraphicalUserInterFaceData->FinalBarTexture[GreenAbility], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
GraphicalUserInterFaceData->AbilityData[GreenAbility].TextureSizeX, 
GraphicalUserInterFaceData->AbilityData[GreenAbility].TextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

DrawVectorTexture(
FinalVectorBlue, GraphicalUserInterFaceData->AbilityTexture[BlueAbility], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
GraphicalUserInterFaceData->AbilityData[BlueAbility].TextureSizeX, 
GraphicalUserInterFaceData->AbilityData[BlueAbility].TextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

DrawVectorTexture(
FinalVectorBlue, GraphicalUserInterFaceData->FinalBarTexture[BlueAbility], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
GraphicalUserInterFaceData->AbilityData[BlueAbility].TextureSizeX, 
GraphicalUserInterFaceData->AbilityData[BlueAbility].TextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

}
