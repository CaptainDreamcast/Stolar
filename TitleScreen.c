uint8 TitleScreen(void** TransitionData){

TitleScreenStruct TitleScreenData;

TitleScreenLoad(&TitleScreenData);
SoundPlay(0);

while(TitleScreenData.LogicData.MainLoop){
TitleScreenDraw(&TitleScreenData);
TitleScreenLogic(&TitleScreenData, TransitionData);
TitleScreenInput(&TitleScreenData);
}

SoundStop(0);
TitleScreenDeLoad(&TitleScreenData);

return(TitleScreenData.LogicData.ReturnStage);
}
