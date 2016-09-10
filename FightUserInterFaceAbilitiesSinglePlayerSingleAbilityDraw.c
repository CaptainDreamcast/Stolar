#define FightUserInterFaceAbilitiesTransformationDataAmount	2
#define FightUserInterFaceAbilitiesSinglePlayerSingleAbilityDrawBlackOutInActive	0.5f

void FightUserInterFaceAbilitiesSinglePlayerSingleAbilityDraw(FightStruct* FightData, uint8 WhichPlayer, uint8 WhichAbility){

vector_t FinalVector[PolygonCornerAmount];
TransformationStruct TransformationData;
OverWorldCrewFluxAbilityStruct* AbilityData;
float AbilityBlackOutFactor;


AbilityData = &FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].FluxData.Abilities[WhichAbility];

if(FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData.Active) AbilityBlackOutFactor = FullColorFloatValue;
else AbilityBlackOutFactor = FightUserInterFaceAbilitiesSinglePlayerSingleAbilityDrawBlackOutInActive;

TransformationData = CombineMultipleTransformationData(FightUserInterFaceAbilitiesTransformationDataAmount, &FightData->LogicData.General.TransformationData, &FightData->LogicData.UserInterFace.TransformationData);
SetupTransformAndDrawSimplest(FinalVector, &TransformationData, FightData->PlayerData[WhichPlayer].AbilityData[WhichAbility].TextureData.Gauge, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Gauge.PositionX, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Gauge.PositionY, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.ScreenPositionZ, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeY, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeY, 
(PVR_TXRFMT_PAL4BPP | PVR_TXRFMT_4BPP_PAL((PalettePositionAbilityGaugesOffset+(WhichAbility-1)))), PVR_LIST_TR_POLY); 
 
SetupTransformAndDrawSimplest(FinalVector, &TransformationData, FightData->OverWorldData->TextureData.Fight.UserInterFace.AbilityBackGround, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].BackGround.PositionX, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].BackGround.PositionY, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.BackGround.ScreenPositionZ, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.BackGround.TextureSizeX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.BackGround.TextureSizeY, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.BackGround.TextureSizeX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.BackGround.TextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY); 

TextureAtlasDraw( 
AbilityData->AbilityData->TextureAtlasIndex, &TransformationData, FightData->OverWorldData->TextureData.Abilities, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Ability.PositionX,
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Ability.PositionY, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Ability.ScreenPositionZ, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Ability.SizeX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.Specific[WhichAbility].Ability.SizeY, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Ability.TextureSizeX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Ability.TextureSizeY, 
FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Ability.SingleTextureSizeX, FightData->OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Ability.SingleTextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY, 
FullColorFloatValue, AbilityBlackOutFactor, AbilityBlackOutFactor, AbilityBlackOutFactor); 

}