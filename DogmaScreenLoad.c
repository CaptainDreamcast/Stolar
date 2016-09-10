#define InitiateDogmaScreenLogicData() 	{ \
 \
DogmaScreenData->LogicData.ReturnValue = BoringStage; \
DogmaScreenData->LogicData.CurrentStage = DogmaScreenStageFirst; \
DogmaScreenData->LogicData.Ticks = 0; \
DogmaScreenData->LogicData.ForceBuildDown = 0; \
 \
DogmaScreenData->LogicData.AlphaValueBlackOut = FullColorFloatValue; \
 \
ResetButtonInputData(DogmaScreenData->LogicData.ButtonInputData, DirtyDeedsDoneDirtCheap); \
DogmaScreenData->LogicData.st = NULL; \
 \
}


void DogmaScreenLoad(DogmaScreenStruct* DogmaScreenData){

char FileDir[NormalFileDirSize];
uint32 CurrentPointerPosition;
uint8 DirtyDeedsDoneDirtCheap;

sprintf(FileDir, "%s/MISC/DOGMA.dgm.gz", FileSystemUsed);
CompressedFileToBuffer(FileDir, (void**)(&DogmaScreenData->Loadable));
CurrentPointerPosition = ((uint32)DogmaScreenData->Loadable)+sizeof(DogmaScreenLoadableStruct);

LoadCurrentPointerPositionSetToLegalStartValue();
LoadTextureFromBufferPointer(CurrentPointerPosition, DogmaScreenData->TextureData.LogoTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, DogmaScreenData->TextureData.BlackOutTexture);

InitiateDogmaScreenLogicData();


DogmaScreenData->Loadable = realloc(DogmaScreenData->Loadable, sizeof(DogmaScreenLoadableStruct));

}