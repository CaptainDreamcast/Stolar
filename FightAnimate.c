void FightAnimate(StolarFightStruct* StolarFightData, EnemyFightStruct* EnemyFightData, uint8 EnemyAmount, FightLocationStruct* FightLocationData, uint8 Flags){

float AnimationFactor;
uint8 DirtyDeedsDoneDirtCheap;

if(!Flags) return;

if(Flags & StolarAnimationFlag){

AnimationFactor = StolarFightData->AnimationFactor;

if(AnimationFactor < 1.0f){
StolarFightData->AnimationFactor += StolarFightData->FactorBuildUp;
if(StolarFightData->AnimationFactor >= 1.0f){
StolarFightData->AnimationFactor = 0.0f;
AnimationFactor = 1.0f;
}
}

if(AnimationFactor >= 1.0f){
do{
StolarFightData->AnimationTicks++;
if(StolarFightData->AnimationTicks >= StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].Speed){

StolarFightData->AnimationTicks = 0;
StolarFightData->CurrentFrame++;
if(StolarFightData->CurrentFrame >= StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureAmount){

StolarFightData->CurrentAnimation = StolarIdleAnimationRight+StolarFightData->FaceDirection;
StolarFightData->CurrentFrame = 0;
}
}
AnimationFactor-=1.0f;
} while(AnimationFactor > 0.0f);
}
}

if(Flags & EnemyAnimationFlag){
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EnemyAmount; DirtyDeedsDoneDirtCheap++){

AnimationFactor = EnemyFightData[DirtyDeedsDoneDirtCheap].AnimationFactor;

if(AnimationFactor < 1.0f){
EnemyFightData[DirtyDeedsDoneDirtCheap].AnimationFactor += EnemyFightData[DirtyDeedsDoneDirtCheap].FactorBuildUp;
if(EnemyFightData[DirtyDeedsDoneDirtCheap].AnimationFactor >= 1.0f){
EnemyFightData[DirtyDeedsDoneDirtCheap].AnimationFactor = 0.0f;
AnimationFactor = 1.0f;
}
}

if(AnimationFactor >= 1.0f){
do{
EnemyFightData[DirtyDeedsDoneDirtCheap].AnimationTicks++;
if(EnemyFightData[DirtyDeedsDoneDirtCheap].AnimationTicks >= EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyAnimationData[EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentAnimation].Speed){

EnemyFightData[DirtyDeedsDoneDirtCheap].AnimationTicks = 0;
EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentFrame++;
if(EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentFrame >= EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyAnimationData[EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentAnimation].TextureAmount){

EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentAnimation = EnemyIdleAnimation;
EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentFrame = 0;

}
}
AnimationFactor-=1.0f;
} while(AnimationFactor > 0.0f);
}
}
}


if(Flags & StageAnimationFlag){

AnimationFactor = FightLocationData->AnimationFactor;


if(AnimationFactor < 1.0f){
FightLocationData->AnimationFactor += FightLocationData->FactorBuildUp;
if(FightLocationData->AnimationFactor >= 1.0f){
FightLocationData->AnimationFactor = 0.0f;
AnimationFactor = 1.0f;
}
}

if(AnimationFactor >= 1.0f){
do{


for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<FightLocationData->LocationData.AnimationAmount; DirtyDeedsDoneDirtCheap++){
if(FightLocationData->AnimationData[DirtyDeedsDoneDirtCheap].TextureAmount > 1){



FightLocationData->Ticks[DirtyDeedsDoneDirtCheap]++;
if(FightLocationData->Ticks[DirtyDeedsDoneDirtCheap] >= FightLocationData->AnimationData[DirtyDeedsDoneDirtCheap].Speed){

FightLocationData->Ticks[DirtyDeedsDoneDirtCheap] = 0;
FightLocationData->CurrentFrame[DirtyDeedsDoneDirtCheap]++;
if(FightLocationData->CurrentFrame[DirtyDeedsDoneDirtCheap] >= FightLocationData->AnimationData[DirtyDeedsDoneDirtCheap].TextureAmount){

FightLocationData->CurrentFrame[DirtyDeedsDoneDirtCheap] = 0;

}
}

}
}

} while(AnimationFactor > 0.0f);
}

}


}