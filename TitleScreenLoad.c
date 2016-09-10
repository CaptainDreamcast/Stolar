#define TitleScreenLogicDataInitiate() 	{ \
 \
TitleScreenData->LogicData.MainLoop = 1; \
TitleScreenData->LogicData.CurrentStage = TitleScreenStageFirst; \
TitleScreenData->LogicData.ReturnStage = BoringStage; \
 \
TitleScreenData->LogicData.TicksUniversalReboot = 0; \
 \
TitleScreenData->LogicData.AlphaValueBlackOut = FullColorFloatValue; \
 \
InitiateTransformationDataWithPosition((&TitleScreenData->LogicData.TransformationDataZoomOut), (ScreenSizeX/2), (ScreenSizeY/2), UnusedAnywayPositionZ); \
 \
TitleScreenData->LogicData.st = NULL; \
ResetButtonInputData(TitleScreenData->LogicData.ButtonInputData, DirtyDeedsDoneDirtCheap); \
 \
}


void TitleScreenLoad(TitleScreenStruct* TitleScreenData){

char FileDir[NormalFileDirSize];
uint32 CurrentPointerPosition;
uint8 DirtyDeedsDoneDirtCheap;

sprintf(FileDir, "%s/MISC/TITLE.tsc.gz", FileSystemUsed);
CompressedFileToBuffer(FileDir, (void**)(&TitleScreenData->Loadable));
CurrentPointerPosition = ((uint32)TitleScreenData->Loadable)+sizeof(TitleScreenLoadableStruct);

LoadCurrentPointerPositionSetToLegalStartValue();
LoadTextureFromBufferPointer(CurrentPointerPosition, TitleScreenData->TextureData.BlackOutTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, TitleScreenData->TextureData.BackGroundTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, TitleScreenData->TextureData.PressStartTexture);

//LoadSoundEffectFromBufferPointer(CurrentPointerPosition, TitleScreenData->SoundEffectData.?);

TitleScreenLogicDataInitiate();

TitleScreenData->Loadable = realloc(TitleScreenData->Loadable, sizeof(TitleScreenLoadableStruct));

}