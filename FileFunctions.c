#define StandardFileSystemFlag 0x80000000

file_t FileOpen(char* FileDir, uint32 Flags){

int ReturnValue;

ReturnValue = fs_open(FileDir, Flags);
if(ReturnValue == FILEHND_INVALID) return(FILEHND_INVALID);
else ReturnValue |= StandardFileSystemFlag;

return((file_t)ReturnValue);
}

void FileClose(file_t FileHandler){

fs_close((FileHandler & (~StandardFileSystemFlag)));


}

uint32 FileRead(file_t FileHandler, void* Buffer, uint32 Size){

uint32 ReturnValue;

ReturnValue = fs_read((FileHandler & (~StandardFileSystemFlag)), Buffer, Size);

return(ReturnValue);
}

uint32 FileWrite(file_t FileHandler, void* Buffer, uint32 Size){

uint32 ReturnValue;

ReturnValue = fs_write((FileHandler & (~StandardFileSystemFlag)), Buffer, Size);

return(ReturnValue);
}

uint32 FileSeek(file_t FileHandler, uint32 Offset, int Flags){

uint32 ReturnValue;

ReturnValue = fs_seek((FileHandler & (~StandardFileSystemFlag)), Offset, Flags);

return(ReturnValue);
}

uint8 FileUnlink(char* FileDir){

uint8 ReturnValue;

ReturnValue = fs_unlink(FileDir);

return(ReturnValue);
}

char* FileMemoryMap(file_t FileHandler){

char* ReturnBuffer;

ReturnBuffer = fs_mmap((FileHandler & (~StandardFileSystemFlag)));

return(ReturnBuffer);
}

uint32 FileTotal(file_t FileHandler){

uint32 ReturnValue;

ReturnValue = fs_total((FileHandler & (~StandardFileSystemFlag)));

return(ReturnValue);
}

uint32 FileTell(file_t FileHandler){

uint32 ReturnValue;

ReturnValue = fs_tell((FileHandler & (~StandardFileSystemFlag)));

return(ReturnValue);
}
