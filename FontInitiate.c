void FontInitiate(){

char FileDir[NormalFileDirSize];
uint8 ManipulationPosition;
uint8 DirtyDeedsDoneDirtCheap;
uint8 FontAmount;

sprintf(FileDir, "%s/FONTS", FileSystemUsed);
FontAmount = CountFilesInDirectory(FileDir);

FontData = (FontStruct*)malloc(sizeof(FontStruct)*FontAmount);

ManipulationPosition = sprintf(FileDir, "%s/", FileDir);
sprintf((char*)(FileDir+ManipulationPosition+1), ".fnt.gz");
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < FontAmount; DirtyDeedsDoneDirtCheap++){
FileDir[ManipulationPosition] = (char)(DirtyDeedsDoneDirtCheap+HexNumberValueOffset);
FontLoadSingleFile(FileDir, DirtyDeedsDoneDirtCheap);
}


}