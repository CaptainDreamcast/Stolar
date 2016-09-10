void* FightObjectInstanceFluxDataIntelligenceCreateEnemyStateMachineBuffer(){

FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineStruct* Buffer;

Buffer = (FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineStruct*)malloc(sizeof(FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineStruct));
Buffer->LogicData.CurrentState = FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineStandingIdentifier;
Buffer->LogicData.Ticks = NewTicksStandardValue;
Buffer->LogicData.SpeedX = DummyValueFloat;
Buffer->LogicData.SpeedZ = DummyValueFloat;
Buffer->LogicData.EnemiesHitAlready = NULL;

Buffer->Loadable.FightAttackData.ForceX = 10;
Buffer->Loadable.FightAttackData.ForceY = DummyValueFloat;
Buffer->Loadable.FightAttackData.ForceZ = DummyValueFloat;
Buffer->Loadable.FightAttackData.Damage = 10;

Buffer->FluxData.MeleeOffsetData = (FightCollisionDetectRectangleStruct2D*)malloc(sizeof(FightCollisionDetectRectangleStruct2D));
Buffer->FluxData.MeleeOffsetData->TopLeft.PositionX = 79;
Buffer->FluxData.MeleeOffsetData->TopLeft.StagePositionZ = 14;
Buffer->FluxData.MeleeOffsetData->BottomRight.PositionX = 94;
Buffer->FluxData.MeleeOffsetData->BottomRight.StagePositionZ = 57;

return(Buffer);
}