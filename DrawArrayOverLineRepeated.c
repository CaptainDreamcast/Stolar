void DrawArrayOverLineRepeated(char* Array, uint16 ArraySize, float StartPositionX, float EndPositionX, float CurrentPositionX, float PositionY, float PositionZ, uint16 FontSizeX, uint16 FontSizeY, uint8 Color, uint8 WhichFont, TransformationStruct* TransformationData, float* ArraySizeFetcherX){

float ArraySizeX;

ArraySizeX = 0.0f;
while(CurrentPositionX < EndPositionX){

DrawArrayToScreenD(Array, CurrentPositionX, PositionY, PositionZ,  
FontSizeX, FontSizeY, Color, WhichFont, TransformationData, StartPositionX, EndPositionX, &ArraySizeX);
CurrentPositionX+=ArraySizeX;

}

if(ArraySizeFetcherX != NULL) (*ArraySizeFetcherX) = ArraySizeX;
}