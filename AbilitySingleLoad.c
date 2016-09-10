void AbilitySingleLoad(OverWorldCrewFluxAbilityStruct* OverWorldCrewFluxAbilityData, uint16 WhichAbility){

char FileDir[NormalFileDirSize];
uint32 CurrentPointerPosition;

sprintf(FileDir, "%s/ABILITIES/%d.abl", FileSystemUsed, WhichAbility);
/*
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/%d.abl", WhichAbility);
*/
FileToBuffer(FileDir, (void**)(&OverWorldCrewFluxAbilityData->AbilityData));
CurrentPointerPosition = ((uint32)OverWorldCrewFluxAbilityData->AbilityData)+sizeof(OverWorldCrewFluxAbilityLoadableStruct);
LoadSetThisToThatPointer(void*, OverWorldCrewFluxAbilityData->Loadable, DummyValueInteger);

}