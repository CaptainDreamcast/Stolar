void LoadGameLoadSingleSaveData(uint8 WhichPort, uint8 WhichSlot, uint16 WhichSave, LoadScreenControllerStruct* LoadScreenControllerData){

char FileDir[NormalFileDirSize];

InitializeSaveData(); 
sprintf(FileDir, "/vmu/%c%d/STOLAR%d.sav", ((char)(WhichPort+('a'))), (WhichSlot+1), WhichSave);
CompressedFileToBuffer(FileDir, (void**)(&SaveData.CompressableData));
memcpy4(SaveData.HeaderData, LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot].SingleSaveData[WhichSave].Data, sizeof(SaveHeaderStruct));

}