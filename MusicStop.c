#define MusicLogicLoopNot		0
#define MusicLogicLoop			1

void MusicStop(){
char FileDir[NormalFileDirSize];

sprintf(FileDir, MusicTemporaryFileDir);
sndoggvorbis_stop();
fs_unlink(FileDir);
}