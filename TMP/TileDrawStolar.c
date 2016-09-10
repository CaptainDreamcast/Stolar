#define TileDrawStolarTransformationDataAmount	2
#define TileDrawStolarResetAnimationStolar()	{ \
TileData->LogicData.Stolar.CurrentAnimation = StolarIdleAnimationRight+TileData->LogicData.Stolar.FaceDirection; \
} 

void TileDrawStolar(TileStruct* TileData, OverWorldStruct* OverWorldData){

TransformationStruct TransformationData;

if((TileData->LogicData.General.DrawFlags & TileDrawFlagStolar)){

TransformationData = CombineMultipleTransformationData(TileDrawStolarTransformationDataAmount, &TileData->LogicData.General.TransformationData, &TileData->LogicData.Stolar.TransformationData);
TextureAtlasDrawSimplest((OverWorldData->FluxData.Stolar.AnimationData[TileData->LogicData.Stolar.CurrentAnimation].TextureOffset+TileData->LogicData.Stolar.CurrentFrame),
&TransformationData, 
OverWorldData->TextureData.Stolar, 
TileStolarFetchTopLeftPositionScreenX(TileData), TileStolarFetchTopLeftPositionScreenY(TileData), 
TileData->LogicData.Stolar.ScreenPositionZ, 
TileData->LogicData.Stolar.SizeX, TileData->LogicData.Stolar.SizeY, 
OverWorldData->Loadable->Stolar.TextureSizeX, OverWorldData->Loadable->Stolar.TextureSizeY, 
OverWorldData->Loadable->Stolar.SingleTextureSizeX, OverWorldData->Loadable->Stolar.SingleTextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY);
}


if((TileData->LogicData.General.AnimationFlags & TileAnimationFlagStolar)){
AnimateWithAnimationFactor(TileData->LogicData.Stolar.Ticks, 
OverWorldData->FluxData.Stolar.AnimationData[TileData->LogicData.Stolar.CurrentAnimation].AnimationDurationInSeconds, 
TileData->LogicData.Stolar.AnimationFactor, 
TileData->LogicData.Stolar.CurrentFrame, 
OverWorldData->FluxData.Stolar.AnimationData[TileData->LogicData.Stolar.CurrentAnimation].FrameAmount, 
{
TileDrawStolarResetAnimationStolar();
}
);
}


}