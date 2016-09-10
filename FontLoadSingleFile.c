void FontLoadSingleFile(char* InputFileDir, uint8 WhichFont){

uint32 CurrentPointerPosition;

CompressedFileToBuffer(InputFileDir, (void**)(&FontData[WhichFont].Loadable));

CurrentPointerPosition = ((uint32)FontData[WhichFont].Loadable)+sizeof(FontLoadableStruct);
LoadTextureFromBufferPointer(CurrentPointerPosition, FontData[WhichFont].Texture);

FontData[WhichFont].Loadable = realloc(FontData[WhichFont].Loadable, sizeof(FontLoadableStruct));
}