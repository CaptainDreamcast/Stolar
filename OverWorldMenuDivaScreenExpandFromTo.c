void OverWorldMenuDivaScreenExpandFromTo(OverWorldMenuStruct* OverWorldMenuData, uint8 BehindFlag, uint8 FrontFlag, float FromPositionX, float FromPositionY, float FromSizeX, float FromSizeY, float ToPositionX, float ToPositionY, float ToSizeX, float ToSizeY){

OverWorldMenuData->DivaData.ExpansionMode = OverWorldMenuDivaScreenExpand;
OverWorldMenuData->DivaData.ActiveScreenFlags = (FrontFlag | BehindFlag);

OverWorldMenuData->DivaData.ScreenInFront = FrontFlag;
OverWorldMenuData->DivaData.ScreenInBack = BehindFlag;

OverWorldMenuData->DivaData.ExpandEndPositionLeft = ToPositionX;
OverWorldMenuData->DivaData.ExpandEndPositionUp = ToPositionY;
OverWorldMenuData->DivaData.ExpandEndPositionRight = ToPositionX+ToSizeX;
OverWorldMenuData->DivaData.ExpandEndPositionDown = ToPositionY+ToSizeY;

OverWorldMenuData->DivaData.ExpandStartPositionLeft = OverWorldMenuData->DivaData.ExpandPositionLeft = FromPositionX;
OverWorldMenuData->DivaData.ExpandStartPositionUp = OverWorldMenuData->DivaData.ExpandPositionUp = FromPositionY;
OverWorldMenuData->DivaData.ExpandStartPositionRight = OverWorldMenuData->DivaData.ExpandPositionRight = FromPositionX+FromSizeX;
OverWorldMenuData->DivaData.ExpandStartPositionDown = OverWorldMenuData->DivaData.ExpandPositionDown = FromPositionY+FromSizeY;


SetTransformationDataPositionVector((&OverWorldMenuData->DivaData.ExpansionTransformationData), FromPositionX+(FromSizeX/2), FromPositionY+(FromSizeY/2), 0.0f);
if(FromSizeX < ToSizeX){ 
StartZoomingPlusAdvanced((&OverWorldMenuData->DivaData.ExpansionTransformationData), (FromSizeX/ToSizeX), (FromSizeY/ToSizeY));
OverWorldMenuData->DivaData.ExpansionMode = OverWorldMenuDivaScreenExpand;
}
else{
StartZoomingPlusAdvanced((&OverWorldMenuData->DivaData.ExpansionTransformationData), 1.0f, 1.0f);
OverWorldMenuData->DivaData.ExpansionMode = OverWorldMenuDivaScreenDexpand;
}

}