void EventSpeechDrawSpeechBubbleGeneral(
OverWorldStruct* OverWorldData, uint8 SpeechBubbleType, 
float SpeechBubblePositionX, float SpeechBubblePositionY, float SpeechBubblePositionZ, 
uint16 ArrayPosition, char** Array, uint16* ArrayLength, 
float* FontPositionX, float FontPositionY, float FontPositionZ, 
float FontSizeX, float FontSizeY, 
uint8 FontColor, uint8 WhichFont
){

vector_t FinalVector[PolygonCornerAmount];
float PositionY;
uint16 LettersRemaining;
uint8 CurrentRow;
uint8 CharacterBuffer;

SetupTransformAndDrawSimplest(FinalVector, NULL, 
OverWorldData->TextureData.SpeechBubbleTexture[SpeechBubbleType], 
SpeechBubblePositionX, SpeechBubblePositionY, SpeechBubblePositionZ, 
OverWorldData->Loadable->SpeechBubbles[SpeechBubbleType].TextureSizeX, OverWorldData->Loadable->SpeechBubbles[SpeechBubbleType].TextureSizeY, 
OverWorldData->Loadable->SpeechBubbles[SpeechBubbleType].TextureSizeX, OverWorldData->Loadable->SpeechBubbles[SpeechBubbleType].TextureSizeY, 
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL(PalettePositionFonts)), PVR_LIST_TR_POLY);

CharacterBuffer = ArrayEndSymbol;
PositionY = FontPositionY;
LettersRemaining = ArrayPosition;

CurrentRow = 0;
while(LettersRemaining){
if(ArrayLength[CurrentRow] > LettersRemaining){
CharacterBuffer = Array[CurrentRow][LettersRemaining];
Array[CurrentRow][LettersRemaining] = ArrayEndSymbol;
}

DrawArrayToScreen(Array[CurrentRow], 
SpeechBubblePositionX+FontPositionX[CurrentRow], SpeechBubblePositionY+PositionY, FontPositionZ,  
FontSizeX, FontSizeY, 
FontColor, WhichFont, NULL);

PositionY += FontSizeBetweenLettersY(FontSizeY, WhichFont);
if(ArrayLength[CurrentRow] > LettersRemaining){
Array[CurrentRow][LettersRemaining] = CharacterBuffer;
LettersRemaining = 0;
}
else LettersRemaining -= ArrayLength[CurrentRow];
CurrentRow++;
}
}