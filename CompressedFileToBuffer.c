uint32 CompressedFileToBuffer(char* FileDir, void** Buffer){

gzFile CompressedInputFile;
uint32 InputFileSize;

InputFileSize = zlib_getlength(FileDir);
*Buffer = (void*)(malloc(InputFileSize));
CompressedInputFile = gzopen(FileDir, "rb");
gzread(CompressedInputFile, *Buffer, InputFileSize);
gzclose(CompressedInputFile);

return(InputFileSize);
}
