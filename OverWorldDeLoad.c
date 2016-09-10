void OverWorldDeLoad(OverWorldStruct* OverWorldData, void** TransitionData){

uint8 DirtyDeedsDoneDirtCheap;

PrepareScreenForActiveTextureDeLoad();
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < SpeechBubbleAmountOverall; DirtyDeedsDoneDirtCheap++){
FreeTexture(OverWorldData->TextureData.SpeechBubbleTexture[DirtyDeedsDoneDirtCheap]);
}

(*TransitionData) = OverWorldData->FluxData.General.TransitionData;

//free(OverWorldData->Loadable);

}