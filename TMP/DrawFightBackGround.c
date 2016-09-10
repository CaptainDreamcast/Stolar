void DrawFightBackGround(FightLocationStruct* FightLocationData, TransformationStruct* TransformationData){

pvr_poly_cxt_t cxt;
pvr_poly_hdr_t hdr;
pvr_vertex_t vert;

short TexturePositionX, TexturePositionY;
uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;
vector_t FinalVector[PolygonCornerAmount];


for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<FightLocationData->LocationData.AnimationAmount;DirtyDeedsDoneDirtCheap++){


if(FightLocationData->LocationData.StageSizeX > ScreenSizeX) TexturePositionX = FightLocationData->TexturePositionX[DirtyDeedsDoneDirtCheap]-FightLocationData->LocationData.StagePositionX*(((float)(FightLocationData->LayerSizeX[DirtyDeedsDoneDirtCheap]-ScreenSizeX))/(FightLocationData->LocationData.StageSizeX-ScreenSizeX));
else TexturePositionX = 0;

if(FightLocationData->LocationData.StageSizeY > ScreenSizeY) TexturePositionY = FightLocationData->TexturePositionY[DirtyDeedsDoneDirtCheap]-FightLocationData->LocationData.StagePositionY*(((float)(FightLocationData->LayerSizeY[DirtyDeedsDoneDirtCheap]-ScreenSizeY))/(FightLocationData->LocationData.StageSizeY-ScreenSizeY));
else TexturePositionY = 0;


FinalVector[0].x = TexturePositionX;
FinalVector[0].y = TexturePositionY;
FinalVector[0].z = FightLocationData->TexturePositionZ[DirtyDeedsDoneDirtCheap];

FinalVector[1].x = TexturePositionX+FightLocationData->TextureSizeX[DirtyDeedsDoneDirtCheap];
FinalVector[1].y = TexturePositionY;
FinalVector[1].z = FightLocationData->TexturePositionZ[DirtyDeedsDoneDirtCheap];

FinalVector[2].x = TexturePositionX;
FinalVector[2].y = TexturePositionY+FightLocationData->TextureSizeY[DirtyDeedsDoneDirtCheap];
FinalVector[2].z = FightLocationData->TexturePositionZ[DirtyDeedsDoneDirtCheap];

FinalVector[3].x = TexturePositionX+FightLocationData->TextureSizeX[DirtyDeedsDoneDirtCheap];
FinalVector[3].y = TexturePositionY+FightLocationData->TextureSizeY[DirtyDeedsDoneDirtCheap];
FinalVector[3].z = FightLocationData->TexturePositionZ[DirtyDeedsDoneDirtCheap];


if(TransformationData != NULL && TransformationData->Active){

mat_identity();
mat_translate(TransformationData->PositionVector.x, TransformationData->PositionVector.y, TransformationData->PositionVector.z);

if(TransformationData->Active & ZoomInIdentifier) mat_scale(TransformationData->ScaleValue, TransformationData->ScaleValue, 1.0f);
if(TransformationData->Active & RotateXIdentifier) mat_rotate_x(TransformationData->RotationValueX);
if(TransformationData->Active & RotateYIdentifier) mat_rotate_y(TransformationData->RotationValueY);
if(TransformationData->Active & RotateZIdentifier) mat_rotate_z(TransformationData->RotationValueZ);

for(BurningDownTheHouse=0; BurningDownTheHouse<PolygonCornerAmount; BurningDownTheHouse++){
FinalVector[BurningDownTheHouse].x = FinalVector[BurningDownTheHouse].x-TransformationData->PositionVector.x;
FinalVector[BurningDownTheHouse].y = FinalVector[BurningDownTheHouse].y-TransformationData->PositionVector.y;
FinalVector[BurningDownTheHouse].z = FinalVector[BurningDownTheHouse].z-TransformationData->PositionVector.z;
mat_trans_single3(FinalVector[BurningDownTheHouse].x, FinalVector[BurningDownTheHouse].y, FinalVector[BurningDownTheHouse].z);
}
}


pvr_poly_cxt_txr(&cxt, PVR_LIST_TR_POLY, PVR_TXRFMT_ARGB4444, FightLocationData->TextureSizeX[DirtyDeedsDoneDirtCheap], FightLocationData->TextureSizeY[DirtyDeedsDoneDirtCheap], FightLocationData->Texture[FightLocationData->AnimationData[DirtyDeedsDoneDirtCheap].TextureOffset+FightLocationData->CurrentFrame[DirtyDeedsDoneDirtCheap]], PVR_FILTER_BILINEAR);
pvr_poly_compile(&hdr, &cxt);
pvr_prim(&hdr, sizeof(hdr));

vert.argb = PVR_PACK_COLOR(1.0f, 1.0f, 1.0f, 1.0f);
vert.oargb = 0;
vert.flags = PVR_CMD_VERTEX;

vert.x = FinalVector[0].x;
vert.y = FinalVector[0].y;
vert.z = FinalVector[0].z;
vert.u = 0;
vert.v = 0;
pvr_prim(&vert, sizeof(vert));

vert.x = FinalVector[1].x;
vert.y = FinalVector[1].y;
vert.z = FinalVector[1].z;
vert.u = 1.0;
vert.v = 0;
pvr_prim(&vert, sizeof(vert));

vert.x = FinalVector[2].x;
vert.y = FinalVector[2].y;
vert.z = FinalVector[2].z;
vert.u = 0;
vert.v = 1.0;
pvr_prim(&vert, sizeof(vert));

vert.x = FinalVector[3].x;
vert.y = FinalVector[3].y;
vert.z = FinalVector[3].z;
vert.u = 1.0;
vert.v = 1.0;
vert.flags = PVR_CMD_VERTEX_EOL;
pvr_prim(&vert, sizeof(vert));
}


}
