void SoundPlay(uint8 WhichTrack){

char FileDir[NormalFileDirSize];
char NewFileDir[NormalFileDirSize];

sprintf(FileDir, "%s/MUSIC/%d.ogg", FileSystemUsed, WhichTrack);
sprintf(NewFileDir, "/ram/%d.ogg", WhichTrack);
FileCopyToOtherFileSystem(FileDir, NewFileDir);

sndoggvorbis_start(NewFileDir, 0);

}

void SoundStop(uint8 WhichTrack){

char NewFileDir[NormalFileDirSize];


sndoggvorbis_stop();
sprintf(NewFileDir, "/ram/%d.ogg", WhichTrack);
fs_unlink(NewFileDir);

}