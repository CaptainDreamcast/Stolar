void TitleScreenDraw(TitleScreenStruct* TitleScreenData){

vector_t FinalVector[PolygonCornerAmount];

SceneInitiate(TitleScreenData->Loadable->StreamingLoadTime, PVR_LIST_TR_POLY);

SetupTransformAndDraw(FinalVector, NULL, TitleScreenData->TextureData.BlackOutTexture, 
OverallScreenPositionLeft, OverallScreenPositionUp, TitleScreenData->Loadable->BlackOutPositionZ, 
ScreenSizeX, ScreenSizeY, 
TitleScreenData->Loadable->BlackOutTextureSizeX, TitleScreenData->Loadable->BlackOutTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, TitleScreenData->LogicData.AlphaValueBlackOut, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue);

SetupTransformAndDrawSimplest(FinalVector, &TitleScreenData->LogicData.TransformationDataZoomOut, TitleScreenData->TextureData.BackGroundTexture, 
TitleScreenData->Loadable->BackGroundPositionX, TitleScreenData->Loadable->BackGroundPositionY, TitleScreenData->Loadable->BackGroundPositionZ, 
TitleScreenData->Loadable->BackGroundTextureSizeX, TitleScreenData->Loadable->BackGroundTextureSizeY, 
TitleScreenData->Loadable->BackGroundTextureSizeX, TitleScreenData->Loadable->BackGroundTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

SetupTransformAndDrawSimplest(FinalVector, &TitleScreenData->LogicData.TransformationDataZoomOut, TitleScreenData->TextureData.PressStartTexture, 
TitleScreenData->Loadable->PressStartPositionX, TitleScreenData->Loadable->PressStartPositionY, TitleScreenData->Loadable->PressStartPositionZ, 
TitleScreenData->Loadable->PressStartTextureSizeX, TitleScreenData->Loadable->PressStartTextureSizeY, 
TitleScreenData->Loadable->PressStartTextureSizeX, TitleScreenData->Loadable->PressStartTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

SceneFinish(PVR_LIST_TR_POLY);

}