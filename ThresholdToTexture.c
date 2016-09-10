void ThresholdToTexture(void* ThresholdTexture, pvr_ptr_t FinalTexture, uint8 Threshold, uint16 Length, uint8 Red, uint8 Green, uint8 Blue){

uint8 DirtyDeedsDoneDirtCheap;

uint16* InputPointer;
uint32* OutputPointer;

InputPointer = (uint16*) ThresholdTexture;
OutputPointer = (uint32*) FinalTexture;

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<Length;DirtyDeedsDoneDirtCheap+=2){

if(InputPointer[DirtyDeedsDoneDirtCheap] > Threshold) OutputPointer[DirtyDeedsDoneDirtCheap/2] = ((Red << 16) | (Green << 8) | Blue);
else OutputPointer[DirtyDeedsDoneDirtCheap/2] = 0;
}

}
