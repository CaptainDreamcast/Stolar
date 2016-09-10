void RedSpotScreenDeLoad(RedSpotScreenStruct* RedSpotScreenData){

PrepareScreenForActiveTextureDeLoad();
FreeTexture(RedSpotScreenData->TextureData.BlackOutTexture);
FreeTexture(RedSpotScreenData->TextureData.RedSpotTexture);
FreeTexture(RedSpotScreenData->TextureData.BackGroundTexture);
FreeTexture(RedSpotScreenData->TextureData.EffectTexture);

FreeSoundEffect(RedSpotScreenData->SoundEffectData.RedSpotGamesSoundEffect);


free(RedSpotScreenData->Loadable);

}