
void FightLoadObjectInstanceCreateLoadablePlayer(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichCrewMember){

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable = (FightObjectInstanceLoadableStruct*)malloc(sizeof(FightObjectInstanceLoadableStruct));

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->IntelligenceAmount = FightPlayerIntelligenceAmount;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection = FightData->Loadable.Given->PlayerFaceDirection;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentFrame = NewFrameStandardValue;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->OnGround = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->Fight.OnGround;

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation = PlayerIdleAnimation;

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX = FightData->Loadable.Given->PlayerPositionX;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ = FightData->Loadable.Given->PlayerStagePositionZ;

FightStagePositionParseZ(
FightData, FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ, 
&FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->ScreenPositionZ, 
&FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionY
);

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeX = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->General.SizeX*FightData->Loadable.Stage->General.SizeFactor;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeY = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->General.SizeY*FightData->Loadable.Stage->General.SizeFactor;

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->AnimationFactor = AnimationFactorStandard;

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->Physics = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->Fight.Physics;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->Fight.HitOffset;

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->Blockage.Type = FightObjectsSingleObjectSingleInstanceBlockageFunctionNoneIdentifier;
}

void FightLoadObjectInstanceCreateLoadableCrew(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichCrewMember){
printf("FightLoadObjectInstanceCreateLoadableCrew called!\n");
}


uint32 FightLoadObjectInstanceCreateLoadableEnemy(FightStruct* FightData, FightEnemyGivenStruct* FightEnemyGivenData, uint32 CurrentPointerPosition, uint8 WhichObject, uint8 WhichInstance, uint8 WhichEnemy){

FightEnemyLoadableStruct* Loadable;

LoadSetThisToThatPointer(FightEnemyLoadableStruct*, Loadable, sizeof(FightEnemyLoadableStruct));

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable = (FightObjectInstanceLoadableStruct*)malloc(sizeof(FightObjectInstanceLoadableStruct));

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->IntelligenceAmount = FightEnemyIntelligenceAmount;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection = FightEnemyGivenData[WhichEnemy].FaceDirection;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentFrame = NewFrameStandardValue;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->OnGround = Loadable->OnGround;

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation = PlayerIdleAnimation;

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX = FightEnemyGivenData[WhichEnemy].PositionX;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ = FightEnemyGivenData[WhichEnemy].StagePositionZ;

FightStagePositionParseZ(
FightData, FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ, 
&FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->ScreenPositionZ, 
&FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionY
);

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeX = Loadable->SizeX*FightEnemyGivenData[WhichEnemy].SizeFactor;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeY = Loadable->SizeY*FightEnemyGivenData[WhichEnemy].SizeFactor;

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->AnimationFactor = AnimationFactorStandard;

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->Physics = Loadable->Physics;
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset = Loadable->HitOffset;

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->Blockage.Type = FightObjectsSingleObjectSingleInstanceBlockageFunctionNoneIdentifier;

return(CurrentPointerPosition);
}
