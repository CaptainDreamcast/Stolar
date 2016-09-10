
#define LoadScreenVisualMemorySelectorChangeDurationInSeconds		2
#define LoadScreenVisualMemorySelectorSpeedX							((LoadScreenBackGroundData->Loadable->VisualMemoryFinalVector[2].x-LoadScreenBackGroundData->Loadable->VisualMemoryFinalVector[0].x)/(LoadScreenVisualMemorySelectorChangeDurationInSeconds*FrameRate))
#define LoadScreenVisualMemorySelectorSpeedY							((LoadScreenBackGroundData->Loadable->VisualMemoryFinalVector[1].y-LoadScreenBackGroundData->Loadable->VisualMemoryFinalVector[0].y)/(LoadScreenVisualMemorySelectorChangeDurationInSeconds*FrameRate))


#define LoadGameTotalBuildUpTimeInSeconds		2
#define LoadGameShowSaveBuildUpTimeInSeconds	0.7


uint8  LoadGameDraw(void** TransitionData, LoadScreenBackGroundStruct* LoadScreenBackGroundData, LoadScreenControllerStruct* LoadScreenControllerData, uint8 WhichPort, uint8 WhichSlot, short WhichSave, uint8 SpecialOptionSelected, uint8 ReadyToRock){

vector_t FinalVector[PolygonCornerAmount];
uint16 DirtyDeedsDoneDirtCheap;
uint8 BurningDownTheHouse;
pvr_ptr_t DrawnTexture;


pvr_scene_begin();
pvr_list_begin(PVR_LIST_TR_POLY);

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < DreamcastControllerAmount; DirtyDeedsDoneDirtCheap++){

SetupVectors(FinalVector, LoadScreenControllerData[DirtyDeedsDoneDirtCheap].Loadable->PositionX, LoadScreenControllerData[DirtyDeedsDoneDirtCheap].Loadable->PositionY, LoadScreenControllerPositionZ, LoadScreenBackGroundData->Loadable->ControllerTextureSizeX, LoadScreenBackGroundData->Loadable->ControllerTextureSizeY);
Transformation(FinalVector, &LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData);

DrawVectorTexture(
FinalVector, LoadScreenBackGroundData->ControllerTexture[LoadScreenControllerData[DirtyDeedsDoneDirtCheap].Active], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
LoadScreenBackGroundData->Loadable->ControllerTextureSizeX, LoadScreenBackGroundData->Loadable->ControllerTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

if(ReadyToRock == LoadGameRockOut || (!LoadScreenControllerData[DirtyDeedsDoneDirtCheap].Active)){
if(DirtyDeedsDoneDirtCheap < (DreamcastControllerAmount/2) && LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY > ThreeQuarterRotationValue){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY -= ((FullRotationValue-ThreeQuarterRotationValue)/(LoadGameTotalBuildUpTimeInSeconds*FrameRate));
if(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY <=  ThreeQuarterRotationValue) LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY =  ThreeQuarterRotationValue;
}
else if(DirtyDeedsDoneDirtCheap >= (DreamcastControllerAmount/2) && LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY < QuarterRotationValue){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY += (QuarterRotationValue/(LoadGameTotalBuildUpTimeInSeconds*FrameRate));
if(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY >= QuarterRotationValue) LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY = QuarterRotationValue;
}
}
else if(DirtyDeedsDoneDirtCheap < (DreamcastControllerAmount/2) && LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY < FullRotationValue){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY += ((FullRotationValue-ThreeQuarterRotationValue)/(LoadGameTotalBuildUpTimeInSeconds*FrameRate));
if(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY >= FullRotationValue) LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY = FullRotationValue;
}
else if(DirtyDeedsDoneDirtCheap >= (DreamcastControllerAmount/2) && LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY > NoRotationValue){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY -= (QuarterRotationValue/(LoadGameTotalBuildUpTimeInSeconds*FrameRate));
if(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY <= NoRotationValue) LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY = NoRotationValue;
}

if(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].Active){
for(BurningDownTheHouse = 0; BurningDownTheHouse < VisualMemoryPerController; BurningDownTheHouse++){

SetupVectors(FinalVector, LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionX, LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY, LoadScreenVisualMemoryPositionZ, LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeX, LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY);
if(DirtyDeedsDoneDirtCheap == WhichPort && BurningDownTheHouse == WhichSlot) Transformation(FinalVector, &LoadScreenBackGroundData->SelectedVisualMemoryTransformationData);
if(!LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].Active) DrawnTexture = LoadScreenBackGroundData->VisualMemoryTexture[LoadGameNoVisualMemoryTexture];
else if(!LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].SaveAmount) DrawnTexture = LoadScreenBackGroundData->VisualMemoryTexture[LoadGameEmptyVisualMemoryTexture];
else DrawnTexture = LoadScreenBackGroundData->VisualMemoryTexture[LoadGameOkayVisualMemoryTexture];
DrawVectorTexture(
FinalVector, DrawnTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeX, LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

if(ReadyToRock == LoadGameRockOut || (!LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].Active)){
if(!(BurningDownTheHouse%VisualMemoryPerController) && LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY > (-LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY)){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY -= ((LoadScreenBackGroundData->Loadable->VisualMemoryFinalPositionY[(BurningDownTheHouse%VisualMemoryPerController)]-(-LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY))/(LoadGameTotalBuildUpTimeInSeconds*FrameRate));
if(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY <= (-LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY)) LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY = (-LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY);
}
else if((BurningDownTheHouse%VisualMemoryPerController) && LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY < (ScreenSizeY+LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY)){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY += (((ScreenSizeY+LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY)- LoadScreenBackGroundData->Loadable->VisualMemoryFinalPositionY[(BurningDownTheHouse%VisualMemoryPerController)])/(LoadGameTotalBuildUpTimeInSeconds*FrameRate));
if(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY >= (ScreenSizeY+LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY)) LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY = (ScreenSizeY+LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY);
}
}
else if(!(BurningDownTheHouse%VisualMemoryPerController) && LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY < LoadScreenBackGroundData->Loadable->VisualMemoryFinalPositionY[(BurningDownTheHouse%VisualMemoryPerController)]){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY += ((LoadScreenBackGroundData->Loadable->VisualMemoryFinalPositionY[(BurningDownTheHouse%VisualMemoryPerController)]-(-LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY))/(LoadGameTotalBuildUpTimeInSeconds*FrameRate));
if(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY >= LoadScreenBackGroundData->Loadable->VisualMemoryFinalPositionY[(BurningDownTheHouse%VisualMemoryPerController)]) LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY = LoadScreenBackGroundData->Loadable->VisualMemoryFinalPositionY[(BurningDownTheHouse%VisualMemoryPerController)];
}
else if((BurningDownTheHouse%VisualMemoryPerController) && LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY > LoadScreenBackGroundData->Loadable->VisualMemoryFinalPositionY[(BurningDownTheHouse%VisualMemoryPerController)]){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY -= (((ScreenSizeY+LoadScreenBackGroundData->Loadable->VisualMemoryTextureSizeY)- LoadScreenBackGroundData->Loadable->VisualMemoryFinalPositionY[(BurningDownTheHouse%VisualMemoryPerController)])/(LoadGameTotalBuildUpTimeInSeconds*FrameRate));
if(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY <= LoadScreenBackGroundData->Loadable->VisualMemoryFinalPositionY[(BurningDownTheHouse%VisualMemoryPerController)]) LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY = LoadScreenBackGroundData->Loadable->VisualMemoryFinalPositionY[(BurningDownTheHouse%VisualMemoryPerController)];
}

}
}

}

if((ReadyToRock == LoadGameRockOut || LoadScreenBackGroundData->BackGroundPositionX == 0.0f)  && LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot].SaveAmount){

if(WhichPort < (DreamcastControllerAmount/2)){DirtyDeedsDoneDirtCheap = 0;} else {DirtyDeedsDoneDirtCheap = 1;}

if(LoadScreenBackGroundData->CurrentPort != WhichPort || LoadScreenBackGroundData->CurrentSlot != WhichSlot){
LoadScreenBackGroundData->CurrentPort = WhichPort;
LoadScreenBackGroundData->CurrentSlot = WhichSlot;

LoadScreenBackGroundData->SaveShowData.PositionX = LoadScreenBackGroundData->Loadable->SaveShowStartPositionX[DirtyDeedsDoneDirtCheap];
}

SetupVectors(FinalVector, LoadScreenBackGroundData->SaveShowData.PositionX, LoadScreenBackGroundData->SaveShowData.PositionY, LoadScreenSaveShowPositionZ, LoadScreenBackGroundData->Loadable->SaveShowTextureSizeX, LoadScreenBackGroundData->Loadable->SaveShowTextureSizeY);
DrawVectorTexture(
FinalVector, LoadScreenBackGroundData->SaveShowTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
LoadScreenBackGroundData->Loadable->SaveShowTextureSizeX, LoadScreenBackGroundData->Loadable->SaveShowTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

if(ReadyToRock == LoadGameRockOut){
if(DirtyDeedsDoneDirtCheap && LoadScreenBackGroundData->SaveShowData.PositionX > (-LoadScreenBackGroundData->Loadable->SaveShowTextureSizeX)){
LoadScreenBackGroundData->SaveShowData.PositionX -= (LoadScreenBackGroundData->Loadable->SaveShowEndPositionX[DirtyDeedsDoneDirtCheap]-(-LoadScreenBackGroundData->Loadable->SaveShowTextureSizeX))/(LoadGameTotalBuildUpTimeInSeconds*FrameRate);
if(LoadScreenBackGroundData->SaveShowData.PositionX <= (-LoadScreenBackGroundData->Loadable->SaveShowTextureSizeX)) LoadScreenBackGroundData->SaveShowData.PositionX = (-LoadScreenBackGroundData->Loadable->SaveShowTextureSizeX);
}
else if(!DirtyDeedsDoneDirtCheap && LoadScreenBackGroundData->SaveShowData.PositionX < (ScreenSizeX + LoadScreenBackGroundData->Loadable->SaveShowTextureSizeX)){
LoadScreenBackGroundData->SaveShowData.PositionX += ((ScreenSizeX + LoadScreenBackGroundData->Loadable->SaveShowTextureSizeX)-LoadScreenBackGroundData->Loadable->SaveShowEndPositionX[DirtyDeedsDoneDirtCheap])/(LoadGameTotalBuildUpTimeInSeconds*FrameRate);
if(LoadScreenBackGroundData->SaveShowData.PositionX >= (ScreenSizeX + LoadScreenBackGroundData->Loadable->SaveShowTextureSizeX)) LoadScreenBackGroundData->SaveShowData.PositionX = (ScreenSizeX + LoadScreenBackGroundData->Loadable->SaveShowTextureSizeX);
}
}
else{
if(DirtyDeedsDoneDirtCheap && LoadScreenBackGroundData->SaveShowData.PositionX < LoadScreenBackGroundData->Loadable->SaveShowEndPositionX[DirtyDeedsDoneDirtCheap]){
LoadScreenBackGroundData->SaveShowData.PositionX += (LoadScreenBackGroundData->Loadable->SaveShowEndPositionX[DirtyDeedsDoneDirtCheap]-LoadScreenBackGroundData->Loadable->SaveShowStartPositionX[DirtyDeedsDoneDirtCheap])/(LoadGameShowSaveBuildUpTimeInSeconds*FrameRate);
if(LoadScreenBackGroundData->SaveShowData.PositionX >= LoadScreenBackGroundData->Loadable->SaveShowEndPositionX[DirtyDeedsDoneDirtCheap]) LoadScreenBackGroundData->SaveShowData.PositionX = LoadScreenBackGroundData->Loadable->SaveShowEndPositionX[DirtyDeedsDoneDirtCheap];
}
else if(!DirtyDeedsDoneDirtCheap && LoadScreenBackGroundData->SaveShowData.PositionX > LoadScreenBackGroundData->Loadable->SaveShowEndPositionX[DirtyDeedsDoneDirtCheap]){
LoadScreenBackGroundData->SaveShowData.PositionX -= (LoadScreenBackGroundData->Loadable->SaveShowStartPositionX[DirtyDeedsDoneDirtCheap]-LoadScreenBackGroundData->Loadable->SaveShowEndPositionX[DirtyDeedsDoneDirtCheap])/(LoadGameShowSaveBuildUpTimeInSeconds*FrameRate);
if(LoadScreenBackGroundData->SaveShowData.PositionX <= LoadScreenBackGroundData->Loadable->SaveShowEndPositionX[DirtyDeedsDoneDirtCheap]) LoadScreenBackGroundData->SaveShowData.PositionX = LoadScreenBackGroundData->Loadable->SaveShowEndPositionX[DirtyDeedsDoneDirtCheap];
}
}

for(BurningDownTheHouse = 0; BurningDownTheHouse < LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot].SaveAmount; BurningDownTheHouse++){
LoadGameDrawSaveData(&LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot], LoadScreenBackGroundData, WhichSave, LoadScreenBackGroundData->Loadable->SaveDrawStartPositionX[DirtyDeedsDoneDirtCheap], LoadScreenBackGroundData->Loadable->SaveDrawStartPositionY[DirtyDeedsDoneDirtCheap]);
}

}

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < LoadGameSpecialOptionAmount; DirtyDeedsDoneDirtCheap++){

SetupVectors(FinalVector, LoadScreenBackGroundData->Loadable->SpecialOptionPositionVector[DirtyDeedsDoneDirtCheap].x, LoadScreenBackGroundData->Loadable->SpecialOptionPositionVector[DirtyDeedsDoneDirtCheap].y, LoadScreenSpecialOptionPositionZ, LoadScreenBackGroundData->Loadable->SpecialOptionTextureSizeX, LoadScreenBackGroundData->Loadable->SpecialOptionTextureSizeY);
if(DirtyDeedsDoneDirtCheap == SpecialOptionSelected) Transformation(FinalVector, &LoadScreenBackGroundData->SelectedVisualMemoryTransformationData);

DrawVectorTexture(
FinalVector, LoadScreenBackGroundData->SpecialOptionTexture[DirtyDeedsDoneDirtCheap], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
LoadScreenBackGroundData->Loadable->SpecialOptionTextureSizeX, LoadScreenBackGroundData->Loadable->SpecialOptionTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);
}

SetupVectors(FinalVector, LoadScreenBackGroundData->VisualMemorySelectorPositionVector.x, LoadScreenBackGroundData->VisualMemorySelectorPositionVector.y, LoadScreenVisualMemorySelectorPositionZ, LoadScreenBackGroundData->Loadable->VisualMemorySelectorTextureSizeX,  LoadScreenBackGroundData->Loadable->VisualMemorySelectorTextureSizeY);
Transformation(FinalVector, &LoadScreenBackGroundData->SelectedVisualMemoryTransformationData);
DrawVectorTexture(
FinalVector, LoadScreenBackGroundData->SelectorTexture[LoadScreenBackGroundData->WhichSelectorTexture], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
LoadScreenBackGroundData->Loadable->VisualMemorySelectorTextureSizeX, LoadScreenBackGroundData->Loadable->VisualMemorySelectorTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

if(SpecialOptionSelected == LoadGameSpecialOptionUnSelected){
GoHomeValueYouAreDrunk(LoadScreenBackGroundData->VisualMemorySelectorPositionVector.x, LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot].PositionX, LoadScreenVisualMemorySelectorSpeedX);
GoHomeValueYouAreDrunk(LoadScreenBackGroundData->VisualMemorySelectorPositionVector.y, LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot].PositionY, LoadScreenVisualMemorySelectorSpeedY);
}
else{
GoHomeValueYouAreDrunk(LoadScreenBackGroundData->VisualMemorySelectorPositionVector.x, LoadScreenBackGroundData->Loadable->SpecialOptionPositionVector[((uint8)(SpecialOptionSelected))].x, LoadScreenVisualMemorySelectorSpeedX);
GoHomeValueYouAreDrunk(LoadScreenBackGroundData->VisualMemorySelectorPositionVector.y, LoadScreenBackGroundData->Loadable->SpecialOptionPositionVector[((uint8)(SpecialOptionSelected))].y, LoadScreenVisualMemorySelectorSpeedY);
}
if(LoadScreenBackGroundData->VisualMemorySelectorPositionVector.y <= LoadScreenBackGroundData->Loadable->VisualMemoryFinalVector[1].y) LoadScreenBackGroundData->WhichSelectorTexture = 0;
else LoadScreenBackGroundData->WhichSelectorTexture = ((LoadScreenBackGroundData->VisualMemorySelectorPositionVector.y-LoadScreenBackGroundData->Loadable->VisualMemoryFinalVector[1].y)/(LoadScreenBackGroundData->Loadable->SpecialOptionPositionVector[((uint8)(SpecialOptionSelected))].y-LoadScreenBackGroundData->Loadable->VisualMemoryFinalVector[1].y))*(LoadGameSelectorTransmorphTextureAmount-1);


SetupVectors(FinalVector, LoadScreenBackGroundData->BackGroundPositionX-ScreenSizeX, 0, LoadScreenPreviousBackGroundPositionZ, FrameBufferSizeX,  FrameBufferSizeY);
DrawVectorTexture(
FinalVector, (pvr_ptr_t)(*TransitionData), FrameBufferFormat, PVR_LIST_TR_POLY, 
FrameBufferSizeX, FrameBufferSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

SetupVectors(FinalVector, LoadScreenBackGroundData->BackGroundPositionX, 0, LoadScreenRealBackGroundPositionZ, LoadScreenBackGroundData->Loadable->BackGroundTextureSizeX,  LoadScreenBackGroundData->Loadable->BackGroundTextureSizeY);
DrawVectorTexture(
FinalVector, LoadScreenBackGroundData->BackGroundTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
LoadScreenBackGroundData->Loadable->BackGroundTextureSizeX, LoadScreenBackGroundData->Loadable->BackGroundTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

if(ReadyToRock == LoadGameRockOut){
if(LoadScreenBackGroundData->BackGroundPositionX < ScreenSizeX){
LoadScreenBackGroundData->BackGroundPositionX += (ScreenSizeX)/(LoadGameTotalBuildUpTimeInSeconds*FrameRate);
if(LoadScreenBackGroundData->BackGroundPositionX >= ScreenSizeX){
LoadScreenBackGroundData->BackGroundPositionX = ScreenSizeX;
ReadyToRock = LoadGameRockOver;
}
}
}
else if(LoadScreenBackGroundData->BackGroundPositionX > 0.0f){
LoadScreenBackGroundData->BackGroundPositionX -= ((ScreenSizeX)/(LoadGameTotalBuildUpTimeInSeconds*FrameRate));
if(LoadScreenBackGroundData->BackGroundPositionX <= 0.0f){
LoadScreenBackGroundData->BackGroundPositionX = 0.0f;
ReadyToRock = LoadGameRock;
}
}

pvr_list_finish(PVR_LIST_TR_POLY);
pvr_scene_finish();

return(ReadyToRock);
}
