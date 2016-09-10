void OverWorldMenuLogicGeneral(OverWorldMenuStruct* OverWorldMenuData, StolarOverWorldStruct* StolarOverWorldData){

if(OverWorldMenuData->LogicData.ActiveScreenTransformationData.RotationValueY != NoRotationValue){
OverWorldMenuData->LogicData.ActiveScreenTransformationData.RotationValueY += OverWorldMenuData->LogicData.ActiveScreenRotationSpeedY;
if(
(OverWorldMenuData->LogicData.ActiveScreenRotationSpeedY > 0 && OverWorldMenuData->LogicData.ActiveScreenTransformationData.RotationValueY < NoRotationValue) || 
(OverWorldMenuData->LogicData.ActiveScreenRotationSpeedY < 0 && OverWorldMenuData->LogicData.ActiveScreenTransformationData.RotationValueY > NoRotationValue)
){
OverWorldMenuData->LogicData.ActiveScreenRotationSpeedY = 0;
OverWorldMenuData->LogicData.ActiveScreenTransformationData.RotationValueY = NoRotationValue;
OverWorldMenuData->LogicData.ActiveScreenTransformationData.Active = 0;
}
else{
if(OverWorldMenuData->LogicData.ActiveScreenRotationSpeedY > 0) OverWorldMenuData->LogicData.ActiveScreenRotationSpeedY -= (OverWorldMenuData->Loadable->ActiveScreenRotationDecreaseForSixtyHertz*(SixtyHertz/FrameRate));
else  OverWorldMenuData->LogicData.ActiveScreenRotationSpeedY += (OverWorldMenuData->Loadable->ActiveScreenRotationDecreaseForSixtyHertz*(SixtyHertz/FrameRate));
}
}

if(OverWorldMenuData->LogicData.CaptureActiveScreen){
OverWorldMenuCaptureActiveScreen(OverWorldMenuData, StolarOverWorldData);
OverWorldMenuData->LogicData.ActiveScreen += OverWorldMenuData->LogicData.CaptureActiveScreen;
OverWorldMenuData->LogicData.CaptureActiveScreen = 0;
}

if(OverWorldMenuData->DivaData.ExpansionMode == OverWorldMenuDivaScreenExpand){

OverWorldMenuData->DivaData.ExpandPositionLeft -= ((OverWorldMenuData->DivaData.ExpandStartPositionLeft-OverWorldMenuData->DivaData.ExpandEndPositionLeft)/((OverWorldMenuData->Loadable->DivaDataLoadable.ExpansionDuration)*FrameRate));
OverWorldMenuData->DivaData.ExpandPositionRight += ((OverWorldMenuData->DivaData.ExpandEndPositionRight-OverWorldMenuData->DivaData.ExpandStartPositionRight)/((OverWorldMenuData->Loadable->DivaDataLoadable.ExpansionDuration)*FrameRate));
OverWorldMenuData->DivaData.ExpandPositionUp -= ((OverWorldMenuData->DivaData.ExpandStartPositionUp-OverWorldMenuData->DivaData.ExpandEndPositionUp)/((OverWorldMenuData->Loadable->DivaDataLoadable.ExpansionDuration)*FrameRate));
OverWorldMenuData->DivaData.ExpandPositionDown += ((OverWorldMenuData->DivaData.ExpandEndPositionDown-OverWorldMenuData->DivaData.ExpandStartPositionDown)/((OverWorldMenuData->Loadable->DivaDataLoadable.ExpansionDuration)*FrameRate));

if(OverWorldMenuData->DivaData.ExpandPositionLeft <= OverWorldMenuData->DivaData.ExpandEndPositionLeft){
OverWorldMenuData->DivaData.ExpansionMode = OverWorldMenuDivaScreenNoExpand;
OverWorldMenuData->DivaData.ActiveScreenFlags &= ~OverWorldMenuData->DivaData.ScreenInBack;
OverWorldMenuData->DivaData.ScreenInBack = OverWorldMenuDivaNoScreenActiveFlag;
DeActivateTransformationData((&OverWorldMenuData->DivaData.ExpansionTransformationData));
}
else{
SetTransformationDataPositionVector((&OverWorldMenuData->DivaData.ExpansionTransformationData), 
OverWorldMenuData->DivaData.ExpandPositionLeft+((OverWorldMenuData->DivaData.ExpandPositionRight-OverWorldMenuData->DivaData.ExpandPositionLeft)/2), 
OverWorldMenuData->DivaData.ExpandPositionUp+((OverWorldMenuData->DivaData.ExpandPositionDown-OverWorldMenuData->DivaData.ExpandPositionUp)/2), 
0.0f);
SetScaleValuePlusAdvanced((&OverWorldMenuData->DivaData.ExpansionTransformationData), 
((OverWorldMenuData->DivaData.ExpandPositionRight-OverWorldMenuData->DivaData.ExpandPositionLeft)/(OverWorldMenuData->DivaData.ExpandEndPositionRight-OverWorldMenuData->DivaData.ExpandEndPositionLeft)),
((OverWorldMenuData->DivaData.ExpandPositionDown-OverWorldMenuData->DivaData.ExpandPositionUp)/(OverWorldMenuData->DivaData.ExpandEndPositionDown-OverWorldMenuData->DivaData.ExpandEndPositionUp))
);
}

}
else if(OverWorldMenuData->DivaData.ExpansionMode == OverWorldMenuDivaScreenDexpand){

OverWorldMenuData->DivaData.ExpandPositionLeft += ((OverWorldMenuData->DivaData.ExpandEndPositionLeft-OverWorldMenuData->DivaData.ExpandStartPositionLeft)/((OverWorldMenuData->Loadable->DivaDataLoadable.ExpansionDuration)*FrameRate));
OverWorldMenuData->DivaData.ExpandPositionRight -= ((OverWorldMenuData->DivaData.ExpandStartPositionRight-OverWorldMenuData->DivaData.ExpandEndPositionRight)/((OverWorldMenuData->Loadable->DivaDataLoadable.ExpansionDuration)*FrameRate));
OverWorldMenuData->DivaData.ExpandPositionUp += ((OverWorldMenuData->DivaData.ExpandEndPositionUp-OverWorldMenuData->DivaData.ExpandStartPositionUp)/((OverWorldMenuData->Loadable->DivaDataLoadable.ExpansionDuration)*FrameRate));
OverWorldMenuData->DivaData.ExpandPositionDown -= ((OverWorldMenuData->DivaData.ExpandStartPositionDown-OverWorldMenuData->DivaData.ExpandEndPositionDown)/((OverWorldMenuData->Loadable->DivaDataLoadable.ExpansionDuration)*FrameRate));

if(OverWorldMenuData->DivaData.ExpandPositionLeft >= OverWorldMenuData->DivaData.ExpandEndPositionLeft){
OverWorldMenuData->DivaData.ExpansionMode = OverWorldMenuDivaScreenNoExpand;
OverWorldMenuData->DivaData.ActiveScreenFlags &= ~OverWorldMenuData->DivaData.ScreenInFront;
OverWorldMenuData->DivaData.ScreenInFront = OverWorldMenuData->DivaData.ScreenInBack;
OverWorldMenuData->DivaData.ScreenInBack = OverWorldMenuDivaNoScreenActiveFlag;
DeActivateTransformationData((&OverWorldMenuData->DivaData.ExpansionTransformationData));
}
else{
SetTransformationDataPositionVector((&OverWorldMenuData->DivaData.ExpansionTransformationData), 
OverWorldMenuData->DivaData.ExpandPositionLeft+((OverWorldMenuData->DivaData.ExpandPositionRight-OverWorldMenuData->DivaData.ExpandPositionLeft)/2), 
OverWorldMenuData->DivaData.ExpandPositionUp+((OverWorldMenuData->DivaData.ExpandPositionDown-OverWorldMenuData->DivaData.ExpandPositionUp)/2), 
0.0f);
SetScaleValuePlusAdvanced((&OverWorldMenuData->DivaData.ExpansionTransformationData), 
((OverWorldMenuData->DivaData.ExpandPositionRight-OverWorldMenuData->DivaData.ExpandPositionLeft)/(OverWorldMenuData->DivaData.ExpandStartPositionRight-OverWorldMenuData->DivaData.ExpandStartPositionLeft)),
((OverWorldMenuData->DivaData.ExpandPositionDown-OverWorldMenuData->DivaData.ExpandPositionUp)/(OverWorldMenuData->DivaData.ExpandStartPositionDown-OverWorldMenuData->DivaData.ExpandStartPositionUp))
);
}

}

}