void CompressedFileDirToRomDisk(char FileDir[], char MountPoint[]){

gzFile InputFile;
uint32 Length;

uint8* RomDiskBuffer;


Length = zlib_getlength(FileDir);
RomDiskBuffer = (uint8*)malloc(Length);

InputFile = gzopen(FileDir, "rb");
gzread(InputFile, RomDiskBuffer, Length);
gzclose(InputFile);

fs_romdisk_mount(MountPoint, RomDiskBuffer, 1);

}

void FileDirToRomDisk(char RomDiskDir[], char MountPoint[]){

file_t RomDiskFile;
uint8* RomDiskBuffer;
long RomDiskSize;


RomDiskFile = fs_open(RomDiskDir, O_RDONLY);

RomDiskSize = fs_total(RomDiskFile);

RomDiskBuffer = (uint8 *)malloc(RomDiskSize);

fs_read(RomDiskFile, RomDiskBuffer, RomDiskSize);

fs_romdisk_mount(MountPoint, RomDiskBuffer, 1);

fs_close(RomDiskFile);
}
