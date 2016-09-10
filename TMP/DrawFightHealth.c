#define FightHealthBackGroundPositionX 		10
#define FightHealthBackGroundPositionY 		10
#define FightHealthBackGroundPositionZ 		7
#define FightHealthBackGroundSizeX		200
#define FightHealthBackGroundSizeY		200

#define FightHealthActualHealthPositionX 	10
#define FightHealthActualHealthPositionY 	10
#define FightHealthActualHealthPositionZ 	8
#define FightHealthMaximumSizeX			200
#define FightHealthActualHealthSizeY		200


void DrawFightHealth(StolarFightStruct* StolarFightData, GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, TransformationStruct* TransformationData){

vector_t FinalVectorBackGround[PolygonCornerAmount];
vector_t FinalVectorActualHealth[PolygonCornerAmount];
float Red, Green;

uint16 HealthSizeX;

SetupVectors(FinalVectorBackGround, FightHealthBackGroundPositionX, FightHealthBackGroundPositionY, FightHealthBackGroundPositionZ, FightHealthBackGroundSizeX, FightHealthBackGroundSizeY);

HealthSizeX = ((float)StolarFightData->StolarData->HealthNow/StolarFightData->StolarData->HealthMax)*FightHealthMaximumSizeX;
Green = 1.0f*((StolarFightData->StolarData->HealthNow-(StolarFightData->StolarData->HealthMax/10))/(StolarFightData->StolarData->HealthMax*(9.0f/10)));
if(Green<0.0f) Green = 0.0f;
Red = 1.0f-Green;

SetupVectors(FinalVectorActualHealth, FightHealthActualHealthPositionX, FightHealthActualHealthPositionY, FightHealthActualHealthPositionZ, HealthSizeX, FightHealthActualHealthSizeY);

if(TransformationData != NULL && TransformationData->Active){ 
Transformation(FinalVectorBackGround, TransformationData);
Transformation(FinalVectorActualHealth, TransformationData);
}

DrawVectorTexture(
FinalVectorBackGround, GraphicalUserInterFaceData->HealthBackGroundTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.HealthBackGroundTextureSizeX, 
GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.HealthBackGroundTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);

DrawVectorTexture(
FinalVectorActualHealth, GraphicalUserInterFaceData->HealthTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.HealthTextureSizeX, 
GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.HealthTextureSizeY, 
1.0f, Red, Green, 1.0f);


}