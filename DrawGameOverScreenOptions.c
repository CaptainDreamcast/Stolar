void DrawGameOverScreenOptions(GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, float AlphaValueText, short OptionSelected, float* ScaleValueSelected, float* ScaleValueChangeValue, TransformationStruct* TransformationData){

vector_t FinalVector[GameOverScreenOptionAmount][PolygonCornerAmount];
TransformationStruct SecondTransformationData;
uint8 DirtyDeedsDoneDirtCheap;
float Green, Blue;

OptionSelected &= ~GameOverScreenOptionSelectedFlag;

SetupVectorAdvanced(FinalVector[GameOverScreenOptionRestart], GameOverScreenRestartUpLeftX, GameOverScreenRestartUpLeftY, GameOverScreenRestartUpRightX, GameOverScreenRestartUpRightY, GameOverScreenRestartDownLeftX, GameOverScreenRestartDownLeftY, GameOverScreenRestartDownRightX, GameOverScreenRestartDownRightY, GameOverScreenRestartPositionZ);
SetupVectorAdvanced(FinalVector[GameOverScreenOptionExit], GameOverScreenExitUpLeftX, GameOverScreenExitUpLeftY, GameOverScreenExitUpRightX, GameOverScreenExitUpRightY, GameOverScreenExitDownLeftX, GameOverScreenExitDownLeftY, GameOverScreenExitDownRightX, GameOverScreenExitDownRightY, GameOverScreenExitPositionZ);
SetupVectorAdvanced(FinalVector[GameOverScreenOptionLoad], GameOverScreenLoadUpLeftX, GameOverScreenLoadUpLeftY, GameOverScreenLoadUpRightX, GameOverScreenLoadUpRightY, GameOverScreenLoadDownLeftX, GameOverScreenLoadDownLeftY, GameOverScreenLoadDownRightX, GameOverScreenLoadDownRightY, GameOverScreenLoadPositionZ);

SetSingleVector(SecondTransformationData.PositionVector, (FinalVector[OptionSelected][3].x-FinalVector[OptionSelected][0].x)/2, (FinalVector[OptionSelected][2].y-FinalVector[OptionSelected][1].y)/2, GameOverScreenSelectedPositionZ);
SecondTransformationData.Active |= ZoomInIdentifier;
SecondTransformationData.ScaleValue = *ScaleValueSelected;
Transformation(FinalVector[OptionSelected], &SecondTransformationData);

if(TransformationData != NULL && TransformationData->Active){
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<GameOverScreenOptionAmount; DirtyDeedsDoneDirtCheap++){
Transformation(FinalVector[DirtyDeedsDoneDirtCheap], TransformationData);
}
}

if(OptionSelected == GameOverScreenOptionRestart) Green = Blue = 0.0f;
else Green = Blue = 1.0f;
DrawVectorTexturePlus(
FinalVector[GameOverScreenOptionRestart], GraphicalUserInterFaceData->GameOverScreenTexture[GameOverScreenBackGroundTexturePlus], 
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL(GameOverScreenPaletteOffset/GameOverScreenPaletteSize)), PVR_LIST_TR_POLY, 
GameOverScreenTextureSizeX, GameOverScreenTextureSizeY,
AlphaValueText, 1.0f, Green, Blue, GameOverScreenRestartTexturePositionLeft, GameOverScreenRestartTexturePositionRight, GameOverScreenRestartTexturePositionUp, GameOverScreenRestartTexturePositionDown
);

if(OptionSelected == GameOverScreenOptionExit) Green = Blue = 0.0f;
else Green = Blue = 1.0f;
DrawVectorTexturePlus(
FinalVector[GameOverScreenOptionExit], GraphicalUserInterFaceData->GameOverScreenTexture[GameOverScreenBackGroundTexturePlus], 
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL(GameOverScreenPaletteOffset/GameOverScreenPaletteSize)), PVR_LIST_TR_POLY, 
GameOverScreenTextureSizeX, GameOverScreenTextureSizeY,
AlphaValueText, 1.0f, Green, Blue, GameOverScreenExitTexturePositionLeft, GameOverScreenExitTexturePositionRight, GameOverScreenExitTexturePositionUp, GameOverScreenExitTexturePositionDown
);

if(OptionSelected == GameOverScreenOptionLoad) Green = Blue = 0.0f;
else Green = Blue = 1.0f;
DrawVectorTexturePlus(
FinalVector[GameOverScreenOptionLoad], GraphicalUserInterFaceData->GameOverScreenTexture[GameOverScreenOtherTexture], 
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL(GameOverScreenPaletteOffset/GameOverScreenPaletteSize)), PVR_LIST_TR_POLY, 
GameOverScreenTextureSizeX, GameOverScreenTextureSizeY,
AlphaValueText, 1.0f, Green, Blue, GameOverScreenLoadTexturePositionLeft, GameOverScreenLoadTexturePositionRight, GameOverScreenLoadTexturePositionUp, GameOverScreenLoadTexturePositionDown
);

*ScaleValueSelected+=(*ScaleValueChangeValue);
if(*ScaleValueSelected >= GameOverScreenMaximumScaleValue || *ScaleValueSelected <= GameOverScreenMinimumScaleValue){
*ScaleValueChangeValue = -(*ScaleValueChangeValue);
if(*ScaleValueSelected >= GameOverScreenMaximumScaleValue) *ScaleValueSelected = 2*GameOverScreenMaximumScaleValue-(*ScaleValueSelected);
else *ScaleValueSelected = 2*GameOverScreenMinimumScaleValue+(*ScaleValueSelected);
}



}
