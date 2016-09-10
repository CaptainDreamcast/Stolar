#define HertzSelectScreenTestScreenInitiate() { \
HertzSelectScreenData->LogicData.CurrentScreen = HertzSelectScreenTestScreen; \
HertzSelectScreenData->LogicData.TestSecondTicks = 0; \
HertzSelectScreenData->LogicData.TestSecondsLeft = HertzSelectScreenData->Loadable->TestSecondAmount; \
SetVideoModeNeverForget(SixtyHertz, StolarSixtyHertzCableMode); \
}

void HertzSelectScreenInput(HertzSelectScreenStruct* HertzSelectScreenData){

ReadInputAndCheckControllerLegitimacy(HertzSelectScreenData->LogicData.ButtonInputData, &HertzSelectScreenData->LogicData.st);

if(HertzSelectScreenData->LogicData.CurrentScreen == HertzSelectScreenSelectScreen && HertzSelectScreenData->LogicData.CurrentStage == HertzSelectScreenStageNormal){

if(ButtonLegit(ButtonRight, HertzSelectScreenData->LogicData.ButtonInputData)){
HertzSelectScreenData->LogicData.SelectScreenOptionSelected = (HertzSelectScreenData->LogicData.SelectScreenOptionSelected+1)%HertzSelectScreenSelectOptionAmount;
}

if(ButtonLegit(ButtonLeft, HertzSelectScreenData->LogicData.ButtonInputData)){
if(HertzSelectScreenData->LogicData.SelectScreenOptionSelected == 0) HertzSelectScreenData->LogicData.SelectScreenOptionSelected = HertzSelectScreenSelectOptionAmount-1;
HertzSelectScreenData->LogicData.SelectScreenOptionSelected--;
}

if(ButtonLegit(ButtonA, HertzSelectScreenData->LogicData.ButtonInputData) || ButtonLegit(ButtonStart, HertzSelectScreenData->LogicData.ButtonInputData)){
if(HertzSelectScreenData->LogicData.SelectScreenOptionSelected < HertzSelectScreenSelectOptionTest	){
HertzSelectScreenData->LogicData.ReturnFrameRate = HertzSelectScreenParseSelectedOptionToReturnFrameRate(HertzSelectScreenData->LogicData.SelectScreenOptionSelected);
HertzSelectScreenData->LogicData.CurrentStage = HertzSelectScreenStageBuildDown;
}
else{
HertzSelectScreenTestScreenInitiate();
}
}

}

StairWayToHeavenCheck(HertzSelectScreenData->LogicData.st, {
HertzSelectScreenData->LogicData.ReturnFrameRate = StairWayToHeavenIdentifier;
HertzSelectScreenData->LogicData.CurrentStage = HertzSelectScreenStageFinished;
});

}