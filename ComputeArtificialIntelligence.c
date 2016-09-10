void DarkStolar(uint8 WhichEnemy, StolarFightStruct* StolarFightData, EnemyFightStruct* EnemyFightData, uint8 EnemyAmount, FightLocationStruct* FightLocationData, GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, uint8* AnimationFlags, FloatingValueStruct* FloatingValueData){

short MinimumEnemyX, MaximumEnemyX, MinimumEnemyY, MaximumEnemyY, MinimumEnemyZ, MaximumEnemyZ; 
short MinimumStolarX, MaximumStolarX, MinimumStolarY, MaximumStolarY, MinimumStolarZ, MaximumStolarZ; 

if(EnemyFightData[WhichEnemy].Active){

//---------------------------------------------------------------------------------

if(EnemyFightData[WhichEnemy].DamagePending != 0){

if(StolarFightData->CurrentAnimation != EnemyFightData[WhichEnemy].ReactionAnimation || StolarFightData->CurrentFrame != EnemyFightData[WhichEnemy].ReactionFrame){

if(EnemyFightData[WhichEnemy].DamagePending < EnemyFightData[WhichEnemy].EnemyData.Defense) EnemyFightData[WhichEnemy].DamagePending -= EnemyFightData[WhichEnemy].EnemyData.Defense;
else EnemyFightData[WhichEnemy].DamagePending = 0;

AddFloatingDamageValue(FloatingValueData, EnemyFightData[WhichEnemy].DamagePending, EnemyFightData[WhichEnemy].PositionX, EnemyFightData[WhichEnemy].PositionY);
}

EnemyFightData[WhichEnemy].DamagePending = 0;
}

//---------------------------------------------------------------------------------

if(StolarFightData->CurrentAnimation != EnemyFightData[WhichEnemy].ReactionAnimation || StolarFightData->CurrentFrame != EnemyFightData[WhichEnemy].ReactionFrame){

if(EnemyFightData[WhichEnemy].WhatIsHappeningHere == EnemyJustGotHit){
EnemyFightData[WhichEnemy].WhatIsHappeningHere = 0;

//Nothing happens, though. YOHOHOHO!

EnemyFightData[WhichEnemy].ReactionAnimation = StolarFightData->CurrentAnimation;
EnemyFightData[WhichEnemy].ReactionFrame = StolarFightData->CurrentFrame;
}
else{
EnemyFightData[WhichEnemy].ReactionAnimation = 0;
EnemyFightData[WhichEnemy].ReactionFrame = 0;
}

}

//---------------------------------------------------------------------------------

if(EnemyFightData[WhichEnemy].StoredUpVelocityX != 0){

EnemyFightData[WhichEnemy].PositionX += EnemyFightData[WhichEnemy].StoredUpVelocityX;

if(EnemyFightData[WhichEnemy].StoredUpVelocityX > 0){
EnemyFightData[WhichEnemy].StoredUpVelocityX -= FightLocationData->LocationData.AirResistance*StolarAirFrictionFactor;
if(EnemyFightData[WhichEnemy].StoredUpVelocityX < 0) EnemyFightData[WhichEnemy].StoredUpVelocityX = 0;
if(EnemyFightData[WhichEnemy].PositionX >= FightLocationData->LocationData.StageSizeX){
EnemyFightData[WhichEnemy].StoredUpVelocityX *= -(1/2);
EnemyFightData[WhichEnemy].PositionX = FightLocationData->LocationData.StageSizeX;
}
}
else{
EnemyFightData[WhichEnemy].StoredUpVelocityX += FightLocationData->LocationData.AirResistance*StolarAirFrictionFactor;
if(EnemyFightData[WhichEnemy].StoredUpVelocityX > 0) EnemyFightData[WhichEnemy].StoredUpVelocityX = 0;
if(EnemyFightData[WhichEnemy].PositionX <= 0){
EnemyFightData[WhichEnemy].StoredUpVelocityX *= -(1/2);
EnemyFightData[WhichEnemy].PositionX = 0;
}
}
}

//---------------------------------------------------------------------------------

if(EnemyFightData[WhichEnemy].StoredUpVelocityY != 0){

EnemyFightData[WhichEnemy].PositionY += EnemyFightData[WhichEnemy].StoredUpVelocityY;
EnemyFightData[WhichEnemy].StoredUpVelocityY -= FightLocationData->LocationData.Gravity*StolarWeightFactor;
if(EnemyFightData[WhichEnemy].PositionY+EnemyFightData[WhichEnemy].SizeY >= FightLocationData->LocationData.StolarStartPositionY+((EnemyFightData[WhichEnemy].StagePositionZ-FightLocationData->LocationData.StolarStartStagePositionZ)*FightLocationData->LocationData.StolarSpeedY)+StolarFightData->SizeY){
EnemyFightData[WhichEnemy].PositionY = -EnemyFightData[WhichEnemy].SizeY+FightLocationData->LocationData.StolarStartPositionY+((EnemyFightData[WhichEnemy].StagePositionZ-FightLocationData->LocationData.StolarStartStagePositionZ)*FightLocationData->LocationData.StolarSpeedY)+StolarFightData->SizeY;
EnemyFightData[WhichEnemy].StoredUpVelocityY = 0;
}
else if(EnemyFightData[WhichEnemy].StoredUpVelocityY == 0) EnemyFightData[WhichEnemy].StoredUpVelocityY = 0.0001f;

}

//---------------------------------------------------------------------------------

if(EnemyFightData[WhichEnemy].StoredUpVelocityZ != 0){

EnemyFightData[WhichEnemy].StagePositionZ += EnemyFightData[WhichEnemy].StoredUpVelocityZ;
EnemyFightData[WhichEnemy].PositionY+=EnemyFightData[WhichEnemy].StoredUpVelocityZ*FightLocationData->LocationData.StolarSpeedY;
EnemyFightData[WhichEnemy].ScreenPositionZ+=EnemyFightData[WhichEnemy].StoredUpVelocityZ*FightLocationData->LocationData.StolarScreenSpeedZ;


if(EnemyFightData[WhichEnemy].StoredUpVelocityZ > 0){
EnemyFightData[WhichEnemy].StoredUpVelocityZ -= FightLocationData->LocationData.AirResistance*StolarAirFrictionFactor;
if(EnemyFightData[WhichEnemy].StoredUpVelocityZ < 0) EnemyFightData[WhichEnemy].StoredUpVelocityZ = 0;
if(EnemyFightData[WhichEnemy].StagePositionZ >= FightLocationData->LocationData.StageSizeMaxZ){
EnemyFightData[WhichEnemy].StoredUpVelocityZ *= -(1/2);

EnemyFightData[WhichEnemy].PositionY-=(EnemyFightData[WhichEnemy].StagePositionZ-FightLocationData->LocationData.StageSizeMaxZ)*FightLocationData->LocationData.StolarSpeedY;
EnemyFightData[WhichEnemy].ScreenPositionZ-=(EnemyFightData[WhichEnemy].StagePositionZ-FightLocationData->LocationData.StageSizeMaxZ)*FightLocationData->LocationData.StolarScreenSpeedZ;
EnemyFightData[WhichEnemy].StagePositionZ = FightLocationData->LocationData.StageSizeMaxZ;
}
}
else{
EnemyFightData[WhichEnemy].StoredUpVelocityZ += FightLocationData->LocationData.AirResistance*StolarAirFrictionFactor;
if(EnemyFightData[WhichEnemy].StoredUpVelocityZ > 0) EnemyFightData[WhichEnemy].StoredUpVelocityZ = 0;
if(EnemyFightData[WhichEnemy].StagePositionZ <= FightLocationData->LocationData.StageSizeMinZ){
EnemyFightData[WhichEnemy].StoredUpVelocityZ *= -(1/2);

EnemyFightData[WhichEnemy].PositionY+=(FightLocationData->LocationData.StageSizeMinZ-EnemyFightData[WhichEnemy].StagePositionZ)*FightLocationData->LocationData.StolarSpeedY;
EnemyFightData[WhichEnemy].ScreenPositionZ+=(FightLocationData->LocationData.StageSizeMinZ-EnemyFightData[WhichEnemy].StagePositionZ)*FightLocationData->LocationData.StolarScreenSpeedZ;
EnemyFightData[WhichEnemy].StagePositionZ = FightLocationData->LocationData.StageSizeMinZ;
}
}
}


//---------------------------------------------------------------------------------

if(EnemyFightData[WhichEnemy].CurrentAnimation == EnemyIdleAnimation+EnemyFightData[WhichEnemy].FaceDirection){

if(EnemyFightData[WhichEnemy].FaceDirection == FightFaceRight){
MinimumEnemyX = EnemyFightData[WhichEnemy].PositionX+StolarRedAbilityRangeMinimumX;
MaximumEnemyX = EnemyFightData[WhichEnemy].PositionX+StolarRedAbilityRangeMaximumX;
}
else{
MinimumEnemyX = EnemyFightData[WhichEnemy].PositionX+EnemyFightData[WhichEnemy].SizeX-StolarRedAbilityRangeMaximumX;
MaximumEnemyX = EnemyFightData[WhichEnemy].PositionX+EnemyFightData[WhichEnemy].SizeX-StolarRedAbilityRangeMinimumX;
}

MinimumEnemyY = EnemyFightData[WhichEnemy].PositionY+StolarRedAbilityRangeMinimumY;
MaximumEnemyY = EnemyFightData[WhichEnemy].PositionY+StolarRedAbilityRangeMaximumY;

MinimumEnemyZ = EnemyFightData[WhichEnemy].StagePositionZ+StolarRedAbilityRangeMinimumZ;
MaximumEnemyZ = EnemyFightData[WhichEnemy].StagePositionZ+StolarRedAbilityRangeMaximumZ;

if(StolarFightData->FaceDirection == FightFaceRight){
MinimumStolarX = StolarFightData->PositionX+StolarHitOffsetLeft;
MaximumStolarX = StolarFightData->PositionX+StolarHitOffsetRight;
}
else{
MinimumStolarX = StolarFightData->PositionX+StolarFightData->SizeX-StolarHitOffsetRight;
MaximumStolarX = StolarFightData->PositionX+StolarFightData->SizeX-StolarHitOffsetLeft;
}

MinimumStolarY = StolarFightData->PositionY+StolarHitOffsetUp;
MaximumStolarY = StolarFightData->PositionY+StolarHitOffsetDown;

MinimumStolarZ = StolarFightData->StagePositionZ+StolarHitOffsetBack;
MaximumStolarZ = StolarFightData->StagePositionZ+StolarHitOffsetFront;

if(MaximumEnemyX > MinimumStolarX && MinimumEnemyX < MaximumStolarX && MaximumEnemyY > MinimumStolarY && MinimumEnemyY < MaximumStolarY && MaximumEnemyZ > MinimumStolarZ && MinimumEnemyZ < MaximumStolarZ){

AcrossTheFaceMyFriend(WhichEnemy, &EnemyFightData[WhichEnemy], StolarFightData, EnemyFightData[WhichEnemy].EnemyData.Attack, 0, 0, 0);

}
else{
//STAND STILL OR BE USELESS, I DON'T CARE
}

}

//---------------------------------------------------------------------------------



}
}

void (*ComputeArtificialIntelligence[ArtificialIntelligenceAmount])(uint8 WhichEnemy, StolarFightStruct* StolarFightData, EnemyFightStruct* EnemyFightData, uint8 EnemyAmount, FightLocationStruct* FightLocationData, GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, uint8* AnimationFlags, FloatingValueStruct* FloatingValueData) = 
{
DarkStolar
};