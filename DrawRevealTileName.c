uint8 DrawRevealTileName(RevealTileNameStruct* RevealTileNameData){

uint8 ReturnValue;
vector_t FinalVector[PolygonCornerAmount];

SetupVectors(FinalVector, RevealTileNameData->PositionX, RevealTileNamePositionY, RevealTileNamePositionZ, OverWorldInterFaceData->Loadable->RevealTileNameTextureSizeX, OverWorldInterFaceData->Loadable->RevealTileNameTextureSizeY);
Transformation(FinalVector, &OverWorldInterFaceData->TransformationData);

DrawVectorTexture(
FinalVector, GraphicalUserInterFaceData->RevealTileNameTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
OverWorldInterFaceData->Loadable->RevealTileNameTextureSizeX, 
OverWorldInterFaceData->Loadable->RevealTileNameTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

DrawArrayToScreen(TileData->TileHeaderData->TileName, RevealTileNameData->PositionX+RevealTileNameArrayOffsetX, RevealTileNamePositionY+RevealTileNameArrayOffsetY,  RevealTileNameArrayFontSizeX, RevealTileNameArrayFontSizeY, RevealTileNameArrayColor, RevealTileNameArrayFont, &OverWorldInterFaceData->TransformationData)

ReturnValue = DrawRevealTileNameOn;
if(RevealTileNameData->Stage == RevealTileNameStageAppear){
RevealTileNameData->PositionX-= (RevealTileNameDataStartPositionX-RevealTileNameDataEndPositionX)/(RevealTileNameStageAppearTimeInSeconds*FrameRate);
if(RevealTileNameData->PositionX <= RevealTileNameDataEndPositionX) {
RevealTileNameData->PositionX = RevealTileNameDataEndPositionX;
RevealTileNameData->Stage = RevealTileNameStay;
}
}
else if(RevealTileNameData->Stage == RevealTileNameStageStay){
RevealTileNameData->StayTicks++;
if(RevealTileNameData->StayTicks > (RevealTileNameStageStayTimeInSeconds*FrameRate)) RevealTileNameData->Stage = RevealTileNameStageDisappear;
}
else if(RevealTileNameData->Stage == RevealTileNameStageDisappear){
RevealTileNameData->PositionX+= (RevealTileNameDataStartPositionX-RevealTileNameDataEndPositionX)/(RevealTileNameStageAppearTimeInSeconds*FrameRate);
if(RevealTileNameData->PositionX >= RevealTileNameDataStartPositionX) {
RevealTileNameData->PositionX = RevealTileNameDataStartPositionX;
ReturnValue = DrawRevealTileNameOver;
}
}

return(ReturnValue);
}