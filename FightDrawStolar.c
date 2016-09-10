#define FightDrawStolarTransformationDataAmount	2
#define FightDrawStolarResetAnimationStolar()	{ \
FightData->LogicData.Stolar.CurrentAnimation = StolarIdleAnimationRight+FightData->LogicData.Stolar.FaceDirection; \
} 

void FightDrawStolar(FightStruct* FightData, OverWorldStruct* OverWorldData){

TransformationStruct TransformationData;

if((FightData->LogicData.General.DrawFlags & FightDrawFlagStolar)){

TransformationData = CombineMultipleTransformationData(FightDrawStolarTransformationDataAmount, &FightData->LogicData.General.TransformationData, &FightData->LogicData.Stolar.TransformationData);
TextureAtlasDrawSimplest((OverWorldData->FluxData.Stolar.AnimationData[FightData->LogicData.Stolar.CurrentAnimation].TextureOffset+FightData->LogicData.Stolar.CurrentFrame),
&TransformationData, 
OverWorldData->TextureData.Stolar, 
FightStolarFetchLeftPositionScreenX(FightData), FightStolarFetchTopPositionScreenY(FightData), 
FightData->LogicData.Stolar.ScreenPositionZ, 
FightData->LogicData.Stolar.SizeX, FightData->LogicData.Stolar.SizeY, 
OverWorldData->Loadable->Stolar.TextureSizeX, OverWorldData->Loadable->Stolar.TextureSizeY, 
OverWorldData->Loadable->Stolar.SingleTextureSizeX, OverWorldData->Loadable->Stolar.SingleTextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY);
}


if((FightData->LogicData.General.AnimationFlags & FightAnimationFlagStolar)){
AnimateWithAnimationFactor(FightData->LogicData.Stolar.Ticks, 
OverWorldData->FluxData.Stolar.AnimationData[FightData->LogicData.Stolar.CurrentAnimation].AnimationDurationInSeconds, 
FightData->LogicData.Stolar.AnimationFactor, 
FightData->LogicData.Stolar.CurrentFrame, 
OverWorldData->FluxData.Stolar.AnimationData[FightData->LogicData.Stolar.CurrentAnimation].FrameAmount, 
{
FightDrawStolarResetAnimationStolar();
}
);
}


}