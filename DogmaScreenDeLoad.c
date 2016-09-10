void DogmaScreenDeLoad(DogmaScreenStruct* DogmaScreenData){

PrepareScreenForActiveTextureDeLoad()
FreeTexture(DogmaScreenData->TextureData.LogoTexture);
FreeTexture(DogmaScreenData->TextureData.BlackOutTexture);

free(DogmaScreenData->Loadable);

}