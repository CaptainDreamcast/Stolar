#define RedSpotScreenDrawMovingLetterMovementTypeAmount		2

#define RedSpotScreenDrawMovingLetterLogicRight()	RedSpotScreenDrawMovingLetterLogicGeneral(>, +=, -=, OverallScreenPositionLeft)
#define RedSpotScreenDrawMovingLetterLogicLeft()	RedSpotScreenDrawMovingLetterLogicGeneral(<=, -=, +=, (-ArraySizeX))

#define RedSpotScreenDrawMovingLetterLogicGeneral(EqualityOperation, AdditionOperation, SubtractionOperation, CheckForValue)	{  \
RedSpotScreenData->LogicData.MovingArrayCurrentPositionX[WhichLine] AdditionOperation (ScreenSizeX/(RedSpotScreenData->Loadable->MovingArrayTraverseScreenTimeInSeconds*FrameRate)); \
if(RedSpotScreenData->LogicData.MovingArrayCurrentPositionX[WhichLine] EqualityOperation CheckForValue){ \
RedSpotScreenData->LogicData.MovingArrayCurrentPositionX[WhichLine] SubtractionOperation ArraySizeX; \
} \
}

void RedSpotScreenDrawMovingLetters(RedSpotScreenStruct* RedSpotScreenData){

float PositionY;
float ArraySizeX;
uint8 WhichLine;

PositionY = OverallScreenPositionUp;
for(WhichLine = 0; WhichLine < RedSpotScreenMovingArrayAmount; WhichLine++){

DrawArrayOverLineRepeated(RedSpotScreenData->LogicData.MovingArray[WhichLine], RedSpotScreenData->Loadable->MovingArraySize[WhichLine], 
OverallScreenPositionLeft, ScreenSizeX, RedSpotScreenData->LogicData.MovingArrayCurrentPositionX[WhichLine], 
PositionY, RedSpotScreenData->Loadable->MovingArrayPositionZ, 
RedSpotScreenData->Loadable->MovingArrayFontSizeX, RedSpotScreenData->Loadable->MovingArrayFontSizeY, 
RedSpotScreenData->Loadable->MovingArrayColor, RedSpotScreenData->Loadable->MovingArrayWhichFont, NULL, &ArraySizeX);
if(WhichLine%RedSpotScreenDrawMovingLetterMovementTypeAmount){
RedSpotScreenDrawMovingLetterLogicRight();
} 
else{ 
RedSpotScreenDrawMovingLetterLogicLeft()
}

PositionY += FontSizeBetweenLettersY(RedSpotScreenData->Loadable->MovingArrayFontSizeY, RedSpotScreenData->Loadable->MovingArrayWhichFont);
}

}