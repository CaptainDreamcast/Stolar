void DogmaScreenLogic(DogmaScreenStruct* DogmaScreenData){


if(DogmaScreenData->LogicData.CurrentStage == DogmaScreenStageBuildDown || DogmaScreenData->LogicData.ForceBuildDown){
if(DogmaScreenData->LogicData.CurrentStage == DogmaScreenStageFirst) DogmaScreenData->LogicData.CurrentStage = DogmaScreenStageBuildDown;
LogicAlphaBuildUp(DogmaScreenData->LogicData.AlphaValueBlackOut, DogmaScreenData->Loadable->BuildDownTimeInSeconds, 
{
DogmaScreenData->LogicData.CurrentStage = DogmaScreenStageFinished;
}
);
}

if(DogmaScreenData->LogicData.CurrentStage == DogmaScreenStageLogoBuildUp){
LogicAlphaBuildDown(DogmaScreenData->LogicData.AlphaValueBlackOut, DogmaScreenData->Loadable->LogoBuildUpTimeInSeconds, 
{
LogicCounterInitiate(DogmaScreenData->LogicData.Ticks);
DogmaScreenData->LogicData.CurrentStage = DogmaScreenStageLogoBuildUpAfterWait;
}
);
}
else if(DogmaScreenData->LogicData.CurrentStage == DogmaScreenStageLogoBuildUpAfterWait){
LogicCounter(
DogmaScreenData->LogicData.Ticks, DogmaScreenData->Loadable->LogoBuildUpAfterWaitTimeInSeconds, {DogmaScreenData->LogicData.CurrentStage = DogmaScreenStageBuildDown;}
);
}


}