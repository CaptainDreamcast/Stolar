void FightCollisionCheckPlayerIncreaseAbilities(FightStruct* FightData, uint8 WhichPlayer, FightAttackStruct* FightAttackData){

uint8 WhichAbility;

for(WhichAbility = (AbilityRed+1); WhichAbility < AbilityAmount; WhichAbility++){
if(SaveData.CompressableData->CrewMemberAbility[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember][WhichAbility] != NoAbilityIdentifier){
FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData.FilledNow += FightAttackData->Damage;
}
if(FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData.FilledNow > FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].FluxData.Abilities[WhichAbility].AbilityData->FilledMax){
FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData.FilledNow = FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].FluxData.Abilities[WhichAbility].AbilityData->FilledMax;
FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData.Active = LogicActive;
}
}

}