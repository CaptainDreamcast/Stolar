#define DefinitionMinimumEnemyY	EnemyFightData[DirtyDeedsDoneDirtCheap].PositionY+EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetUp]
#define DefinitionMaximumEnemyY	EnemyFightData[DirtyDeedsDoneDirtCheap].PositionY+EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetDown]

#define DefinitionMinimumEnemyZ	EnemyFightData[DirtyDeedsDoneDirtCheap].StagePositionZ+EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetBack]
#define DefinitionMaximumEnemyZ	EnemyFightData[DirtyDeedsDoneDirtCheap].StagePositionZ+EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetFront]

#define RedAbilityMinimumHitFrame		2
#define RedAbilityMaximumHitFrame		3

#define RedAbilitySecondMinimumHitFrame		2
#define RedAbilitySecondMaximumHitFrame		3

#define RedAbilityThirdMinimumHitFrame		2
#define RedAbilityThirdMaximumHitFrame		3

#define StolarRedAbilityRangeMinimumX		10
#define StolarRedAbilityRangeMaximumX		10
#define StolarRedAbilityRangeMinimumY		10
#define StolarRedAbilityRangeMaximumY		10
#define StolarRedAbilityRangeMinimumZ		10
#define StolarRedAbilityRangeMaximumZ		10

#define StolarRedAbilitySecondRangeMinimumX	10
#define StolarRedAbilitySecondRangeMaximumX	10
#define StolarRedAbilitySecondRangeMinimumY	10
#define StolarRedAbilitySecondRangeMaximumY	10
#define StolarRedAbilitySecondRangeMinimumZ	10
#define StolarRedAbilitySecondRangeMaximumZ	10

#define StolarRedAbilityThirdRangeMinimumX	10
#define StolarRedAbilityThirdRangeMaximumX	10
#define StolarRedAbilityThirdRangeMinimumY	10
#define StolarRedAbilityThirdRangeMaximumY	10
#define StolarRedAbilityThirdRangeMinimumZ	10
#define StolarRedAbilityThirdRangeMaximumZ	10

void RedAbilityFunction(cont_state_t* st, uint32 AbilityButton, uint8* ButtonStatus, StolarFightStruct* StolarFightData, EnemyFightStruct* EnemyFightData, uint8 EnemyAmount, FightLocationStruct* FightLocationData, GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, uint8* AnimationFlags, FloatingValueStruct* FloatingValueData){

uint8 DirtyDeedsDoneDirtCheap;
short MinimumX, MaximumX, MinimumY, MaximumY, MinimumZ, MaximumZ, MinimumEnemyX, MaximumEnemyX;


if((st->buttons & AbilityButton) && *ButtonStatus){

if(StolarFightData->CurrentAnimation == StolarIdleAnimationRight+StolarFightData->FaceDirection){
StolarFightData->CurrentAnimation = StolarNormalPunchAnimation+StolarFightData->CurrentAnimation;
StolarFightData->CurrentFrame = 0;
StolarFightData->AnimationTicks = 0;
}
else if(StolarFightData->CurrentAnimation == StolarNormalPunchAnimation+StolarFightData->FaceDirection && StolarFightData->CurrentFrame >= RedAbilityMaximumHitFrame){
StolarFightData->CurrentAnimation = StolarSecondPunchAnimation+StolarFightData->FaceDirection;
StolarFightData->CurrentFrame = 0;
StolarFightData->AnimationTicks = 0;
}
else if(StolarFightData->CurrentAnimation == StolarSecondPunchAnimation+StolarFightData->FaceDirection && StolarFightData->CurrentFrame >= RedAbilitySecondMaximumHitFrame){
StolarFightData->CurrentAnimation = StolarThirdPunchAnimation+StolarFightData->FaceDirection;
StolarFightData->CurrentFrame = 0;
StolarFightData->AnimationTicks = 0;
}

*ButtonStatus = 0;
}
else if(!(st->buttons & AbilityButton) && !(*ButtonStatus)) *ButtonStatus = 1;



if(StolarFightData->CurrentAnimation == StolarNormalPunchAnimation+StolarFightData->FaceDirection && StolarFightData->CurrentFrame >= RedAbilityMinimumHitFrame && StolarFightData->CurrentFrame <= RedAbilityMaximumHitFrame){

if(StolarFightData->FaceDirection == FightFaceRight){
MinimumX = StolarFightData->PositionX+StolarRedAbilityRangeMinimumX;
MaximumX = StolarFightData->PositionX+StolarRedAbilityRangeMaximumX;
}
else{
MinimumX = StolarFightData->PositionX+StolarFightData->SizeX-StolarRedAbilityRangeMaximumX;
MaximumX = StolarFightData->PositionX+StolarFightData->SizeX-StolarRedAbilityRangeMinimumX;
}

MinimumY = StolarFightData->PositionY+StolarRedAbilityRangeMinimumY;
MaximumY = StolarFightData->PositionY+StolarRedAbilityRangeMaximumY;

MinimumZ = StolarFightData->StagePositionZ+StolarRedAbilityRangeMinimumZ;
MaximumZ = StolarFightData->StagePositionZ+StolarRedAbilityRangeMaximumZ;


for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EnemyAmount; DirtyDeedsDoneDirtCheap++){

if(EnemyFightData[DirtyDeedsDoneDirtCheap].FaceDirection == FightFaceRight){
MinimumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetLeft];
MaximumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetRight];
}
else{
MinimumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].SizeX-EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetRight];
MaximumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].SizeX-EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetLeft];
}

if(MaximumX > MinimumEnemyX && MinimumX < MaximumEnemyX && MaximumY > DefinitionMinimumEnemyY && MinimumY < DefinitionMaximumEnemyY && MaximumZ > DefinitionMinimumEnemyZ && MinimumZ < DefinitionMaximumEnemyZ){

YouJustGotSlapped(&EnemyFightData[DirtyDeedsDoneDirtCheap], StolarFightData, GraphicalUserInterFaceData, StolarFightData->StolarData->Attack, StolarFightData->FaceDirection, RedAbilityFillUpMultiplicator, 0, 0);

}

}
}


if(StolarFightData->CurrentAnimation == StolarSecondPunchAnimation+StolarFightData->FaceDirection && StolarFightData->CurrentFrame >= RedAbilitySecondMinimumHitFrame && StolarFightData->CurrentFrame <= RedAbilitySecondMaximumHitFrame){

if(StolarFightData->FaceDirection == FightFaceRight){
MinimumX = StolarFightData->PositionX+StolarRedAbilitySecondRangeMinimumX;
MaximumX = StolarFightData->PositionX+StolarRedAbilitySecondRangeMaximumX;
}
else{
MinimumX = StolarFightData->PositionX+StolarFightData->SizeX-StolarRedAbilitySecondRangeMaximumX;
MaximumX = StolarFightData->PositionX+StolarFightData->SizeX-StolarRedAbilitySecondRangeMinimumX;
}

MinimumY = StolarFightData->PositionY+StolarRedAbilitySecondRangeMinimumY;
MaximumY = StolarFightData->PositionY+StolarRedAbilitySecondRangeMaximumY;

MinimumZ = StolarFightData->StagePositionZ+StolarRedAbilitySecondRangeMinimumZ;
MaximumZ = StolarFightData->StagePositionZ+StolarRedAbilitySecondRangeMaximumZ;


for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EnemyAmount; DirtyDeedsDoneDirtCheap++){

if(EnemyFightData[DirtyDeedsDoneDirtCheap].FaceDirection == FightFaceRight){
MinimumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetLeft];
MaximumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetRight];
}
else{
MinimumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].SizeX-EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetRight];
MaximumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].SizeX-EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetLeft];
}

if(MaximumX > MinimumEnemyX && MinimumX < MaximumEnemyX && MaximumY > DefinitionMinimumEnemyY && MinimumY < DefinitionMaximumEnemyY && MaximumZ > DefinitionMinimumEnemyZ && MinimumZ < DefinitionMaximumEnemyZ){

YouJustGotSlapped(&EnemyFightData[DirtyDeedsDoneDirtCheap], StolarFightData, GraphicalUserInterFaceData, StolarFightData->StolarData->Attack, StolarFightData->FaceDirection, RedAbilityFillUpMultiplicator, 0, 0);

}

}
}

if(StolarFightData->CurrentAnimation == StolarThirdPunchAnimation+StolarFightData->FaceDirection && StolarFightData->CurrentFrame >= RedAbilityThirdMinimumHitFrame && StolarFightData->CurrentFrame <= RedAbilityThirdMaximumHitFrame){

if(StolarFightData->FaceDirection == FightFaceRight){
MinimumX = StolarFightData->PositionX+StolarRedAbilityThirdRangeMinimumX;
MaximumX = StolarFightData->PositionX+StolarRedAbilityThirdRangeMaximumX;
}
else{
MinimumX = StolarFightData->PositionX+StolarFightData->SizeX-StolarRedAbilityThirdRangeMaximumX;
MaximumX = StolarFightData->PositionX+StolarFightData->SizeX-StolarRedAbilityThirdRangeMinimumX;
}

MinimumY = StolarFightData->PositionY+StolarRedAbilityThirdRangeMinimumY;
MaximumY = StolarFightData->PositionY+StolarRedAbilityThirdRangeMaximumY;

MinimumZ = StolarFightData->StagePositionZ+StolarRedAbilityThirdRangeMinimumZ;
MaximumZ = StolarFightData->StagePositionZ+StolarRedAbilityThirdRangeMaximumZ;


for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EnemyAmount; DirtyDeedsDoneDirtCheap++){

if(EnemyFightData[DirtyDeedsDoneDirtCheap].FaceDirection == FightFaceRight){
MinimumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetLeft];
MaximumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetRight];
}
else{
MinimumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].SizeX-EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetRight];
MaximumEnemyX = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].SizeX-EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.HitOffset[HitOffsetLeft];
}

if(MaximumX > MinimumEnemyX && MinimumX < MaximumEnemyX && MaximumY > DefinitionMinimumEnemyY && MinimumY < DefinitionMaximumEnemyY && MaximumZ > DefinitionMinimumEnemyZ && MinimumZ < DefinitionMaximumEnemyZ){

YouJustGotSlapped(&EnemyFightData[DirtyDeedsDoneDirtCheap], StolarFightData, GraphicalUserInterFaceData, StolarFightData->StolarData->Attack, StolarFightData->FaceDirection, RedAbilityFillUpMultiplicator, 0, 0);

}

}
}

}



void (*AbilityFunction[OverallAbilityAmount])(cont_state_t* st, uint32 AbilityButton, uint8* ButtonStatus, StolarFightStruct* StolarFightData, EnemyFightStruct* EnemyFightData, uint8 EnemyAmount, FightLocationStruct* FightLocationData, GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, uint8* AnimationFlags, FloatingValueStruct* FloatingValueData) = 
{
RedAbilityFunction
};
