void FightObjectsSingleObjectSingleInstanceDraw(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

TransformationStruct PersonalTransformationData;
uint8 WhichEntry, WhichTexture;

if(!FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SemaphoreDraw && FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeX != 0.0f && FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeY != 0.0f){
PersonalTransformationData = CombineMultipleTransformationData(FightDrawTransformationDataPersonalAmount, &FightData->ObjectData[WhichObject].ClassData->LogicData.GeneralTransformationData, &FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.TransformationData);

WhichEntry = (FightData->ObjectData[WhichObject].FluxData.AnimationData[FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation].TextureOffset+FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentFrame);
WhichTexture = (WhichEntry/((FightData->ObjectData[WhichObject].Loadable->TextureSizeX/FightData->ObjectData[WhichObject].Loadable->SingleTextureSizeX)*(FightData->ObjectData[WhichObject].Loadable->TextureSizeY/FightData->ObjectData[WhichObject].Loadable->SingleTextureSizeY)));
TextureAtlasDrawWithReverseSimplest(
WhichEntry, 
&PersonalTransformationData, 
FightData->ObjectData[WhichObject].Texture[WhichTexture], 
FightObjectFetchLeftPositionScreenX(FightData, WhichObject, WhichInstance), 
FightObjectFetchTopPositionScreenY(FightData, WhichObject, WhichInstance), 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->ScreenPositionZ, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeX, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeY, 
FightData->ObjectData[WhichObject].Loadable->TextureSizeX, FightData->ObjectData[WhichObject].Loadable->TextureSizeY, 
FightData->ObjectData[WhichObject].Loadable->SingleTextureSizeX, FightData->ObjectData[WhichObject].Loadable->SingleTextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection
);
}

}