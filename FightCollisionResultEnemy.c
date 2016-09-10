uint8 FightCollisionResultEnemyStandard(FightStruct* FightData, OverWorldStruct* OverWorldData, uint8 WhichEnemy){

uint16 FinalDamage;
uint8 Hit;

FinalDamage = FightCollisionResultDecreaseLife(FightData->EnemyData[WhichEnemy].FluxData.FightAttackedData, &FightData->EnemyData[WhichEnemy].Loadable->FightDefenseData, &FightData->EnemyData[WhichEnemy].LogicData.Health);

ListAdd(&FightData->FloatingValueData, FightFloatingValueNew(FightData, OverWorldData, FinalDamage, FightEnemyFetchCenterPositionX(FightData, WhichEnemy), FightEnemyFetchTopPositionY(FightData, WhichEnemy), FightData->EnemyData[WhichEnemy].LogicData.ScreenPositionZ));
Hit = FightCollisionResultMoved(FightData->EnemyData[WhichEnemy].FluxData.FightAttackedData, &FightData->EnemyData[WhichEnemy].Loadable->FightDefenseData, FinalDamage, &FightData->EnemyData[WhichEnemy].LogicData.VelocityX, &FightData->EnemyData[WhichEnemy].LogicData.VelocityY);

return(Hit);
}