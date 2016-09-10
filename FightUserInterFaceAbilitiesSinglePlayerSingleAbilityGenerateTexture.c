void FightUserInterFaceAbilitiesSinglePlayerSingleAbilityGenerateTexture(FightStruct* FightData, uint8 WhichPlayer, uint8 WhichAbility){

FightCrewAbilityLogicStruct* AbilityLogicData;
OverWorldCrewFluxAbilityLoadableStruct* AbilityLoadableData;

AbilityLoadableData = FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].FluxData.Abilities[WhichAbility].AbilityData;
AbilityLogicData = &FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData;


if(AbilityLogicData->FilledNow != AbilityLogicData->FilledLast){

FightUserInterFaceAbilitiesSinglePlayerSingleAbilityGenerateTextureThresholdToTexture(
FightData->OverWorldData->FluxData.Fight.UserInterFace.Abilities.ThresholdTexture, FightData->PlayerData[WhichPlayer].AbilityData[WhichAbility].TextureData.Gauge, 
((uint8)((MaximumByteValue-1)*(((float)AbilityLogicData->FilledNow)/AbilityLoadableData->FilledMax))), 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeX, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeY
);
}

}