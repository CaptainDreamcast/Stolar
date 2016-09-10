void FightUserInterFaceAbilitiesSinglePlayer(FightStruct* FightData, uint8 WhichPlayer){

uint8 WhichAbility;

for(WhichAbility = (AbilityRed+1); WhichAbility < AbilityAmount; WhichAbility++){
FightUserInterFaceAbilitiesSinglePlayerSingleAbility(FightData, WhichPlayer, WhichAbility);
}


}