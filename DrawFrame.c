void DrawFrameBuffer(){

pvr_poly_cxt_t cxt;
pvr_poly_hdr_t hdr;
pvr_vertex_t vert;

pvr_poly_cxt_txr(&cxt, PVR_LIST_TR_POLY, (PVR_TXRFMT_RGB565 | PVR_TXRFMT_NONTWIDDLED), 512, 512, (pvr_ptr_t)vram_s, PVR_FILTER_BILINEAR);
pvr_poly_compile(&hdr, &cxt);
pvr_prim(&hdr, sizeof(hdr));

vert.argb = PVR_PACK_COLOR(1.0f, 1.0f, 1.0f, 1.0f);
vert.oargb = 0;
vert.flags = PVR_CMD_VERTEX;

vert.x = 0;
vert.y = 0;
vert.z = 1;
vert.u = 0;
vert.v = 0;
pvr_prim(&vert, sizeof(vert));

vert.x = 1024;
vert.y = 0;
vert.z = 1;
vert.u = 1.0;
vert.v = 0;
pvr_prim(&vert, sizeof(vert));

vert.x = 0;
vert.y = 512;
vert.z = 1;
vert.u = 0;
vert.v = 1.0;
pvr_prim(&vert, sizeof(vert));

vert.x = 1024;
vert.y = 512;
vert.z = 1;
vert.u = 1.0;
vert.v = 1.0;
vert.flags = PVR_CMD_VERTEX_EOL;
pvr_prim(&vert, sizeof(vert));

}

void DrawFrame(pvr_ptr_t Texture, uint32 SizeX, uint32 SizeY){

pvr_poly_cxt_t cxt;
pvr_poly_hdr_t hdr;
pvr_vertex_t vert;

pvr_poly_cxt_txr(&cxt, PVR_LIST_OP_POLY, (PVR_TXRFMT_RGB565 | PVR_TXRFMT_NONTWIDDLED), SizeX, SizeY, Texture, PVR_FILTER_BILINEAR);
pvr_poly_compile(&hdr, &cxt);
pvr_prim(&hdr, sizeof(hdr));

vert.argb = PVR_PACK_COLOR(1.0f, 1.0f, 1.0f, 1.0f);
vert.oargb = 0;
vert.flags = PVR_CMD_VERTEX;

vert.x = 0;
vert.y = 0;
vert.z = 1;
vert.u = 0;
vert.v = 0;
pvr_prim(&vert, sizeof(vert));

vert.x = 1024;
vert.y = 0;
vert.z = 1;
vert.u = 1.0;
vert.v = 0;
pvr_prim(&vert, sizeof(vert));

vert.x = 0;
vert.y = 512;
vert.z = 1;
vert.u = 0;
vert.v = 1.0;
pvr_prim(&vert, sizeof(vert));

vert.x = 1024;
vert.y = 512;
vert.z = 1;
vert.u = 1.0;
vert.v = 1.0;
vert.flags = PVR_CMD_VERTEX_EOL;
pvr_prim(&vert, sizeof(vert));

}