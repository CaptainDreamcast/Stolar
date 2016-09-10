void FightCollisionRegisterAddEnemyToHitAlreadyList(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, ListStruct** EnemiesHitAlready){
ListAdd(EnemiesHitAlready, &FightData->ObjectData[WhichObject].Instance[WhichInstance]);
}