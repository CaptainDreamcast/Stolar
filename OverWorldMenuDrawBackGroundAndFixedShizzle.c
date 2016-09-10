void OverWorldMenuDrawBackGroundAndFixedShizzle(OverWorldMenuStruct* OverWorldMenuData){

vector_t FinalVector[PolygonCornerAmount];

SetupVectors(FinalVector, OverWorldMenuData->Loadable->BackGroundPositionX, OverWorldMenuData->Loadable->BackGroundPositionY, OverWorldMenuData->Loadable->BackGroundPositionZ, OverWorldMenuData->Loadable->BackGroundTextureSizeX, OverWorldMenuData->Loadable->BackGroundTextureSizeY);
Transformation(FinalVector, &OverWorldMenuData->TransformationData);

DrawVectorTexture(
FinalVector, OverWorldMenuData->BackGroundTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
OverWorldMenuData->Loadable->BackGroundTextureSizeX, 
OverWorldMenuData->Loadable->BackGroundTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

if(OverWorldMenuData->LogicData.Stage == OverWorldMenuStageBuildUp){

OverWorldMenuData->TransformationData.RotationValueX+= (OverWorldMenuData->Loadable->BackGroundEndRotationValue-OverWorldMenuData->Loadable->BackGroundStartRotationValue)/(OverWorldMenuData->Loadable->BackGroundBuildUpTime*FrameRate);
if(OverWorldMenuData->TransformationData.RotationValueX >= OverWorldMenuData->Loadable->BackGroundEndRotationValue){
OverWorldMenuData->TransformationData.Active = 0;
OverWorldMenuData->TransformationData.RotationValueX = OverWorldMenuData->Loadable->BackGroundEndRotationValue;
OverWorldMenuData->LogicData.Stage = OverWorldMenuStageRunning;
}

}
else if(OverWorldMenuData->LogicData.Stage ==  OverWorldMenuStageBuildDown){

OverWorldMenuData->TransformationData.RotationValueX-= (OverWorldMenuData->Loadable->BackGroundEndRotationValue-OverWorldMenuData->Loadable->BackGroundStartRotationValue)/(OverWorldMenuData->Loadable->BackGroundBuildUpTime*FrameRate);
if(OverWorldMenuData->TransformationData.RotationValueX <= OverWorldMenuData->Loadable->BackGroundStartRotationValue){
OverWorldMenuData->TransformationData.Active = 0;
OverWorldMenuData->TransformationData.RotationValueX = OverWorldMenuData->Loadable->BackGroundStartRotationValue;
OverWorldMenuData->LogicData.Stage = OverWorldMenuStageFinished;
}

}


if(OverWorldMenuData->BackGroundData.HandActive){
SetupVectors(FinalVector, OverWorldMenuData->BackGroundData.HandPositionX, OverWorldMenuData->Loadable->HandPositionY, OverWorldMenuData->Loadable->HandPositionZ, OverWorldMenuData->Loadable->HandTextureSizeX, OverWorldMenuData->Loadable->HandTextureSizeY);

DrawVectorTexture(
FinalVector, OverWorldMenuData->HandTexture[(OverWorldMenuData->BackGroundData.HandActive-1)][OverWorldMenuData->BackGroundData.HandFrame], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
OverWorldMenuData->Loadable->HandTextureSizeX, 
OverWorldMenuData->Loadable->HandTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

if(OverWorldMenuData->BackGroundData.HandActive == OverWorldMenuHandSwipeRight){
OverWorldMenuData->BackGroundData.HandFrame = OverWorldMenuData->Loadable->HandFrameAmount*((OverWorldMenuData->BackGroundData.HandPositionX-OverWorldMenuData->Loadable->HandStartPositionX)/(OverWorldMenuData->Loadable->HandEndPositionX-OverWorldMenuData->Loadable->HandStartPositionX));
if(OverWorldMenuData->BackGroundData.HandFrame >= OverWorldMenuData->Loadable->HandActivatesScreenRotationFrameSwipeRight && !OverWorldMenuData->BackGroundData.HandTouchedScreen){
OverWorldMenuData->BackGroundData.HandTouchedScreen = OverWorldMenuHandTouchedScreen;
StartRotationYAdvanced((&OverWorldMenuData->LogicData.ActiveScreenTransformationData), (OverWorldMenuData->LogicData.ActiveScreenTransformationData.RotationValueY-(FullRotationValue/OverWorldMenuScreenAmount)));
OverWorldMenuData->LogicData.CaptureActiveScreen = -1;
OverWorldMenuData->LogicData.ActiveScreenRotationSpeedY -= (OverWorldMenuActiveScreenRotationStartValueForSixtyHertz*(SixtyHertz/FrameRate));
}
OverWorldMenuData->BackGroundData.HandPositionX += (OverWorldMenuData->Loadable->HandEndPositionX-OverWorldMenuData->Loadable->HandStartPositionX)/(OverWorldMenuData->Loadable->HandSwipeTime*FrameRate);
if(OverWorldMenuData->BackGroundData.HandPositionX >= OverWorldMenuData->Loadable->HandEndPositionX){
OverWorldMenuDeActivateHand();
}
}
else{
OverWorldMenuData->BackGroundData.HandFrame = OverWorldMenuData->Loadable->HandFrameAmount-(OverWorldMenuData->Loadable->HandFrameAmount*((OverWorldMenuData->BackGroundData.HandPositionX-OverWorldMenuData->Loadable->HandStartPositionX)/(OverWorldMenuData->Loadable->HandEndPositionX-OverWorldMenuData->Loadable->HandStartPositionX)));
if(OverWorldMenuData->BackGroundData.HandFrame >= OverWorldMenuData->Loadable->HandActivatesScreenRotationFrameSwipeLeft && !OverWorldMenuData->BackGroundData.HandTouchedScreen){
OverWorldMenuData->BackGroundData.HandTouchedScreen = OverWorldMenuHandTouchedScreen;
StartRotationYAdvanced((&OverWorldMenuData->LogicData.ActiveScreenTransformationData), (OverWorldMenuData->LogicData.ActiveScreenTransformationData.RotationValueY+(FullRotationValue/OverWorldMenuScreenAmount)));
OverWorldMenuData->LogicData.CaptureActiveScreen = 1;
OverWorldMenuData->LogicData.ActiveScreenRotationSpeedY += (OverWorldMenuActiveScreenRotationStartValueForSixtyHertz*(SixtyHertz/FrameRate));
}
OverWorldMenuData->BackGroundData.HandPositionX -= (OverWorldMenuData->Loadable->HandEndPositionX-OverWorldMenuData->Loadable->HandStartPositionX)/(OverWorldMenuData->Loadable->HandSwipeTime*FrameRate);
if(OverWorldMenuData->BackGroundData.HandPositionX <= OverWorldMenuData->Loadable->HandStartPositionX){
OverWorldMenuDeActivateHand();
}
}

}

}