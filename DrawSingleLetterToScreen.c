
#define DrawSingleLetterToScreenAndTransform(LetterToBeDrawn, PositionX, PositionY, PositionZ, FontSizeX, FontSizeY, Color, WhichFont, TransformationData) DrawSingleLetterToScreenAndTransformPlus(LetterToBeDrawn, PositionX, PositionY, PositionZ, FontSizeX, FontSizeY, Color, WhichFont, TransformationData, 0.0f, 1.0f, 0.0f, 1.0f)

void DrawSingleLetterToScreenAndTransformPlus(uint8 LetterToBeDrawn, float PositionX, float PositionY, float PositionZ, uint16 FontSizeX, uint16 FontSizeY, uint8 Color, uint8 WhichFont, TransformationStruct* TransformationData, float Left, float Right, float Up, float Down){

vector_t FinalVector[PolygonCornerAmount];
float Red, Green, Blue;

ColorToFloats(Color, Red, Green, Blue);

LetterToBeDrawn -= FontIncludedLetterOffset;
SetupTransformAndDrawPlus(FinalVector, TransformationData, FontData[WhichFont].Texture, 
PositionX, PositionY+(FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].RelativeDrawOffsetUp*FontSizeY), PositionZ, 
(FontGetCharacterEffectiveSizeX(WhichFont, LetterToBeDrawn)*(Right-Left)), 
(FontGetCharacterDrawSizeY(WhichFont, LetterToBeDrawn)*(Down-Up)), 
FontData[WhichFont].Loadable->FontHeaderData.TextureSizeX, FontData[WhichFont].Loadable->FontHeaderData.TextureSizeY, 
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL(PalettePositionFonts)), PVR_LIST_TR_POLY, FullColorFloatValue, Red, Green, Blue, 
FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetLeft+((FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetRight-FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetLeft)*Left), 
FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetLeft+((FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetRight-FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetLeft)*Right), 
FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetUp+((FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetDown-FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetUp)*Up), 
FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetUp+((FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetDown-FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].TextureFileOffsetUp)*Down)
);


}

#define DrawSingleLetterToScreen(LetterToBeDrawn, PositionX, PositionY, PositionZ, FontSizeX, FontSizeY, Color, WhichFont) 	DrawSingleLetterToScreenAndTransform(LetterToBeDrawn, PositionX, PositionY, PositionZ, FontSizeX, FontSizeY, Color, WhichFont, NULL)