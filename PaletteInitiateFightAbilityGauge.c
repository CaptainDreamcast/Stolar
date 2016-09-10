void PaletteInitiateFightAbilityGauge(uint8 WhichAbility){

pvr_set_pal_entry(
(((PalettePositionAbilityGaugesOffset+(WhichAbility-1))*PaletteEntryAmountBitsPerPixelAbilityGauges)+FightDrawAbilitiesThresholdToTexturePaletteOffsetTransparent), 
PACK_ARGB1555(LogicActiveNot, MinimumByteValue, MinimumByteValue, MinimumByteValue)
);
pvr_set_pal_entry(
(((PalettePositionAbilityGaugesOffset+(WhichAbility-1))*PaletteEntryAmountBitsPerPixelAbilityGauges)+FightDrawAbilitiesThresholdToTexturePaletteOffsetOpaque), 
PACK_ARGB1555(LogicActive, MinimumByteValue, MinimumByteValue, MinimumByteValue)
);

}