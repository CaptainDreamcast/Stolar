#define TextureAtlasGetFilePositionLeft(SingleTextureSizeX, TextureSizeX, CurrentAnimation)	(TextureAtlasGetFilePositionSize(SingleTextureSizeX, TextureSizeX)*(CurrentAnimation%(TextureSizeX/SingleTextureSizeX)))
#define TextureAtlasGetFilePositionUp(SingleTextureSizeY, TextureSizeY, CurrentAnimation)	(TextureAtlasGetFilePositionSize(SingleTextureSizeY, TextureSizeY)*(CurrentAnimation/(TextureSizeX/SingleTextureSizeX)))

#define TextureAtlasGetFilePositionSize(SingleTextureSize, TextureSize)	((SingleTextureSize/(float)TextureSize))

#define TextureAtlasDrawSimplest(CurrentTexture, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, SingleTextureSizeX, SingleTextureSizeY, Format, List)		TextureAtlasDraw(CurrentTexture, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, SingleTextureSizeX, SingleTextureSizeY, Format, List, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue)
#define TextureAtlasDraw(CurrentTexture, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, SingleTextureSizeX, SingleTextureSizeY, Format, List, Alpha, Red, Green, Blue)		TextureAtlasDrawAdvanced(CurrentTexture, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, SingleTextureSizeX, SingleTextureSizeY, Format, List, Alpha, Red, Green, Blue, FullSmallTexturePosition, FullBigTexturePosition, FullSmallTexturePosition, FullBigTexturePosition)
#define TextureAtlasDrawAdvanced(CurrentTexture, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, SingleTextureSizeX, SingleTextureSizeY, Format, List, Alpha, Red, Green, Blue, Left, Right, Up, Down)		TextureAtlasDrawAdvancedPlus(CurrentTexture, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, SingleTextureSizeX, SingleTextureSizeY, Format, List, Alpha, Red, Green, Blue, Left, Right, Up, Down, TextureDrawReverseNot)

#define TextureAtlasDrawWithReverseSimplest(CurrentTexture, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, SingleTextureSizeX, SingleTextureSizeY, Format, List, Reverse)		TextureAtlasDrawAdvancedPlus(CurrentTexture, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, SingleTextureSizeX, SingleTextureSizeY, Format, List, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue, FullSmallTexturePosition, FullBigTexturePosition, FullSmallTexturePosition, FullBigTexturePosition, Reverse)
#define TextureAtlasDrawWithReverse(CurrentTexture, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, SingleTextureSizeX, SingleTextureSizeY, Format, List, Alpha, Red, Green, Blue, Reverse)		TextureAtlasDrawAdvancedPlus(CurrentTexture, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, SingleTextureSizeX, SingleTextureSizeY, Format, List, Alpha, Red, Green, Blue, FullSmallTexturePosition, FullBigTexturePosition, FullSmallTexturePosition, FullBigTexturePosition, Reverse)


void TextureAtlasDrawAdvancedPlus(uint16 CurrentTexture, TransformationStruct* TransformationData, pvr_ptr_t Texture, float PositionX, float PositionY, float PositionZ, float SizeX, float SizeY,
uint16 TextureSizeX, uint16 TextureSizeY, uint16 SingleTextureSizeX, uint16 SingleTextureSizeY, uint32 Format, uint32 List, float Alpha, float Red, float Green, float Blue, 
float Left, float Right, float Up, float Down, uint8 Reverse){

vector_t FinalVector[PolygonCornerAmount];
float TextureAtlasLeft, TextureAtlasUp;
float FilePositionSizeX, FilePositionSizeY;
float FinalLeft, FinalRight;

TextureAtlasLeft = TextureAtlasGetFilePositionLeft(SingleTextureSizeX, TextureSizeX, CurrentTexture);
TextureAtlasUp = TextureAtlasGetFilePositionUp(SingleTextureSizeY, TextureSizeY, CurrentTexture);
FilePositionSizeX = TextureAtlasGetFilePositionSize(SingleTextureSizeX, TextureSizeX);
FilePositionSizeY = TextureAtlasGetFilePositionSize(SingleTextureSizeY, TextureSizeY);

if(Reverse){
FinalLeft = TextureAtlasLeft+(FilePositionSizeX*Right);
FinalRight = TextureAtlasLeft+(FilePositionSizeX*Left);
}
else{
FinalLeft = TextureAtlasLeft+(FilePositionSizeX*Left);
FinalRight = TextureAtlasLeft+(FilePositionSizeX*Right);
}

SetupTransformAndDrawPlus(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List, Alpha, Red, Green, Blue,
FinalLeft, FinalRight, TextureAtlasUp+(FilePositionSizeY*Up), TextureAtlasUp+(FilePositionSizeY*Down));

}