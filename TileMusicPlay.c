#define OverWorldLogicMusicUpdate(TrackIdentifier, Buffer)	{ \
OverWorldData->LogicData.Music.CurrentTrack = TrackIdentifier; \
OverWorldData->LogicData.Music.AudioBuffer = Buffer; \
}

void TileMusicPlay(OverWorldStruct* OverWorldData, uint16 TrackIdentifier){
char FileDir[NormalFileDirSize];
void* Buffer;
uint32 BufferSize;

sprintf(FileDir, "%s/MUSIC/%d.%s", FileSystemUsed, TrackIdentifier, MusicStandardFileType);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/%d.%s", TrackIdentifier, MusicStandardFileType);
BufferSize = CompressedFileToBuffer(FileDir, &Buffer);
if(TileMusicIsPlaying()) TileMusicStop(OverWorldData);
MusicPlayBuffer(Buffer, BufferSize);
OverWorldLogicMusicUpdate(TrackIdentifier, Buffer);
}