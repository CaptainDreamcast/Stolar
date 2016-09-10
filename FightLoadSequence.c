void FightLoadSequence(){
char FileDir[NormalFileDirSize];
sprintf(FileDir, "%s/STORYBOARDS/1.sbd", FileSystemUsed);

SoundPlay(2);
LetsSeeTheStory(FileDir);
SoundStop(2);

}