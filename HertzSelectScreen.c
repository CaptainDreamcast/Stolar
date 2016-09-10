uint8 HertzSelectScreen(){

HertzSelectScreenStruct HertzSelectScreenData;

HertzSelectScreenLoad(&HertzSelectScreenData);

while(HertzSelectScreenData.LogicData.CurrentStage != HertzSelectScreenStageFinished){

HertzSelectScreenDraw(&HertzSelectScreenData);
HertzSelectScreenInput(&HertzSelectScreenData);
}

HertzSelectScreenDeLoad(&HertzSelectScreenData);

return(HertzSelectScreenData.LogicData.ReturnFrameRate);
}