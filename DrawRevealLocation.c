void DrawRevealLocation(RevealLocationStruct* RevealLocationData){

vector_t FinalVector[PolygonVectorAmount];

SetupVectors(FinalVector, RevealLocationData->PositionX, RevealLocationPositionY, RevealLocationPositionZ, TileData->TileHeaderData->RevealLocationTextureSizeX, TileData->TileHeaderData->RevealLocationTextureSizeY);
Transformation(FinalVector, &OverWorldInterFaceData->TransformationData);

DrawVectorTexture(
FinalVector, TileData->RevealLocationTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
TileData->TileHeaderData->RevealLocationTextureSizeX, 
TileData->TileHeaderData->RevealLocationTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

if(RevealLocationData->PositionX < RevealLocationEndPositionX){
if(RevealLocationData->PositionX > RevealLocationSlowDownStartPositionX && RevealLocationData->PositionX < RevealLocationSlowDownEndPositionX){
RevealLocationData->PositionX+= (RevealLocationSlowDownEndPositionX-RevealLocationSlowDownStartPositionX)/(RevealLocationSlowDownDurationInSeconds*FrameRate);
}
else RevealLocationData->PositionX+= (RevealLocationSlowDownStartPositionX-RevealLocationStartPositionX)/(RevealLocationToSlowDownDurationInSeconds*FrameRate);
if(RevealLocationData->PositionX > RevealLocationEndPositionX) RevealLocationData->PositionX = RevealLocationEndPositionX;
}

}