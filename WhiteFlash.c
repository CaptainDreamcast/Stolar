uint8 WhiteFlash(float* TransparencyValue, float* TransparencyChangeValue, uint8 PositionZ){

vector_t FinalVector[PolygonCornerAmount];
uint8 ReturnValue;

ReturnValue = 1;

SetupVectors(FinalVector, 0, 0, PositionZ, ScreenSizeX, ScreenSizeY);

DrawVectorTexture(
FinalVector, WhiteTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
WhiteTextureSizeX, WhiteTextureSizeY, 
*TransparencyValue, 1.0f, 1.0f, 1.0f);


*TransparencyValue+=(*TransparencyChangeValue);
if(*TransparencyValue >= 1.0f) *TransparencyChangeValue = -(*TransparencyChangeValue);
else if(*TransparencyValue <= 0.0f) ReturnValue = 1;
else ReturnValue = 0;

return(ReturnValue);
}