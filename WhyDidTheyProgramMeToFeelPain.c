void WhyDidTheyProgramMeToFeelPain(StolarFightStruct* StolarFightData, pvr_ptr_t* StolarTexture, EnemyFightStruct* EnemyFightData, uint8 EnemyAmount, FightLocationStruct* FightLocationData, FloatingValueStruct* FloatingValueData, TransformationStruct* TransformationData, uint8* ReturnValue, uint8* ButtonStatus){

uint8 DirtyDeedsDoneDirtCheap;

if(StolarFightData->SpecialEvent == StolarYouAreAlreadyDead){

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<ButtonAmount; DirtyDeedsDoneDirtCheap++) ButtonStatus[DirtyDeedsDoneDirtCheap] = 0;

if(DoGameOverFancyStuff(StolarTexture, StolarFightData, TransformationData)){
*ReturnValue |= StolarIsMoreThanDead;
}

}

//---------------------------------------------------------------------------------

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<EnemyAmount; DirtyDeedsDoneDirtCheap++){
if(StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].Active){

if(EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentAnimation != StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].ReactionAnimation || EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentFrame != StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].ReactionFrame){

if(StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].DamagePending < StolarFightData->StolarData->Defense) StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].DamagePending -= StolarFightData->StolarData->Defense;
else StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].DamagePending = 0;

StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].ReactionAnimation = EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentAnimation;
StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].ReactionFrame = EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentFrame;

if(StolarFightData->StoredUpVelocityX == 0 && StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].DamagePending != 0){
if(EnemyFightData[DirtyDeedsDoneDirtCheap].FaceDirection == StolarFightData->FaceDirection){StolarChangeAnimationSimplest(StolarGettingHitFromBehindAnimation);}
else{StolarChangeAnimationSimplest(StolarGettingHitFromFrontAnimation);}
}

if(StolarFightData->StolarData->HealthNow-StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].DamagePending > 0){
StolarFightData->StolarData->HealthNow -= StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].DamagePending;
}
else{
StolarFightData->StolarData->HealthNow = 0;
StolarFightData->SpecialEvent = StolarYouAreAlreadyDead;
StolarFightData->SpecialEventTicks = 0;
StolarFightData->AnimationFactor = 0.0f;
StolarFightData->FactorBuildUp = StolarDeathSlowness;
StolarChangeAnimationSimplest(StolarDeathAnimation);

SetSingleVector(TransformationData->PositionVector, StolarFightData->PositionX+(StolarFightData->SizeX/2), StolarFightData->PositionY+(StolarFightData->SizeY/2), StolarPositionZ);
StartZooming(1.0f)
StartRotationZ(0.0f);



}

AddFloatingDamageValue(FloatingValueData, StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].DamagePending, StolarFightData->PositionX, StolarFightData->PositionY);
}

StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].Active = 0;
StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].DamagePending = 0;
}
else{
StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].ReactionAnimation = 0;
StolarFightData->TakingDamageData[DirtyDeedsDoneDirtCheap].ReactionFrame = 0;
}
}

//---------------------------------------------------------------------------------

if(StolarFightData->StoredUpVelocityX != 0){

StolarFightData->PositionX += StolarFightData->StoredUpVelocityX;

if(StolarFightData->StoredUpVelocityX > 0){

if(StolarFightData->FaceDirection == FightFaceRight && StolarFightData->CurrentAnimation != StolarGettingHitFromBehindAnimation+StolarFightData->FaceDirection){
StolarFightData->CurrentAnimation = StolarGettingHitFromBehindAnimation+StolarFightData->FaceDirection;
StolarFightData->CurrentFrame = StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureAmount;
StolarFightData->AnimationTicks = 0;
}
else if(StolarFightData->FaceDirection == FightFaceLeft && StolarFightData->CurrentAnimation != StolarGettingHitFromFrontAnimation+StolarFightData->FaceDirection){
StolarFightData->CurrentAnimation = StolarGettingHitFromFrontAnimation+StolarFightData->FaceDirection;
StolarFightData->CurrentFrame = StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureAmount;
StolarFightData->AnimationTicks = 0;
}

StolarFightData->StoredUpVelocityX -= FightLocationData->LocationData.AirResistance*StolarAirFrictionFactor;
if(StolarFightData->StoredUpVelocityX < 0) StolarFightData->StoredUpVelocityX = 0;
if(StolarFightData->PositionX >= FightLocationData->LocationData.StageSizeX){
StolarFightData->StoredUpVelocityX *= -(1/2);
StolarFightData->PositionX = FightLocationData->LocationData.StageSizeX;
}
}
else{

if(StolarFightData->FaceDirection == FightFaceLeft && StolarFightData->CurrentAnimation != StolarGettingHitFromBehindAnimation+StolarFightData->FaceDirection){
StolarFightData->CurrentAnimation = StolarGettingHitFromBehindAnimation+StolarFightData->FaceDirection;
StolarFightData->CurrentFrame = StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureAmount;
StolarFightData->AnimationTicks = 0;
}
else if(StolarFightData->FaceDirection == FightFaceRight && StolarFightData->CurrentAnimation != StolarGettingHitFromFrontAnimation+StolarFightData->FaceDirection){
StolarFightData->CurrentAnimation = StolarGettingHitFromFrontAnimation+StolarFightData->FaceDirection;
StolarFightData->CurrentFrame = StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureAmount;
StolarFightData->AnimationTicks = 0;
}

StolarFightData->StoredUpVelocityX += FightLocationData->LocationData.AirResistance*StolarAirFrictionFactor;
if(StolarFightData->StoredUpVelocityX > 0) StolarFightData->StoredUpVelocityX = 0;
if(StolarFightData->PositionX <= 0){
StolarFightData->StoredUpVelocityX *= -(1/2);
StolarFightData->PositionX = 0;
}
}
}


if(StolarFightData->StoredUpVelocityY != 0){

if(StolarFightData->StoredUpVelocityX == 0){
if(StolarFightData->StoredUpVelocityX <= 0 && StolarFightData->CurrentAnimation != StolarNormalAscendAnimation+StolarFightData->FaceDirection){StolarChangeAnimationSimplest(StolarNormalAscendAnimation);}
else if(StolarFightData->StoredUpVelocityX > 0 && StolarFightData->CurrentAnimation != StolarNormalFallAnimation+StolarFightData->FaceDirection){StolarChangeAnimationSimplest(StolarNormalFallAnimation);}
}

StolarFightData->PositionY += StolarFightData->StoredUpVelocityY;
StolarFightData->StoredUpVelocityY -= FightLocationData->LocationData.Gravity*StolarWeightFactor;
if(StolarFightData->PositionY >= FightLocationData->LocationData.StolarStartPositionY+((StolarFightData->StagePositionZ-FightLocationData->LocationData.StolarStartStagePositionZ)*FightLocationData->LocationData.StolarSpeedY)){
StolarFightData->PositionY = FightLocationData->LocationData.StolarStartPositionY+((StolarFightData->StagePositionZ-FightLocationData->LocationData.StolarStartStagePositionZ)*FightLocationData->LocationData.StolarSpeedY);
StolarFightData->StoredUpVelocityY = 0;
}
else if(StolarFightData->StoredUpVelocityY == 0) StolarFightData->StoredUpVelocityY = 0.0001f;

}



//---------------------------------------------------------------------------------

if(StolarFightData->StoredUpVelocityZ != 0){

StolarFightData->StagePositionZ += StolarFightData->StoredUpVelocityZ;
StolarFightData->PositionY+=StolarFightData->StoredUpVelocityZ*FightLocationData->LocationData.StolarSpeedY;
StolarFightData->ScreenPositionZ+=StolarFightData->StoredUpVelocityZ*FightLocationData->LocationData.StolarScreenSpeedZ;


if(StolarFightData->StoredUpVelocityZ > 0){

if(StolarFightData->StoredUpVelocityX == 0){
if(StolarFightData->FaceDirection == FightFaceRight && StolarFightData->CurrentAnimation != StolarGettingHitFromBehindAnimation+StolarFightData->FaceDirection){StolarChangeAnimationAdvanced(StolarGettingHitFromBehindAnimation, StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureAmount);}
else if(StolarFightData->FaceDirection == FightFaceLeft && StolarFightData->CurrentAnimation != StolarGettingHitFromFrontAnimation+StolarFightData->FaceDirection){StolarChangeAnimationAdvanced(StolarGettingHitFromFrontAnimation, StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureAmount);}
}

StolarFightData->StoredUpVelocityZ -= FightLocationData->LocationData.AirResistance*StolarAirFrictionFactor;
if(StolarFightData->StoredUpVelocityZ < 0) StolarFightData->StoredUpVelocityZ = 0;
if(StolarFightData->StagePositionZ >= FightLocationData->LocationData.StageSizeMaxZ){
StolarFightData->StoredUpVelocityZ *= -(1/2);

StolarFightData->PositionY-=(StolarFightData->StagePositionZ-FightLocationData->LocationData.StageSizeMaxZ)*FightLocationData->LocationData.StolarSpeedY;
StolarFightData->ScreenPositionZ-=(StolarFightData->StagePositionZ-FightLocationData->LocationData.StageSizeMaxZ)*FightLocationData->LocationData.StolarScreenSpeedZ;
StolarFightData->StagePositionZ = FightLocationData->LocationData.StageSizeMaxZ;
}
}
else{

if(StolarFightData->StoredUpVelocityX == 0){
if(StolarFightData->FaceDirection == FightFaceLeft && StolarFightData->CurrentAnimation != StolarGettingHitFromBehindAnimation+StolarFightData->FaceDirection){StolarChangeAnimationAdvanced(StolarGettingHitFromBehindAnimation, StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureAmount);}
else if(StolarFightData->FaceDirection == FightFaceRight && StolarFightData->CurrentAnimation != StolarGettingHitFromFrontAnimation+StolarFightData->FaceDirection){StolarChangeAnimationAdvanced(StolarGettingHitFromFrontAnimation, StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureAmount);}
}

StolarFightData->StoredUpVelocityZ += FightLocationData->LocationData.AirResistance*StolarAirFrictionFactor;
if(StolarFightData->StoredUpVelocityZ > 0) StolarFightData->StoredUpVelocityZ = 0;
if(StolarFightData->StagePositionZ <= FightLocationData->LocationData.StageSizeMinZ){
StolarFightData->StoredUpVelocityZ *= -(1/2);

StolarFightData->PositionY+=(FightLocationData->LocationData.StageSizeMinZ-StolarFightData->StagePositionZ)*FightLocationData->LocationData.StolarSpeedY;
StolarFightData->ScreenPositionZ+=(FightLocationData->LocationData.StageSizeMinZ-StolarFightData->StagePositionZ)*FightLocationData->LocationData.StolarScreenSpeedZ;
StolarFightData->StagePositionZ = FightLocationData->LocationData.StageSizeMinZ;
}
}
}


}

