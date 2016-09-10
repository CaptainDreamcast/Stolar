#define VisualMemoryBlockAmount		200
#define VisualMemoryBlockSize			512
#define MaximumVisualMemorySpace	(VisualMemoryBlockAmount*VisualMemoryBlockSize)
//#define MaximumSaveFileAmount		(MaximumVisualMemorySpace/((sizeof(SaveStruct)/VisualMemoryBlockSize)+1))
#define MaximumSaveFileAmount		10

uint8 SaveGameExists(){

char FileDir[NormalFileDirSize];
uint8 ReturnValue;
uint8 WhichPort, WhichSlot;
uint16 WhichSave;

ReturnValue = 0;
for(WhichPort = 'a'; WhichPort<= 'd'; WhichPort++){
for(WhichSlot = 1; WhichSlot <= 2; WhichSlot++){
for(WhichSave = 1; WhichSave <= MaximumSaveFileAmount; WhichSave++){
sprintf(FileDir, "/vmu/%c%d/STOLAR%d.sav", WhichPort, WhichSlot, WhichSave);
if(FileExists(FileDir)) ReturnValue = 1;
}
}
}


if(ReturnValue) sprintf(FileDir, "%s/VMU/SAVE.dri", FileSystemUsed);
else sprintf(FileDir, "%s/VMU/NOSAVE.dri", FileSystemUsed);


FileDirToLCD(FileDir, DisplayBeep);

return(ReturnValue);
}