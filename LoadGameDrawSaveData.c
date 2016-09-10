#define LoadGameDrawSaveDataArrayStaticLength	50
#define LoadGameDrawSaveDataArrayChangeLength	50
#define LineBreak		((char)(0xA))
#define HoursAndMinutesSeparatorThing	100



void LoadGameDrawSaveData(LoadScreenVisualMemoryStruct* LoadScreenVisualMemoryData, LoadScreenBackGroundStruct* LoadScreenBackGroundData, short WhichSave, float StartPositionX, float StartPositionY){

TransformationStruct SingleTransformationData;

uint8 DirtyDeedsDoneDirtCheap;
char DrawArrayStatic[LoadGameDrawSaveDataArrayStaticLength];
char DrawArrayChange[LoadGameDrawSaveDataArrayChangeLength];

sprintf(DrawArrayStatic, "File: %c%cLevel:%cGame Time:%cDate Saved:", LineBreak, LineBreak, LineBreak, LineBreak);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<LoadScreenVisualMemoryData->SaveAmount; DirtyDeedsDoneDirtCheap++){
if(DirtyDeedsDoneDirtCheap == WhichSave){StartZoomingAdvanced((&SingleTransformationData), LoadScreenBackGroundData->Loadable->SaveDrawZoomFactor);}
else SingleTransformationData.Active = 0;

DrawArrayToScreen(DrawArrayStatic, StartPositionX, StartPositionY, LoadScreenBackGroundData->Loadable->SaveDrawFontPositionZ,  LoadScreenBackGroundData->Loadable->SaveDrawFontSizeX[LoadGameSaveDrawStatic], LoadScreenBackGroundData->Loadable->SaveDrawFontSizeY[LoadGameSaveDrawStatic], LoadScreenBackGroundData->Loadable->SaveDrawFontColor[LoadGameSaveDrawStatic], LoadScreenBackGroundData->Loadable->SaveDrawWhichFont[LoadGameSaveDrawStatic], &SingleTransformationData);
sprintf(DrawArrayChange, "%d%c%c%d%c%d:%d%c%d/%d/%d", LoadScreenVisualMemoryData->SingleSaveData[DirtyDeedsDoneDirtCheap].WhichFile, LineBreak, LineBreak, LoadScreenVisualMemoryData->SingleSaveData[DirtyDeedsDoneDirtCheap].Data->Level, LineBreak, LoadScreenVisualMemoryData->SingleSaveData[DirtyDeedsDoneDirtCheap].Data->Hours, LoadScreenVisualMemoryData->SingleSaveData[DirtyDeedsDoneDirtCheap].Data->Minutes, LineBreak, LoadScreenVisualMemoryData->SingleSaveData[DirtyDeedsDoneDirtCheap].Data->Day, LoadScreenVisualMemoryData->SingleSaveData[DirtyDeedsDoneDirtCheap].Data->Month, LoadScreenVisualMemoryData->SingleSaveData[DirtyDeedsDoneDirtCheap].Data->Year);
DrawArrayToScreen(DrawArrayChange, StartPositionX+LoadScreenBackGroundData->Loadable->SaveDrawChangeOffsetX, StartPositionY, LoadScreenBackGroundData->Loadable->SaveDrawFontPositionZ, LoadScreenBackGroundData->Loadable->SaveDrawFontSizeX[LoadGameSaveDrawChange], LoadScreenBackGroundData->Loadable->SaveDrawFontSizeY[LoadGameSaveDrawChange], LoadScreenBackGroundData->Loadable->SaveDrawFontColor[LoadGameSaveDrawChange], LoadScreenBackGroundData->Loadable->SaveDrawWhichFont[LoadGameSaveDrawChange], &SingleTransformationData);
}

}