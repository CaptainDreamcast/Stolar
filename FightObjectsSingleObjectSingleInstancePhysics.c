void FightObjectsSingleObjectSingleInstancePhysics(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){
(*FightObjectsSingleObjectSingleInstancePhysicsFunction[FightData->ObjectData[WhichObject].Loadable->PhysicsType])(FightData, WhichObject, WhichInstance);
}