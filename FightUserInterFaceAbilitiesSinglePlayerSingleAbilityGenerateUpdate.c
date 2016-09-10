void FightUserInterFaceAbilitiesSinglePlayerSingleAbilityGenerateUpdate(FightStruct* FightData, uint8 WhichPlayer, uint8 WhichAbility){

FightCrewAbilityLogicStruct* AbilityLogicData;

AbilityLogicData = &FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData;

AbilityLogicData->ActiveLast = AbilityLogicData->Active;
AbilityLogicData->FilledLast = AbilityLogicData->FilledNow;

}