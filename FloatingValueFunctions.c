#define FloatingValueBuildUp			(FrameRate/2)
#define FloatingValueDuration			(FrameRate*2)
#define FloatingValueFinish			(FloatingValueDuration+FloatingValueBuildUp)

#define FloatingValueTextureSizeX		128
#define FloatingValueTextureSizeY		8

#define FloatingValueScreenSizeX		128
#define FloatingValueScreenSizeY		128

#define	SingleFloatingValueInsidePixelTextureSize	8
#define SingleFloatingValueInsideTextureSize		((1/FloatingValueTextureSizeX)*SingleFloatingValueInsidePixelTextureSize-1)
#define SingleFloatingValueRealInsideTextureSize	((1/FloatingValueTextureSizeX)*SingleFloatingValueInsidePixelTextureSize)

#define FloatingValuePlusSignPosition			(10*SingleFloatingValueRealInsideTextureSize)
#define FloatingValueMinusSignPosition			(11*SingleFloatingValueRealInsideTextureSize)

#define FloatingValueDistanceY				100
#define FloatingValuePositionChangeY			(FloatingValueDistanceY/FloatingValueFinish)

void DrawFloatingValues(FloatingValueStruct* FloatingValueData, TransformationStruct* TransformationData){

uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;
vector_t FinalVector[PolygonCornerAmount];
float AlphaValue, Red, Green, Blue, Left;
float PositionX;

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<FloatingValueData->MaximumAmount; DirtyDeedsDoneDirtCheap++){
if(FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].Active){

if(FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].Ticks < FloatingValueBuildUp) AlphaValue = FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].Ticks/(float)FloatingValueBuildUp;
else if(FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].Ticks > FloatingValueFinish){AlphaValue = 0.0f; FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].Active = 0;}
else if(FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].Ticks > FloatingValueDuration) AlphaValue = 1.0f-((FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].Ticks-FloatingValueDuration)/(float)(FloatingValueFinish-FloatingValueDuration));
else AlphaValue = 1.0f;
FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].Ticks++;

if(FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].Color == RedColor){Red = 1.0f; Green = Blue = 0.0f;}
else if(FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].Color == GreenColor){Green = 1.0f; Red = Blue = 0.0f;}
else if(FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].Color == BlueColor){Red = Green = 0.0f; Blue = 1.0f;}
else{Red = Green = Blue = 0.0f;}

PositionX = FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].PositionX;

for(BurningDownTheHouse = 0; FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].String[BurningDownTheHouse] != '\0'; BurningDownTheHouse++){

if(FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].String[BurningDownTheHouse] == '+') Left = FloatingValuePlusSignPosition;
else if(FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].String[BurningDownTheHouse] == '-') Left = FloatingValueMinusSignPosition;
else if(FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].String[BurningDownTheHouse] >= HexNumberValueOffset && FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].String[BurningDownTheHouse] <= HexNumberValueOffset+9) Left = (FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].String[BurningDownTheHouse]-HexNumberValueOffset)*SingleFloatingValueRealInsideTextureSize;

else {Left = 0.0f; printf("Could not print String: (%s)\n", FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].String);}

SetupVectors(FinalVector, PositionX, FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].PositionY, FloatingValueTexturePositionZ, FloatingValueScreenSizeX, FloatingValueScreenSizeY);

if(TransformationData != NULL && TransformationData->Active) Transformation(FinalVector, TransformationData);


DrawVectorTexturePlus(
FinalVector, FloatingValueData->Texture, 
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL(FloatingValuePaletteOffset/FloatingValuePaletteSize)), PVR_LIST_TR_POLY, 
FloatingValueTextureSizeX, FloatingValueTextureSizeY,
AlphaValue, Red, Green, Blue, Left, Left+SingleFloatingValueInsideTextureSize, 0.0f, 1.0f
);

PositionX += FloatingValueScreenSizeX;


}

FloatingValueData->SingleValueData[DirtyDeedsDoneDirtCheap].PositionY -= FloatingValuePositionChangeY;

}
}
}

void AddFloatingValue(FloatingValueStruct* FloatingValueData, int Value, char* String, uint8 Color, float StartPositionX, float StartPositionY){

uint8 WhichValueIdentifier;
uint8 LoopCheck;

LoopCheck = 0;
WhichValueIdentifier = FloatingValueData->NextUp;
while(!FloatingValueData->SingleValueData[WhichValueIdentifier].Active){
if((WhichValueIdentifier = (WhichValueIdentifier+1)%FloatingValueData->MaximumAmount) == FloatingValueData->NextUp){
if(LoopCheck) break;
else LoopCheck = 1;
}
}

FloatingValueData->NextUp = WhichValueIdentifier+1;

FloatingValueData->SingleValueData[WhichValueIdentifier].Active = FloatingValueBuildUpStage;
FloatingValueData->SingleValueData[WhichValueIdentifier].PositionX = StartPositionX;
FloatingValueData->SingleValueData[WhichValueIdentifier].PositionY = StartPositionY;
FloatingValueData->SingleValueData[WhichValueIdentifier].Color = Color;
FloatingValueData->SingleValueData[WhichValueIdentifier].Ticks = 0;



if(String != NULL){
sprintf(FloatingValueData->SingleValueData[WhichValueIdentifier].String, "%s", String);
}
else{
sprintf(FloatingValueData->SingleValueData[WhichValueIdentifier].String, "%d", Value);
}

}

#define AddFloatingDamageValue(FloatingValueData, Value, StartPositionX, StartPositionY) AddFloatingValue(FloatingValueData, Value, NULL, RedColor, StartPositionX, StartPositionY)
