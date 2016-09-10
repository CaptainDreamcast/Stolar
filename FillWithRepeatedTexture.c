void FillWithRepeatedTexture(
pvr_ptr_t Texture, short PositionX, short PositionY, short PositionZ, short SizeX, short SizeY, 
short TextureSizeX, short TextureSizeY, uint32 TextureType, uint32 ListType, 
float Alpha, float Red, float Green, float Blue){


pvr_poly_hdr_t hdr;
pvr_vertex_t vert;
pvr_poly_cxt_t cxt;

pvr_poly_cxt_txr(&cxt, ListType, TextureType, TextureSizeX, TextureSizeY, Texture, PVR_FILTER_BILINEAR);
pvr_poly_compile(&hdr, &cxt);
pvr_prim(&hdr, sizeof(hdr));

vert.argb = PVR_PACK_COLOR(Alpha, Red, Green, Blue);
vert.oargb = 0;

while(PositionY < SizeY){
while(PositionX < SizeX){

vert.flags = PVR_CMD_VERTEX;

vert.x = PositionX;
vert.y = PositionY;
vert.z = PositionZ;
vert.u = 0;
vert.v = 0;
pvr_prim(&vert, sizeof(vert));

vert.x = PositionX+TextureSizeX;
vert.y = PositionY;
vert.z = PositionZ;
vert.u = 1.0;
vert.v = 0;
pvr_prim(&vert, sizeof(vert));

vert.x = PositionX;
vert.y = PositionY+TextureSizeY;
vert.z = PositionZ;
vert.u = 0;
vert.v = 1.0;
pvr_prim(&vert, sizeof(vert));

vert.x = PositionX+TextureSizeX;
vert.y = PositionY+TextureSizeY;
vert.z = PositionZ;
vert.u = 1.0;
vert.v = 1.0;
vert.flags = PVR_CMD_VERTEX_EOL;
pvr_prim(&vert, sizeof(vert));

}
PositionX+=TextureSizeX;
}
PositionY+=TextureSizeY;
}
