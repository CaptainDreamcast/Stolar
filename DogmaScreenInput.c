void DogmaScreenInput(DogmaScreenStruct* DogmaScreenData){

ReadInputAndCheckControllerLegitimacy(DogmaScreenData->LogicData.ButtonInputData, &DogmaScreenData->LogicData.st);

if(ButtonLegit(ButtonA, DogmaScreenData->LogicData.ButtonInputData) || ButtonLegit(ButtonStart, DogmaScreenData->LogicData.ButtonInputData)){
DogmaScreenData->LogicData.ForceBuildDown = 1;
}

StairWayToHeavenCheck(DogmaScreenData->LogicData.st, 
{
DogmaScreenData->LogicData.CurrentStage = DogmaScreenStageFinished;
DogmaScreenData->LogicData.ReturnValue = StairWayToHeavenIdentifier;
}
);

}