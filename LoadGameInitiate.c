void LoadGameInitiate(LoadScreenBackGroundStruct* LoadScreenBackGroundData, LoadScreenControllerStruct* LoadScreenControllerData, uint8* WhichPort, uint8* WhichSlot, uint8* SpecialOptionSelected, short* WhichSave){

uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;
uint32 CurrentPointerPosition, ReAllocationSize;
char FileDir[NormalFileDirSize];


for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<DreamcastControllerAmount; DirtyDeedsDoneDirtCheap++){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].Active = 0;
for(BurningDownTheHouse = 0; BurningDownTheHouse<VisualMemoryPerController; BurningDownTheHouse++) LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].Active = 0;
}
(*WhichSave) = LoadGameNoSaveSelected;
(*WhichPort) = (DreamcastControllerAmount-1);
(*WhichSlot) = 0;
(*SpecialOptionSelected) = LoadGameSpecialOptionUnSelected;
LoadGameFindNewPort((*WhichPort), (*WhichSlot), (*SpecialOptionSelected), DirtyDeedsDoneDirtCheap);


sprintf(FileDir, "%s/DREAMCAST/LOADGAME.lod.gz", FileSystemUsed);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/LOADGAME.lod.gz");
CompressedFileToBuffer(FileDir, ((void**)(&LoadScreenBackGroundData->Loadable)));


LoadScreenBackGroundData->SaveShowData.PositionX = ScreenSizeX;
LoadScreenBackGroundData->SaveShowData.PositionY = 0;

LoadScreenBackGroundData->BackGroundPositionX = ScreenSizeX;

LoadScreenBackGroundData->CurrentPort = (*WhichPort);
LoadScreenBackGroundData->CurrentSlot = (*WhichSlot);

if((*SpecialOptionSelected) == LoadGameSpecialOptionUnSelected) LoadScreenBackGroundData->WhichSelectorTexture = 0;
else LoadScreenBackGroundData->WhichSelectorTexture = (LoadGameSelectorTransmorphTextureAmount-1);

SetSingleVector(LoadScreenBackGroundData->VisualMemorySelectorPositionVector, LoadScreenControllerData[(*WhichPort)].LoadScreenVisualMemoryData[(*WhichSlot)].PositionX, LoadScreenControllerData[(*WhichPort)].LoadScreenVisualMemoryData[(*WhichSlot)].PositionY, LoadScreenVisualMemorySelectorPositionZ);

SetSingleVector(LoadScreenBackGroundData->SelectedVisualMemoryTransformationData.PositionVector, LoadScreenControllerData[(*WhichPort)].LoadScreenVisualMemoryData[(*WhichSlot)].PositionX+(LoadScreenBackGroundData->Loadable->VisualMemorySelectorTextureSizeX/2), LoadScreenControllerData[(*WhichPort)].LoadScreenVisualMemoryData[(*WhichSlot)].PositionY+(LoadScreenBackGroundData->Loadable->VisualMemorySelectorTextureSizeY/2), LoadScreenVisualMemorySelectorPositionZ);
StartZoomingAdvanced((&LoadScreenBackGroundData->SelectedVisualMemoryTransformationData), 1.0f);

CurrentPointerPosition = (uint32)(LoadScreenBackGroundData->Loadable+sizeof(LoadScreenBackGroundLoadableStruct));
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<DreamcastControllerAmount; DirtyDeedsDoneDirtCheap++){

for(BurningDownTheHouse = 0; BurningDownTheHouse<VisualMemoryPerController; BurningDownTheHouse++){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionX = LoadScreenBackGroundData->Loadable->VisualMemoryStartVector[((DirtyDeedsDoneDirtCheap*VisualMemoryPerController)+BurningDownTheHouse)].x;
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].PositionY = LoadScreenBackGroundData->Loadable->VisualMemoryStartVector[((DirtyDeedsDoneDirtCheap*VisualMemoryPerController)+BurningDownTheHouse)].y;
}

StartRotationYAdvanced((&LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData), 0.0f);
if(DirtyDeedsDoneDirtCheap < (DreamcastControllerAmount/2)) LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY = ThreeQuarterRotationValue;
else LoadScreenControllerData[DirtyDeedsDoneDirtCheap].TransformationData.RotationValueY = QuarterRotationValue;

LoadScreenControllerData[DirtyDeedsDoneDirtCheap].Loadable = ((LoadScreenControllerLoadableStruct*)(CurrentPointerPosition));
CurrentPointerPosition+=sizeof(LoadScreenControllerLoadableStruct);
}

ReAllocationSize = CurrentPointerPosition;

LoadTextureFromBufferPointer(CurrentPointerPosition, LoadScreenBackGroundData->BackGroundTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, LoadScreenBackGroundData->SaveShowTexture);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<LoadGameControllerTextureAmount; DirtyDeedsDoneDirtCheap++) LoadTextureFromBufferPointer(CurrentPointerPosition, LoadScreenBackGroundData->ControllerTexture[DirtyDeedsDoneDirtCheap]);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<LoadGameVisualMemoryTextureAmount; DirtyDeedsDoneDirtCheap++) LoadTextureFromBufferPointer(CurrentPointerPosition, LoadScreenBackGroundData->VisualMemoryTexture[DirtyDeedsDoneDirtCheap]);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<LoadGameSpecialOptionAmount; DirtyDeedsDoneDirtCheap++) LoadTextureFromBufferPointer(CurrentPointerPosition, LoadScreenBackGroundData->SpecialOptionTexture[DirtyDeedsDoneDirtCheap]);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<LoadGameSelectorTransmorphTextureAmount; DirtyDeedsDoneDirtCheap++) LoadTextureFromBufferPointer(CurrentPointerPosition, LoadScreenBackGroundData->SelectorTexture[DirtyDeedsDoneDirtCheap]);

LoadScreenBackGroundData->Loadable = realloc(LoadScreenBackGroundData->Loadable, ReAllocationSize);
}