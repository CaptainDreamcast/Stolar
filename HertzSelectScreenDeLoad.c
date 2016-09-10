void HertzSelectScreenDeLoad(HertzSelectScreenStruct* HertzSelectScreenData){

uint8 DirtyDeedsDoneDirtCheap;


pvr_mem_free(HertzSelectScreenData->TextureData.BlackOutTexture);
pvr_mem_free(HertzSelectScreenData->TextureData.BackGroundTexture);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < HertzSelectScreenSelectOptionAmount; DirtyDeedsDoneDirtCheap++){
pvr_mem_free(HertzSelectScreenData->TextureData.SelectScreenOptionTexture[DirtyDeedsDoneDirtCheap]);
pvr_mem_free(HertzSelectScreenData->TextureData.SelectScreenOptionSelectedTexture[DirtyDeedsDoneDirtCheap]);
pvr_mem_free(HertzSelectScreenData->TextureData.SelectScreenOptionDescriptionTexture[DirtyDeedsDoneDirtCheap]);
}
pvr_mem_free(HertzSelectScreenData->TextureData.TestTexture);

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < HertzSelectScreenData->Loadable->TestSecondAmount; DirtyDeedsDoneDirtCheap++){
pvr_mem_free(HertzSelectScreenData->TextureData.TestSecondTexture[DirtyDeedsDoneDirtCheap]);
}
free(HertzSelectScreenData->TextureData.TestSecondTexture);

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < HertzSelectScreenData->Loadable->TestSecondPlusTextureAmount; DirtyDeedsDoneDirtCheap++){
pvr_mem_free(HertzSelectScreenData->TextureData.TestSecondPlusTexture[DirtyDeedsDoneDirtCheap]);
}
free(HertzSelectScreenData->TextureData.TestSecondPlusTexture);


free(HertzSelectScreenData->Loadable);

}