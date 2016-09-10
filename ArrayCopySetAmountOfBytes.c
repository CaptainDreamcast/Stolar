void ArrayCopySetAmountOfBytes(char* DestinationArray, char* SourceArray, uint32 ByteAmount){

for(CopyCounter = 0; CopyCounter < ByteAmount; CopyCounter++){
DestinationArray[CopyCounter] = SourceArray[CopyCounter];
}


}