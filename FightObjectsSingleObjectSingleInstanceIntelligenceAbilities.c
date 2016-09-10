void FightObjectsSingleObjectSingleInstanceIntelligenceAbilities(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichIntelligence){

uint8 WhichPlayer;

WhichPlayer = FightPlayerGetWhichPlayerFromObjectAndInstance(FightData, WhichObject, WhichInstance);

(*AbilityFunction[FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].FluxData.Abilities[RedAbility].AbilityData->FunctionIndex])(FightData, WhichObject, WhichInstance, WhichPlayer, RedAbility, ButtonA, CONT_A);

if(FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[BlueAbility].LogicData.Active){
(*AbilityFunction[FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].FluxData.Abilities[BlueAbility].AbilityData->FunctionIndex])(FightData, WhichObject, WhichInstance, WhichPlayer, BlueAbility, ButtonB, CONT_B);
}

if(FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[YellowAbility].LogicData.Active){
(*AbilityFunction[FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].FluxData.Abilities[YellowAbility].AbilityData->FunctionIndex])(FightData, WhichObject, WhichInstance, WhichPlayer, YellowAbility, ButtonX, CONT_X);
}

if(FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[GreenAbility].LogicData.Active){
(*AbilityFunction[FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].FluxData.Abilities[GreenAbility].AbilityData->FunctionIndex])(FightData, WhichObject, WhichInstance, WhichPlayer, GreenAbility, ButtonY, CONT_Y);
}

}