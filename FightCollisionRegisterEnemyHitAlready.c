uint8 FightCollisionRegisterEnemyHitAlready(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, ListStruct* EnemiesHitAlready){
return(ListIncludes(EnemiesHitAlready, &FightData->ObjectData[WhichObject].Instance[WhichInstance]));
}