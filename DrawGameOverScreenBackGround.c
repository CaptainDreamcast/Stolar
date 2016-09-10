void DrawGameOverScreenBackGround(GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, float AlphaValueBackGround, float* MovementBackGround, char* BackGroundColor, TransformationStruct* TransformationData){

vector_t FinalVector[GameOverScreenBackGroundAmount*2][PolygonCornerAmount];
float PositionY, Red, Green, Blue;
uint8 CurrentLine, CurrentColor;

CurrentLine = 0;
while(CurrentLine<GameOverScreenBackGroundAmount){


if(!CurrentLine){
PositionY = -GameOverScreenBackGroundTextureSizeY+((ScreenSizeY%GameOverScreenBackGroundTextureSizeY)/2.0f);
for(CurrentLine = 0; CurrentLine<GameOverScreenBackGroundAmount; CurrentLine+=2){

SetupVectors(FinalVector[CurrentLine*2], (*MovementBackGround)-ScreenSizeX, PositionY, 1, ScreenSizeX, GameOverScreenBackGroundTextureSizeY);
SetupVectors(FinalVector[CurrentLine*2+1], (*MovementBackGround), PositionY, 1, ScreenSizeX, GameOverScreenBackGroundTextureSizeY);

PositionY += GameOverScreenBackGroundTextureSizeY*2;
}
}
else{
PositionY = (ScreenSizeY%GameOverScreenBackGroundTextureSizeY)/2.0f;
for(CurrentLine = 1; CurrentLine<GameOverScreenBackGroundAmount; CurrentLine+=2){

SetupVectors(FinalVector[CurrentLine*2], ScreenSizeX-(*MovementBackGround), PositionY, 1, ScreenSizeX, GameOverScreenBackGroundTextureSizeY);
SetupVectors(FinalVector[CurrentLine*2+1], -(*MovementBackGround), PositionY, 1, ScreenSizeX, GameOverScreenBackGroundTextureSizeY);

PositionY += GameOverScreenBackGroundTextureSizeY*2;
}
}

}


if(TransformationData != NULL && TransformationData->Active){
for(CurrentLine=0; CurrentLine<GameOverScreenBackGroundAmount*2; CurrentLine++){
Transformation(FinalVector[CurrentLine], TransformationData);
}
}

CurrentColor = *BackGroundColor;

for(CurrentLine=0; CurrentLine<GameOverScreenBackGroundAmount*2; CurrentLine++){

ColorToFloats(CurrentColor, Red, Green, Blue);

DrawVectorTexturePlus(
FinalVector[CurrentLine], GraphicalUserInterFaceData->GameOverScreenTexture[GameOverScreenBackGroundTexturePlus], 
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL(GameOverScreenPaletteOffset/GameOverScreenPaletteSize)), PVR_LIST_TR_POLY, 
GameOverScreenTextureSizeX, GameOverScreenTextureSizeY,
AlphaValueBackGround, Red, Green, Blue, GameOverScreenBackGroundTexturePositionLeft, GameOverScreenBackGroundTexturePositionRight, 0.0f, 1.0f
);

CurrentColor++;
if(CurrentColor >= ColorAmountSansBlack) CurrentColor-=ColorAmountSansBlack;
}

(*MovementBackGround)+=GameOverScreenBackGroundMovement;
if(*MovementBackGround >= ScreenSizeX){
(*MovementBackGround)-=ScreenSizeX;

(*BackGroundColor)--;
if(*BackGroundColor < 0) *BackGroundColor+=ColorAmountSansBlack;

}
}