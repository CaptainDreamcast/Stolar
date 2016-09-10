void BufferToFileRandomAccessMemoryDisk(void* Buffer, uint32 BufferSize, char* FileDir){
fs_ramdisk_attach(FileDir, Buffer, BufferSize);
}