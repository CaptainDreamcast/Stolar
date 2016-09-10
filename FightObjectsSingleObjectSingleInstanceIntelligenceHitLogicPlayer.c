void FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicPlayer(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichIntelligence){

FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicPlayerStruct* Data;

Data = (FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicPlayerStruct*)FightData->ObjectData[WhichObject].Instance[WhichInstance].Intelligence[WhichIntelligence].Buffer;

if(!Data->LogicData.Active){
if(FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX || FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityY || FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ){
FightObjectChangeAnimationSimplest(FightData->ObjectData[WhichObject].Instance[WhichInstance], PlayerHitAnimation);
FightData->ObjectData[WhichObject].Instance[WhichInstance].Intelligence[FightPlayerIntelligenceIdentifierMovement].LogicData.Semaphore++;
Data->LogicData.Active = LogicActive;
}
}
else{
if(
!(FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX || FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityY || FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ) && 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != PlayerHitAnimation
){
FightData->ObjectData[WhichObject].Instance[WhichInstance].Intelligence[FightPlayerIntelligenceIdentifierMovement].LogicData.Semaphore--;
Data->LogicData.Active = LogicActiveNot;
}
else if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != PlayerHitAnimation){
FightObjectChangeAnimationSimple(FightData->ObjectData[WhichObject].Instance[WhichInstance], PlayerHitAnimation, (FightData->ObjectData[WhichObject].FluxData.AnimationData[PlayerHitAnimation].FrameAmount-1));
}
}


}