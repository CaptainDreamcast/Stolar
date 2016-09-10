void ComeOutSwinging(AbilityFunctionArguments){

ComeOutSwingingStruct* ComeOutSwingingData;

ComeOutSwingingData = (ComeOutSwingingStruct*)FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].FluxData.Buffer;

if(!ComeOutSwingingData->LogicData.Active){
if(ButtonLegit(WhichButton, FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.ButtonInputData) && FightPlayerAnimationIsIdle(FightData, WhichPlayer)) {
FightPlayerChangeAnimationSimplest(WhichPlayer, OverrideAnimation);

if(FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData.FilledNow <= (FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].FluxData.Abilities[WhichAbility].AbilityData->FilledMax/2)){
FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData.FilledNow = MinimumByteValue;
}
else FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData.FilledNow -= (FightData->OverWorldData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].FluxData.Abilities[WhichAbility].AbilityData->FilledMax/2);

FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SemaphoreDraw++;
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SemaphoreAnimate++;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Intelligence[FightPlayerIntelligenceIdentifierMovement].LogicData.Semaphore++;
ComeOutSwingingData->LogicData.Active = FightLogicSingleActive;
}
}
else{
FightObjectsSingleObjectSingleInstanceDrawOverride(
FightData, WhichObject, WhichInstance, 
ComeOutSwingingData->Texture[FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentFrame], 
ComeOutSwingingData->Loadable->TextureSizeX, ComeOutSwingingData->Loadable->TextureSizeY
);
FightObjectsSingleObjectSingleInstanceAnimateOverride(
FightData, WhichObject, WhichInstance, &ComeOutSwingingData->Loadable->AnimationData
);
}

if(ComeOutSwingingData->LogicData.Active){
if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != OverrideAnimation){

if(FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData.FilledNow == MinimumByteValue){
FightData->CrewData[FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember].AbilityData[WhichAbility].LogicData.Active = LogicActiveNot;
}


ComeOutSwingingData->LogicData.EnemiesHitAlready = NULL;
ComeOutSwingingData->LogicData.BoundEnemyProcessedAmount = LogicActiveNot;
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SemaphoreDraw--;
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SemaphoreAnimate--;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Intelligence[FightPlayerIntelligenceIdentifierMovement].LogicData.Semaphore--;
ComeOutSwingingData->LogicData.Active = FightLogicSingleActiveNot;
}
else{
if(FightCollisionCheckPlayerToEnemyRectangle2D(FightData, FightCollisionCheckPlayerDependent, WhichPlayer, ComeOutSwingingData->FluxData.OffsetData[FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentFrame], &ComeOutSwingingData->Loadable->FightAttackData, &ComeOutSwingingData->LogicData.EnemiesHitAlready)){
ComeOutSwingingAddNewEnemiesToProcessing(FightData, ComeOutSwingingData);
}
}
}

ComeOutSwingingBoundEnemyLogic(FightData, ComeOutSwingingData);


}
