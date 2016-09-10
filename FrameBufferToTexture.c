pvr_ptr_t OriginalFrameBufferToTexture(){

pvr_ptr_t Texture;
//uint32* = TexturePointer;
uint16 DirtyDeedsDoneDirtCheap;

Texture = pvr_mem_malloc(1024*512*2);

//TexturePointer = (uint32*)Texture;

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<480; DirtyDeedsDoneDirtCheap++){
sq_cpy(Texture+DirtyDeedsDoneDirtCheap*1024*2, vram_s+DirtyDeedsDoneDirtCheap*640*2, 640*2);
}


return(Texture);
}

pvr_ptr_t FrameBufferToTexture(){

pvr_ptr_t Texture;
uint32 FrameBufferPosition, TextureMemoryPosition, FinalPosition;
uint32 save;

Texture = pvr_mem_malloc(1024*512*2);
sq_clr(Texture, 1024*512*2);

TextureMemoryPosition = (uint32)Texture;
FinalPosition = ((uint32)vram_s)+640*480*2;

save = irq_disable();
for(FrameBufferPosition=(uint32)vram_s; FrameBufferPosition<FinalPosition; FrameBufferPosition+=1280){
sq_cpy((void*)TextureMemoryPosition, (void*)FrameBufferPosition, 1280);
TextureMemoryPosition+=2048;
}
irq_restore(save);

return(Texture);
}

void TextureToFrameBuffer(pvr_ptr_t Texture){

uint32 FrameBufferPosition, TextureMemoryPosition, FinalPosition;
uint32 save;

TextureMemoryPosition = (uint32)Texture;
FinalPosition = ((uint32)vram_s)+640*480*2;

save = irq_disable();
for(FrameBufferPosition=(uint32)vram_s; FrameBufferPosition<FinalPosition; FrameBufferPosition+=1280){
//sq_cpy(Texture+DirtyDeedsDoneDirtCheap*1024*2, vram_s+DirtyDeedsDoneDirtCheap*640*2, 640*2);
sq_cpy((void*)FrameBufferPosition, (void*)TextureMemoryPosition, 1280);

TextureMemoryPosition+=2048;
}
irq_restore(save);


}

void TextureToFrameBuffer2(pvr_ptr_t Texture){

sq_cpy((void*)vram_s, (void*)Texture, 0x96000);

}

void TextureToFrameBuffer3(pvr_ptr_t Texture){

vram_s = (uint16*)Texture;
vram_l = (uint32*)Texture;

}
