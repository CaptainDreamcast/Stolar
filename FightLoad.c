
#define FightLogicGeneralInitiate()	{ \
FightData->LogicData.General.LoopFight = LogicActive; \
 \
FightData->LogicData.General.ObjectAmount = FightData->Loadable.Stage->General.ObjectAmount+FightData->Loadable.Enemies->General.EnemyObjectAmount+OverWorldData->LogicData.General.CrewSize; \
 \
InitiateTransformationData((&FightData->LogicData.General.TransformationData)); \
}


#define FightLogicStageInitiate()	{ \
FightData->LogicData.Stage.StagePositionX = FightData->Loadable.Stage->BackGround.StartStagePositionX; \
FightData->LogicData.Stage.StagePositionY = FightData->Loadable.Stage->BackGround.StartStagePositionY; \
}

#define FightLogicBackGroundInitiate()	{ \
InitiateTransformationData((&FightData->LogicData.BackGround.GeneralTransformationData)); \
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



#define FightBackGroundObjectLogicInitiate(WhichObject)		{ \
 \
}

#define FightBackGroundObjectInstanceLogicInitiate(WhichObject, WhichInstance)		{ \
 \
FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.Active = LogicActive; \
FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.Animate = LogicActive; \
FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.Draw = LogicActive; \
 \
FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.CurrentAnimation = FightBackGroundInstanceAnimationValue; \
FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.Ticks = NewTicksStandardValue; \
 \
InitiateTransformationData((&FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.TransformationData)); \
}

#define FightSingleObjectLogicInitiate(WhichObject)	{ \
 \
FightData->ObjectData[WhichObject].LogicData.WhichObject = WhichObject; \
 \
}

#define FightSingleObjectSingleInstanceLogicInitiate(WhichObject, WhichInstance, HealthMax)	{ \
 \
FightData->ObjectData[WhichObject].Instance[WhichInstance].Object = &FightData->ObjectData[WhichObject]; \
 \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SemaphoreDraw = LogicActiveNot; \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SemaphoreAnimate = LogicActiveNot; \
 \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Health = HealthMax; \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Damage = NewDamageStandardValue; \
 \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Ticks = NewTicksStandardValue; \
 \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.WhichInstance = WhichInstance; \
 \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX = PhysicsVelocityNot; \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityY = PhysicsVelocityNot; \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ = PhysicsVelocityNot; \
 \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationX = PhysicsAccelerationNot; \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationY = PhysicsAccelerationNot; \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationZ = PhysicsAccelerationNot; \
 \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ForceX = PhysicsForceNot; \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ForceY = PhysicsForceNot; \
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ForceZ = PhysicsForceNot; \
 \
InitiateTransformationData((&FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.TransformationData)); \
}

#define FightCrewAbilityLogicInitiate(WhichCrewMember, WhichAbility)	{ \
FightData->CrewData[WhichCrewMember].AbilityData[WhichAbility].LogicData.Active = LogicActiveNot; \
FightData->CrewData[WhichCrewMember].AbilityData[WhichAbility].LogicData.ActiveLast = LogicActive; \
 \
FightData->CrewData[WhichCrewMember].AbilityData[WhichAbility].LogicData.Red = DummyValueInteger; \
FightData->CrewData[WhichCrewMember].AbilityData[WhichAbility].LogicData.Green = DummyValueInteger; \
FightData->CrewData[WhichCrewMember].AbilityData[WhichAbility].LogicData.Blue = DummyValueInteger; \
 \
FightData->CrewData[WhichCrewMember].AbilityData[WhichAbility].LogicData.FilledNow = NewAbilityFilledNowStandardValue; \
FightData->CrewData[WhichCrewMember].AbilityData[WhichAbility].LogicData.FilledLast = NewAbilityFilledNowStandardValue+1; \
}

#define FightCrewAbilityLogicGaugeColorInitiate(WhichCrewMember, WhichAbility, RedValue, GreenValue, BlueValue)	{ \
FightData->CrewData[WhichCrewMember].AbilityData[WhichAbility].LogicData.Red = RedValue; \
FightData->CrewData[WhichCrewMember].AbilityData[WhichAbility].LogicData.Green = GreenValue; \
FightData->CrewData[WhichCrewMember].AbilityData[WhichAbility].LogicData.Blue = BlueValue; \
}

#define FightPlayerLogicGeneralInitiate(WhichPlayer)	{ \
FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject = DummyValueInteger; \
FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance = DummyValueInteger; \
}

#define FightPlayerLogicInitiate(WhichPlayer)	{ \
FightPlayerLogicGeneralInitiate(WhichPlayer); \
}

void FightLoad(FightStruct* FightData, OverWorldStruct* OverWorldData){

char FileDir[NormalFileDirSize];
uint32 CurrentPointerPosition, CurrentPointerPositionStage;
uint32 FinalBufferSize, FinalBufferSizePassable;
uint8 WhichObject, WhichInstance, CurrentObject, WhichPlayer;
FightEnemyGivenStruct* FightEnemyGivenData;
FightObjectClassStruct* CurrentClass;

FightLoadSequence();

FightData->OverWorldData = OverWorldData;

//
sprintf(FileDir, "%s/TEST.fgt.gz", FileSystemUsed);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/TEST.fgt.gz");
CompressedFileToBuffer(FileDir, &OverWorldData->LogicData.Passable);
//

CurrentPointerPosition = ((uint32)OverWorldData->LogicData.Passable);

LoadSetThisToThatPointer(FightLoadableGivenStruct*, FightData->Loadable.Given, sizeof(FightLoadableGivenStruct));
LoadSetThisToThatPointer(FightLoadableEnemiesStruct*, FightData->Loadable.Enemies, sizeof(FightLoadableEnemiesStruct));
FinalBufferSizePassable = CurrentPointerPosition-((uint32)OverWorldData->LogicData.Passable);
LoadSetThisToThatPointer(FightEnemyGivenStruct*, FightEnemyGivenData, (sizeof(FightEnemyGivenStruct)*FightData->Loadable.Enemies->General.EnemyAmount));


sprintf(FileDir, "%s/STAGES/%d.stg.gz", FileSystemUsed, FightData->Loadable.Given->WhichStage);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/%d.stg.gz", FightData->Loadable.Given->WhichStage);
CompressedFileToBuffer(FileDir, (void**)(&FightData->Loadable.Stage));
CurrentPointerPosition = ((uint32)FightData->Loadable.Stage)+sizeof(FightLoadableStageStruct);

FightLogicInitiate();

FightData->BackGroundData = (FightBackGroundStruct*)malloc(sizeof(FightBackGroundStruct)*FightData->Loadable.Stage->General.BackGroundObjectAmount);
for(WhichObject = 0; WhichObject< FightData->Loadable.Stage->General.BackGroundObjectAmount; WhichObject++){
LoadSetThisToThatPointer(FightBackGroundLoadableStruct*, FightData->BackGroundData[WhichObject].Loadable, sizeof(FightBackGroundLoadableStruct));
FightBackGroundObjectLogicInitiate(WhichObject);

FightData->BackGroundData[WhichObject].Instance = (FightBackGroundInstanceStruct*)malloc(sizeof(FightBackGroundInstanceStruct)*FightData->BackGroundData[WhichObject].Loadable->InstanceAmount);
for(WhichInstance = 0; WhichInstance < FightData->BackGroundData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
LoadSetThisToThatPointer(FightBackGroundInstanceLoadableStruct*, FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable, sizeof(FightBackGroundInstanceLoadableStruct));
FightBackGroundObjectInstanceLogicInitiate(WhichObject, WhichInstance);
}
}

CurrentPointerPositionStage = CurrentPointerPosition;



FightData->PlayerData = (FightPlayerStruct*)malloc(sizeof(FightPlayerStruct)*OverWorldData->LogicData.General.PlayerAmount);
for(WhichObject=0; WhichObject < OverWorldData->LogicData.General.PlayerAmount; WhichObject++){
FightPlayerLogicInitiate(WhichObject);

for(WhichInstance = 0; WhichInstance < AbilityAmount; WhichInstance++){
if(WhichInstance != AbilityRed){
FightData->PlayerData[WhichObject].AbilityData[WhichInstance].TextureData.Gauge = pvr_mem_malloc(TextureTypeMultiplierDispatch(PVR_TXRFMT_PAL4BPP)*OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeX*OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeY);
}
}
}

WhichObject = 0;
if(FightData->LogicData.General.ObjectAmount > 0) FightData->ObjectData = (FightObjectStruct*)malloc(sizeof(FightObjectStruct)*FightData->LogicData.General.ObjectAmount);
CurrentClass = NULL;

FightData->CrewData = (FightCrewStruct*)malloc(sizeof(FightCrewStruct)*OverWorldData->LogicData.General.CrewSize);
if(OverWorldData->LogicData.General.CrewSize > 0){
CurrentClass = FightLoadClassCreate();
}
for(CurrentObject=0; CurrentObject < OverWorldData->LogicData.General.CrewSize; CurrentObject++){
FightData->ObjectData[WhichObject].Loadable = FightLoadObjectCreateLoadableCrew(FightData, CurrentObject);
FightData->ObjectData[WhichObject].ClassData = CurrentClass;
FightData->ObjectData[WhichObject].Texture = OverWorldData->CrewData[CurrentObject].Texture;
FightData->ObjectData[WhichObject].FluxData.AnimationData = OverWorldData->CrewData[CurrentObject].FluxData.AnimationData;
FightSingleObjectLogicInitiate(WhichObject);

if(FightData->ObjectData[WhichObject].Loadable->InstanceAmount > 0) FightData->ObjectData[WhichObject].Instance = (FightObjectInstanceStruct*)malloc(sizeof(FightObjectInstanceStruct)*FightData->ObjectData[WhichObject].Loadable->InstanceAmount);
for(WhichInstance=0; WhichInstance<FightData->ObjectData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
if(CrewIsPlayer(FightData->OverWorldData, CurrentObject)){
FightLoadObjectInstanceCreateLoadablePlayer(FightData, WhichObject, WhichInstance, CurrentObject);
CurrentPointerPosition = FightLoadObjectInstanceCreateFluxDataPlayer(FightData, CurrentPointerPosition, WhichObject, WhichInstance, CurrentObject);

WhichPlayer = CrewIsPlayerValueGet(FightData->OverWorldData, CurrentObject);
FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject = WhichObject;
FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance = WhichInstance;
}
else{
FightLoadObjectInstanceCreateLoadableCrew(FightData, WhichObject, WhichInstance, CurrentObject);
FightLoadObjectInstanceCreateFluxDataCrew(FightData, WhichObject, WhichInstance, CurrentObject);
}
FightSingleObjectSingleInstanceLogicInitiate(WhichObject, WhichInstance, OverWorldData->CrewData[CurrentObject].LogicData.Fight.HealthMax);
}

for(WhichInstance = AbilityRed; WhichInstance < AbilityAmount; WhichInstance++){
FightData->CrewData[CurrentObject].AbilityData[WhichInstance].FluxData.Buffer = (*AbilityLoadFunction[OverWorldData->CrewData[CurrentObject].FluxData.Abilities[WhichInstance].AbilityData->FunctionIndex])(FightData, OverWorldData, &OverWorldData->CrewData[CurrentObject].FluxData.Abilities[WhichInstance]);
FightCrewAbilityLogicInitiate(CurrentObject, WhichInstance);
}
FightCrewAbilityLogicGaugeColorInitiate(CurrentObject, AbilityYellow, MaximumByteValue, MaximumByteValue, MinimumByteValue);
FightCrewAbilityLogicGaugeColorInitiate(CurrentObject, AbilityGreen, MinimumByteValue, MaximumByteValue, MinimumByteValue);
FightCrewAbilityLogicGaugeColorInitiate(CurrentObject, AbilityBlue, MinimumByteValue, MinimumByteValue, MaximumByteValue);

WhichObject++;
}



FightData->LogicData.Enemies.General.ObjectStart = WhichObject;
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

FightData->ObjectData[WhichObject].Texture = (pvr_ptr_t*)malloc(sizeof(pvr_ptr_t)*FightData->ObjectData[WhichObject].Loadable->TextureAmount);
for(WhichInstance = 0; WhichInstance < FightData->ObjectData[WhichObject].Loadable->TextureAmount; WhichInstance++){
LoadTextureFromBufferPointer(CurrentPointerPosition, FightData->ObjectData[WhichObject].Texture[WhichInstance]);
}

if(FightData->ObjectData[WhichObject].Loadable->InstanceAmount > 0) FightData->ObjectData[WhichObject].Instance = (FightObjectInstanceStruct*)malloc(sizeof(FightObjectInstanceStruct)*FightData->ObjectData[WhichObject].Loadable->InstanceAmount);
for(WhichInstance = 0; WhichInstance < FightData->ObjectData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
CurrentPointerPosition = FightLoadObjectInstanceCreateLoadableEnemy(FightData, FightEnemyGivenData, CurrentPointerPosition, WhichObject, WhichInstance, CurrentObject);
CurrentPointerPosition = FightLoadObjectInstanceCreateFluxDataEnemy(FightData, FightEnemyGivenData, CurrentPointerPosition, WhichObject, WhichInstance, CurrentObject);
FightSingleObjectSingleInstanceLogicInitiate(WhichObject, WhichInstance, FightEnemyGivenData[CurrentObject].HealthMax);
}


FightData->ObjectData[WhichObject].Loadable = realloc(FightData->ObjectData[WhichObject].Loadable, FinalBufferSize);
WhichObject++;
}
FightData->LogicData.Enemies.General.ObjectEnd = WhichObject;



CurrentPointerPosition = CurrentPointerPositionStage;

FightData->LogicData.Objects.General.ObjectStart = WhichObject;
if(FightData->Loadable.Stage->General.ObjectAmount > 0){
CurrentClass = FightLoadClassCreate();
}
for(CurrentObject=0; CurrentObject<FightData->Loadable.Stage->General.ObjectAmount; CurrentObject++){
LoadSetThisToThatPointer(FightObjectLoadableStruct*, FightData->ObjectData[WhichObject].Loadable, sizeof(FightObjectLoadableStruct));
LoadSetThisToThatPointer(AnimationStruct*, FightData->ObjectData[WhichObject].FluxData.AnimationData, sizeof(AnimationStruct)*FightData->ObjectData[WhichObject].Loadable->AnimationAmount);
FightData->ObjectData[WhichObject].ClassData = CurrentClass;
FightSingleObjectLogicInitiate(WhichObject);

if(FightData->ObjectData[WhichObject].Loadable->InstanceAmount > 0) FightData->ObjectData[WhichObject].Instance = (FightObjectInstanceStruct*)malloc(sizeof(FightObjectInstanceStruct)*FightData->ObjectData[WhichObject].Loadable->InstanceAmount);
for(WhichInstance = 0; WhichInstance < FightData->ObjectData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
LoadSetThisToThatPointer(FightObjectInstanceLoadableStruct*, FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable, sizeof(FightObjectInstanceLoadableStruct));
CurrentPointerPosition = FightLoadObjectInstanceCreateFluxDataObject(FightData, CurrentPointerPosition, WhichObject, WhichInstance, CurrentObject);
FightSingleObjectSingleInstanceLogicInitiate(WhichObject, WhichInstance, DummyValueInteger);
}

WhichObject++;
}
FightData->LogicData.Objects.General.ObjectEnd = WhichObject;


FinalBufferSize = CurrentPointerPosition-((uint32)FightData->Loadable.Stage);

for(WhichObject = 0; WhichObject < FightData->Loadable.Stage->General.BackGroundObjectAmount; WhichObject++){
FightData->BackGroundData[WhichObject].Texture = (pvr_ptr_t*)malloc(sizeof(pvr_ptr_t)*FightData->BackGroundData[WhichObject].Loadable->FrameAmount);
for(WhichInstance = 0; WhichInstance < FightData->BackGroundData[WhichObject].Loadable->FrameAmount; WhichInstance++){
LoadTextureFromBufferPointer(CurrentPointerPosition, FightData->BackGroundData[WhichObject].Texture[WhichInstance]);
}
}

WhichObject = FightData->LogicData.Objects.General.ObjectStart;
for(CurrentObject=0; CurrentObject<FightData->Loadable.Stage->General.ObjectAmount; CurrentObject++){

if(FightData->ObjectData[WhichObject].Loadable->TextureAmount > 0) FightData->ObjectData[WhichObject].Texture = (pvr_ptr_t*)malloc(sizeof(pvr_ptr_t)*FightData->ObjectData[WhichObject].Loadable->TextureAmount);
for(WhichInstance = 0; WhichInstance < FightData->ObjectData[WhichObject].Loadable->TextureAmount; WhichInstance++){
LoadTextureFromBufferPointer(CurrentPointerPosition, FightData->ObjectData[WhichObject].Texture[WhichInstance]);
}

WhichObject++;
}


FightData->Loadable.Stage = realloc(FightData->Loadable.Stage, FinalBufferSize);


OverWorldData->LogicData.Passable = realloc(OverWorldData->LogicData.Passable, FinalBufferSizePassable);
}