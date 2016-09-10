void FightObjectsSingleObjectSingleInstanceAnimate(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

if(!FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SemaphoreAnimate){
FightAnimateWithAnimationFactor(FightData->ObjectData[WhichObject].FluxData.AnimationData, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Ticks, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->AnimationFactor, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentFrame, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation);
}

}