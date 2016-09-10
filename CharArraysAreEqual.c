uint8 CharArraysAreEqual(char* InputFileDir, char* OutputFileDir){

uint8 DirtyDeedsDoneDirtCheap;
uint8 ReturnValue;

ReturnValue = 1;
for(DirtyDeedsDoneDirtCheap=0; (InputFileDir[DirtyDeedsDoneDirtCheap] != '\0' && ReturnValue); DirtyDeedsDoneDirtCheap++){
if(OutputFileDir == '\0' || InputFileDir[DirtyDeedsDoneDirtCheap] != OutputFileDir[DirtyDeedsDoneDirtCheap]) ReturnValue = 0;
}
if(OutputFileDir != '\0') ReturnValue = 0;

return(ReturnValue);
}
