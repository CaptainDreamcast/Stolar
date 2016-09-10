#define MusicLogicLoopNot		0
#define MusicLogicLoop			1

void MusicPlayBuffer(void* Buffer, uint32 BufferSize){
char FileDir[NormalFileDirSize];

sprintf(FileDir, MusicTemporaryFileDir);
BufferToFileRandomAccessMemoryDisk(Buffer, BufferSize, FileDir);
sndoggvorbis_start(FileDir, MusicLogicLoop);
}