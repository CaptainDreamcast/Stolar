void DrawContextTexture(vector_t* FinalVector, pvr_poly_cxt_t* cxt, float Alpha, float Red, float Green, float Blue, float Left, float Right, float Up, float Down){

pvr_poly_hdr_t hdr;
pvr_vertex_t vert;

pvr_poly_compile(&hdr, cxt);
pvr_prim(&hdr, sizeof(hdr));

vert.argb = PVR_PACK_COLOR(Alpha, Red, Green, Blue);
vert.oargb = 0;
vert.flags = PVR_CMD_VERTEX;

vert.x = FinalVector[0].x;
vert.y = FinalVector[0].y;
vert.z = FinalVector[0].z;
vert.u = Left;
vert.v = Up;
pvr_prim(&vert, sizeof(vert));

vert.x = FinalVector[1].x;
vert.y = FinalVector[1].y;
vert.z = FinalVector[1].z;
vert.u = Right;
vert.v = Up;
pvr_prim(&vert, sizeof(vert));

vert.x = FinalVector[2].x;
vert.y = FinalVector[2].y;
vert.z = FinalVector[2].z;
vert.u = Left;
vert.v = Down;
pvr_prim(&vert, sizeof(vert));

vert.x = FinalVector[3].x;
vert.y = FinalVector[3].y;
vert.z = FinalVector[3].z;
vert.u = Right;
vert.v = Down;
vert.flags = PVR_CMD_VERTEX_EOL;
pvr_prim(&vert, sizeof(vert));

}

/*
void DrawVectorTexture(
vector_t* FinalVector, pvr_ptr_t Texture, uint32 TextureType, uint32 TextureList, 
uint16 TextureSizeX, uint16 TextureSizeY, float Alpha, float Red, float Green, float Blue){

pvr_poly_cxt_t cxt;

pvr_poly_cxt_txr(&cxt, TextureList, TextureType, TextureSizeX, TextureSizeY, Texture, PVR_FILTER_BILINEAR);
DrawContextTexture(FinalVector, &cxt, Alpha, Red, Green, Blue, 0.0f, 1.0f, 0.0f, 1.0f);

}
*/



void DrawVectorTexturePlus(
vector_t* FinalVector, pvr_ptr_t Texture, uint32 TextureType, uint32 TextureList, 
uint16 TextureSizeX, uint16 TextureSizeY, float Alpha, float Red, float Green, float Blue, float Left, float Right, float Up, float Down){

pvr_poly_cxt_t cxt;

pvr_poly_cxt_txr(&cxt, TextureList, TextureType, TextureSizeX, TextureSizeY, Texture, PVR_FILTER_BILINEAR);
DrawContextTexture(FinalVector, &cxt, Alpha, Red, Green, Blue, Left, Right, Up, Down);

}

void DrawVectorTextureCheckReverseX(
vector_t* FinalVector, pvr_ptr_t Texture, uint32 TextureType, uint32 TextureList, 
uint16 TextureSizeX, uint16 TextureSizeY, float Alpha, float Red, float Green, float Blue, float Left, float Right, float Up, float Down, uint8 Reverse){

if(!Reverse) DrawVectorTexturePlus(FinalVector, Texture, TextureType, TextureList, TextureSizeX, TextureSizeY, Alpha, Red, Green, Blue, Left, Right, Up, Down);
else DrawVectorTexturePlus(FinalVector, Texture, TextureType, TextureList, TextureSizeX, TextureSizeY, Alpha, Red, Green, Blue, Right, Left, Up, Down);
}

#define DrawVectorTexture(FinalVector, Texture, TextureType, TextureList, TextureSizeX, TextureSizeY, Alpha, Red, Green, Blue) DrawVectorTexturePlus(FinalVector, Texture, TextureType, TextureList, TextureSizeX, TextureSizeY, Alpha, Red, Green, Blue, 0.0f, 1.0f, 0.0f, 1.0f)


