void RedSpotScreenLogic(RedSpotScreenStruct* RedSpotScreenData){


if(RedSpotScreenData->LogicData.CurrentStage == RedSpotScreenStageBuildDown || RedSpotScreenData->LogicData.ForceBuildDown){
LogicAlphaBuildUp(RedSpotScreenData->LogicData.AlphaValueBlackOut, RedSpotScreenData->Loadable->BuildDownTimeInSeconds, 
{
RedSpotScreenData->LogicData.CurrentStage = RedSpotScreenStageFinished;
}
);
}


if(RedSpotScreenData->LogicData.CurrentStage == RedSpotScreenStageBuildUp){
if(!RedSpotScreenData->LogicData.ForceBuildDown){
LogicAlphaBuildDown(RedSpotScreenData->LogicData.AlphaValueBlackOut, RedSpotScreenData->Loadable->BuildUpTimeInSeconds, 
{
LogicCounterInitiate(RedSpotScreenData->LogicData.Ticks);
RedSpotScreenData->LogicData.CurrentStage = RedSpotScreenStageBuildUpAfterWait;
}
);
}
}
else if(RedSpotScreenData->LogicData.CurrentStage == RedSpotScreenStageBuildUpAfterWait){
LogicCounter(RedSpotScreenData->LogicData.Ticks, RedSpotScreenData->Loadable->BuildUpAfterWaitTimeInSeconds, 
{
RedSpotScreenData->LogicData.CurrentStage = RedSpotScreenStageRedSpotExpand;
}
);
}
else if(RedSpotScreenData->LogicData.CurrentStage == RedSpotScreenStageRedSpotExpand){
LogicExpand((&RedSpotScreenData->LogicData.TransformationDataRedSpot), RedSpotScreenData->Loadable->RedSpotExpandTimeInSeconds, 
RedSpotScreenData->Loadable->RedSpotExpandStartValue, RedSpotScreenData->Loadable->RedSpotExpandEndValue, 
{
RedSpotScreenData->LogicData.CurrentStage = RedSpotScreenStageBackGroundFadeIn;
}
);
}
else if(RedSpotScreenData->LogicData.CurrentStage == RedSpotScreenStageBackGroundFadeIn){
LogicAlphaBuildUp(RedSpotScreenData->LogicData.AlphaValueBackGround, RedSpotScreenData->Loadable->BackGroundFadeInTimeInSeconds, 
{
LogicCounterInitiate(RedSpotScreenData->LogicData.Ticks);
SoundEffectPlay(RedSpotScreenData->SoundEffectData.RedSpotGamesSoundEffect);
RedSpotScreenData->LogicData.CurrentStage = RedSpotScreenStageBackGround;
}
);
}
else if(RedSpotScreenData->LogicData.CurrentStage == RedSpotScreenStageBackGround){
LogicCounter(RedSpotScreenData->LogicData.Ticks, RedSpotScreenData->Loadable->BackGroundTimeInSeconds, 
{
RedSpotScreenData->LogicData.CurrentStage = RedSpotScreenStageEffect;
}
);
}
else if(RedSpotScreenData->LogicData.CurrentStage == RedSpotScreenStageEffect){
LogicAlphaRisesWithPosition(RedSpotScreenData->LogicData.AlphaValueEffect, RedSpotScreenData->LogicData.EffectPositionX, 
RedSpotScreenData->Loadable->EffectStartPositionX, RedSpotScreenData->Loadable->EffectFadeInEndPositionX
);
LogicAlphaFallsWithPosition(RedSpotScreenData->LogicData.AlphaValueEffect, RedSpotScreenData->LogicData.EffectPositionX, 
RedSpotScreenData->Loadable->EffectFadeOutStartPositionX, RedSpotScreenData->Loadable->EffectEndPositionX
);
LogicRawMovementRight(RedSpotScreenData->LogicData.EffectPositionX, RedSpotScreenData->Loadable->EffectStartPositionX, RedSpotScreenData->Loadable->EffectEndPositionX, 
RedSpotScreenData->Loadable->EffectTimeInSeconds, 
{
RedSpotScreenData->LogicData.CurrentStage = RedSpotScreenStageBuildDown;
}
);
}


}