uint16 CountFilesInDirectory(char* Directory){

file_t InputDirectory;
dirent_t* DirectoryReader;
uint16 ReturnValue;


InputDirectory = fs_open(Directory, O_RDONLY | O_DIR);
ReturnValue = 0;
while ((DirectoryReader = fs_readdir(InputDirectory))) {
if(DirectoryReader->size >= 0){
ReturnValue++;
}
}
fs_close(InputDirectory);


return(ReturnValue);
}