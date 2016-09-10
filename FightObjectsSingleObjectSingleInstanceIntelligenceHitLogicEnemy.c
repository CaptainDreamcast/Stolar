void FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicEnemy(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichIntelligence){

FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicEnemyStruct* Data;

Data = (FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicEnemyStruct*)FightData->ObjectData[WhichObject].Instance[WhichInstance].Intelligence[WhichIntelligence].Buffer;

if(!Data->LogicData.Active){
if(FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX || FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityY || FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ){
Data->LogicData.Active = LogicActive;
}
}
else{
if(
!(FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX || FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityY || FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ) && 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != StandardEnemyHitAnimation
){
Data->LogicData.Active = LogicActiveNot;
}
else if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != StandardEnemyHitAnimation){
FightObjectChangeAnimationSimple(FightData->ObjectData[WhichObject].Instance[WhichInstance], StandardEnemyHitAnimation, (FightData->ObjectData[WhichObject].FluxData.AnimationData[StandardEnemyHitAnimation].FrameAmount-1));
}
}


}