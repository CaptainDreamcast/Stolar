#define TileLogicOutroFinalize()		{ \
TileGoSomeWhereDispatch(TileData, OverWorldData, TileData->LogicData.Outro.NewGamePlay, TileData->LogicData.Outro.WhereExactly); \
}

#define TileLogicOutroAmount		4
#define TileLogicOutroArguments				TileStruct* TileData, OverWorldStruct* OverWorldData
#define TileLogicOutroInitiateArguments		TileStruct* TileData, OverWorldStruct* OverWorldData, uint8 NewGamePlay, uint8 NewWhereExactly


#define TileLogicIntroFlagActiveNot	0
#define TileLogicIntroFlagActive		1

#define TileLogicOutroActivate(WhichOutro, WhichGamePlay, NewWhereExactly)	{ \
TileData->LogicData.Outro.Active = LogicActive; \
TileData->LogicData.Outro.Identifier = WhichOutro; \
TileData->LogicData.Outro.NewGamePlay = WhichGamePlay; \
TileData->LogicData.Outro.WhereExactly = NewWhereExactly; \
}



void TileLogicOutroFlipInitiate(TileLogicOutroInitiateArguments){
printf("Error: TileLogicOutroFlipInitiate called!\n");
}


void TileLogicOutroFlip(TileLogicOutroArguments){
printf("Error: TileLogicOutroFlip called!\n");
}


void TileLogicOutroZoomOutInitiate(TileLogicOutroInitiateArguments){
printf("Error: TileLogicOutroZoomOutInitiate called!\n");
}


void TileLogicOutroZoomOut(TileLogicOutroArguments){
printf("Error: TileLogicOutroZoomOut called!\n");
}

void TileLogicOutroBlackOutInitiate(TileLogicOutroInitiateArguments){

TileLogicOutroBlackOutStruct* TileLogicOutroBlackOutData;

TileLogicOutroActivate(TileLogicOutroBlackOutIdentifier, NewGamePlay, NewWhereExactly);

TileData->FluxData.Outro.Buffer = malloc(sizeof(TileLogicOutroBlackOutStruct));
TileLogicOutroBlackOutData = (TileLogicOutroBlackOutStruct*)TileData->FluxData.Outro.Buffer;

TileLogicOutroBlackOutData->Loadable.DurationInSeconds = TileLogicOutroBlackOutDurationInSecondsStandard;
TileLogicOutroBlackOutData->LogicData.AlphaValue = NoColorFloatValue;

}

void TileLogicOutroBlackOut(TileLogicOutroArguments){

TileLogicOutroBlackOutStruct* TileLogicOutroBlackOutData;
vector_t FinalVector[PolygonCornerAmount];

TileLogicOutroBlackOutData = (TileLogicOutroBlackOutStruct*)TileData->FluxData.Outro.Buffer;

SetupTransformAndDraw(FinalVector, NULL, OverWorldData->TextureData.Tile.Intro.General.Black, 
OverallScreenPositionLeft, OverallScreenPositionUp, TileOverallScreenPositionZ, 
ScreenSizeX, ScreenSizeY, 
OverWorldData->Loadable->Tile.Intro.General.BlackTextureSizeX, OverWorldData->Loadable->Tile.Intro.General.BlackTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, TileLogicOutroBlackOutData->LogicData.AlphaValue, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue);


LogicAlphaBuildUp(TileLogicOutroBlackOutData->LogicData.AlphaValue, TileLogicOutroBlackOutData->Loadable.DurationInSeconds, 
{
TileLogicOutroFinalize();
}
);

}

void TileLogicOutroNoneInitiate(TileLogicOutroInitiateArguments){
TileLogicOutroActivate(TileLogicOutroNoneIdentifier, NewGamePlay, NewWhereExactly);
}

void TileLogicOutroNone(TileLogicOutroArguments){
TileLogicOutroFinalize();
}

void (*TileLogicOutroInitiate[TileLogicOutroAmount])(TileLogicOutroInitiateArguments)= 
{
TileLogicOutroFlipInitiate, 
TileLogicOutroZoomOutInitiate, 
TileLogicOutroBlackOutInitiate, 
TileLogicOutroNoneInitiate, 
};

void (*TileLogicOutro[TileLogicOutroAmount])(TileLogicOutroArguments)= 
{
TileLogicOutroFlip, 
TileLogicOutroZoomOut, 
TileLogicOutroBlackOut, 
TileLogicOutroNone, 
};