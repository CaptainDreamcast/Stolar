void IconListScrollableDraw(
float DisplayedUp, float DisplayedDown, float DrawStartPositionX, float DrawStartPositionY, float DrawEndPositionY, float IconDrawPositionZ, float IconDrawSizeX, float IconDrawSizeY, 
float ScrollButtonPositionX, float ScrollButtonStartPositionY, float ScrollButtonPositionZ, float ScrollButtonSizeX, float ScrollButtonMinimumSizeY, float ScrollButtonMaximumSizeY,
PositionInFileStruct* PositionInFileData, uint8* IdentificationValueList, 
uint8 IconAmountPerRow, uint16 IconAmountMax, uint16 IconAmountMaxOverall, uint8 DisplayedRowAmount, uint16 IconDrawTextureSizeX, uint16 IconDrawTextureSizeY,
uint16 ScrollButtonTextureSizeX, uint16 ScrollButtonTextureSizeY,
pvr_ptr_t IconTextures, pvr_ptr_t ScrollButtonTexture,
TransformationStruct* TransformationData){

float UpFactor, DownFactor;
float PositionY;
float SizeY;
float Left, Right, Up, Down; 
uint8 DirtyDeedsDoneDirtCheap;
vector_t FinalVector[PolygonCornerAmount];

UpFactor = (DisplayedUp-((uint8)(DisplayedUp)));
DownFactor = 0.0f;
PositionY = DrawStartPositionY;
SizeY = (1.0f-UpFactor)*IconDrawSizeY;

for(DirtyDeedsDoneDirtCheap = (((uint8)(DisplayedUp))*IconAmountPerRow); ((DirtyDeedsDoneDirtCheap < ((((uint8)(DisplayedDown))+1)*IconAmountPerRow)) && (DirtyDeedsDoneDirtCheap < IconAmountMax)); DirtyDeedsDoneDirtCheap++){

if((DirtyDeedsDoneDirtCheap%IconAmountPerRow) == 0){
UpFactor = 0.0f;
PositionY += IconDrawSizeY;
if(DirtyDeedsDoneDirtCheap == (((uint8)(DisplayedDown))*IconAmountPerRow)){
SizeY = DrawEndPositionY-PositionY;
DownFactor = 1.0f-(SizeY/IconDrawSizeY);
}
else{
SizeY = IconDrawSizeY;
}
}

if(IdentificationValueList == NULL){
Left = PositionInFileData[DirtyDeedsDoneDirtCheap].Left;
Right = PositionInFileData[DirtyDeedsDoneDirtCheap].Right;
Up = PositionInFileData[DirtyDeedsDoneDirtCheap].Up+UpFactor;
Down = PositionInFileData[DirtyDeedsDoneDirtCheap].Down-DownFactor;
}
else{
Left = PositionInFileData[IdentificationValueList[DirtyDeedsDoneDirtCheap]].Left;
Right = PositionInFileData[IdentificationValueList[DirtyDeedsDoneDirtCheap]].Right;
Up = PositionInFileData[IdentificationValueList[DirtyDeedsDoneDirtCheap]].Up+UpFactor;
Down = PositionInFileData[IdentificationValueList[DirtyDeedsDoneDirtCheap]].Down-DownFactor;
}

SetupTransformAndDrawPlus(
FinalVector, TransformationData, 
IconTextures, 
DrawStartPositionX+((DirtyDeedsDoneDirtCheap%IconAmountPerRow)*IconDrawSizeX), 
PositionY, 
IconDrawPositionZ, IconDrawSizeX, SizeY,
IconDrawTextureSizeX, IconDrawTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 1.0f, 1.0f, 1.0f, 1.0f, 
Left, Right, Up, Down
);

}

if((IconAmountMax/((float)(IconAmountPerRow))) > DisplayedRowAmount){

SizeY = (ScrollButtonMinimumSizeY+((ScrollButtonMaximumSizeY-ScrollButtonMinimumSizeY)*(IconAmountMax/IconAmountMaxOverall)));

SetupTransformAndDrawSimplest(
FinalVector, TransformationData, 
ScrollButtonTexture, 
ScrollButtonPositionX, 
ScrollButtonStartPositionY+((ScrollButtonMaximumSizeY-SizeY)*(DisplayedUp/(((uint8)(IconAmountMax/((float)(IconAmountPerRow)))) - DisplayedRowAmount))),
ScrollButtonPositionZ, ScrollButtonSizeX, 
SizeY,
ScrollButtonTextureSizeX, ScrollButtonTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

}

}