#define FightObjectsSingleObjectSingleInstanceAnimateOverrideDummyAnimation	0

void FightObjectsSingleObjectSingleInstanceAnimateOverride(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, AnimationStruct* AnimationData){

FightAnimateWithAnimationFactorManual(AnimationData, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Ticks, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->AnimationFactor, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentFrame, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation);

}