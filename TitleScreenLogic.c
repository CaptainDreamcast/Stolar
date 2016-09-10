void TitleScreenLogic(TitleScreenStruct* TitleScreenData, void** TransitionData){

if(TitleScreenData->LogicData.CurrentStage == TitleScreenStageBuildUp){
LogicAlphaBuildDown(TitleScreenData->LogicData.AlphaValueBlackOut, TitleScreenData->Loadable->TimeInSecondsBuildUp, 
{
LogicCounterInitiate(TitleScreenData->LogicData.TicksUniversalReboot);
TitleScreenData->LogicData.CurrentStage = TitleScreenStageInputWait;
}
);
}
else if(TitleScreenData->LogicData.CurrentStage == TitleScreenStageInputWait){
LogicCounter(TitleScreenData->LogicData.TicksUniversalReboot, TitleScreenData->Loadable->TimeInSecondsUniversalReboot, 
{
TitleScreenData->LogicData.ReturnStage = BootUpStage;
TitleScreenData->LogicData.CurrentStage = TitleScreenStageBuildDown;
}
);
}
else if(TitleScreenData->LogicData.CurrentStage == TitleScreenStageZoomOut){
LogicDexpand((&TitleScreenData->LogicData.TransformationDataZoomOut), TitleScreenData->Loadable->TimeInSecondsZoomOut, NormalSizeScaleValue, (NormalSizeScaleValue/(ScreenSizeX/2)), 
{
TitleScreenData->LogicData.CurrentStage = TitleScreenStageFinished;
}
);
}
else if(TitleScreenData->LogicData.CurrentStage == TitleScreenStageBuildDown){
LogicAlphaBuildUp(TitleScreenData->LogicData.AlphaValueBlackOut, TitleScreenData->Loadable->TimeInSecondsBuildDown, 
{
TitleScreenData->LogicData.CurrentStage = TitleScreenStageFinished;
}
);
}
else if(TitleScreenData->LogicData.CurrentStage == TitleScreenStageFinished){
if(TitleScreenData->LogicData.ReturnStage == LoadGameStage){FrameBufferLoadToTransitionData((*TransitionData));}
TitleScreenData->LogicData.MainLoop = 0;
}

}