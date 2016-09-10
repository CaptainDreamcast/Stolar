#define DrawArrayToScreenInDisplayedDownCounterInActive	-1.0f
#define DrawArrayToScreenDisplayedRightCounterDisabled	-1.0f

#define DrawArrayToScreen(Array, StartPositionX, StartPositionY, PositionZ,  FontSizeX, FontSizeY, Color, WhichFont, TransformationData) DrawArrayToScreenPlus(Array, StartPositionX, StartPositionY, PositionZ,  FontSizeX, FontSizeY, Color, WhichFont, TransformationData, 0.0f, DrawArrayToScreenInDisplayedDownCounterInActive)
#define DrawArrayToScreenPlus(Array, StartPositionX, StartPositionY, PositionZ,  FontSizeX, FontSizeY, Color, WhichFont, TransformationData, DisplayedUp, DisplayedDownCounter) DrawArrayToScreenPlusPlus(Array, StartPositionX, StartPositionY, PositionZ,  FontSizeX, FontSizeY, Color, WhichFont, TransformationData, DisplayedUp, DisplayedDownCounter, OverallScreenPositionLeft, ScreenSizeX, NULL, DrawArrayReturnNothing)
#define DrawArrayToScreenD(Array, StartPositionX, StartPositionY, PositionZ,  FontSizeX, FontSizeY, Color, WhichFont, TransformationData, StartOffsetX, EndOffsetX, ReturnPositionX) DrawArrayToScreenPlusPlus(Array, StartPositionX, StartPositionY, PositionZ,  FontSizeX, FontSizeY, Color, WhichFont, TransformationData, 0.0f, DrawArrayToScreenInDisplayedDownCounterInActive, StartOffsetX, EndOffsetX, ReturnPositionX, DrawArrayReturnArraySizeX)

#define DrawArrayReturnNothing	0
#define DrawArrayReturnArraySizeX	1
#define DrawArrayReturnArraySizeY	2

void DrawArrayToScreenPlusPlus(char* Array, float StartPositionX, float StartPositionY, float PositionZ,  uint16 FontSizeX, uint16 FontSizeY, uint8 Color, uint8 WhichFont, TransformationStruct* TransformationData, float DisplayedUp, float DisplayedDownCounter, float StartOffsetX, float EndOffsetX, float* ReturnFloat, uint8 ReturnWhat){

uint16 CurrentDrawArrayPosition;
float PositionX, PositionY;
float DisplayedDown;
float Left, Right;

CurrentDrawArrayPosition = 0;
while(DisplayedUp >= 1.0f){
while(Array[CurrentDrawArrayPosition] != 0xA){
CurrentDrawArrayPosition++;
}
DisplayedUp-=1.0f;
DisplayedDownCounter-=1.0f;
}
DisplayedDown = 1.0f;

PositionX = StartPositionX;
PositionY = StartPositionY;
while(Array[CurrentDrawArrayPosition] != '\0' && !(Array[CurrentDrawArrayPosition] == 0xA && DisplayedDownCounter < 1.0f && DisplayedDownCounter > 0.0f)){
if(Array[CurrentDrawArrayPosition] == 0xA){
PositionX = StartPositionX;
PositionY +=FontSizeY + FontData[WhichFont].Loadable->FontHeaderData.InterLetterSpaceY;
DisplayedUp = 0.0f;

if(DisplayedDownCounter > 0.0f){
DisplayedDownCounter -= 1.0f;
if(DisplayedDownCounter < 1.0f) DisplayedDown = 1.0f-DisplayedDownCounter;
}
}
else{
if((PositionX+FontGetCharacterEffectiveSizeFromArrayX(WhichFont, Array[CurrentDrawArrayPosition])) > StartOffsetX && PositionX < EndOffsetX){
if(PositionX < StartOffsetX){
Left = ((StartOffsetX-PositionX)/FontGetCharacterEffectiveSizeFromArrayX(WhichFont, Array[CurrentDrawArrayPosition]));
PositionX = StartOffsetX;
}
else Left = FullLeftTexturePosition;
if((PositionX+FontGetCharacterEffectiveSizeFromArrayX(WhichFont, Array[CurrentDrawArrayPosition])) > EndOffsetX) Right = ((EndOffsetX-PositionX)/FontGetCharacterEffectiveSizeFromArrayX(WhichFont, Array[CurrentDrawArrayPosition]));
else Right = FullRightTexturePosition;

DrawSingleLetterToScreenAndTransformPlus(Array[CurrentDrawArrayPosition], PositionX, PositionY, PositionZ, FontSizeX, FontSizeY, Color, WhichFont, TransformationData, Left, Right, DisplayedUp, DisplayedDown);
}
else{
Left = FullLeftTexturePosition;
Right = FullRightTexturePosition;
}

PositionX += ((FullRightTexturePosition-Left)*FontGetCharacterEffectiveSizeFromArrayX(WhichFont, Array[CurrentDrawArrayPosition])) + FontData[WhichFont].Loadable->FontHeaderData.InterLetterSpaceX;
}
CurrentDrawArrayPosition++;
}

if(ReturnFloat != NULL) {
if(ReturnWhat == DrawArrayReturnArraySizeX) (*ReturnFloat) = PositionX-StartPositionX;
else if(ReturnWhat == DrawArrayReturnArraySizeY) (*ReturnFloat) = PositionY-StartPositionY;
}

}