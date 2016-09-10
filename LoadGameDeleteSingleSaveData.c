void LoadGameDeleteSingleSaveData(uint8 WhichPort, uint8 WhichSlot, uint16 WhichSave, LoadScreenControllerStruct* LoadScreenControllerData){

char FileDir[NormalFileDirSize];

sprintf(FileDir, "/vmu/%c%d/STOLAR%d.sav", ((char)(WhichPort+('a'))), (WhichSlot+1), WhichSave);
fs_unlink(FileDir);

LoadGameDeActivateVisualMemoryData(LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot]);
LoadGameActivateVisualMemoryData(&LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot], WhichPort, WhichSlot);
}