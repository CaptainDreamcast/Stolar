uint8 RedSpotScreen(){

RedSpotScreenStruct RedSpotScreenData;

RedSpotScreenLoad(&RedSpotScreenData);

while(RedSpotScreenData.LogicData.CurrentStage != RedSpotScreenStageFinished){

RedSpotScreenDraw(&RedSpotScreenData);
RedSpotScreenLogic(&RedSpotScreenData);
RedSpotScreenInput(&RedSpotScreenData);

}

RedSpotScreenDeLoad(&RedSpotScreenData);

return(RedSpotScreenData.LogicData.ReturnValue);
}