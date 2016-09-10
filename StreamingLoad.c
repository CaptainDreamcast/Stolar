#define StreamingLoadFileAmountMax	5

#define StreamingLoadSourceFile 	0
#define StreamingLoadDestinationFile 	1
#define StreamingLoadFileHandlerAmount	2

#define StreamingLoadLowestPriority		0
#define StreamingLoadNormalPriority		(StreamingLoadFileAmountMax/2)
#define StreamingLoadHighPriority			StreamingLoadFileAmountMax

#define StreamingLoadStandardMagicValue		10

uint64 PowerVRTestTimeOld, PowerVRTestTimeNew;
uint8 StreamingLoadFileAmount = 0;
uint8 CurrentPositionStreamingLoadFileBuffer = 0;
char StreamingLoadFileDir[StreamingLoadFileAmountMax][NormalFileDirSize];
file_t StreamingLoadFile[StreamingLoadFileHandlerAmount];
uint8 StreamingLoadActive;

#define SetStreamingLoadFileSimplest(FileDir) 	SetStreamingLoadFile(FileDir, StreamingLoadNormalPriority)
void SetStreamingLoadFile(char FileDir[], uint8 Priority){
uint8 BufferPosition;

StreamingLoadFileAmount++;
if(StreamingLoadFileAmount > StreamingLoadFileAmountMax){
printf("StreamingLoadFileAmount: (%d)\n", StreamingLoadFileAmount);
arch_exit();
}

BufferPosition = CurrentPositionStreamingLoadFileBuffer;
while(StreamingLoadActive & (1 << BufferPosition)){
BufferPosition++;
}

StreamingLoadActive |= (1 << CurrentPositionStreamingLoadFileBuffer);

sprintf(StreamingLoadFileDir[BufferPosition], "%s", FileDir);
}

void OpenStreamingLoadFile(){

char FileDir[NormalFileDirSize];
uint8 DirtyDeedsDoneDirtCheap;

while(!(StreamingLoadActive & (1 << CurrentPositionStreamingLoadFileBuffer))){
CurrentPositionStreamingLoadFileBuffer++;
}


DirtyDeedsDoneDirtCheap = sprintf(FileDir, "%s", StreamingLoadFileDir[CurrentPositionStreamingLoadFileBuffer]);
while(FileDir[DirtyDeedsDoneDirtCheap] != '/') DirtyDeedsDoneDirtCheap--;

sprintf(FileDir, "/ram%s", (StreamingLoadFileDir[CurrentPositionStreamingLoadFileBuffer])+DirtyDeedsDoneDirtCheap);
printf("FileDir: (%s)\n", FileDir);

if(FileExists(FileDir)){

StreamingLoadActive ^= (1 << CurrentPositionStreamingLoadFileBuffer);

CurrentPositionStreamingLoadFileBuffer++;
StreamingLoadFileAmount--;

} 
else{
StreamingLoadFile[StreamingLoadSourceFile] = fs_open(StreamingLoadFileDir[CurrentPositionStreamingLoadFileBuffer], O_RDONLY);
StreamingLoadFile[StreamingLoadDestinationFile] = fs_open(FileDir, O_WRONLY);
}

}


void StreamingLoad(uint32 Multiplicator){

uint8* StreamingBuffer;
uint8 BytesRetrieved;
uint32 Magic;

if(PowerVRTestTimeOld != -1){

PowerVRTestTimeNew = timer_ms_gettime64();

if(Multiplicator & (1<<31)) Magic = Multiplicator & (~(1<<31));
else Magic = (16-(PowerVRTestTimeNew - PowerVRTestTimeOld))*Multiplicator;

if(Magic > 0 && StreamingLoadFileAmount != 0){
if(StreamingLoadFile[StreamingLoadSourceFile] == -1) OpenStreamingLoadFile();

StreamingBuffer = (uint8*)malloc(Magic);
BytesRetrieved = fs_read(StreamingLoadFile[StreamingLoadSourceFile], StreamingBuffer, Magic);
fs_write(StreamingLoadFile[StreamingLoadDestinationFile], StreamingBuffer, BytesRetrieved);
free(StreamingBuffer);

if(BytesRetrieved != Magic){

fs_close(StreamingLoadFile[StreamingLoadSourceFile]);
StreamingLoadFile[StreamingLoadSourceFile] = -1;
fs_close(StreamingLoadFile[StreamingLoadDestinationFile]);
StreamingLoadFile[StreamingLoadDestinationFile] = -1;

StreamingLoadActive ^= (1 << CurrentPositionStreamingLoadFileBuffer);

CurrentPositionStreamingLoadFileBuffer++;
StreamingLoadFileAmount--;
}
}
}

if(!(Multiplicator & (1<<31))){
#ifdef FunFunFun
vid_border_color(0, 255, 0);
#endif
pvr_wait_ready();
PowerVRTestTimeOld = timer_ms_gettime64();
}

}

void InitiateStreamingLoad(){

StreamingLoadFile[StreamingLoadSourceFile] = -1;
StreamingLoadFile[StreamingLoadDestinationFile] = -1;
StreamingLoadFileAmount = 0;
StreamingLoadActive = 0;
CurrentPositionStreamingLoadFileBuffer = 0;
PowerVRTestTimeOld = -1;
}

void StreamingLoadRemoveFromList(char* FileDir){

uint8 DirtyDeedsDoneDirtCheap;

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<StreamingLoadFileAmountMax; DirtyDeedsDoneDirtCheap++){
if((StreamingLoadActive & (1 << DirtyDeedsDoneDirtCheap)) && CharArraysAreEqual(FileDir, StreamingLoadFileDir[DirtyDeedsDoneDirtCheap])) {
if(StreamingLoadFile[StreamingLoadSourceFile] != -1 && DirtyDeedsDoneDirtCheap == CurrentPositionStreamingLoadFileBuffer){
fs_close(StreamingLoadFile[StreamingLoadSourceFile]);
StreamingLoadFile[StreamingLoadSourceFile] = -1;
fs_close(StreamingLoadFile[StreamingLoadDestinationFile]);
StreamingLoadFile[StreamingLoadDestinationFile] = -1;
}
StreamingLoadActive ^= (1 << CurrentPositionStreamingLoadFileBuffer);
}
}

}

void StreamingLoadFlush(char FileDir[]){

file_t InputFile, OutputFile;
uint32 InputFileSize, OutputFileSize;

char OutputFileDir[NormalFileDirSize];
uint8* StreamingLoadBuffer;
uint8 DirtyDeedsDoneDirtCheap;

DirtyDeedsDoneDirtCheap = sprintf(OutputFileDir, "%s", FileDir);
while(FileDir[DirtyDeedsDoneDirtCheap] != '/') DirtyDeedsDoneDirtCheap--;

sprintf(OutputFileDir, "/ram%s", FileDir+DirtyDeedsDoneDirtCheap);
printf("OutputFileDir: (%s)\n", OutputFileDir);

InputFile = fs_open(FileDir, O_RDONLY);
OutputFile = fs_open(OutputFileDir, O_WRONLY);

InputFileSize = fs_total(InputFile);
OutputFileSize = fs_total(OutputFile);

if(OutputFileSize > 0 && OutputFileSize < InputFileSize){

PowerVRTestTimeOld = timer_ms_gettime64()-14;
InputFileSize |= (1<<31);
StreamingLoad(InputFileSize);

}
else if(OutputFileSize == 0){
StreamingLoadBuffer = (uint8*)malloc(InputFileSize);
fs_read(InputFile, StreamingLoadBuffer, InputFileSize);
fs_write(OutputFile, StreamingLoadBuffer, InputFileSize);
free(StreamingLoadBuffer);
}

fs_close(InputFile);
fs_close(OutputFile);

StreamingLoadRemoveFromList(FileDir);
}


void StreamingLoadUnlink(char* FileDir){

char OutputFileDir[NormalFileDirSize];
uint8 DirtyDeedsDoneDirtCheap;

DirtyDeedsDoneDirtCheap = sprintf(OutputFileDir, "%s", FileDir);
while(FileDir[DirtyDeedsDoneDirtCheap] != '/') DirtyDeedsDoneDirtCheap--;
sprintf(OutputFileDir, "/ram%s", FileDir+DirtyDeedsDoneDirtCheap);

if(FileExists(OutputFileDir)) fs_unlink(OutputFileDir);
StreamingLoadRemoveFromList(FileDir);

}
