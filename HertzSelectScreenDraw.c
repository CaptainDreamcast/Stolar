
void HertzSelectScreenDraw(HertzSelectScreenStruct* HertzSelectScreenData){

vector_t FinalVector[PolygonCornerAmount];
uint8 DirtyDeedsDoneDirtCheap;

if(HertzSelectScreenData->LogicData.CurrentStage == HertzSelectScreenStageBuildUp){

SetupTransformAndDraw(FinalVector, NULL, HertzSelectScreenData->TextureData.BlackOutTexture, 
OverallScreenPositionLeft, OverallScreenPositionUp, HertzSelectScreenData->Loadable->BlackOutPositionZ, ScreenSizeX, ScreenSizeY, 
HertzSelectScreenData->Loadable->BlackOutTextureSizeX, HertzSelectScreenData->Loadable->BlackOutTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, HertzSelectScreenData->LogicData.BlackOutAlpha, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue);

HertzSelectScreenData->LogicData.BlackOutAlpha -= FullColorFloatValue/(HertzSelectScreenData->Loadable->BlackOutTimeInSeconds*FrameRate);
if(HertzSelectScreenData->LogicData.BlackOutAlpha <= NoColorFloatValue){
HertzSelectScreenData->LogicData.BlackOutAlpha = NoColorFloatValue;
HertzSelectScreenData->LogicData.CurrentStage = HertzSelectScreenStageNormal;
}
}
else if(HertzSelectScreenData->LogicData.CurrentStage == HertzSelectScreenStageBuildDown){

SetupTransformAndDraw(FinalVector, NULL, HertzSelectScreenData->TextureData.BlackOutTexture, 
OverallScreenPositionLeft, OverallScreenPositionUp, HertzSelectScreenData->Loadable->BlackOutPositionZ, ScreenSizeX, ScreenSizeY, 
HertzSelectScreenData->Loadable->BlackOutTextureSizeX, HertzSelectScreenData->Loadable->BlackOutTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, HertzSelectScreenData->LogicData.BlackOutAlpha, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue);

HertzSelectScreenData->LogicData.BlackOutAlpha += FullColorFloatValue/(HertzSelectScreenData->Loadable->BlackOutTimeInSeconds*FrameRate);
if(HertzSelectScreenData->LogicData.BlackOutAlpha >= FullColorFloatValue){
HertzSelectScreenData->LogicData.BlackOutAlpha = FullColorFloatValue;
HertzSelectScreenData->LogicData.CurrentStage = HertzSelectScreenStageFinished;
}
}

if(HertzSelectScreenData->LogicData.CurrentScreen == HertzSelectScreenSelectScreen){

SetupTransformAndDrawSimplest(FinalVector, NULL, HertzSelectScreenData->TextureData.BackGroundTexture, 
HertzSelectScreenData->Loadable->BackGroundPositionX, HertzSelectScreenData->Loadable->BackGroundPositionY, HertzSelectScreenData->Loadable->BackGroundPositionZ, 
HertzSelectScreenData->Loadable->BackGroundTextureSizeX, HertzSelectScreenData->Loadable->BackGroundTextureSizeY, 
HertzSelectScreenData->Loadable->BackGroundTextureSizeX, HertzSelectScreenData->Loadable->BackGroundTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<HertzSelectScreenSelectOptionAmount; DirtyDeedsDoneDirtCheap++){

if(DirtyDeedsDoneDirtCheap != HertzSelectScreenData->LogicData.SelectScreenOptionSelected){
SetupTransformAndDrawSimplest(FinalVector, NULL, HertzSelectScreenData->TextureData.SelectScreenOptionTexture[DirtyDeedsDoneDirtCheap], 
HertzSelectScreenData->Loadable->SelectScreenOptionPositionX[DirtyDeedsDoneDirtCheap], HertzSelectScreenData->Loadable->SelectScreenOptionPositionY[DirtyDeedsDoneDirtCheap], 
HertzSelectScreenData->Loadable->SelectScreenOptionPositionZ, 
HertzSelectScreenData->Loadable->SelectScreenOptionTextureSizeX, HertzSelectScreenData->Loadable->SelectScreenOptionTextureSizeY, 
HertzSelectScreenData->Loadable->SelectScreenOptionTextureSizeX, HertzSelectScreenData->Loadable->SelectScreenOptionTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);
}
}

SetupTransformAndDrawSimplest(FinalVector, NULL, 
HertzSelectScreenData->TextureData.SelectScreenOptionSelectedTexture[HertzSelectScreenData->LogicData.SelectScreenOptionSelected], 
HertzSelectScreenData->Loadable->SelectScreenOptionPositionX[HertzSelectScreenData->LogicData.SelectScreenOptionSelected], 
HertzSelectScreenData->Loadable->SelectScreenOptionPositionY[HertzSelectScreenData->LogicData.SelectScreenOptionSelected], 
HertzSelectScreenData->Loadable->SelectScreenOptionPositionZ, 
HertzSelectScreenData->Loadable->SelectScreenOptionTextureSizeX, HertzSelectScreenData->Loadable->SelectScreenOptionTextureSizeY, 
HertzSelectScreenData->Loadable->SelectScreenOptionTextureSizeX, HertzSelectScreenData->Loadable->SelectScreenOptionTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

SetupTransformAndDrawSimplest(FinalVector, NULL, 
HertzSelectScreenData->TextureData.SelectScreenOptionDescriptionTexture[HertzSelectScreenData->LogicData.SelectScreenOptionSelected], 
HertzSelectScreenData->Loadable->SelectScreenOptionDescriptionPositionX, 
HertzSelectScreenData->Loadable->SelectScreenOptionDescriptionPositionY, 
HertzSelectScreenData->Loadable->SelectScreenOptionDescriptionPositionZ, 
HertzSelectScreenData->Loadable->SelectScreenOptionDescriptionTextureSizeX, HertzSelectScreenData->Loadable->SelectScreenOptionDescriptionTextureSizeY, 
HertzSelectScreenData->Loadable->SelectScreenOptionDescriptionTextureSizeX, HertzSelectScreenData->Loadable->SelectScreenOptionDescriptionTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);


}
else if(HertzSelectScreenData->LogicData.CurrentScreen == HertzSelectScreenTestScreen){

SetupTransformAndDrawSimplest(FinalVector, NULL, HertzSelectScreenData->TextureData.TestTexture, 
HertzSelectScreenData->Loadable->TestTexturePositionX, HertzSelectScreenData->Loadable->TestTexturePositionY, HertzSelectScreenData->Loadable->TestTexturePositionZ, 
HertzSelectScreenData->Loadable->TestTextureSizeX, HertzSelectScreenData->Loadable->TestTextureSizeY, 
HertzSelectScreenData->Loadable->TestTextureSizeX, HertzSelectScreenData->Loadable->TestTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

SetupTransformAndDrawSimplest(FinalVector, NULL, HertzSelectScreenData->TextureData.TestSecondTexture[HertzSelectScreenData->LogicData.TestSecondsLeft], 
HertzSelectScreenData->Loadable->TestSecondPositionX, HertzSelectScreenData->Loadable->TestSecondPositionY, HertzSelectScreenData->Loadable->TestSecondPositionZ, 
HertzSelectScreenData->Loadable->TestSecondTextureSizeX, HertzSelectScreenData->Loadable->TestSecondTextureSizeY, 
HertzSelectScreenData->Loadable->TestSecondTextureSizeX, HertzSelectScreenData->Loadable->TestSecondTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

SetupTransformAndDrawSimplest(FinalVector, NULL, HertzSelectScreenData->TextureData.TestSecondPlusTexture[(uint8)((((float)HertzSelectScreenData->LogicData.TestSecondTicks)/FrameRate)*(HertzSelectScreenData->Loadable->TestSecondPlusTextureAmount))], 
HertzSelectScreenData->Loadable->TestSecondPlusPositionX, HertzSelectScreenData->Loadable->TestSecondPlusPositionY, HertzSelectScreenData->Loadable->TestSecondPlusPositionZ, 
HertzSelectScreenData->Loadable->TestSecondPlusTextureSizeX, HertzSelectScreenData->Loadable->TestSecondPlusTextureSizeY, 
HertzSelectScreenData->Loadable->TestSecondPlusTextureSizeX, HertzSelectScreenData->Loadable->TestSecondPlusTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

HertzSelectScreenData->LogicData.TestSecondTicks++;
if(HertzSelectScreenData->LogicData.TestSecondTicks >= FrameRate){
HertzSelectScreenData->LogicData.TestSecondTicks = 0;
if(HertzSelectScreenData->LogicData.TestSecondsLeft > 0) HertzSelectScreenData->LogicData.TestSecondsLeft--;
else{
HertzSelectScreenData->LogicData.CurrentScreen = HertzSelectScreenSelectScreen;
SetVideoModeNeverForget(FiftyHertz, StolarSixtyHertzCableMode);
}
}

}

}