void TitleScreenDeLoad(TitleScreenStruct* TitleScreenData){

PrepareScreenForActiveTextureDeLoad();
FreeTexture(TitleScreenData->TextureData.BlackOutTexture);
FreeTexture(TitleScreenData->TextureData.BackGroundTexture);
FreeTexture(TitleScreenData->TextureData.PressStartTexture);

//FreeSoundEffect(TitleScreenData->SoundEffectData.?);

free(TitleScreenData->Loadable);

}