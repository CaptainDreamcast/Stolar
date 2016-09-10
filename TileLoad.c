#define TileLogicLoopTileNot		0
#define TileLogicLoopTile			1

#define TileLoadSingleEventLoad(EventData)		{ \
LoadSetThisToThatPointer(EventLoadableStruct*, EventData.Loadable, sizeof(EventLoadableStruct)); \
TileLoadFlags(EventData.FlagData.Load); \
TileLoadFlags(EventData.FlagData.Active); \
TileLoadSingleEventLogicInitiate(EventData.LogicData); \
}

#define TileLoadLogicGeneralInitiate()	{ \
TileData->LogicData.General.LoopTile = TileLogicLoopTile; \
TileData->LogicData.General.DrawFlags = TileDrawFlagEverything; \
TileData->LogicData.General.AnimationFlags = TileAnimationFlagEverything; \
TileData->LogicData.General.EnableFlags = TileEnableFlagEverything; \
 \
TileData->LogicData.General.StartMenu = TileLogicStartMenuNot; \
TileData->LogicData.General.IntroFlag = TileLogicIntroFlagActive; \
TileData->LogicData.General.ObjectAmount = DummyValueInteger; \
 \
InitiateTransformationData((&TileData->LogicData.General.TransformationData)); \
}

#define TileLoadLogicOutroInitiate()	{ \
TileData->LogicData.Outro.Active = LogicActiveNot; \
TileData->LogicData.Outro.Identifier = DummyValueInteger; \
TileData->LogicData.Outro.NewGamePlay = DummyValueInteger; \
TileData->LogicData.Outro.WhereExactly = DummyValueInteger; \
}


/*
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
*/


#define TileLoadLogicBackGroundInitiate()	{ \
TileData->LogicData.BackGround.StagePositionX = DummyValueFloat; \
TileData->LogicData.BackGround.StagePositionY = DummyValueFloat; \
 \
TileLoadMovementPreCompute(TileData, &TileData->TileHeaderData->Movement, &TileData->LogicData.BackGround.Movement); \
 \
InitiateTransformationData((&TileData->LogicData.BackGround.TransformationData)); \
}

#define TileLoadLogicInitiate()	{ \
TileLoadLogicGeneralInitiate(); \
TileLoadLogicOutroInitiate() \
TileLoadLogicBackGroundInitiate(); \
}

#define TileLoadSinglePlayerLogicInitiate()	{ \
TileData->PlayerData[DirtyDeedsDoneDirtCheap].LogicData.EventAmount = TileData->TileHeaderData->EventPlayerAmount; \
TileData->PlayerData[DirtyDeedsDoneDirtCheap].LogicData.WhichObject = DummyValueInteger; \
TileData->PlayerData[DirtyDeedsDoneDirtCheap].LogicData.WhichInstance = DummyValueInteger; \
}

#define TileLoadSingleBackGroundHeaderLogicInitiate()	{ \
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].LogicData.Load = TileLogicSingleLoadNot; \
}

#define TileLoadSingleBackGroundHeaderInstanceLogicInitiate()	{ \
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Active = TileLogicSingleActiveNot; \
 \
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Draw = TileLogicSingleDraw; \
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Animate = TileLogicSingleAnimate; \
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Ticks = NewTicksStandardValue; \
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.CurrentAnimation = TileBackGroundInstanceAnimationValue; \
 \
InitiateTransformationData((&TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.TransformationData)); \
}

#define TileLoadSingleObjectLogicInitiate(WhichObject)	{ \
TileData->ObjectData[WhichObject].LogicData.Load = TileLogicSingleLoadNot; \
}

#define TileLoadSingleObjectInstanceLogicInitiate(WhichObject, WhichInstance)	{ \
TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Active = TileLogicSingleActiveNot; \
 \
TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Draw = TileLogicSingleDraw; \
TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Animate = TileLogicSingleAnimate; \
TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.MoveNot = LogicActiveNot; \
TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Ticks = NewTicksStandardValue; \
 \
TileLoadCalculateFromMap(TileData, \
TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ, \
&TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.PositionY, \
&TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ScreenPositionZ, \
TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeX, \
&TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SizeX, \
TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeY, \
&TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SizeY, \
TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SpeedX, \
&TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SpeedX, \
&TileData->TileHeaderData->Movement, &TileData->LogicData.BackGround.Movement); \
 \
InitiateTransformationData((&TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.TransformationData)); \
}

/*
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
*/

#define TileLoadSingleSpriteLogicInitiate()	{ \
TileData->Sprites[DirtyDeedsDoneDirtCheap].LogicData.Load = TileLogicSingleLoadNot; \
}

#define TileLoadSingleEventLogicInitiate(LogicData)	{ \
LogicData.Load = TileLogicSingleLoadNot; \
}

#define TileLoadSingleMusicLogicInitiate()	{ \
TileData->MusicData[DirtyDeedsDoneDirtCheap].LogicData.Active = TileLogicSingleActiveNot; \
}

void TileLoad(TileStruct* TileData, OverWorldStruct* OverWorldData){

TileObjectClassStruct* CurrentClass;
char FileDir[NormalFileDirSize];
uint32 CurrentPointerPosition;
uint32 FinalBufferSize;
uint16 DirtyDeedsDoneDirtCheap, BurningDownTheHouse, WhichEvent;
uint16 WhichObject;

sprintf(FileDir, "%s/TILES/%d.til.gz", FileSystemUsed, OverWorldData->LogicData.General.CurrentTile);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/%d.til.gz", OverWorldData->LogicData.General.CurrentTile);
CompressedFileToBuffer(FileDir, (void**)(&TileData->TileHeaderData));
CurrentPointerPosition = ((uint32)TileData->TileHeaderData)+sizeof(TileHeaderStruct);
LoadSetThisToThatPointer(char*, TileData->FluxData.General.LocationName, TileData->TileHeaderData->LocationNameSize);
LoadSetThisToThatPointer(char*, TileData->FluxData.General.TileName, TileData->TileHeaderData->TileNameSize);
LoadCurrentPointerPositionSetToLegalStartValue();

TileLoadLogicInitiate();


TileData->PlayerData = (TilePlayerStruct*)malloc(sizeof(TilePlayerStruct)*OverWorldData->LogicData.General.PlayerAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < OverWorldData->LogicData.General.PlayerAmount; DirtyDeedsDoneDirtCheap++){
TileLoadSinglePlayerLogicInitiate();
TileData->PlayerData[DirtyDeedsDoneDirtCheap].EventSelfData = (EventSelfStruct*)malloc(sizeof(EventSelfStruct)*TileData->TileHeaderData->EventPlayerAmount);
for(WhichEvent = 0; WhichEvent < TileData->TileHeaderData->EventPlayerAmount; WhichEvent++){
LoadSetThisToThatPointer(EventSelfLoadableStruct*, TileData->PlayerData[DirtyDeedsDoneDirtCheap].EventSelfData[WhichEvent].Loadable, sizeof(EventSelfLoadableStruct));
TileLoadSingleEventLoad(TileData->PlayerData[DirtyDeedsDoneDirtCheap].EventSelfData[WhichEvent].EventData);	
}
}


if(TileData->TileHeaderData->AnimationAmount > 0) TileData->BackGroundHeaderData = (BackGroundHeaderStruct*)malloc(sizeof(BackGroundHeaderStruct)*TileData->TileHeaderData->AnimationAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->AnimationAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(BackGroundHeaderLoadableStruct*, TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable, sizeof(BackGroundHeaderLoadableStruct));
TileLoadFlags(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].FlagData.Load);
TileLoadSingleBackGroundHeaderLogicInitiate();

if(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->InstanceAmount > 0) TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance = (BackGroundHeaderInstanceStruct*)malloc(sizeof(BackGroundHeaderInstanceStruct)*TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->InstanceAmount);
for(BurningDownTheHouse=0; BurningDownTheHouse<TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->InstanceAmount; BurningDownTheHouse++){
LoadSetThisToThatPointer(BackGroundHeaderInstanceLoadableStruct*, TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable, sizeof(BackGroundHeaderInstanceLoadableStruct));
TileLoadFlags(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].FlagData.Active);
TileLoadSingleBackGroundHeaderInstanceLogicInitiate();
}
}


TileData->LogicData.General.ObjectAmount = TileData->TileHeaderData->ObjectAmount+OverWorldData->LogicData.General.CrewSize;
WhichObject = 0;
if(TileData->LogicData.General.ObjectAmount > 0) TileData->ObjectData = (TileObjectStruct*)malloc(sizeof(TileObjectStruct)*TileData->LogicData.General.ObjectAmount);
CurrentClass = NULL;

if(OverWorldData->LogicData.General.CrewSize > 0){
CurrentClass = TileLoadClassCreate();
}
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < OverWorldData->LogicData.General.CrewSize; DirtyDeedsDoneDirtCheap++){
TileData->ObjectData[WhichObject].Loadable = TileLoadObjectLoadableCreateCrew(TileData, OverWorldData, DirtyDeedsDoneDirtCheap);
TileLoadFlagsDummyFalse(TileData->ObjectData[WhichObject].FlagData.Load);
TileData->ObjectData[WhichObject].ClassData = CurrentClass;
TileLoadSingleObjectLogicInitiate(WhichObject);

if(TileData->ObjectData[WhichObject].Loadable->InstanceAmount > 0) TileData->ObjectData[WhichObject].Instance = (TileObjectInstanceStruct*)malloc(sizeof(TileObjectInstanceStruct)*TileData->ObjectData[WhichObject].Loadable->InstanceAmount);
for(BurningDownTheHouse=0; BurningDownTheHouse<TileData->ObjectData[WhichObject].Loadable->InstanceAmount; BurningDownTheHouse++){
if(CrewIsPlayer(OverWorldData, DirtyDeedsDoneDirtCheap)){
TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable = TileLoadObjectInstanceLoadableCreatePlayer(TileData, OverWorldData, DirtyDeedsDoneDirtCheap, WhichObject, BurningDownTheHouse);
WhichEvent = CrewIsPlayerValueGet(OverWorldData, DirtyDeedsDoneDirtCheap);
TileData->PlayerData[WhichEvent].LogicData.WhichObject = WhichObject;
TileData->PlayerData[WhichEvent].LogicData.WhichInstance = BurningDownTheHouse;
}
else{
TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable = TileLoadObjectInstanceLoadableCreateCrew(TileData, OverWorldData, DirtyDeedsDoneDirtCheap, WhichObject, BurningDownTheHouse);
}
TileLoadFlagsDummyTrue(TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].FlagData.Active);
TileLoadSingleObjectInstanceLogicInitiate(WhichObject, BurningDownTheHouse);

if(TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable->EventAmount > 0) TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData = (EventStruct*)malloc(sizeof(EventStruct)*TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable->EventAmount);
for(WhichEvent=0; WhichEvent<TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable->EventAmount; WhichEvent++){
TileLoadSingleEventLoad(TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent]);
}
}
WhichObject++;
}

if(TileData->TileHeaderData->PersonAmount > 0){
CurrentClass = TileLoadClassCreate();
}
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->PersonAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(TileObjectLoadableStruct*, TileData->ObjectData[WhichObject].Loadable, sizeof(TileObjectLoadableStruct));

TileLoadFlags(TileData->ObjectData[WhichObject].FlagData.Load);

TileData->ObjectData[WhichObject].ClassData = CurrentClass;
TileLoadSingleObjectLogicInitiate(WhichObject);

if(TileData->ObjectData[WhichObject].Loadable->InstanceAmount > 0) TileData->ObjectData[WhichObject].Instance = (TileObjectInstanceStruct*)malloc(sizeof(TileObjectInstanceStruct)*TileData->ObjectData[WhichObject].Loadable->InstanceAmount);
for(BurningDownTheHouse=0; BurningDownTheHouse<TileData->ObjectData[WhichObject].Loadable->InstanceAmount; BurningDownTheHouse++){
LoadSetThisToThatPointer(TileObjectInstanceLoadableStruct*, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable, sizeof(TileObjectInstanceLoadableStruct));
TileLoadFlags(TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].FlagData.Active);
TileLoadSingleObjectInstanceLogicInitiate(WhichObject, BurningDownTheHouse);


if(TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable->EventAmount > 0) TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData = (EventStruct*)malloc(sizeof(EventStruct)*TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable->EventAmount);
for(WhichEvent=0; WhichEvent<TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable->EventAmount; WhichEvent++){
TileLoadSingleEventLoad(TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent]);
}
}
WhichObject++;
}


if(TileData->TileHeaderData->SpriteAmount > 0) TileData->Sprites = (TileSpriteStruct*)malloc(sizeof(TileSpriteStruct)*TileData->TileHeaderData->SpriteAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->SpriteAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(TileSpriteLoadableStruct*, TileData->Sprites[DirtyDeedsDoneDirtCheap].Loadable, sizeof(TileSpriteLoadableStruct));
TileLoadFlags(TileData->Sprites[DirtyDeedsDoneDirtCheap].FlagData.Load);
TileLoadSingleSpriteLogicInitiate();
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


for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < OverWorldData->LogicData.General.PlayerAmount; DirtyDeedsDoneDirtCheap++){
for(WhichEvent = 0; WhichEvent < TileData->TileHeaderData->EventPlayerAmount; WhichEvent++){
if(TileData->PlayerData[DirtyDeedsDoneDirtCheap].EventSelfData[WhichEvent].EventData.LogicData.Load){
LoadBufferFromBufferPointer(void*, TileData->PlayerData[DirtyDeedsDoneDirtCheap].EventSelfData[WhichEvent].EventData.EventBuffer, TileData->PlayerData[DirtyDeedsDoneDirtCheap].EventSelfData[WhichEvent].EventData.Loadable->EventBufferSize);
}
else{
LoadBufferFromBufferPointerSkip(void*, TileData->PlayerData[DirtyDeedsDoneDirtCheap].EventSelfData[WhichEvent].EventData.EventBuffer, TileData->PlayerData[DirtyDeedsDoneDirtCheap].EventSelfData[WhichEvent].EventData.Loadable->EventBufferSize);
}
}
}

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

WhichObject = 0;

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < OverWorldData->LogicData.General.CrewSize; DirtyDeedsDoneDirtCheap++){
TileData->ObjectData[WhichObject].AnimationData = OverWorldData->CrewData[DirtyDeedsDoneDirtCheap].FluxData.AnimationData;
TileData->ObjectData[WhichObject].Texture = OverWorldData->CrewData[DirtyDeedsDoneDirtCheap].Texture;
for(BurningDownTheHouse=0; BurningDownTheHouse<TileData->ObjectData[WhichObject].Loadable->InstanceAmount; BurningDownTheHouse++){
for(WhichEvent=0; WhichEvent<TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable->EventAmount; WhichEvent++){
if(TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].LogicData.Load){
LoadBufferFromBufferPointer(void*, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].EventBuffer, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].Loadable->EventBufferSize);
}
else{
LoadBufferFromBufferPointerSkip(void*, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].EventBuffer, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].Loadable->EventBufferSize);
}
}
}
WhichObject++;
}


for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->PersonAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->ObjectData[WhichObject].LogicData.Load){
LoadBufferFromBufferPointer(AnimationStruct*, TileData->ObjectData[WhichObject].AnimationData, (sizeof(AnimationStruct)*TileData->ObjectData[WhichObject].Loadable->AnimationAmount));
TileData->ObjectData[WhichObject].Texture = malloc(sizeof(pvr_ptr_t*)*TileData->ObjectData[WhichObject].Loadable->TextureAmount);
for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->ObjectData[WhichObject].Loadable->TextureAmount; BurningDownTheHouse++){
LoadTextureFromBufferPointer(CurrentPointerPosition, TileData->ObjectData[WhichObject].Texture[BurningDownTheHouse]);
}
for(BurningDownTheHouse=0; BurningDownTheHouse<TileData->ObjectData[WhichObject].Loadable->InstanceAmount; BurningDownTheHouse++){
for(WhichEvent=0; WhichEvent<TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable->EventAmount; WhichEvent++){
if(TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].LogicData.Load){
LoadBufferFromBufferPointer(void*, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].EventBuffer, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].Loadable->EventBufferSize);
}
else{
LoadBufferFromBufferPointerSkip(void*, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].EventBuffer, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].Loadable->EventBufferSize);
}
}
}
}
else{
LoadBufferFromBufferPointerSkip(AnimationStruct*, TileData->ObjectData[WhichObject].AnimationData, (sizeof(AnimationStruct)*TileData->ObjectData[WhichObject].Loadable->AnimationAmount));
for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->ObjectData[WhichObject].Loadable->TextureAmount; BurningDownTheHouse++){
LoadTextureFromBufferPointerSkip(CurrentPointerPosition, TileData->ObjectData[WhichObject].Texture[BurningDownTheHouse]);
}
for(BurningDownTheHouse=0; BurningDownTheHouse<TileData->ObjectData[WhichObject].Loadable->InstanceAmount; BurningDownTheHouse++){
for(WhichEvent=0; WhichEvent<TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].Loadable->EventAmount; WhichEvent++){
if(TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].LogicData.Load){
LoadBufferFromBufferPointer(void*, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].EventBuffer, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].Loadable->EventBufferSize);
}
else{
LoadBufferFromBufferPointerSkip(void*, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].EventBuffer, TileData->ObjectData[WhichObject].Instance[BurningDownTheHouse].EventData[WhichEvent].Loadable->EventBufferSize);
}
}
}
}
WhichObject++;
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


TileData->TileHeaderData = realloc(TileData->TileHeaderData, FinalBufferSize);


TileData->LogicData.BackGround.StagePositionX = TileLoadCreateNewStagePositionFromPlayerStartPositionX(TileData, OverWorldData, PlayerMain);
TileData->LogicData.BackGround.StagePositionY = TileLoadCreateNewStagePositionFromPlayerStartPositionY(TileData, OverWorldData, PlayerMain);

}