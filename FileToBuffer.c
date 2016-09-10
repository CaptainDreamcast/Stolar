uint32 FileToBuffer(char* FileDir, void** Buffer){

file_t InputFile;
uint32 InputFileSize;

InputFile = fs_open(FileDir, O_RDONLY);
CheckInvalidFileHandler(InputFile, FileDir);
InputFileSize = fs_total(InputFile);

if(FileDir[1] != 'p' && FileDir[1] != 'c' && FileDir[1] != 's') *Buffer = fs_mmap(InputFile);
else{
*Buffer = (void*)(malloc(InputFileSize));
fs_read(InputFile, *Buffer, InputFileSize);
}

fs_close(InputFile);

return(InputFileSize);
}