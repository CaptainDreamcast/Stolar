void LoadFight(
StolarFightStruct* StolarFightData, EnemyFightStruct* EnemyFightData, FightLocationStruct* FightLocationData, 
GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, 
uint16 BackGroundIdentifier, uint8 EnemyAmount, uint16* EnemyIdentifier
){

file_t InputFile;

char FileDir[NormalFileDirSize];
char MountPoint[NormalMountPointSize];

uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;
int BluffX, BluffY, PaletteLocation;

PaletteLocation = EnemyPaletteOffset;

sprintf(FileDir, "%s/STAGES/BG%d.img.gz", FileSystemUsed, BackGroundIdentifier);
StreamingLoadFlush(FileDir);

sprintf(FileDir, "/ram/BG%d.img.gz", BackGroundIdentifier);
sprintf(MountPoint, "/STAGE");
CompressedFileDirToRomDisk(FileDir, MountPoint);

sprintf(FileDir, "%s/HEADER.hdr", MountPoint);
InputFile = fs_open(FileDir, O_RDONLY);
fs_read(InputFile, &FightLocationData->LocationData, sizeof(FightLocationDataStruct));

FightLocationData->AnimationData = (AnimationStruct*)malloc((FightLocationData->LocationData.AnimationAmount)*sizeof(AnimationStruct));
FightLocationData->LayerSizeX = (uint16*)malloc((FightLocationData->LocationData.AnimationAmount)*2);
FightLocationData->LayerSizeY = (uint16*)malloc((FightLocationData->LocationData.AnimationAmount)*2);
FightLocationData->TextureSizeX = (uint16*)malloc((FightLocationData->LocationData.AnimationAmount)*2);
FightLocationData->TextureSizeY = (uint16*)malloc((FightLocationData->LocationData.AnimationAmount)*2);
FightLocationData->TexturePositionX = (short*)malloc((FightLocationData->LocationData.AnimationAmount)*2);
FightLocationData->TexturePositionY = (short*)malloc((FightLocationData->LocationData.AnimationAmount)*2);
FightLocationData->TexturePositionZ = (short*)malloc((FightLocationData->LocationData.AnimationAmount)*2);
FightLocationData->CurrentFrame = (uint16*)malloc((FightLocationData->LocationData.AnimationAmount)*2);
FightLocationData->Ticks = (uint8*)malloc(FightLocationData->LocationData.AnimationAmount);

fs_read(InputFile, FightLocationData->AnimationData, (FightLocationData->LocationData.AnimationAmount)*sizeof(AnimationStruct));
fs_read(InputFile, FightLocationData->LayerSizeX, (FightLocationData->LocationData.AnimationAmount)*2);
fs_read(InputFile, FightLocationData->LayerSizeY, (FightLocationData->LocationData.AnimationAmount)*2);
fs_read(InputFile, FightLocationData->TextureSizeX, (FightLocationData->LocationData.AnimationAmount)*2);
fs_read(InputFile, FightLocationData->TextureSizeY, (FightLocationData->LocationData.AnimationAmount)*2);
fs_read(InputFile, FightLocationData->TexturePositionX, (FightLocationData->LocationData.AnimationAmount)*2);
fs_read(InputFile, FightLocationData->TexturePositionY, (FightLocationData->LocationData.AnimationAmount)*2);
fs_read(InputFile, FightLocationData->TexturePositionZ, (FightLocationData->LocationData.AnimationAmount)*2);
fs_read(InputFile, FightLocationData->CurrentFrame, (FightLocationData->LocationData.AnimationAmount)*2);
fs_read(InputFile, FightLocationData->Ticks, FightLocationData->LocationData.AnimationAmount);

fs_close(InputFile);

FightLocationData->Texture = (pvr_ptr_t*)malloc((FightLocationData->LocationData.TextureAmount)*sizeof(pvr_ptr_t));

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<FightLocationData->LocationData.TextureAmount; DirtyDeedsDoneDirtCheap++){
sprintf(FileDir, "%s/%d.kmg", MountPoint, DirtyDeedsDoneDirtCheap);
FightLocationData->Texture[DirtyDeedsDoneDirtCheap] = pvr_mem_malloc(FightLocationData->TextureSizeX[DirtyDeedsDoneDirtCheap]*FightLocationData->TextureSizeY[DirtyDeedsDoneDirtCheap]*2);
TextureLoadKMG(FileDir, &FightLocationData->Texture[DirtyDeedsDoneDirtCheap], &BluffX, &BluffY, NoAllocateTextureMemory);
}

fs_romdisk_unmount(MountPoint);


sprintf(FileDir, "%s/OTHER/FIGHTGUI.img.gz", FileSystemUsed);
StreamingLoadFlush(FileDir);

sprintf(FileDir, "/ram/FIGHTGUI.img.gz");
sprintf(MountPoint, "/GUI");
CompressedFileDirToRomDisk(FileDir, MountPoint);

sprintf(FileDir, "%s/HEADER.hdr", MountPoint);
InputFile = fs_open(FileDir, O_RDONLY);
fs_read(InputFile, &GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData, sizeof(GraphicalUserInterFaceLoadStruct));
fs_close(InputFile);

sprintf(FileDir, "%s/BG.kmg", MountPoint);
GraphicalUserInterFaceData->HealthBackGroundTexture = pvr_mem_malloc(GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.HealthBackGroundTextureSizeX*GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.HealthBackGroundTextureSizeY*2);
TextureLoadKMG(FileDir, &GraphicalUserInterFaceData->HealthBackGroundTexture, &BluffX, &BluffY, NoAllocateTextureMemory);

sprintf(FileDir, "%s/FG.kmg", MountPoint);
GraphicalUserInterFaceData->HealthTexture = pvr_mem_malloc(GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.HealthTextureSizeX*GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.HealthTextureSizeY*2);
TextureLoadKMG(FileDir, &GraphicalUserInterFaceData->HealthTexture, &BluffX, &BluffY, NoAllocateTextureMemory);

sprintf(FileDir, "%s/SHADER.kmg", MountPoint);
GraphicalUserInterFaceData->ThresholdTexture = pvr_mem_malloc(AbilityDrawSizeX*AbilityDrawSizeY*2);
TextureLoadKMG(FileDir, &GraphicalUserInterFaceData->ThresholdTexture, &BluffX, &BluffY, NoAllocateTextureMemory);

sprintf(FileDir, "%s/DISTORTION.kmg", MountPoint);
GraphicalUserInterFaceData->DistortionTexture = pvr_mem_malloc(DistortionTextureSizeX*DistortionTextureSizeY*2);
TextureLoadKMG(FileDir, &GraphicalUserInterFaceData->DistortionTexture, &BluffX, &BluffY, NoAllocateTextureMemory);

sprintf(FileDir, "%s/SCANLINE.kmg", MountPoint);
GraphicalUserInterFaceData->ScanLineTexture = pvr_mem_malloc(ScanLineTextureSizeX*ScanLineTextureSizeY*2);
TextureLoadKMG(FileDir, &GraphicalUserInterFaceData->ScanLineTexture, &BluffX, &BluffY, NoAllocateTextureMemory);

sprintf(FileDir, "%s/PAUSE.kmg", MountPoint);
GraphicalUserInterFaceData->PauseTexture = pvr_mem_malloc(GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.PauseSizeX*GraphicalUserInterFaceData->GraphicalUserInterFaceLoadData.PauseSizeY*2);
TextureLoadKMG(FileDir, &GraphicalUserInterFaceData->PauseTexture, &BluffX, &BluffY, NoAllocateTextureMemory);

sprintf(FileDir, "%s/ESCALATION.pal", MountPoint);
FileDirToPalette(FileDir, EscalationPaletteOffset,  NULL, NULL);

sprintf(FileDir, "%s/ESCALATION.kmg", MountPoint);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EscalationTextureAmount; DirtyDeedsDoneDirtCheap++){
GraphicalUserInterFaceData->EscalationTexture[DirtyDeedsDoneDirtCheap] = pvr_mem_malloc(EscalationTextureSizeX*EscalationTextureSizeY/2);
TextureLoadKMG(FileDir, &GraphicalUserInterFaceData->EscalationTexture[DirtyDeedsDoneDirtCheap], &BluffX, &BluffY, NoAllocateTextureMemory);
}

fs_romdisk_unmount(MountPoint);



for(DirtyDeedsDoneDirtCheap = YellowAbility; DirtyDeedsDoneDirtCheap<AbilityAmount; DirtyDeedsDoneDirtCheap++){
sprintf(FileDir, "%s/ABILITIES/AB%d.img.gz", FileSystemUsed, StolarFightData->StolarData->Ability[DirtyDeedsDoneDirtCheap]);
StreamingLoadFlush(FileDir);

sprintf(FileDir, "/ram/AB%d.img.gz", StolarFightData->StolarData->Ability[DirtyDeedsDoneDirtCheap]);
sprintf(MountPoint, "/ABILITY%d", DirtyDeedsDoneDirtCheap);
CompressedFileDirToRomDisk(FileDir, MountPoint);

sprintf(FileDir, "%s/HEADER.hdr", MountPoint);
InputFile = fs_open(FileDir, O_RDONLY);
fs_read(InputFile, &GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap], sizeof(AbilityStruct));
fs_close(InputFile);

GraphicalUserInterFaceData->FinalBarTexture[DirtyDeedsDoneDirtCheap] = pvr_mem_malloc(GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap].TextureSizeX*GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap].TextureSizeY*2);

sprintf(FileDir, "%s/GUI.kmg", MountPoint);
GraphicalUserInterFaceData->AbilityTexture[DirtyDeedsDoneDirtCheap] = pvr_mem_malloc(GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap].TextureSizeX*GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap].TextureSizeY*2);
TextureLoadKMG(FileDir, &GraphicalUserInterFaceData->AbilityTexture[DirtyDeedsDoneDirtCheap], &BluffX, &BluffY, NoAllocateTextureMemory);

fs_romdisk_unmount(MountPoint);
}



for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EnemyAmount; DirtyDeedsDoneDirtCheap++){

sprintf(FileDir, "%s/MONSTERS/M%d.img.gz", FileSystemUsed, EnemyIdentifier[DirtyDeedsDoneDirtCheap]);
StreamingLoadFlush(FileDir);

sprintf(FileDir, "/ram/M%d.img.gz", EnemyIdentifier[DirtyDeedsDoneDirtCheap]);
sprintf(MountPoint, "/SCARY");
CompressedFileDirToRomDisk(FileDir, MountPoint);

sprintf(FileDir, "%s/HEADER.hdr", MountPoint);
InputFile = fs_open(FileDir, O_RDONLY);
fs_read(InputFile, &EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData, sizeof(EnemyDataStruct));

EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyAnimationData = (AnimationStruct*)malloc(sizeof(AnimationStruct)*EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.AnimationAmount);

for(BurningDownTheHouse=0; BurningDownTheHouse<EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.AnimationAmount; BurningDownTheHouse++){
fs_read(InputFile, &EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyAnimationData[BurningDownTheHouse], sizeof(AnimationStruct));
}

fs_close(InputFile);

EnemyFightData[DirtyDeedsDoneDirtCheap].Stack = (uint8*)malloc(EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.StackNeeded);
EnemyFightData[DirtyDeedsDoneDirtCheap].Texture = (pvr_ptr_t*)malloc(EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.TexturesNeeded*sizeof(pvr_ptr_t));

BurningDownTheHouse = 0;
while(BurningDownTheHouse<DirtyDeedsDoneDirtCheap){

if(EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.PaletteIdentifier == EnemyFightData[BurningDownTheHouse].EnemyData.PaletteIdentifier){
EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.PaletteType = EnemyFightData[BurningDownTheHouse].EnemyData.PaletteType;
EnemyFightData[DirtyDeedsDoneDirtCheap].PalettePosition = EnemyFightData[BurningDownTheHouse].PalettePosition;
BurningDownTheHouse = 0xFF;
}
else BurningDownTheHouse++;

}

if(BurningDownTheHouse != 0xFF){
sprintf(FileDir, "%s/%d.pal", MountPoint, EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.PaletteIdentifier);
PaletteLocation = FileDirToPalette(FileDir, PaletteLocation, &EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.PaletteType, &EnemyFightData[DirtyDeedsDoneDirtCheap].PalettePosition);
}

for(BurningDownTheHouse=0; BurningDownTheHouse<EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.TexturesNeeded; BurningDownTheHouse++){
sprintf(FileDir, "%s/%d.kmg", MountPoint, BurningDownTheHouse);
EnemyFightData[DirtyDeedsDoneDirtCheap].Texture[BurningDownTheHouse] = pvr_mem_malloc(EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.TextureSizeX*EnemyFightData[DirtyDeedsDoneDirtCheap].EnemyData.TextureSizeY*2);
TextureLoadKMG(FileDir, &EnemyFightData[DirtyDeedsDoneDirtCheap].Texture[BurningDownTheHouse], &BluffX, &BluffY, NoAllocateTextureMemory);
}

fs_romdisk_unmount(MountPoint);
}



}