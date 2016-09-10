uint8 ActualFight(pvr_ptr_t* StolarTexture, StolarFightStruct* StolarFightData, FightLocationStruct* FightLocationData, EnemyFightStruct* EnemyFightData, uint8 EnemyAmount, GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, AbilityFightStruct* AbilityFightData, FloatingValueStruct* FloatingValueData){

maple_device_t *cont;
cont_state_t *st;

TransformationStruct TransformationData;

uint8 AnimationFlags;
uint8 ReturnValue;
uint8 ButtonStatus[ButtonAmount];
uint8 DirtyDeedsDoneDirtCheap;

TransformationData.Active = 0;
AnimationFlags = 0xFF;

ReturnValue = 0;
while(!ReturnValue){

//-------------------------------------------------------------------

pvr_wait_ready();
pvr_scene_begin();

pvr_list_begin(PVR_LIST_TR_POLY);

DrawFightBackGround(FightLocationData, &TransformationData);
DrawStolar(StolarTexture[StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureOffset+StolarFightData->CurrentFrame], StolarFightData->PositionX, StolarFightData->PositionY, StolarFightData->ScreenPositionZ, StolarFightData->SizeX, StolarFightData->SizeY, &TransformationData);
DrawFightEnemies(EnemyFightData, EnemyAmount, &TransformationData);
DrawFightHealth(StolarFightData, GraphicalUserInterFaceData, &TransformationData);
DrawFightAbilities(GraphicalUserInterFaceData, &TransformationData);
DrawFloatingValues(FloatingValueData, &TransformationData);

//-------------------------------------------------------------------

if((cont = maple_enum_dev(0, 0)) == NULL){
ReturnValue = FightPauseEverything;
SetControllerToDummy(st);
} 
else st = (cont_state_t *)maple_dev_status(cont);

//-------------------------------------------------------------------

FightAnimate(StolarFightData, EnemyFightData, EnemyAmount, FightLocationData, AnimationFlags);

//-------------------------------------------------------------------

(*AbilityFunction[RedAbilityIdentifier])
(st, CONT_A, &ButtonStatus[ButtonA], StolarFightData, EnemyFightData, EnemyAmount, FightLocationData, GraphicalUserInterFaceData, &AnimationFlags, FloatingValueData);

(*AbilityFunction[StolarFightData->StolarData->Ability[BlueAbility]])
(st, CONT_B, &ButtonStatus[ButtonB], StolarFightData, EnemyFightData, EnemyAmount, FightLocationData, GraphicalUserInterFaceData, &AnimationFlags, FloatingValueData);

(*AbilityFunction[StolarFightData->StolarData->Ability[YellowAbility]])
(st, CONT_X, &ButtonStatus[ButtonX], StolarFightData, EnemyFightData, EnemyAmount, FightLocationData, GraphicalUserInterFaceData, &AnimationFlags, FloatingValueData);

(*AbilityFunction[StolarFightData->StolarData->Ability[GreenAbility]])
(st, CONT_Y, &ButtonStatus[ButtonY], StolarFightData, EnemyFightData, EnemyAmount, FightLocationData, GraphicalUserInterFaceData, &AnimationFlags, FloatingValueData);

//-------------------------------------------------------------------

if((st->buttons & CONT_DPAD_LEFT)){
if(StolarFightData->CurrentAnimation == StolarIdleAnimationRight+StolarFightData->FaceDirection || StolarFightData->CurrentAnimation == StolarRunningAnimation+StolarFightData->FaceDirection){
if(StolarFightData->FaceDirection == FightFaceRight){

StolarFightData->CurrentAnimation = StolarTurnAroundAnimation+StolarFightData->FaceDirection;
StolarFightData->CurrentFrame = 0;
StolarFightData->AnimationTicks = 0;

StolarFightData->FaceDirection = FightFaceLeft;
}
else{
if(StolarFightData->CurrentAnimation == StolarIdleAnimationRight+StolarFightData->FaceDirection){
StolarFightData->CurrentAnimation = StolarRunningAnimation+StolarFightData->FaceDirection;
StolarFightData->CurrentFrame = 0;
StolarFightData->AnimationTicks = 0;
}

StolarFightData->PositionX -= FightLocationData->LocationData.StolarSpeedX;
if(StolarFightData->PositionX < ScreenShakingThreshold) StolarFightData->PositionX = ScreenShakingThreshold;
}
}
}
else if((st->buttons & CONT_DPAD_RIGHT)){
if(StolarFightData->CurrentAnimation == StolarIdleAnimationRight+StolarFightData->FaceDirection || StolarFightData->CurrentAnimation == StolarRunningAnimation+StolarFightData->FaceDirection){
if(StolarFightData->FaceDirection == FightFaceLeft){

StolarChangeAnimationSimplest(StolarTurnAroundAnimation);
StolarFightData->FaceDirection = FightFaceRight;
}
else{
if(StolarFightData->CurrentAnimation == StolarIdleAnimationRight+StolarFightData->FaceDirection){
StolarChangeAnimationSimplest(StolarRunningAnimation);
}

StolarFightData->PositionX += FightLocationData->LocationData.StolarSpeedX;
if(StolarFightData->PositionX >= (FightLocationData->LocationData.StageSizeX-ScreenShakingThreshold)-StolarFightData->SizeX) StolarFightData->PositionX = (FightLocationData->LocationData.StageSizeX-ScreenShakingThreshold)-StolarFightData->SizeX;
}
}
}

if((st->buttons & CONT_DPAD_DOWN)){
if(StolarFightData->CurrentAnimation == StolarIdleAnimationRight+StolarFightData->FaceDirection || StolarFightData->CurrentAnimation == StolarRunningAnimation+StolarFightData->FaceDirection){

if(StolarFightData->CurrentAnimation == StolarIdleAnimationRight+StolarFightData->FaceDirection){
StolarFightData->CurrentAnimation = StolarRunningAnimation+StolarFightData->FaceDirection;
StolarFightData->CurrentFrame = 0;
StolarFightData->AnimationTicks = 0;
}

if(StolarFightData->StagePositionZ+FightLocationData->LocationData.StolarStageSpeedZ < FightLocationData->LocationData.StageSizeMaxZ){
StolarFightData->PositionY+=FightLocationData->LocationData.StolarStageSpeedZ*FightLocationData->LocationData.StolarSpeedY;
StolarFightData->ScreenPositionZ+=FightLocationData->LocationData.StolarStageSpeedZ*FightLocationData->LocationData.StolarScreenSpeedZ;
StolarFightData->StagePositionZ+=FightLocationData->LocationData.StolarStageSpeedZ;
}
else{
StolarFightData->PositionY+=(FightLocationData->LocationData.StageSizeMaxZ-StolarFightData->StagePositionZ)*FightLocationData->LocationData.StolarSpeedY;
StolarFightData->ScreenPositionZ+=(FightLocationData->LocationData.StageSizeMaxZ-StolarFightData->StagePositionZ)*FightLocationData->LocationData.StolarScreenSpeedZ;
StolarFightData->StagePositionZ=FightLocationData->LocationData.StageSizeMaxZ;
}
}
}
else if((st->buttons & CONT_DPAD_UP)){
if(StolarFightData->CurrentAnimation == StolarIdleAnimationRight+StolarFightData->FaceDirection || StolarFightData->CurrentAnimation == StolarRunningAnimation+StolarFightData->FaceDirection){

if(StolarFightData->CurrentAnimation == StolarIdleAnimationRight+StolarFightData->FaceDirection){
StolarFightData->CurrentAnimation = StolarRunningAnimation+StolarFightData->FaceDirection;
StolarFightData->CurrentFrame = 0;
StolarFightData->AnimationTicks = 0;
}

if(StolarFightData->StagePositionZ-FightLocationData->LocationData.StolarStageSpeedZ >= FightLocationData->LocationData.StageSizeMinZ){
StolarFightData->PositionY-=FightLocationData->LocationData.StolarStageSpeedZ*FightLocationData->LocationData.StolarSpeedY;
StolarFightData->ScreenPositionZ-=FightLocationData->LocationData.StolarStageSpeedZ*FightLocationData->LocationData.StolarScreenSpeedZ;
StolarFightData->StagePositionZ-=FightLocationData->LocationData.StolarStageSpeedZ;
}
else{
StolarFightData->PositionY-=(StolarFightData->StagePositionZ-FightLocationData->LocationData.StageSizeMinZ)*FightLocationData->LocationData.StolarSpeedY;
StolarFightData->ScreenPositionZ-=(StolarFightData->StagePositionZ-FightLocationData->LocationData.StageSizeMinZ)*FightLocationData->LocationData.StolarScreenSpeedZ;
StolarFightData->StagePositionZ=FightLocationData->LocationData.StageSizeMinZ;
}
}
}

if ((st->buttons & (StairWayToHeaven)) == (StairWayToHeaven)) ReturnValue |= StairWayToHeavenIdentifier;

if((st->buttons & CONT_START) && ButtonStatus[ButtonStart] && !ReturnValue){
ReturnValue = FightPauseEverything;
ButtonStatus[ButtonStart] = 0;
}
else if(!(st->buttons & CONT_START) && !ButtonStatus[ButtonStart]) ButtonStatus[ButtonStart] = 1;

//-------------------------------------------------------------------

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EnemyAmount; DirtyDeedsDoneDirtCheap++){

(*ComputeArtificialIntelligence[EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.ArtificialIntelligence])
(DirtyDeedsDoneDirtCheap, StolarFightData, EnemyFightData, EnemyAmount, FightLocationData, GraphicalUserInterFaceData, &AnimationFlags, FloatingValueData);
}

//-------------------------------------------------------------------

WhyDidTheyProgramMeToFeelPain(StolarFightData, StolarTexture, EnemyFightData, EnemyAmount, FightLocationData, FloatingValueData, &TransformationData, &ReturnValue, ButtonStatus);

//-------------------------------------------------------------------

pvr_list_finish();
pvr_scene_finish();

//-------------------------------------------------------------------

if(ReturnValue == FightPauseEverything){
if((ReturnValue = FightPause(GraphicalUserInterFaceData)) == BoringStage) ReturnValue = 0;
}

//-------------------------------------------------------------------

}

return(ReturnValue);
}