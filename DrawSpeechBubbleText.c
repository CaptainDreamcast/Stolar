void DrawSpeechBubbleText(SpeechBubbleActiveStruct* SpeechBubbleActiveData, SpeechBubbleStruct* SpeechBubbleData){

uint16 CurrentDrawArrayPosition;
float PositionX, PositionY;
uint8 WhichRow;

WhichRow = 0;
CurrentDrawArrayPosition = 0;
PositionX = SpeechBubbleActiveData->FontPositionX[WhichRow];
PositionY = SpeechBubbleActiveData->FontPositionY;
while(CurrentDrawArrayPosition < SpeechBubbleActiveData->ArrayPosition){
if(SpeechBubbleData->ActualArray[CurrentDrawArrayPosition] == 0xA){
WhichRow++;
PositionX = SpeechBubbleActiveData->FontPositionX[WhichRow];
PositionY += SpeechBubbleData->FontSizeY + FontData[SpeechBubbleData->WhichFont].Loadable->FontHeaderData.InterLetterSpaceY;
}
else{
DrawSingleLetterToScreen(SpeechBubbleData->ActualArray[CurrentDrawArrayPosition], PositionX, PositionY, SpeechBubbleData->FontPositionZ, SpeechBubbleData->FontSizeX, SpeechBubbleData->FontSizeY, SpeechBubbleData->FontColor, SpeechBubbleData->WhichFont);
PositionX += SpeechBubbleData->FontSizeX + FontData[SpeechBubbleData->WhichFont].Loadable->FontHeaderData.InterLetterSpaceX;
}
CurrentDrawArrayPosition++;
}

}