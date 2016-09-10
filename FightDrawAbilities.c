#define FightDrawAbilitiesTransformationDataAmount		2

#define FightDrawAbilitiesDrawSingleAbility(WhichAbility, Red, Green, Blue)		{ \
 \
FightDrawAbilitiesAdaptGaugeColorSingle(FightData, OverWorldData, WhichAbility, Red, Green, Blue); \
FightDrawAbilitiesThresholdToTexture(OverWorldData->FluxData.Fight.UserInterFace.Abilities.ThresholdTexture, \
OverWorldData->TextureData.Fight.UserInterFace.Abilities.FinalBarTexture[WhichAbility], \
((uint8)((MaximumByteValue-1)*((float)FightData->LogicData.Abilities.Specific[WhichAbility].FilledNow/OverWorldData->FluxData.Abilities[WhichAbility].AbilityData->FilledMax))), \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeX, \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeY); \
 \
SetupTransformAndDrawSimplest(FinalVector, &TransformationData, OverWorldData->TextureData.Fight.UserInterFace.Abilities.FinalBarTexture[WhichAbility], \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Gauge.PositionX, \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Gauge.PositionY, \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.ScreenPositionZ, \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeX, OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeY, \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeX, OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeY, \
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL((PalettePositionAbilityGaugesOffset+(WhichAbility-1)))), PVR_LIST_TR_POLY); \
 \
}

/*
TextureAtlasDrawSimplest( \
OverWorldData->FluxData.Abilities[WhichAbility].AbilityData->TextureAtlasIndex, &TransformationData, OverWorldData->TextureData.Abilities, \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Ability.PositionX, \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Ability.PositionY, \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Ability.ScreenPositionZ, \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Ability.SizeX, OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Ability.SizeY, \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Ability.TextureSizeX, OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Ability.TextureSizeY, \
OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Ability.SingleTextureSizeX, OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Ability.SingleTextureSizeY, \
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY); \
*/


void FightDrawAbilities(FightStruct* FightData, OverWorldStruct* OverWorldData){

TransformationStruct TransformationData;
vector_t FinalVector[PolygonCornerAmount];

TransformationData = CombineMultipleTransformationData(FightDrawAbilitiesTransformationDataAmount, &FightData->LogicData.General.TransformationData, &FightData->LogicData.UserInterFace.TransformationData);

FightDrawAbilitiesDrawSingleAbility(YellowAbility, MaximumByteValue, MaximumByteValue, MinimumByteValue);
FightDrawAbilitiesDrawSingleAbility(GreenAbility, MinimumByteValue, MaximumByteValue, MinimumByteValue);
FightDrawAbilitiesDrawSingleAbility(BlueAbility, MinimumByteValue, MinimumByteValue, MaximumByteValue);

}
