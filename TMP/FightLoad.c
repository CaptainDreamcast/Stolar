
#define FightLogicLoopFight	1
#define FightLogicGeneralInitiate()	{ \
FightData->LogicData.General.LoopFight = LogicActive; \
 \
FightData->LogicData.General.ObjectAmount = FightData->Loadable.Stage->ObjectAmount+FightData->Loadable.Enemies->General.EnemyObjectAmount+OverWorldData->LogicData.General.CrewSize; \
 \
InitiateTransformationData((&FightData->LogicData.General.TransformationData)); \
}


#define FightLogicStageInitiate()	{ \
FightData->LogicData.Stage.StagePositionX = FightData->Loadable.Stage->BackGround.StartStagePositionX; \
FightData->LogicData.Stage.StagePositionY = FightData->Loadable.Stage->BackGround.StartStagePositionY; \
}

#define FightLogicBackGroundInitiate()	{ \
InitiateTransformationData((&FightData->LogicData.BackGround.TransformationData)); \
}

#define FightLogicEnemiesGeneralInitiate()	{ \
FightData->LogicData.Enemies.General.ObjectStart = DummyValueInteger; \
FightData->LogicData.Enemies.General.ObjectEnd = DummyValueInteger; \
}

#define FightLogicEnemiesInitiate()	{ \
FightLogicEnemiesGeneralInitiate(); \
}

#define FightLogicUserInterFaceInitiate()	{ \
InitiateTransformationData((&FightData->LogicData.UserInterFace.TransformationData)); \
}


#define FightLogicInitiate()	{ \
FightLogicGeneralInitiate(); \
FightLogicStageInitiate(); \
FightLogicBackGroundInitiate(); \
FightLogicEnemiesInitiate(); \
FightLogicUserInterFaceInitiate(); \
}


#define FightLogicSingleDraw		1
#define FightLogicSingleAnimate		1
#define FightBackGroundLogicInitiate()	{ \
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.Draw = FightLogicSingleDraw; \
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.Animate = FightLogicSingleAnimate; \
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.CurrentFrame = NewFrameStandardValue; \
 \
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.Ticks = NewTicksStandardValue; \
 \
FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.AnimationFactor = AnimationFactorStandard; \
 \
InitiateTransformationData((&FightData->BackGroundData[DirtyDeedsDoneDirtCheap].LogicData.TransformationData)); \
}

#define FightEnemyLogicArtificialIntelligenceActiveStart	1
#define FightEnemyLogicInitiate()	{ \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.Draw = FightLogicSingleDraw; \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.Animate = FightLogicSingleAnimate; \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.ArtificialIntelligenceActive = FightEnemyLogicArtificialIntelligenceActiveStart; \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.ArtificialIntelligenceFunction = FightData->EnemyData[DirtyDeedsDoneDirtCheap].Loadable->StartArtificialIntelligenceFunction; \
 \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.CurrentFrame = NewFrameStandardValue; \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.Hit = FightLogicEnemyHitNot; \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.VelocityActiveX = FightPhysicsVelocityStandardValueX; \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.VelocityActiveY = DummyValueFloat; \
 \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.EventInducedLoop = EventInducedLoopValueNot; \
 \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.CurrentAnimation = FightData->EnemyData[DirtyDeedsDoneDirtCheap].Loadable->StartAnimation; \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.Ticks = NewTicksStandardValue; \
 \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.Health = FightData->EnemyData[DirtyDeedsDoneDirtCheap].Loadable->HealthMax; \
 \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.AnimationFactor = AnimationFactorStandard; \
FightStagePositionParseZ(FightData, FightData->EnemyData[DirtyDeedsDoneDirtCheap].Given->StagePositionZ, &FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.ScreenPositionZ, &FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.PositionY); \
 \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.VelocityX = LogicActiveNot; \
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.VelocityY = LogicActiveNot; \
 \
InitiateTransformationData((&FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.TransformationData)); \
}

void FightLoad(FightStruct* FightData, OverWorldStruct* OverWorldData){

char FileDir[NormalFileDirSize];
uint32 CurrentPointerPosition, CurrentPointerPositionGiven;
uint32 FinalBufferSize;
uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;
FightEnemyGivenStruct* FightEnemyGivenData;


FightData->OverWorldData = OverWorldData;

//
sprintf(FileDir, "%s/TEST.fgt", FileSystemUsed);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/TEST.fgt");
FileToBuffer(FileDir, &OverWorldData->LogicData.Passable);
//

CurrentPointerPosition = ((uint32)OverWorldData->LogicData.Passable);

LoadSetThisToThatPointer(FightLoadableGivenStruct*, FightData->Loadable.Given, sizeof(FightLoadableGivenStruct));
LoadSetThisToThatPointer(FightLoadableEnemiesStruct*, FightData->Loadable.Enemies, sizeof(FightLoadableEnemiesStruct));
LoadSetThisToThatPointer(FightEnemyGivenStruct*, FightEnemyGivenData, (sizeof(FightEnemyGivenStruct)*FightData->Loadable.Enemies->General.EnemyAmount));

/*
FightData->EnemyData = (FightEnemyStruct*)malloc(sizeof(FightEnemyStruct)*FightData->Loadable.Enemies->General.EnemyAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<FightData->Loadable.Enemies->General.EnemyAmount; DirtyDeedsDoneDirtCheap++){
LoadSetThisToThatPointer(FightEnemyGivenStruct*, FightData->EnemyData[DirtyDeedsDoneDirtCheap].Given, sizeof(FightEnemyGivenStruct));
}
*/
FightEnemyGivenStruct* FightEnemyGivenData = CurrentPointerPosition


sprintf(FileDir, "%s/STAGES/%d.stg.gz", FileSystemUsed, FightData->Loadable.Given->WhichStage);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/%d.stg.gz", FightData->Loadable.Given->WhichStage);
CompressedFileToBuffer(FileDir, (void**)(&FightData->Loadable.Stage));
CurrentPointerPosition = ((uint32)FightData->Loadable.Stage)+sizeof(FightLoadableStageStruct);

FightLogicInitiate();

FightData->BackGroundData = (FightBackGroundStruct*)malloc(sizeof(FightBackGroundStruct)*FightData->Loadable.Stage->General.BackGroundObjectAmount);
for(WhichObject = 0; WhichObject< FightData->Loadable.Stage->General.BackGroundObjectAmount; WhichObject++){
LoadSetThisToThatPointer(FightBackGroundLoadableStruct*, FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Loadable, sizeof(FightBackGroundLoadableStruct));
FightBackGroundObjectLogicInitiate();

FightData->BackGroundData[WhichObject].Instance = (FightBackGroundInstanceStruct*)malloc(sizeof(FightBackGroundInstanceStruct)*FightData->BackGroundData[WhichObject].Loadable->InstanceAmount);
for(WhichInstance = 0; WhichInstance < FightData->BackGroundData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
LoadSetThisToThatPointer(FightBackGroundInstanceLoadableStruct*, FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable, sizeof(FightBackGroundInstanceLoadableStruct));
FightBackGroundObjectInstanceLogicInitiate();
}
}

FinalBufferSize = CurrentPointerPosition-((uint32)FightData->Loadable.Stage);

for(WhichObject = 0; WhichObject < FightData->Loadable.Stage->General.BackGroundObjectAmount; WhichObject++){
FightData->BackGroundData[WhichObject].Texture = (pvr_ptr_t*)malloc(sizeof(pvr_ptr_t)*FightData->BackGroundData[WhichObject].Loadable->FrameAmount);
for(WhichInstance = 0; WhichInstance < FightData->BackGroundData[WhichObject].Loadable->FrameAmount; WhichInstance++){
LoadTextureFromBufferPointer(CurrentPointerPosition, FightData->BackGroundData[WhichObject].Texture[WhichInstance]);
}
}

FightData->Loadable.Stage = realloc(FightData->Loadable.Stage, FinalBufferSize);


FightData->PlayerData = (FightPlayerStruct*)malloc(sizeof(FightPlayerStruct)*OverWorldData->LogicData.General.PlayerAmount);
for(WhichObject=0; WhichObject < OverWorldData->LogicData.General.PlayerAmount; WhichObject++){
FightPlayerLogicInitiate();

for(WhichInstance = 0; WhichInstance < AbilityAmount; WhichInstance++){
if(WhichInstance != AbilityRed){
FightData->PlayerData[WhichObject].AbilityData[WhichInstance].TextureData.Gauge = pvr_mem_malloc(TextureTypeMultiplierDispatch(PVR_TXRFMT_PAL4BPP)*OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeX*OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeY);
}
}
}



OverallObjectAmount = ;
WhichObject = 0;
if(OverallObjectAmount > 0) FightData->ObjectData = (FightObjectStruct*)malloc(sizeof(FightObjectStruct)*OverallObjectAmount);
CurrentClass = NULL;


if(OverWorldData->LogicData.General.CrewSize > 0){
CurrentClass = FightLoadClassCreate();
}
for(WhichObject=0; WhichObject < OverWorldData->LogicData.General.CrewSize; WhichObject++){
FightData->ObjectData[WhichObject].Loadable = FightLoadObjectLoadableCreateCrew(FightData, WhichObject);
FightData->ObjectData[WhichObject].ClassData = CurrentClass;
FightData->ObjectData[WhichObject].FluxData.AnimationData = OverWorldData->CrewData[WhichObject].FluxData.AnimationData;
FightSingleObjectLogicInitiate(WhichObject);

if(FightData->ObjectData[WhichObject].Loadable->InstanceAmount > 0) FightData->ObjectData[WhichObject].Instance = (FightObjectInstanceStruct*)malloc(sizeof(FightObjectInstanceStruct)*FightData->ObjectData[WhichObject].Loadable->InstanceAmount);
for(WhichInstance=0; WhichInstance<FightData->ObjectData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
if(FightLoadCrewIsPlayer(FightData, OverWorldData, WhichObject)){
FightLoadObjectInstanceCreateLoadablePlayer(FightData, WhichObject, WhichInstance, WhichObject);
FightLoadObjectInstanceCreateFluxDataPlayer(FightData, WhichObject, WhichInstance, WhichObject);

WhichPlayer = TileLoadCrewIsPlayerValueGet(TileData, OverWorldData, WhichObject);
FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject = WhichObject;
FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance = BurningDownTheHouse;
}
else{
FightLoadObjectInstanceCreateLoadableCrew(FightData, WhichObject, WhichInstance, WhichObject);
FightLoadObjectInstanceCreateFluxDataCrew(FightData, WhichObject, WhichInstance, WhichObject);
}
FightSingleObjectSingleInstanceLogicInitiate(WhichObject, WhichInstance);


WhichObject++;
}



if(FightData->Loadable.Enemies->General.EnemyObjectAmount > 0){
CurrentClass = FightLoadClassCreate();
}
for(CurrentObject=0; CurrentObject<FightData->Loadable.Enemies->General.EnemyObjectAmount; CurrentObject++){
sprintf(FileDir, "%s/ENEMIES/%d.enm.gz", FileSystemUsed, FightEnemyGivenData[CurrentObject].EnemyIdentifier);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/%d.enm.gz", FightEnemyGivenData[CurrentObject].EnemyIdentifier);
CompressedFileToBuffer(FileDir, (void**)(&FightData->ObjectData[WhichObject].Loadable));
CurrentPointerPosition = ((uint32)FightData->ObjectData[WhichObject].Loadable)+sizeof(FightObjectLoadableStruct);
LoadSetThisToThatPointer(AnimationStruct*, FightData->ObjectData[WhichObject].FluxData.AnimationData, sizeof(AnimationStruct)*FightData->ObjectData[WhichObject].Loadable->AnimationAmount);
FightData->ObjectData[WhichObject].ClassData = CurrentClass;
FightSingleObjectLogicInitiate(WhichObject);

FinalBufferSize = CurrentPointerPosition-((uint32)FightData->ObjectData[WhichObject].Loadable);
LoadTextureFromBufferPointer(CurrentPointerPosition, FightData->ObjectData[WhichObject].Texture);

for(WhichInstance = 0; WhichInstance < FightData->ObjectData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
CurrentPointerPosition = FightLoadCreateLoadableEnemy(FightData, EnemyGivenData, CurrentPointerPosition, WhichObject, WhichInstance, CurrentObject);
CurrentPointerPosition = FightLoadCreateFluxDataEnemy(FightData, EnemyGivenData, CurrentPointerPosition, WhichObject, WhichInstance, CurrentObject);
FightSingleObjectSingleInstanceLogicInitiate(WhichObject, WhichInstance);
}

FightData->ObjectData[WhichObject].Loadable = realloc(FightData->ObjectData[WhichObject].Loadable, FinalBufferSize);
}


}