void StartNewGameSequence(){
char FileDir[NormalFileDirSize];
sprintf(FileDir, "%s/STORYBOARDS/0.sbd", FileSystemUsed);

SoundPlay(0);
LetsSeeTheStory(FileDir);
SoundStop(0);


}