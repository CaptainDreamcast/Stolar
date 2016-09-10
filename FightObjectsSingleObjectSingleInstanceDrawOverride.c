void FightObjectsSingleObjectSingleInstanceDrawOverride(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, pvr_ptr_t WhichTexture, uint16 TextureSizeX, uint16 TextureSizeY){

TransformationStruct PersonalTransformationData;

PersonalTransformationData = CombineMultipleTransformationData(FightDrawTransformationDataPersonalAmount, &FightData->ObjectData[WhichObject].ClassData->LogicData.GeneralTransformationData, &FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.TransformationData);

TextureAtlasDrawWithReverseSimplest(
TextureAtlasDrawSingleEntry, 
&PersonalTransformationData, 
WhichTexture, 
FightObjectFetchLeftPositionScreenX(FightData, WhichObject, WhichInstance), 
FightObjectFetchTopPositionScreenY(FightData, WhichObject, WhichInstance), 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->ScreenPositionZ, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeX, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeY, 
TextureSizeX, TextureSizeY, 
TextureSizeX, TextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection
);

}