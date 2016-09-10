uint8 DogmaScreen(){

DogmaScreenStruct DogmaScreenData;

DogmaScreenLoad(&DogmaScreenData);

while(DogmaScreenData.LogicData.CurrentStage != DogmaScreenStageFinished){

DogmaScreenDraw(&DogmaScreenData);
DogmaScreenLogic(&DogmaScreenData);
DogmaScreenInput(&DogmaScreenData);

}

DogmaScreenDeLoad(&DogmaScreenData);

return(DogmaScreenData.LogicData.ReturnValue);
}