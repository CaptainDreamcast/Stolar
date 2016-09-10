#define EscalationTextureSizeX 		512
#define EscalationTextureSizeY 		256

#define EscalationTexturePositionY	98
#define EscalationTexturePositionZ	8
#define EscalationWhiteFlashPositionZ	9

#define EscalationDrawnAmount		2
#define EscalationPrimeDuration		2

#define ImminentTextureIdentifier	0
#define EscalationTextureIdentifier	1

#define EscalationStaticTicks		3

uint8 DrawFightEscalation(GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, EscalationStruct* EscalationData){

vector_t FinalVector[EscalationDrawnAmount][PolygonCornerAmount];
uint8 ReturnValue;

ReturnValue = 0;

SetupVectors(FinalVector[ImminentTextureIdentifier], EscalationData->PositionX[ImminentTextureIdentifier], EscalationData->PositionY[ImminentTextureIdentifier], EscalationTexturePositionZ, EscalationTextureSizeX, EscalationTextureSizeY/2);
SetupVectors(FinalVector[EscalationTextureIdentifier], EscalationData->PositionX[EscalationTextureIdentifier], EscalationData->PositionY[EscalationTextureIdentifier], EscalationTexturePositionZ, EscalationTextureSizeX, EscalationTextureSizeY/2);

DrawVectorTexturePlus(
FinalVector[ImminentTextureIdentifier], GraphicalUserInterFaceData->EscalationTexture[EscalationData->CurrentFrame], 
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL(EscalationPaletteOffset/EscalationPaletteSize)), PVR_LIST_TR_POLY, 
EscalationTextureSizeX, EscalationTextureSizeY,
1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.5f
);

DrawVectorTexturePlus(
FinalVector[EscalationTextureIdentifier], GraphicalUserInterFaceData->EscalationTexture[EscalationData->CurrentFrame], 
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL(EscalationPaletteOffset/EscalationPaletteSize)), PVR_LIST_TR_POLY, 
EscalationTextureSizeX, EscalationTextureSizeY,
1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.5f, 1.0f
);

EscalationData->Ticks++;
if(EscalationData->Ticks >= EscalationStaticTicks){
EscalationData->Ticks = 0;
EscalationData->CurrentFrame++;
if(EscalationData->CurrentFrame >= EscalationTextureAmount){
EscalationData->CurrentFrame = 0;
}
}

EscalationData->PositionX[ImminentTextureIdentifier]+=EscalationData->SpeedX;
EscalationData->PositionX[EscalationTextureIdentifier]-=EscalationData->SpeedX;

if(EscalationData->PositionX[EscalationTextureIdentifier] >= ScreenSizeX) ReturnValue = 0;
else if(EscalationData->PositionX[ImminentTextureIdentifier]-(EscalationData->PositionX[EscalationTextureIdentifier]+EscalationTextureSizeX) >= FrameRate){ReturnValue = 2; EscalationData->SpeedX = (ScreenSizeX-EscalationData->PositionX[ImminentTextureIdentifier])/EscalationWhiteFlashDuration;}
else if(EscalationData->PositionX[EscalationTextureIdentifier]-(EscalationData->PositionX[ImminentTextureIdentifier]+EscalationTextureSizeX) <= FrameRate) EscalationData->SpeedX = 1;

return(ReturnValue);
}