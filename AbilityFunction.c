#define FightAbilityHittable	1

void VulgarDisplayOfPower(AbilityFunctionArguments){

VulgarDisplayOfPowerStruct* VulgarDisplayOfPowerData;

VulgarDisplayOfPowerData = (VulgarDisplayOfPowerStruct*)FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].FluxData.Buffer;

if(!VulgarDisplayOfPowerData->LogicData.Active){
if(ButtonLegit(ButtonA, FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.ButtonInputData) && FightPlayerAnimationIsIdle(FightData, WhichPlayer)) {
FightPlayerChangeAnimationSimplest(WhichPlayer, VulgarDisplayOfPowerData->Loadable->AnimationIdentifier);
FightData->ObjectData[WhichObject].Instance[WhichInstance].Intelligence[FightPlayerIntelligenceIdentifierMovement].LogicData.Semaphore++;
VulgarDisplayOfPowerData->LogicData.Active = FightLogicSingleActive;
}
}

if(VulgarDisplayOfPowerData->LogicData.Active){
if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != VulgarDisplayOfPowerData->Loadable->AnimationIdentifier){
VulgarDisplayOfPowerData->LogicData.EnemiesHitAlready = NULL;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Intelligence[FightPlayerIntelligenceIdentifierMovement].LogicData.Semaphore--;
VulgarDisplayOfPowerData->LogicData.Active = FightLogicSingleActiveNot;
}
else{
FightCollisionCheckPlayerToEnemyRectangle2D(FightData, FightCollisionCheckPlayerDependent, WhichPlayer, VulgarDisplayOfPowerData->FluxData.OffsetData[FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentFrame], &VulgarDisplayOfPowerData->Loadable->FightAttackData, &VulgarDisplayOfPowerData->LogicData.EnemiesHitAlready);
}
}

}

#define VulgarDisplayOfPowerIdentifier	0
#define ComeOutSwingingIdentifier		1
void (*AbilityFunction[AbilityFunctionAmount])(AbilityFunctionArguments) = 
{
VulgarDisplayOfPower, ComeOutSwinging
};
