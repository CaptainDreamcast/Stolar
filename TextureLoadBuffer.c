void TextureLoadBuffer(void* InputBuffer, pvr_ptr_t* TextureUsed, int* TextureSizeX, int* TextureSizeY, int* BufferSize, char MemoryReAllocation){

if(MemoryReAllocation == ReAllocateTextureMemory){
pvr_mem_free((*TextureUsed));
*TextureUsed = NULL;
*TextureUsed = pvr_mem_malloc((*BufferSize));
}

sq_cpy(*TextureUsed, InputBuffer, (*BufferSize));
}