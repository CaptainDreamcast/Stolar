void FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineWalkWithBias(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineStruct* StateMachineData){
uint8 MovementActive;

MovementActive = LogicActiveNot;

if(FightMovementX(FightData, WhichObject, WhichInstance, StateMachineData->LogicData.SpeedX)){
MovementActive = LogicActive;
}
if(StateMachineData->LogicData.SpeedX > 0) FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection = FightFaceRight;
else if(StateMachineData->LogicData.SpeedX < 0) FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection = FightFaceLeft;

if(
FightMovementZ(FightData, WhichObject, WhichInstance, StateMachineData->LogicData.SpeedZ)
){
MovementActive = LogicActive;
}


if(MovementActive){
if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != EnemyRunningAnimation){
FightObjectChangeAnimationSimplest(FightData->ObjectData[WhichObject].Instance[WhichInstance], EnemyRunningAnimation); 
} 
}
else if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation == EnemyRunningAnimation){
FightObjectChangeAnimationSimplest(FightData->ObjectData[WhichObject].Instance[WhichInstance], EnemyIdleAnimation); 
}


}