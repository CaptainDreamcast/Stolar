void TextureLoadKMG(char WhichFileUsed[], pvr_ptr_t* TextureUsed, int* TextureSizeX, int* TextureSizeY, char MemoryReAllocation){

size_t BufferLength;
file_t KMGFile;
char* KMGData;

KMGFile = fs_open(WhichFileUsed, O_RDONLY);

if(KMGFile == FILEHND_INVALID){ 
printf("\nCouldn't open: (%s)\nAborting Kernel any minute now...\n", WhichFileUsed);
arch_exit();
}

BufferLength = fs_total(KMGFile);

KMGData = fs_mmap(KMGFile);


memcpy4(TextureSizeX, KMGData+16, sizeof(*TextureSizeX));
memcpy4(TextureSizeY, KMGData+20, sizeof(*TextureSizeY));

//printf("Texture Size: %d/%d\n", *TextureSizeX, *TextureSizeY);

if(MemoryReAllocation == ReAllocateTextureMemory){
pvr_mem_free(*TextureUsed);
*TextureUsed = NULL;
*TextureUsed = pvr_mem_malloc(BufferLength-HeaderSizeKMG);
}


//memcpy4(TextureUsed, KMGData+HeaderSizeKMG, BufferLength-HeaderSizeKMG);
sq_cpy(*TextureUsed, KMGData+HeaderSizeKMG, BufferLength-HeaderSizeKMG);


fs_close(KMGFile);

}