void FightDrawAbilitiesAdaptGaugeColorSingle(FightStruct* FightData, OverWorldStruct* OverWorldData, uint8 WhichAbility, uint8 Red, uint8 Green, uint8 Blue){

float Factor;

if(FightData->LogicData.Abilities.Specific[WhichAbility].Active) Factor = FullColorFloatValue;
else Factor = (((float)FightData->LogicData.Abilities.Specific[WhichAbility].FilledNow)/OverWorldData->FluxData.Abilities[WhichAbility].AbilityData->FilledMax);

Red *= Factor;
Green *= Factor;
Blue *= Factor;

pvr_set_pal_entry(
(((PalettePositionAbilityGaugesOffset+(WhichAbility-1))*PaletteEntryAmountBitsPerPixelAbilityGauges)+FightDrawAbilitiesThresholdToTexturePaletteOffsetOpaque), 
PACK_ARGB1555(LogicActive, Red, Green, Blue));
}