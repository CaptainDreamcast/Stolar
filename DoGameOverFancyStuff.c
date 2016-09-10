#define DeathReddishnessBuildUpTime 	(FrameRate*2)
#define DeathFirstWhiteFlash 		(DeathReddishnessBuildUpTime+(FrameRate/5))
#define DeathFirstWhiteFlashEnd		(DeathFirstWhiteFlash+(FrameRate/5))
#define DeathSecondWhiteFlash 		(DeathFirstWhiteFlashEnd+(FrameRate/5))
#define DeathSecondWhiteFlashEnd	(DeathSecondWhiteFlash+(FrameRate/5))
#define DeathFadeToBlack		(DeathSecondWhiteFlashEnd+(FrameRate/5))
#define DeathFinalFinish		(DeathFadeToBlack+(FrameRate/5))	

#define DeathReddishnessMaximumAlpha	0.5f

#define DeathReddishnessVector		0
#define DeathWhiteFlashVector		1
#define DeathStolarVector		2
#define DeathAnimationVectors		3

#define DeathMaximumRotationSpeed	(M_PI/4)
#define DeathMaximumZoomSpeed		0.5f

#define DeathReddishnessPositionZ	FightSecondGreatestPositionZ
#define DeathWhiteFlashPositionZ	FightGreatestPositionZ

uint8 DoGameOverFancyStuff(pvr_ptr_t* StolarTexture, StolarFightStruct* StolarFightData, TransformationStruct* TransformationData){

vector_t FinalVector[DeathAnimationVectors][PolygonCornerAmount];
float AlphaValueReddishness, AlphaValueWhiteFlash, AlphaValueStolar, WhitenessStolar;

if(StolarFightData->SpecialEventTicks == DeathFinalFinish) return(1);

if(StolarFightData->SpecialEventTicks < DeathReddishnessBuildUpTime) AlphaValueReddishness = DeathReddishnessMaximumAlpha*(StolarFightData->SpecialEventTicks/(float)DeathReddishnessBuildUpTime);
else AlphaValueReddishness = DeathReddishnessMaximumAlpha;

if(StolarFightData->SpecialEventTicks >= DeathFirstWhiteFlash && StolarFightData->SpecialEventTicks < DeathFirstWhiteFlashEnd){
AlphaValueWhiteFlash = 1.0f-(StolarFightData->SpecialEventTicks-DeathFirstWhiteFlash)/(float)(DeathFirstWhiteFlashEnd-DeathFirstWhiteFlash);
}
else if(StolarFightData->SpecialEventTicks >= DeathSecondWhiteFlash && StolarFightData->SpecialEventTicks < DeathSecondWhiteFlashEnd){
AlphaValueWhiteFlash = 1.0f-(StolarFightData->SpecialEventTicks-DeathSecondWhiteFlash)/(float)(DeathSecondWhiteFlashEnd-DeathSecondWhiteFlash);
}
else if(StolarFightData->SpecialEventTicks >= DeathFadeToBlack && StolarFightData->SpecialEventTicks < DeathFinalFinish){
AlphaValueWhiteFlash = -(StolarFightData->SpecialEventTicks-DeathFadeToBlack)/(float)(DeathFinalFinish-DeathFadeToBlack);
}
else AlphaValueWhiteFlash = 0.0f;

if(StolarFightData->SpecialEventTicks < DeathFirstWhiteFlashEnd) WhitenessStolar = 1.0f;
else if(StolarFightData->SpecialEventTicks >= DeathFirstWhiteFlashEnd && StolarFightData->SpecialEventTicks<DeathSecondWhiteFlash){
WhitenessStolar = 1.0f-((StolarFightData->SpecialEventTicks-DeathFirstWhiteFlashEnd)/(float)(DeathSecondWhiteFlash-DeathFirstWhiteFlashEnd));
}
else WhitenessStolar = 0.0f;

if(StolarFightData->SpecialEventTicks < DeathSecondWhiteFlashEnd) AlphaValueStolar = 1.0f;
else if(StolarFightData->SpecialEventTicks >= DeathSecondWhiteFlashEnd && StolarFightData->SpecialEventTicks<DeathFadeToBlack){
AlphaValueStolar = (StolarFightData->SpecialEventTicks-DeathSecondWhiteFlashEnd)/(float)(DeathFadeToBlack-DeathSecondWhiteFlashEnd);
}
else AlphaValueStolar = 0.0f;

SetupVectors(FinalVector[DeathReddishnessVector], 0, 0, DeathReddishnessPositionZ, ScreenSizeX, ScreenSizeY);
SetupVectors(FinalVector[DeathWhiteFlashVector], 0, 0, DeathWhiteFlashPositionZ, ScreenSizeX, ScreenSizeY);
SetupVectors(FinalVector[DeathStolarVector], StolarFightData->PositionX, StolarFightData->PositionY, StolarPositionZ, StolarFightData->SizeX, StolarFightData->SizeY);

if(TransformationData != NULL && TransformationData->Active){
Transformation(FinalVector[DeathReddishnessVector], TransformationData);
Transformation(FinalVector[DeathWhiteFlashVector], TransformationData);
Transformation(FinalVector[DeathStolarVector], TransformationData);
}

DrawVectorTexture(
FinalVector[DeathReddishnessVector], WhiteTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
WhiteTextureSizeX, WhiteTextureSizeY, 
AlphaValueReddishness, 1.0f, 0.0f, 0.0f);

if(AlphaValueWhiteFlash < 0){
DrawVectorTexture(
FinalVector[DeathWhiteFlashVector], WhiteTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
WhiteTextureSizeX, WhiteTextureSizeY, 
-AlphaValueWhiteFlash, 0.0f, 0.0f, 0.0f);
}
else{
DrawVectorTexture(
FinalVector[DeathWhiteFlashVector], WhiteTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
WhiteTextureSizeX, WhiteTextureSizeY, 
AlphaValueWhiteFlash, 1.0f, 1.0f, 1.0f);
}

DrawVectorTexture(
FinalVector[DeathStolarVector], StolarTexture[StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureOffset+StolarFightData->CurrentFrame], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
StolarTextureSizeX, StolarTextureSizeY, 
AlphaValueStolar, WhitenessStolar, WhitenessStolar, WhitenessStolar);


TransformationData->ScaleValue+=(StolarFightData->SpecialEventTicks/(float)DeathFinalFinish)*DeathMaximumZoomSpeed;
TransformationData->RotationValueZ+=(StolarFightData->SpecialEventTicks/(float)DeathFinalFinish)*DeathMaximumRotationSpeed;

return(0);
}