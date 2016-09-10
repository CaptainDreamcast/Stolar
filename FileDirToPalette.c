#define CreatePaletteEntry(a,r,g,b) ( ((a & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | ((b & 0xFF)) )

int FileDirToPalette(char FileDir[], int PaletteLocation, uint8* PaletteType, uint16* PalettePosition){

file_t InputFile;

uint32 FileLength;
long PaletteBufferPosition;
unsigned char* PaletteBuffer;


InputFile = fs_open(FileDir, O_RDONLY);

if(InputFile == FILEHND_INVALID){fs_close(InputFile); printf("Couldn't open: (%s)\n", FileDir); return(0);}


FileLength = fs_total(InputFile);
PaletteBuffer = fs_mmap(InputFile);

if(PaletteLocation%(FileLength/4)) PaletteLocation += (FileLength/4)-(PaletteLocation%(FileLength/4));
if(PalettePosition != NULL) *PalettePosition = PaletteLocation/(FileLength/4);

PaletteBufferPosition = 0;

while(PaletteBufferPosition < FileLength){

pvr_set_pal_entry(PaletteLocation, CreatePaletteEntry(PaletteBuffer[PaletteBufferPosition+3], PaletteBuffer[PaletteBufferPosition+2], PaletteBuffer[PaletteBufferPosition+1], PaletteBuffer[PaletteBufferPosition]));
PaletteBufferPosition+=4;
PaletteLocation++;
}

fs_close(InputFile);

if(PaletteType != NULL) (FileLength > 16*4) ? (*PaletteType = 8) : (*PaletteType = 4);

return(PaletteLocation);
}
