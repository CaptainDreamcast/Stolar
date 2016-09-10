void FightUserInterFaceAbilitiesSinglePlayerSingleAbilityGenerateColor(FightStruct* FightData, uint8 WhichPlayer, uint8 WhichAbility){

float Factor;
uint8 Red, Green, Blue;

FightCrewAbilityLogicStruct* AbilityLogicData;
OverWorldCrewFluxAbilityLoadableStruct* AbilityLoadableData;

AbilityLoadableData = FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].FluxData.Abilities[WhichAbility].AbilityData;
AbilityLogicData = &FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData;

if((!AbilityLogicData->Active && AbilityLogicData->FilledNow != AbilityLogicData->FilledLast) || AbilityLogicData->Active != AbilityLogicData->ActiveLast){

if(AbilityLogicData->Active) Factor = FullColorFloatValue;
else Factor = (((float)AbilityLogicData->FilledNow)/AbilityLoadableData->FilledMax);

Red = AbilityLogicData->Red * Factor;
Green = AbilityLogicData->Green * Factor;
Blue = AbilityLogicData->Blue * Factor;

pvr_set_pal_entry(
(((PalettePositionAbilityGaugesOffset+(WhichAbility-1))*PaletteEntryAmountBitsPerPixelAbilityGauges)+FightDrawAbilitiesThresholdToTexturePaletteOffsetOpaque), 
PACK_ARGB1555(LogicActive, Red, Green, Blue));

}

}