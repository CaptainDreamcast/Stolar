void TitleScreenInput(TitleScreenStruct* TitleScreenData){

ReadInputAndCheckControllerLegitimacy(TitleScreenData->LogicData.ButtonInputData, &TitleScreenData->LogicData.st);


if(TitleScreenData->LogicData.CurrentStage == TitleScreenStageInputWait){

if(ButtonPressedAny(TitleScreenData->LogicData.st)){
LogicCounterInitiate(TitleScreenData->LogicData.TicksUniversalReboot);
}

if(ButtonLegit(ButtonStart, TitleScreenData->LogicData.ButtonInputData)){
if(SaveGameExists()){
TitleScreenData->LogicData.CurrentStage = TitleScreenStageFinished;
TitleScreenData->LogicData.ReturnStage = LoadGameStage;
}
else{
StartZoomingAdvanced((&TitleScreenData->LogicData.TransformationDataZoomOut), NormalSizeScaleValue); 
TitleScreenData->LogicData.CurrentStage = TitleScreenStageBuildDown;
TitleScreenData->LogicData.ReturnStage = StartNewGameStage;
}
}

}

StairWayToHeavenCheck(TitleScreenData->LogicData.st, 
{
if(ButtonLegit(ButtonStart, TitleScreenData->LogicData.ButtonInputData) || ButtonLegit(ButtonA, TitleScreenData->LogicData.ButtonInputData) || ButtonLegit(ButtonB, TitleScreenData->LogicData.ButtonInputData) || ButtonLegit(ButtonX, TitleScreenData->LogicData.ButtonInputData) || ButtonLegit(ButtonY, TitleScreenData->LogicData.ButtonInputData)){
TitleScreenData->LogicData.MainLoop = 0;
TitleScreenData->LogicData.ReturnStage = FinalExitStage;
}
}
);

}