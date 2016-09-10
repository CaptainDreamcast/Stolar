void RedSpotScreenDraw(RedSpotScreenStruct* RedSpotScreenData){

vector_t FinalVector[PolygonCornerAmount];

SceneInitiate(RedSpotScreenData->Loadable->StreamingLoadTime, PVR_LIST_TR_POLY);

BlackOutTextureDraw(FinalVector, NULL, RedSpotScreenData->TextureData.BlackOutTexture, RedSpotScreenData->Loadable->BlackOutPositionZ, 
RedSpotScreenData->Loadable->BlackOutTextureSizeX, RedSpotScreenData->Loadable->BlackOutTextureSizeY, RedSpotScreenData->LogicData.AlphaValueBlackOut);

if(RedSpotScreenData->LogicData.CurrentStage < RedSpotScreenStageBackGround){

RedSpotScreenDrawMovingLetters(RedSpotScreenData);

SetupTransformAndDrawSimplest(FinalVector, &RedSpotScreenData->LogicData.TransformationDataRedSpot, RedSpotScreenData->TextureData.RedSpotTexture, 
RedSpotScreenData->Loadable->RedSpotPositionX, RedSpotScreenData->Loadable->RedSpotPositionY, RedSpotScreenData->Loadable->RedSpotPositionZ, 
RedSpotScreenData->Loadable->RedSpotStartSizeX, RedSpotScreenData->Loadable->RedSpotStartSizeY, 
RedSpotScreenData->Loadable->RedSpotTextureSizeX, RedSpotScreenData->Loadable->RedSpotTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

}

if(RedSpotScreenData->LogicData.CurrentStage >= RedSpotScreenStageBackGroundFadeIn){
SetupTransformAndDraw(FinalVector, NULL, RedSpotScreenData->TextureData.BackGroundTexture, 
RedSpotScreenData->Loadable->BackGroundPositionX, RedSpotScreenData->Loadable->BackGroundPositionY, RedSpotScreenData->Loadable->BackGroundPositionZ, 
RedSpotScreenData->Loadable->BackGroundTextureSizeX, RedSpotScreenData->Loadable->BackGroundTextureSizeY, 
RedSpotScreenData->Loadable->BackGroundTextureSizeX, RedSpotScreenData->Loadable->BackGroundTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, RedSpotScreenData->LogicData.AlphaValueBackGround, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue);

if(RedSpotScreenData->LogicData.CurrentStage == RedSpotScreenStageEffect){
SetupTransformAndDraw(FinalVector, NULL, RedSpotScreenData->TextureData.EffectTexture, 
RedSpotScreenData->LogicData.EffectPositionX, RedSpotScreenData->Loadable->EffectPositionY, RedSpotScreenData->Loadable->EffectPositionZ, 
RedSpotScreenData->Loadable->EffectTextureSizeX, RedSpotScreenData->Loadable->EffectTextureSizeY, 
RedSpotScreenData->Loadable->EffectTextureSizeX, RedSpotScreenData->Loadable->EffectTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, RedSpotScreenData->LogicData.AlphaValueEffect, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue);
}
}

SceneFinish(PVR_LIST_TR_POLY);

}