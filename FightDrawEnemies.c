#define FightDrawEnemiesTransformationDataGeneralAmount			2
#define FightDrawEnemiesTransformationDataPersonalAmount		2


void FightDrawEnemies(FightStruct* FightData, OverWorldStruct*OverWorldData){


TransformationStruct GeneralTransformationData, PersonalTransformationData;
uint8 DirtyDeedsDoneDirtCheap;

if((FightData->LogicData.General.DrawFlags & FightDrawFlagEnemies)){
GeneralTransformationData = CombineMultipleTransformationData(FightDrawEnemiesTransformationDataGeneralAmount, &FightData->LogicData.General.TransformationData, &FightData->LogicData.Enemies.TransformationData); 

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<FightData->Loadable.Enemies->General.EnemyAmount; DirtyDeedsDoneDirtCheap++){
if(FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.Draw){

PersonalTransformationData = CombineMultipleTransformationData(FightDrawEnemiesTransformationDataPersonalAmount, &GeneralTransformationData, &FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.TransformationData);


TextureAtlasDrawSimplest((FightData->EnemyData[DirtyDeedsDoneDirtCheap].FluxData.AnimationData[FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.CurrentAnimation].TextureOffset+FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.CurrentFrame),
&PersonalTransformationData, 
FightData->EnemyData[DirtyDeedsDoneDirtCheap].Texture, 
FightData->EnemyData[DirtyDeedsDoneDirtCheap].Given->PositionX-FightData->LogicData.BackGround.StagePositionX, 
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.PositionY-FightData->LogicData.BackGround.StagePositionY, 
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.ScreenPositionZ, 
FightData->EnemyData[DirtyDeedsDoneDirtCheap].Given->SizeX, FightData->EnemyData[DirtyDeedsDoneDirtCheap].Given->SizeY, 
FightData->EnemyData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeX, FightData->EnemyData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeY, 
FightData->EnemyData[DirtyDeedsDoneDirtCheap].Loadable->SingleTextureSizeX, FightData->EnemyData[DirtyDeedsDoneDirtCheap].Loadable->SingleTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

}
}
}

if((FightData->LogicData.General.AnimationFlags & FightAnimationFlagEnemies)){
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<FightData->Loadable.Enemies->General.EnemyAmount; DirtyDeedsDoneDirtCheap++){
if(FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.Animate){
AnimateWithAnimationFactor(FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.Ticks,
FightData->EnemyData[DirtyDeedsDoneDirtCheap].FluxData.AnimationData[FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.CurrentAnimation].AnimationDurationInSeconds,
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.AnimationFactor,
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.CurrentFrame,
FightData->EnemyData[DirtyDeedsDoneDirtCheap].FluxData.AnimationData[FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.CurrentAnimation].FrameAmount,
{
FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.CurrentAnimation = FightDrawEnemyIdleAnimation;
}
);

}
}
}
}

