#define FileDirSaveNumberPosition	15

void LoadGameActivateVisualMemoryData(LoadScreenVisualMemoryStruct* LoadScreenVisualMemoryData, uint8 WhichPort, uint8 WhichSlot){

file_t InputFile;

char FileDir[NormalFileDirSize];
uint16 WhichSave;

LoadScreenVisualMemoryData->SaveAmount = 0;
LoadScreenVisualMemoryData->SingleSaveData = ((SingleSaveStruct*)malloc(sizeof(SingleSaveStruct)));

sprintf(FileDir, "/vmu/%c%d/STOLAR0.sav", ((char)(WhichPort+('a'))), (WhichSlot+1));
for(WhichSave = 1; WhichSave <= MaximumSaveFileAmount; WhichSave++){
sprintf(FileDir+FileDirSaveNumberPosition, "%d.sav", WhichSave);
if(FileExists(FileDir)){
if(LoadScreenVisualMemoryData->SaveAmount > 0){
LoadScreenVisualMemoryData->SingleSaveData = ((SingleSaveStruct*)realloc(LoadScreenVisualMemoryData->SingleSaveData, (sizeof(SingleSaveStruct)*(LoadScreenVisualMemoryData->SaveAmount+1))));
}
InputFile = fs_open(FileDir, O_RDONLY);
fs_seek(InputFile, zlib_getlength(FileDir), SEEK_SET);
fs_read(InputFile, LoadScreenVisualMemoryData->SingleSaveData[LoadScreenVisualMemoryData->SaveAmount].Data, (sizeof(SaveHeaderStruct)));
fs_close(InputFile);
LoadScreenVisualMemoryData->SingleSaveData[LoadScreenVisualMemoryData->SaveAmount].WhichFile = (LoadScreenVisualMemoryData->SaveAmount+1);
LoadScreenVisualMemoryData->SaveAmount++;
}

}

}
