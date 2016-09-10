void DrawZoomOut(pvr_ptr_t Texture, vector_t OriginalVectorData[], float ScaleValue){

pvr_poly_cxt_t cxt;
pvr_poly_hdr_t hdr;
pvr_vertex_t vert;
vector_t VectorData[4];
uint8 DirtyDeedsDoneDirtCheap;

mat_identity();
mat_translate(320.0f, 240.0f, 1.0f);
mat_scale(ScaleValue, ScaleValue, 1.0f);
memcpy4(VectorData, OriginalVectorData, 128);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<4; DirtyDeedsDoneDirtCheap++){
mat_trans_single3(VectorData[DirtyDeedsDoneDirtCheap].x, VectorData[DirtyDeedsDoneDirtCheap].y, VectorData[DirtyDeedsDoneDirtCheap].z);
}

pvr_poly_cxt_txr(&cxt, PVR_LIST_TR_POLY, (PVR_TXRFMT_RGB565 | PVR_TXRFMT_NONTWIDDLED), 1024, 512, Texture, PVR_FILTER_BILINEAR);
pvr_poly_compile(&hdr, &cxt);
pvr_prim(&hdr, sizeof(hdr));

vert.argb = PVR_PACK_COLOR(1.0f, 1.0f, 1.0f, 1.0f);
vert.oargb = 0;
vert.flags = PVR_CMD_VERTEX;

vert.x = VectorData[0].x;
vert.y = VectorData[0].y;
vert.z = 1;
vert.u = 0;
vert.v = 0;
pvr_prim(&vert, sizeof(vert));

vert.x = VectorData[1].x;
vert.y = VectorData[1].y;
vert.z = 1;
vert.u = 1.0;
vert.v = 0;
pvr_prim(&vert, sizeof(vert));

vert.x = VectorData[2].x;
vert.y = VectorData[2].y;
vert.z = 1;
vert.u = 0;
vert.v = 1.0;
pvr_prim(&vert, sizeof(vert));

vert.x = VectorData[3].x;
vert.y = VectorData[3].y;
vert.z = 1;
vert.u = 1.0;
vert.v = 1.0;
vert.flags = PVR_CMD_VERTEX_EOL;
pvr_prim(&vert, sizeof(vert));

}


void ScreenZoomOut(pvr_ptr_t Texture, uint8* OffTo){

maple_device_t *cont;
cont_state_t *st;


vector_t VectorData[4];
float ScaleValue;
float ScaleChangeValue;

ScaleValue = 1.0f;
ScaleChangeValue = 1.0f/(3*FrameRate);

printf("ScaleChangeValue: (%f)\n", (double)ScaleChangeValue);

VectorData[0].x = -320.0f;
VectorData[0].y = -240.0f;
VectorData[0].z = 1.0f;

VectorData[1].x = 704.0f;
VectorData[1].y = -240.0f;
VectorData[1].z = 1.0f;

VectorData[2].x = -320.0f;
VectorData[2].y = 272.0f;
VectorData[2].z = 1.0f;

VectorData[3].x = 704.0f;
VectorData[3].y = 272.0f;
VectorData[3].z = 1.0f;


while(ScaleValue > 0.0f){


#ifdef FunFunFun
vid_border_color(255, 0, 0);
#endif
//StreamingLoad(10);
pvr_wait_ready();
#ifdef FunFunFun
vid_border_color(0, 0, 255);
#endif
pvr_scene_begin();
pvr_list_begin(PVR_LIST_TR_POLY);

DrawZoomOut(Texture, VectorData, ScaleValue);

pvr_list_finish();
pvr_scene_finish();

if((cont = maple_enum_dev(0, 0)) != NULL) {
st = (cont_state_t *)maple_dev_status(cont);

if ((st->buttons & (StairWayToHeaven)) == (StairWayToHeaven)){
ScaleValue = 0.0f;
*OffTo = FinalExitStage;
}
}

ScaleValue-=ScaleChangeValue;
}

}