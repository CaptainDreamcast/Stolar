void RedSpotScreenInput(RedSpotScreenStruct* RedSpotScreenData){

ReadInputAndCheckControllerLegitimacy(RedSpotScreenData->LogicData.ButtonInputData, &RedSpotScreenData->LogicData.st);

if(ButtonLegit(ButtonA, RedSpotScreenData->LogicData.ButtonInputData) || ButtonLegit(ButtonStart, RedSpotScreenData->LogicData.ButtonInputData)){
RedSpotScreenData->LogicData.ForceBuildDown = 1;
}

StairWayToHeavenCheck(RedSpotScreenData->LogicData.st, 
{
RedSpotScreenData->LogicData.CurrentStage = RedSpotScreenStageFinished;
RedSpotScreenData->LogicData.ReturnValue = StairWayToHeavenIdentifier;
}
);

}