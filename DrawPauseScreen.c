#define DistortionTextureSizeX	16
#define DistortionTextureSizeY	16
#define DistortionPositionY 	0
#define DistortionSizeX 	ScreenSizeX+DistortionTextureSizeX
#define DistortionSizeY 	ScreenSizeY
#define DistortionPositionZ 	2


#define ScanLinePositionX 	0
#define ScanLinePositionZ 	3
#define ScanLineSizeX		640
#define ScanLineSizeY		640
#define ScanLineTextureSizeX	64
#define ScanLineTextureSizeY	64

#define PausePositionZ 		4

void DrawPauseScreen(GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, PauseStruct* PauseData){

vector_t ScanLineVectors[PolygonCornerAmount];
vector_t PauseVectors[PolygonCornerAmount];

SetupVectors(ScanLineVectors, ScanLinePositionX, PauseData->ScanLinePositionY, ScanLinePositionZ, ScanLineSizeX, ScanLineSizeY);
SetupVectors(PauseVectors, GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.PausePositionX, GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.PausePositionY, PausePositionZ, GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.PauseSizeX, GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.PauseSizeY);


FillWithRepeatedTexture(
GraphicalUserInterFaceData->DistortionTexture, PauseData->DistortionPositionX, DistortionPositionY, 
DistortionPositionZ, DistortionSizeX, DistortionSizeY, DistortionTextureSizeX, DistortionTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
1.0f, 1.0f, 1.0f, 1.0f);

DrawVectorTexture(
ScanLineVectors, GraphicalUserInterFaceData->ScanLineTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
ScanLineTextureSizeX, ScanLineTextureSizeY,  
1.0f, 1.0f, 1.0f, 1.0f);

DrawVectorTexture(
PauseVectors, GraphicalUserInterFaceData->PauseTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.PauseSizeX, 
GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.PauseSizeY,  
1.0f, 1.0f, 1.0f, 1.0f);



PauseData->ScanLinePositionY-=PauseData->ScanLineSpeedY;
if(PauseData->ScanLinePositionY < PauseData->ScanLineEndPositionY) PauseData->ScanLinePositionY = 0;

PauseData->DistortionPositionX-=PauseData->DistortionSpeedX;
if(PauseData->DistortionPositionX <= -DistortionTextureSizeX) PauseData->DistortionPositionX = 0;


}