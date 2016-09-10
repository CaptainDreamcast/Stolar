void EventSpeechDrawSpeechBubble(uint8 WhichSpeechBubble, EventSpeechStruct* EventSpeechData, OverWorldStruct* OverWorldData){

EventSpeechDrawSpeechBubbleGeneral(
OverWorldData, EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->SpeechBubbleType, 
EventSpeechData->LogicData->SpeechBubbles[WhichSpeechBubble].PositionX, EventSpeechData->LogicData->SpeechBubbles[WhichSpeechBubble].PositionY, 
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->PositionZ, 
EventSpeechData->LogicData->SpeechBubbles[WhichSpeechBubble].ArrayPosition, EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Array, 
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].ArrayLength, 
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].FontPositionX, EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontPositionY, 
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontPositionZ, 
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontSizeX, EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontSizeY, 
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontColor, EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->WhichFont
);

/*
vector_t FinalVector[PolygonCornerAmount];
float PositionY;
uint16 LettersRemaining;
uint8 CurrentRow;
uint8 CharacterBuffer;

SetupTransformAndDrawSimplest(FinalVector, NULL, 
OverWorldData->TextureData.SpeechBubbleTexture[EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->SpeechBubbleType], 
EventSpeechData->LogicData->SpeechBubbles[WhichSpeechBubble].PositionX, EventSpeechData->LogicData->SpeechBubbles[WhichSpeechBubble].PositionY, 
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->PositionZ, 
OverWorldData->Loadable->SpeechBubbles[SpeechBubbleType].TextureSizeX, OverWorldData->Loadable->SpeechBubbles[SpeechBubbleType].TextureSizeY, 
OverWorldData->Loadable->SpeechBubbles[SpeechBubbleType].TextureSizeX, OverWorldData->Loadable->SpeechBubbles[SpeechBubbleType].TextureSizeY, 
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL(PalettePositionFonts)), PVR_LIST_TR_POLY);

CharacterBuffer = ArrayEndSymbol;
PositionY = EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontPositionY;
LettersRemaining = EventSpeechData->LogicData->SpeechBubbles[WhichSpeechBubble].ArrayPosition;

CurrentRow = 0;
while(LettersRemaining){
if(EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].ArrayLength[CurrentRow] > LettersRemaining){
CharacterBuffer = EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Array[CurrentRow][LettersRemaining];
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Array[CurrentRow][LettersRemaining] = ArrayEndSymbol;
}

DrawArrayToScreen(EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Array[CurrentRow], 
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].FontPositionX[CurrentRow], PositionY, 
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontPositionZ,  
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontSizeX, EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontSizeY, 
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontColor, EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->WhichFont, NULL);

PositionY += FontSizeBetweenLettersY(EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontSizeY, EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->WhichFont);
if(EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].ArrayLength[CurrentRow] > LettersRemaining){
EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].Array[CurrentRow][LettersRemaining] = CharacterBuffer;
LettersRemaining = 0;
}
else LettersRemaining -= EventSpeechData->Loadable.SpeechBubbles[WhichSpeechBubble].ArrayLength[CurrentRow];
CurrentRow++;
}

*/
}