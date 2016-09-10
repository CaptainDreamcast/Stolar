#define TileLogicLoopTileNot		0
#define TileLogicLoopTile			1



#define TileLoadLogicGeneralInitiate()	{ \
TileData->LogicData.General.LoopTile = TileLogicLoopTile; \
TileData->LogicData.General.DrawFlags = TileDrawFlagEverything; \
TileData->LogicData.General.AnimationFlags = TileAnimationFlagEverything; \
TileData->LogicData.General.EnableFlags = TileEnableFlagEverything; \
 \
TileData->LogicData.General.StartMenu = TileLogicStartMenuNot; \
TileData->LogicData.General.IntroFlag = TileLogicIntroFlagActive; \
 \
InitiateTransformationData((&TileData->LogicData.General.TransformationData)); \
}

#define TileLoadLogicStolarInitiate()	{ \
TileData->LogicData.Stolar.FaceDirection = OverWorldData->LogicData.Stolar.StartFaceDirection; \
TileData->LogicData.Stolar.CurrentAnimation = (OverWorldData->LogicData.Stolar.StartAnimation+OverWorldData->LogicData.Stolar.StartFaceDirection); \
TileData->LogicData.Stolar.CurrentFrame = NewFrameStandardValue; \
TileData->LogicData.Stolar.Ticks = NewTicksStandardValue; \
 \
TileData->LogicData.Stolar.EventInducedLoop = EventInducedLoopValueNot; \
 \
TileData->LogicData.Stolar.PositionX = OverWorldData->LogicData.Stolar.StartPositionX; \
TileData->LogicData.Stolar.StagePositionZ = OverWorldData->LogicData.Stolar.StartStagePositionZ; \
 \
TileLoadCalculateFromMap(TileData, TileData->LogicData.Stolar.StagePositionZ, &TileData->LogicData.Stolar.PositionY, &TileData->LogicData.Stolar.ScreenPositionZ, \
&TileData->LogicData.Stolar.SizeX, &TileData->LogicData.Stolar.SizeY, &TileData->LogicData.Stolar.SpeedX, \
&TileData->TileHeaderData->Stolar.Movement, &TileData->LogicData.Stolar.Movement); \
 \
TileData->LogicData.Stolar.AnimationFactor = AnimationFactorStandard; \
 \
InitiateTransformationData((&TileData->LogicData.Stolar.TransformationData)); \
}

#define TileLoadLogicBackGroundInitiate()	{ \
TileData->LogicData.BackGround.StagePositionX = TileLoadCreateNewStagePositionFromStolarStartPositionX(TileData, OverWorldData); \
TileData->LogicData.BackGround.StagePositionY = TileLoadCreateNewStagePositionFromStolarStartPositionY(TileData, OverWorldData); \
 \
InitiateTransformationData((&TileData->LogicData.BackGround.TransformationData)); \
}

#define TileLoadLogicPeopleInitiate()	{ \
InitiateTransformationData((&TileData->LogicData.People.TransformationData)); \
}

#define TileLoadLogicNormalEnemiesInitiate()	{ \
InitiateTransformationData((&TileData->LogicData.NormalEnemies.TransformationData)); \
}

#define TileLoadLogicSpecialEnemiesInitiate()	{ \
InitiateTransformationData((&TileData->LogicData.SpecialEnemies.TransformationData)); \
}

#define TileLoadLogicInitiate()	{ \
TileLoadLogicGeneralInitiate(); \
TileLoadLogicStolarInitiate(); \
TileLoadLogicBackGroundInitiate(); \
TileLoadLogicPeopleInitiate(); \
TileLoadLogicNormalEnemiesInitiate(); \
TileLoadLogicSpecialEnemiesInitiate(); \
}

#define TileLoadSingleBackGroundHeaderLogicInitiate()	{ \
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].LogicData.Active = TileLogicSingleActiveNot; \
 \
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].LogicData.Load = TileLogicSingleLoadNot; \
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].LogicData.Draw = TileLogicSingleDraw; \
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].LogicData.Animate = TileLogicSingleAnimate; \
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].LogicData.Ticks = NewTicksStandardValue; \
 \
InitiateTransformationData((&TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].LogicData.TransformationData)); \
}

#define TileLoadSinglePersonLogicInitiate()	{ \
TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Active = TileLogicSingleActiveNot; \
TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Load = TileLogicSingleLoadNot; \
 \
TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Draw = TileLogicSingleDraw; \
TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Animate = TileLogicSingleAnimate; \
TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Ticks = NewTicksStandardValue; \
TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.ArtificialIntelligenceEnabled = TileLogicArtificialIntelligenceEnabled; \
 \
InitiateTransformationData((&TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.TransformationData)); \
}

#define TileLoadSingleNormalEnemyLogicInitiate()	{ \
TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Active = TileLogicSingleActiveNot; \
 \
TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Draw = TileLogicSingleDraw; \
TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Animate = TileLogicSingleAnimate; \
TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Ticks = NewTicksStandardValue; \
TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.ArtificialIntelligenceEnabled = TileLogicArtificialIntelligenceEnabled; \
 \
InitiateTransformationData((&TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.TransformationData)); \
}

#define TileLoadSingleSpecialEnemyLogicInitiate()	{ \
TileData->SpecialEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Active = TileLogicSingleActiveNot; \
 \
TileData->SpecialEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Draw = TileLogicSingleDraw; \
TileData->SpecialEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Animate = TileLogicSingleAnimate; \
TileData->SpecialEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Ticks = NewTicksStandardValue; \
TileData->SpecialEnemyData[DirtyDeedsDoneDirtCheap].LogicData.ArtificialIntelligenceEnabled = TileLogicArtificialIntelligenceEnabled; \
 \
InitiateTransformationData((&TileData->SpecialEnemyData[DirtyDeedsDoneDirtCheap].LogicData.TransformationData)); \
}

#define TileLoadSingleSpriteLogicInitiate()	{ \
TileData->Sprites[DirtyDeedsDoneDirtCheap].LogicData.Load = TileLogicSingleLoadNot; \
}

#define TileLoadSingleEventLogicInitiate()	{ \
TileData->EventData[DirtyDeedsDoneDirtCheap].LogicData.Load = TileLogicSingleLoadNot; \
}

#define TileLoadSingleMusicLogicInitiate()	{ \
TileData->SpecialEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Active = TileLogicSingleActiveNot; \
}

void TileLoad(TileStruct* TileData, OverWorldStruct* OverWorldData){

char FileDir[NormalFileDirSize];
uint32 CurrentPointerPosition;
uint32 FinalBufferSize;
uint16 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;

sprintf(FileDir, "%s/TILES/TILE%d.til", FileSystemUsed, OverWorldData->LogicData.General.CurrentTile);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/TILE%d.til", OverWorldData->LogicData.General.CurrentTile);
CompressedFileToBuffer(FileDir, (void**)(&TileData->TileHeaderData));
CurrentPointerPosition = ((uint32)TileData->TileHeaderData)+sizeof(TileHeaderStruct);
LoadSetThisToThatPointer(char*, TileData->FluxData.General.LocationName, TileData->TileHeaderData->LocationNameSize);
LoadSetThisToThatPointer(char*, TileData->FluxData.General.TileName, TileData->TileHeaderData->TileNameSize);
LoadCurrentPointerPositionSetToLegalStartValue();

TileLoadLogicInitiate();

if(TileData->TileHeaderData->AnimationAmount > 0) TileData->BackGroundHeaderData = (BackGroundHeaderStruct*)malloc(sizeof(BackGroundHeaderStruct)*TileData->TileHeaderData->AnimationAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->AnimationAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(BackGroundHeaderLoadableStruct*, TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable, sizeof(BackGroundHeaderLoadableStruct));
TileLoadFlags(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].FlagData.Load);
TileLoadFlags(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].FlagData.Active);
TileLoadSingleBackGroundHeaderLogicInitiate();
}

if(TileData->TileHeaderData->PersonAmount > 0) TileData->PersonData = (PersonStruct*)malloc(sizeof(PersonStruct)*DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->PersonAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->PersonAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(PersonLoadableStruct*, TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable, sizeof(PersonLoadableStruct));
TileLoadFlags(TileData->PersonData[DirtyDeedsDoneDirtCheap].FlagData.Load);
TileLoadFlags(TileData->PersonData[DirtyDeedsDoneDirtCheap].FlagData.Active);
TileLoadSinglePersonLogicInitiate();
}

if(TileData->TileHeaderData->NormalEnemyAmount > 0) TileData->NormalEnemyData = (NormalEnemyStruct*)malloc(sizeof(NormalEnemyStruct)*TileData->TileHeaderData->NormalEnemyAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->NormalEnemyAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(NormalEnemyLoadableStruct*, TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable, sizeof(NormalEnemyLoadableStruct));
TileLoadFlags(TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].FlagData.Active);
TileLoadSingleNormalEnemyLogicInitiate();
}

if(TileData->TileHeaderData->SpecialEnemyAmount > 0) TileData->SpecialEnemyData = (SpecialEnemyStruct*)malloc(sizeof(SpecialEnemyStruct)*TileData->TileHeaderData->SpecialEnemyAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->SpecialEnemyAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(SpecialEnemyLoadableStruct*, TileData->SpecialEnemyData[DirtyDeedsDoneDirtCheap].Loadable, sizeof(SpecialEnemyLoadableStruct));
TileLoadFlags(TileData->SpecialEnemyData[DirtyDeedsDoneDirtCheap].FlagData.Active);
TileLoadSingleSpecialEnemyLogicInitiate();
}

if(TileData->TileHeaderData->SpriteAmount > 0) TileData->Sprites = (TileSpriteStruct*)malloc(sizeof(TileSpriteStruct)*TileData->TileHeaderData->SpriteAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->SpriteAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(TileSpriteLoadableStruct*, TileData->Sprites[DirtyDeedsDoneDirtCheap].Loadable, sizeof(TileSpriteLoadableStruct));
TileLoadFlags(TileData->Sprites[DirtyDeedsDoneDirtCheap].FlagData.Load);
TileLoadSingleSpriteLogicInitiate();
}

if(TileData->TileHeaderData->EventAmount > 0) TileData->EventData = (EventStruct*)malloc(sizeof(EventStruct)*TileData->TileHeaderData->EventAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->EventAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(EventLoadableStruct*, TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable, sizeof(EventLoadableStruct));
TileLoadFlags(TileData->EventData[DirtyDeedsDoneDirtCheap].FlagData.Load);
TileLoadFlags(TileData->EventData[DirtyDeedsDoneDirtCheap].FlagData.Active);
TileLoadSingleEventLogicInitiate();
}

if(TileData->TileHeaderData->MusicAmount > 0) TileData->MusicData = (TileMusicStruct*)malloc(sizeof(TileMusicStruct)*TileData->TileHeaderData->MusicAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->MusicAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(TileMusicLoadableStruct*, TileData->MusicData[DirtyDeedsDoneDirtCheap].Loadable, sizeof(TileMusicLoadableStruct));
TileLoadFlags(TileData->MusicData[DirtyDeedsDoneDirtCheap].FlagData.Active);
TileLoadSingleMusicLogicInitiate();
}

TileData->LayOutBuffer = (uint8**)malloc(sizeof(uint8*)*(TileData->TileHeaderData->LayOutBuffer.LayOutSizeY));
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->LayOutBuffer.LayOutSizeY; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(uint8*, TileData->LayOutBuffer[DirtyDeedsDoneDirtCheap], TileData->TileHeaderData->LayOutBuffer.LayOutSizeX);
}

TileData->ActiveEventData = (ActiveEventStruct*)(malloc(sizeof(ActiveEventStruct)*TileData->TileHeaderData->MaximumActiveEventAmount));
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->MaximumActiveEventAmount; DirtyDeedsDoneDirtCheap++){
InitiateSingleActiveEvent(TileData->ActiveEventData, DirtyDeedsDoneDirtCheap);
}


FinalBufferSize = CurrentPointerPosition - ((uint32)TileData->TileHeaderData);


TileUpdateFlagsLoad(TileData, OverWorldData);
TileUpdateFlagsActive(TileData, OverWorldData);



for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->AnimationAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].LogicData.Load){
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Texture = (pvr_ptr_t*)malloc(sizeof(pvr_ptr_t)*TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->FrameAmount);
for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->FrameAmount; BurningDownTheHouse++){
LoadTextureFromBufferPointer(CurrentPointerPosition, TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Texture[BurningDownTheHouse]);
}
}
else{
for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->FrameAmount; BurningDownTheHouse++){
LoadTextureFromBufferPointerSkip(CurrentPointerPosition, TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Texture[BurningDownTheHouse]);
}
}
}



for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->PersonAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Load){
LoadBufferFromBufferPointer(AnimationStruct*, TileData->PersonData[DirtyDeedsDoneDirtCheap].AnimationData, (sizeof(AnimationStruct)*TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->AnimationAmount));
LoadTextureFromBufferPointer(CurrentPointerPosition, TileData->PersonData[DirtyDeedsDoneDirtCheap].Texture);
}
else{
LoadBufferFromBufferPointerSkip(AnimationStruct*, TileData->PersonData[DirtyDeedsDoneDirtCheap].AnimationData, (sizeof(AnimationStruct)*TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->AnimationAmount));
LoadTextureFromBufferPointerSkip(CurrentPointerPosition, TileData->PersonData[DirtyDeedsDoneDirtCheap].Texture);
}
}


for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->SpriteAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->Sprites[DirtyDeedsDoneDirtCheap].LogicData.Load){
LoadBufferFromBufferPointer(AnimationStruct*, TileData->Sprites[DirtyDeedsDoneDirtCheap].AnimationData, (sizeof(AnimationStruct)*TileData->Sprites[DirtyDeedsDoneDirtCheap].Loadable->AnimationAmount));
LoadTextureFromBufferPointer(CurrentPointerPosition, TileData->Sprites[DirtyDeedsDoneDirtCheap].Texture);
}
else{
LoadBufferFromBufferPointerSkip(AnimationStruct*, TileData->Sprites[DirtyDeedsDoneDirtCheap].AnimationData, (sizeof(AnimationStruct)*TileData->Sprites[DirtyDeedsDoneDirtCheap].Loadable->AnimationAmount));
LoadTextureFromBufferPointerSkip(CurrentPointerPosition, TileData->Sprites[DirtyDeedsDoneDirtCheap].Texture);
}
}

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->EventAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->EventData[DirtyDeedsDoneDirtCheap].LogicData.Load){
LoadBufferFromBufferPointer(void*, TileData->EventData[DirtyDeedsDoneDirtCheap].EventBuffer, TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->EventBufferSize);
}
else{
LoadBufferFromBufferPointerSkip(void*, TileData->EventData[DirtyDeedsDoneDirtCheap].EventBuffer, TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->EventBufferSize);
}
}

TileData->TileHeaderData = realloc(TileData->TileHeaderData, FinalBufferSize);
}