void OverWorldMenuInputGeneral(OverWorldMenuStruct* OverWorldMenuData){

if(ButtonLegit(ButtonB, OverWorldMenuData->LogicData.ButtonInputData) || ButtonLegit(ButtonStart, OverWorldMenuData->LogicData.ButtonInputData)){
OverWorldMenuData->LogicData.Stage =  OverWorldMenuStageBuildDown;
StartRotationXAdvanced((&OverWorldMenuData->TransformationData), OverWorldMenuData->Loadable->BackGroundEndRotationValue);
}

if(ButtonLegit(ButtonR, OverWorldMenuData->LogicData.ButtonInputData) && OverWorldHandActivismAllowed){
OverWorldMenuActivateHand(OverWorldMenuData, OverWorldMenuHandSwipeLeft, OverWorldMenuData->Loadable->HandEndPositionX);
}
else if(ButtonLegit(ButtonL, OverWorldMenuData->LogicData.ButtonInputData) && OverWorldHandActivismAllowed){
OverWorldMenuActivateHand(OverWorldMenuData, OverWorldMenuHandSwipeRight, OverWorldMenuData->Loadable->HandStartPositionX);
}

}