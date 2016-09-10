void DogmaScreenDraw(DogmaScreenStruct* DogmaScreenData){

vector_t FinalVector[PolygonCornerAmount];

SceneInitiate(DogmaScreenData->Loadable->StreamingLoadTime, PVR_LIST_TR_POLY);


SetupTransformAndDraw(FinalVector, NULL, DogmaScreenData->TextureData.LogoTexture, 
DogmaScreenData->Loadable->LogoPositionX, DogmaScreenData->Loadable->LogoPositionY, DogmaScreenData->Loadable->LogoPositionZ, 
DogmaScreenData->Loadable->LogoTextureSizeX, DogmaScreenData->Loadable->LogoTextureSizeY, 
DogmaScreenData->Loadable->LogoTextureSizeX, DogmaScreenData->Loadable->LogoTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue);


BlackOutTextureDraw(FinalVector, NULL, DogmaScreenData->TextureData.BlackOutTexture, DogmaScreenData->Loadable->BlackOutPositionZ, 
DogmaScreenData->Loadable->BlackOutTextureSizeX, DogmaScreenData->Loadable->BlackOutTextureSizeY, DogmaScreenData->LogicData.AlphaValueBlackOut);

SceneFinish(PVR_LIST_TR_POLY);



}