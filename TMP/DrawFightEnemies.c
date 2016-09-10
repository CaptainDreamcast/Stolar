void DrawFightEnemies(EnemyFightStruct* EnemyFightData, uint8 EnemyAmount, TransformationStruct* TransformationData){

pvr_poly_cxt_t cxt;
pvr_poly_hdr_t hdr;
pvr_vertex_t vert;

vector_t FinalVector[PolygonCornerAmount];
uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;
uint32 PaletteValue;

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EnemyAmount; DirtyDeedsDoneDirtCheap++){
if(EnemyFightData[DirtyDeedsDoneDirtCheap].Active){

FinalVector[0].x = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX;
FinalVector[0].y = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionY;
FinalVector[0].z = EnemyPositionZ;

FinalVector[1].x = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].SizeX;
FinalVector[1].y = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionY;
FinalVector[1].z = EnemyPositionZ;

FinalVector[2].x = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX;
FinalVector[2].y = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionY+EnemyFightData[DirtyDeedsDoneDirtCheap].SizeY;
FinalVector[2].z = EnemyPositionZ;

FinalVector[3].x = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionX+EnemyFightData[DirtyDeedsDoneDirtCheap].SizeX;
FinalVector[3].y = EnemyFightData[DirtyDeedsDoneDirtCheap].PositionY+EnemyFightData[DirtyDeedsDoneDirtCheap].SizeY;
FinalVector[3].z = EnemyPositionZ;

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

if(EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.PaletteType == 8) PaletteValue = (PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(EnemyFightData[DirtyDeedsDoneDirtCheap].PalettePosition)); 
else if(EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.PaletteType == 4) PaletteValue = (PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL(EnemyFightData[DirtyDeedsDoneDirtCheap].PalettePosition)); 
else PaletteValue = PVR_TXRFMT_ARGB4444;


pvr_poly_cxt_txr(&cxt, PVR_LIST_TR_POLY, PaletteValue, EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.TextureSizeX, EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.TextureSizeY, EnemyFightData[DirtyDeedsDoneDirtCheap].Texture[(EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyAnimationData[EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentAnimation].TextureOffset)+EnemyFightData[DirtyDeedsDoneDirtCheap].CurrentFrame], PVR_FILTER_BILINEAR);
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


}