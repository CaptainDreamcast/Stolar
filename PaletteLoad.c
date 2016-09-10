#define MaximumFiveBitValue		0x1F

#define EightToFiveBits(Value)		(((Value*MaximumFiveBitValue)/MaximumByteValue)&MaximumFiveBitValue)

#define FiveBitPositionAlpha		15
#define FiveBitPositionRed		10
#define FiveBitPositionGreen		5
#define FiveBitPositionBlue		0

#define PACK_ARGB1555(Alpha, Red, Green, Blue)	((Alpha << FiveBitPositionAlpha) | (EightToFiveBits(Red) << FiveBitPositionRed) | (EightToFiveBits(Green) << FiveBitPositionGreen) | (EightToFiveBits(Blue)))

#define PaletteLoadFromFileFour(FileDir, PalettePosition)	PaletteLoadFromFile(FileDir, PalettePosition, PaletteBitsPerPixelFour)
#define PaletteLoadFromFileEight(FileDir, PalettePosition)	PaletteLoadFromFile(FileDir, PalettePosition, PaletteBitsPerPixelEight)
void PaletteLoadFromFile(char* FileDir, uint16 PalettePosition, uint8 BitsPerPixel){

void* Buffer;
uint32 CurrentPalettePosition, BailOutValue;
uint16 EntryAmount;

PaletteSingleValueStruct* SingleValueData;

if(BitsPerPixel == PaletteBitsPerPixelFour){
EntryAmount = PaletteEntryAmountBitsPerPixelFour;
}
else{
EntryAmount = PaletteEntryAmountBitsPerPixelEight;
}

FileToBuffer(FileDir, &Buffer);

pvr_set_pal_entry((PalettePosition*EntryAmount), PACK_ARGB1555(LogicActiveNot, 0,0,0));
SingleValueData = (PaletteSingleValueStruct*)(((uint32)Buffer)+sizeof(PaletteSingleValueStruct));
BailOutValue = ((PalettePosition+1)*EntryAmount);
for(CurrentPalettePosition = (PalettePosition*EntryAmount)+1; CurrentPalettePosition < BailOutValue; CurrentPalettePosition++){
pvr_set_pal_entry(CurrentPalettePosition, PACK_ARGB1555(LogicActive, SingleValueData->Red,SingleValueData->Green, SingleValueData->Blue));
SingleValueData++;
}

free(Buffer);
}