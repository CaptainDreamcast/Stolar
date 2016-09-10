#define InitiateHertzSelectScreenLogicData() 	{ \
HertzSelectScreenData->LogicData.CurrentStage = HertzSelectScreenStageFirst; \
HertzSelectScreenData->LogicData.CurrentScreen = HertzSelectScreenFirstScreen; \
HertzSelectScreenData->LogicData.SelectScreenOptionSelected = HertzSelectScreenSelectOptionFirst; \
HertzSelectScreenData->LogicData.ReturnFrameRate = FiftyHertz; \
 \
HertzSelectScreenData->LogicData.TestSecondsLeft = HertzSelectScreenData->Loadable->TestSecondAmount; \
HertzSelectScreenData->LogicData.TestSecondTicks = 0; \
 \
HertzSelectScreenData->LogicData.BlackOutAlpha = FullColorFloatValue; \
 \
ResetButtonInputData(HertzSelectScreenData->LogicData.ButtonInputData, DirtyDeedsDoneDirtCheap); \
HertzSelectScreenData->LogicData.st = NULL; \
 \
}


void HertzSelectScreenLoad(HertzSelectScreenStruct* HertzSelectScreenData){

char FileDir[NormalFileDirSize];
uint32 CurrentPointerPosition;
uint8 DirtyDeedsDoneDirtCheap;

sprintf(FileDir, "%s/MISC/HZSELECT.htz.gz", FileSystemUsed);
CompressedFileToBuffer(FileDir, (void**)(&HertzSelectScreenData->Loadable));
CurrentPointerPosition = ((uint32)HertzSelectScreenData->Loadable)+sizeof(HertzSelectScreenLoadableStruct);

LoadTextureFromBufferPointer(CurrentPointerPosition, HertzSelectScreenData->TextureData.BlackOutTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, HertzSelectScreenData->TextureData.BackGroundTexture);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < HertzSelectScreenSelectOptionAmount; DirtyDeedsDoneDirtCheap++){
LoadTextureFromBufferPointer(CurrentPointerPosition, HertzSelectScreenData->TextureData.SelectScreenOptionTexture[DirtyDeedsDoneDirtCheap]);
LoadTextureFromBufferPointer(CurrentPointerPosition, HertzSelectScreenData->TextureData.SelectScreenOptionSelectedTexture[DirtyDeedsDoneDirtCheap]);
LoadTextureFromBufferPointer(CurrentPointerPosition, HertzSelectScreenData->TextureData.SelectScreenOptionDescriptionTexture[DirtyDeedsDoneDirtCheap]);
}
LoadTextureFromBufferPointer(CurrentPointerPosition, HertzSelectScreenData->TextureData.TestTexture);

HertzSelectScreenData->TextureData.TestSecondTexture = (pvr_ptr_t*)malloc(sizeof(pvr_ptr_t)*HertzSelectScreenData->Loadable->TestSecondAmount);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < HertzSelectScreenData->Loadable->TestSecondAmount; DirtyDeedsDoneDirtCheap++){
LoadTextureFromBufferPointer(CurrentPointerPosition, HertzSelectScreenData->TextureData.TestSecondTexture[DirtyDeedsDoneDirtCheap]);
}
HertzSelectScreenData->TextureData.TestSecondPlusTexture = (pvr_ptr_t*)malloc(sizeof(pvr_ptr_t)*HertzSelectScreenData->Loadable->TestSecondPlusTextureAmount);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < HertzSelectScreenData->Loadable->TestSecondPlusTextureAmount; DirtyDeedsDoneDirtCheap++){
LoadTextureFromBufferPointer(CurrentPointerPosition, HertzSelectScreenData->TextureData.TestSecondPlusTexture[DirtyDeedsDoneDirtCheap]);
}

InitiateHertzSelectScreenLogicData();

HertzSelectScreenData->Loadable = realloc(HertzSelectScreenData->Loadable, sizeof(HertzSelectScreenLoadableStruct));

}