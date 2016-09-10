void FightBackGroundsSingleObjectSingleInstanceAnimate(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

if(FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.Animate){
FightAnimateWithAnimationFactor(
(&FightData->BackGroundData[WhichObject].Loadable->AnimationData), 
FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.Ticks, 
FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable->AnimationFactor, 
FightData->BackGroundData[WhichObject].Instance[WhichInstance].Loadable->CurrentFrame, 
FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.CurrentAnimation 
);
}

}