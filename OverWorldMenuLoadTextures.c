void OverWorldMenuLoadTextures(OverWorldMenuStruct* OverWorldMenuData){

uint32 CurrentPointerPosition;
void* Pointer;
char FileDir[NormalFileDirSize];
uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;

sprintf(FileDir, "%s/MENU/MENUTEXTURES.tex.gz", FileSystemUsed);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/MENUTEXTURES.tex.gz");
CompressedFileToBuffer(FileDir, &Pointer);

CurrentPointerPosition = (uint32)Pointer;

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < OverWorldMenuScreenAmount; DirtyDeedsDoneDirtCheap++) OverWorldMenuData->InactiveScreenTextures[DirtyDeedsDoneDirtCheap] = pvr_mem_malloc((TextureTypeMultiplierDispatch(OverWorldMenuInactiveScreenFormat))*OverWorldMenuData->Loadable->InactiveScreenTextureSizeX*OverWorldMenuData->Loadable->InactiveScreenTextureSizeY);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->BackGroundTexture);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < OverWorldMenuHandSwipeAmount; DirtyDeedsDoneDirtCheap++){
OverWorldMenuData->HandTexture[DirtyDeedsDoneDirtCheap] = (pvr_ptr_t*)malloc(OverWorldMenuData->Loadable->HandFrameAmount*sizeof(pvr_ptr_t));
for(BurningDownTheHouse = 0; BurningDownTheHouse < OverWorldMenuData->Loadable->HandFrameAmount; DirtyDeedsDoneDirtCheap++){
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->HandTexture[DirtyDeedsDoneDirtCheap][BurningDownTheHouse]);
}
}

LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->StatsTextures.BackGroundTexture);

LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->MapData.BackGroundTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->MapData.MapTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->MapData.GoalIcon);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->MapData.StolarIcon);

LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->ItemData.BackGroundTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->ItemData.ScrollButtonTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->ItemData.AllItems);

LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->AbilityData.AllAbilities);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->AbilityData.ScrollButtonTexture);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < (AbilityAmount-1); DirtyDeedsDoneDirtCheap++){
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->AbilityData.EquippedAbilityBackGroundTexture[DirtyDeedsDoneDirtCheap]);
}

LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->DivaData.MainBackGroundTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->DivaData.LogOptionBackGroundTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->DivaData.CharacterEntryBackGroundTexture);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->DivaData.TheatreThumbnailTextures);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->DivaData.TheatreThumbnailsScrollButtonTexture);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < OverallCharacterEntryAmount; DirtyDeedsDoneDirtCheap++){
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->DivaData.CharacterTexture[DirtyDeedsDoneDirtCheap]);
}
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < OverWorldMenuDivaMainOptionAmount; DirtyDeedsDoneDirtCheap++){
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->DivaData.MainOptionTextures[DirtyDeedsDoneDirtCheap]);
}

LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->ConfirmationTextures.ConfirmationMainBox);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < OverWorldMenuConfirmationOptionAmount; DirtyDeedsDoneDirtCheap++){
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->ConfirmationTextures.ConfirmationYes[DirtyDeedsDoneDirtCheap]);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldMenuData->ConfirmationTextures.ConfirmationNo[DirtyDeedsDoneDirtCheap]);
}

free(Pointer);

}