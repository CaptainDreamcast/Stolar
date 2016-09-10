#define TileLogicIntroFinalize()		{ \
free(OverWorldData->FluxData.General.TransitionData);  \
TileData->LogicData.General.IntroFlag = TileLogicIntroFlagActiveNot; \
}

#define TileLogicIntroAmount		4
#define TileLogicIntroArguments				TileStruct* TileData, OverWorldStruct* OverWorldData
#define TileLogicIntroInitiateArguments		TileLogicIntroStruct** TransitionData


#define TileLogicIntroFlagActiveNot	0
#define TileLogicIntroFlagActive		1

#define TileLogicIntroInitiateTransitionDataAllocationRoutine(TransitionData, Size)	{ \
TransitionData = malloc(sizeof(TileLogicIntroStruct)+Size); \
((TileLogicIntroStruct*)TransitionData)->Specific = (void*)(((uint32)TransitionData)+sizeof(TileLogicIntroStruct)); \
}

#define TileLogicIntroGeneralDataSet(TileLogicIntroGeneralData, NewIntroIdentifier)	{ \
TileLogicIntroGeneralData.IntroIdentifier = NewIntroIdentifier; \
}


void TileLogicIntroFlipInitiate(TileLogicIntroInitiateArguments){

TileLogicIntroStruct* TileLogicIntroData;
TileLogicIntroFlipStruct* TileLogicIntroFlipData;

TileLogicIntroInitiateTransitionDataAllocationRoutine((*TransitionData), sizeof(TileLogicIntroFlipStruct));
TileLogicIntroData = (TileLogicIntroStruct*)(*TransitionData);
TileLogicIntroFlipData = (TileLogicIntroFlipStruct*)TileLogicIntroData->Specific;

TileLogicIntroGeneralDataSet(TileLogicIntroData->General, TileLogicIntroFlipIdentifier);

TileLogicIntroFlipData->FlipDurationInSeconds = TileLogicIntroFlipDurationInSecondsStandard;
InitiateTransformationData((&TileLogicIntroFlipData->TransformationData));

}


void TileLogicIntroFlip(TileLogicIntroArguments){

TileLogicIntroFlipStruct* TileLogicIntroFlipData;

TileLogicIntroFlipData = (TileLogicIntroFlipStruct*)(((TileLogicIntroStruct*)OverWorldData->FluxData.General.TransitionData)->Specific);

SetRotationValueAdvancedY((&TileLogicIntroFlipData->TransformationData), (GetRotationValueY((&TileLogicIntroFlipData->TransformationData))+(QuarterRotationValue/(TileLogicIntroFlipData->FlipDurationInSeconds*FrameRate))));
if(GetRotationValueY((&TileLogicIntroFlipData->TransformationData)) >= FullRotationValue){
TileLogicIntroFinalize();
}
else{
CombineTransformationData(&TileData->LogicData.General.TransformationData, &TileLogicIntroFlipData->TransformationData);
}

}


void TileLogicIntroZoomOutInitiate(TileLogicIntroInitiateArguments){

TileLogicIntroStruct* TileLogicIntroData;
TileLogicIntroZoomOutStruct* TileLogicIntroZoomOutData;

TileLogicIntroInitiateTransitionDataAllocationRoutine((*TransitionData), sizeof(TileLogicIntroZoomOutStruct));
TileLogicIntroData = (TileLogicIntroStruct*)(*TransitionData);
TileLogicIntroZoomOutData = (TileLogicIntroZoomOutStruct*)TileLogicIntroData->Specific;

TileLogicIntroGeneralDataSet(TileLogicIntroData->General, TileLogicIntroZoomOutIdentifier);

TileLogicIntroZoomOutData->Ticks = NewTicksStandardValue;

TileLogicIntroZoomOutData->ZoomOutStartValue = TileLogicIntroZoomOutStartValueStandard;
TileLogicIntroZoomOutData->ZoomOutFinalValue = TileLogicIntroZoomOutFinalValueStandard;

TileLogicIntroZoomOutData->ZoomOutDurationInSeconds = TileLogicIntroZoomOutDurationInSecondsStandard;

InitiateTransformationData((&TileLogicIntroZoomOutData->TransformationData));
StartZoomingAdvanced((&TileLogicIntroZoomOutData->TransformationData), TileLogicIntroZoomOutData->ZoomOutStartValue);

TileMovementPreComputeLogarithmicInterPolationAdvanced(TileLogicIntroZoomOutData->LinearInterPolationData.Factor, TileLogicIntroZoomOutData->LinearInterPolationData.Constant, TileLogicIntroZoomOutData->ZoomOutStartValue, TileLogicIntroZoomOutData->ZoomOutFinalValue, LinearInterPolationSmoothRange);
}


void TileLogicIntroZoomOut(TileLogicIntroArguments){

TileLogicIntroZoomOutStruct* TileLogicIntroZoomOutData;

TileLogicIntroZoomOutData = (TileLogicIntroZoomOutStruct*)(((TileLogicIntroStruct*)OverWorldData->FluxData.General.TransitionData)->Specific);


SetTransformationDataPositionVector((&TileLogicIntroZoomOutData->TransformationData), TilePlayerFetchLeftPositionScreenX(TileData, PlayerMain), TilePlayerFetchTopPositionScreenY(TileData, PlayerMain), TileData->ObjectData[TileData->PlayerData[PlayerMain].LogicData.WhichObject].Instance[TileData->PlayerData[PlayerMain].LogicData.WhichInstance].LogicData.ScreenPositionZ);


SetScaleValueAdvanced((&TileLogicIntroZoomOutData->TransformationData), TileMovementComputeLogarithmicInterPolationAdvanced(((TileLogicIntroZoomOutData->Ticks/(TileLogicIntroZoomOutData->ZoomOutDurationInSeconds*FrameRate))*LinearInterPolationSmoothRange), TileLogicIntroZoomOutData->LinearInterPolationData.Factor, TileLogicIntroZoomOutData->LinearInterPolationData.Constant));

if(TileLogicIntroZoomOutData->Ticks >= (TileLogicIntroZoomOutData->ZoomOutDurationInSeconds*FrameRate)){
TileLogicIntroFinalize();
}
else{
CombineTransformationData(&TileData->LogicData.General.TransformationData, &TileLogicIntroZoomOutData->TransformationData);
TileLogicIntroZoomOutData->Ticks++;
}

}

void TileLogicIntroBlackInInitiate(TileLogicIntroInitiateArguments){

TileLogicIntroStruct* TileLogicIntroData;
TileLogicIntroBlackInStruct* TileLogicIntroBlackInData;

TileLogicIntroInitiateTransitionDataAllocationRoutine((*TransitionData), sizeof(TileLogicIntroBlackInStruct));
TileLogicIntroData = (TileLogicIntroStruct*)(*TransitionData);
TileLogicIntroBlackInData = (TileLogicIntroBlackInStruct*)TileLogicIntroData->Specific;

TileLogicIntroGeneralDataSet(TileLogicIntroData->General, TileLogicIntroBlackInIdentifier);

TileLogicIntroBlackInData->Loadable.DurationInSeconds = TileLogicIntroBlackInDurationInSecondsStandard;
TileLogicIntroBlackInData->LogicData.AlphaValue = FullColorFloatValue;

}

void TileLogicIntroBlackIn(TileLogicIntroArguments){

TileLogicIntroBlackInStruct* TileLogicIntroBlackInData;
vector_t FinalVector[PolygonCornerAmount];

TileLogicIntroBlackInData = (TileLogicIntroBlackInStruct*)(((TileLogicIntroStruct*)OverWorldData->FluxData.General.TransitionData)->Specific);

SetupTransformAndDraw(FinalVector, NULL, OverWorldData->TextureData.Tile.Intro.General.Black, 
OverallScreenPositionLeft, OverallScreenPositionUp, TileOverallScreenPositionZ, 
ScreenSizeX, ScreenSizeY, 
OverWorldData->Loadable->Tile.Intro.General.BlackTextureSizeX, OverWorldData->Loadable->Tile.Intro.General.BlackTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, TileLogicIntroBlackInData->LogicData.AlphaValue, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue);


LogicAlphaBuildDown(TileLogicIntroBlackInData->LogicData.AlphaValue, TileLogicIntroBlackInData->Loadable.DurationInSeconds, 
{
TileLogicIntroFinalize();
}
);

}

void TileLogicIntroNoneInitiate(TileLogicIntroInitiateArguments){

TileLogicIntroStruct* TileLogicIntroData;

TileLogicIntroInitiateTransitionDataAllocationRoutine((*TransitionData), TileLogicIntroNoneSize);
TileLogicIntroData = (TileLogicIntroStruct*)(*TransitionData);

TileLogicIntroGeneralDataSet(TileLogicIntroData->General, TileLogicIntroNoneIdentifier);

}

void TileLogicIntroNone(TileLogicIntroArguments){
TileLogicIntroFinalize();
}

void (*TileLogicIntroInitiate[TileLogicIntroAmount])(TileLogicIntroInitiateArguments)= 
{
TileLogicIntroFlipInitiate, 
TileLogicIntroZoomOutInitiate, 
TileLogicIntroBlackInInitiate, 
TileLogicIntroNoneInitiate, 
};

void (*TileLogicIntro[TileLogicIntroAmount])(TileLogicIntroArguments)= 
{
TileLogicIntroFlip, 
TileLogicIntroZoomOut, 
TileLogicIntroBlackIn, 
TileLogicIntroNone, 
};