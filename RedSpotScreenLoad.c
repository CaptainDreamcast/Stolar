
#define InitiateRedSpotScreenLogicData() 	{ \
  \
RedSpotScreenData->LogicData.ReturnValue = BoringStage; \
RedSpotScreenData->LogicData.CurrentStage = RedSpotScreenStageFirst; \
RedSpotScreenData->LogicData.ForceBuildDown = 0; \
 \
RedSpotScreenData->LogicData.Ticks = 0; \
 \
RedSpotScreenData->LogicData.EffectPositionX = RedSpotScreenData->Loadable->EffectStartPositionX; \
 \
RedSpotScreenData->LogicData.AlphaValueBlackOut = FullColorFloatValue; \
RedSpotScreenData->LogicData.AlphaValueBackGround = NoColorFloatValue; \
RedSpotScreenData->LogicData.AlphaValueEffect = NoColorFloatValue; \
 \
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < RedSpotScreenMovingArrayAmount; DirtyDeedsDoneDirtCheap++){ \
RedSpotScreenData->LogicData.MovingArrayCurrentPositionX[DirtyDeedsDoneDirtCheap] = OverallScreenPositionLeft; \
} \
 \
InitiateTransformationData((&RedSpotScreenData->LogicData.TransformationDataRedSpot)); \
SetTransformationDataPositionVector( \
(&RedSpotScreenData->LogicData.TransformationDataRedSpot), \
(RedSpotScreenData->Loadable->RedSpotPositionX+(RedSpotScreenData->Loadable->RedSpotStartSizeX/2)), \
(RedSpotScreenData->Loadable->RedSpotPositionY+(RedSpotScreenData->Loadable->RedSpotStartSizeY/2)), RedSpotScreenData->Loadable->RedSpotPositionZ \
); \
StartZoomingAdvanced((&RedSpotScreenData->LogicData.TransformationDataRedSpot), NormalSizeScaleValue); \
 \
ResetButtonInputData(RedSpotScreenData->LogicData.ButtonInputData, DirtyDeedsDoneDirtCheap); \
RedSpotScreenData->LogicData.st = NULL; \
}


void RedSpotScreenLoad(RedSpotScreenStruct* RedSpotScreenData){

char FileDir[NormalFileDirSize];
uint32 CurrentPointerPosition;
uint32 FinalBufferSize;
uint8 DirtyDeedsDoneDirtCheap;

sprintf(FileDir, "%s/MISC/REDSPOTGAMES.rsg.gz", FileSystemUsed);
CompressedFileToBuffer(FileDir, (void**)(&RedSpotScreenData->Loadable));
CurrentPointerPosition = ((uint32)RedSpotScreenData->Loadable)+sizeof(RedSpotScreenLoadableStruct);

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < RedSpotScreenMovingArrayAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(char*, RedSpotScreenData->LogicData.MovingArray[DirtyDeedsDoneDirtCheap], RedSpotScreenData->Loadable->MovingArraySize[DirtyDeedsDoneDirtCheap]);
}

FinalBufferSize = CurrentPointerPosition-((uint32)RedSpotScreenData->Loadable);

LoadCurrentPointerPositionSetToLegalStartValue();
LoadTextureFromBufferPointer(CurrentPointerPosition, RedSpotScreenData->TextureData.BlackOutTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, RedSpotScreenData->TextureData.RedSpotTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, RedSpotScreenData->TextureData.BackGroundTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, RedSpotScreenData->TextureData.EffectTexture);

LoadSoundEffectFromBufferPointer(CurrentPointerPosition, RedSpotScreenData->SoundEffectData.RedSpotGamesSoundEffect);

InitiateRedSpotScreenLogicData();

RedSpotScreenData->Loadable = realloc(RedSpotScreenData->Loadable, FinalBufferSize);

}