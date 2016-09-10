#define EnemyIdle	(1/0)


void FightArtificialIntelligencePhysicsStandard(FightStruct* FightData, OverWorldStruct* OverWorldData, uint8 WhichEnemy){

if(FightData->EnemyData[WhichEnemy].LogicData.VelocityActiveY){
if(FightVelocityNoLongerInMotionY(FightData->EnemyData[WhichEnemy].LogicData.PositionY, FightData->EnemyData[WhichEnemy].LogicData.VelocityY, FightData->EnemyData[WhichEnemy].Given->StagePositionZ)){
FightVelocityLogicDeActivateY(FightData->EnemyData[WhichEnemy].LogicData.VelocityActiveY, FightData->EnemyData[WhichEnemy].LogicData.VelocityY);
}
else{

FightVelocityPhysicsLogicStandardY(FightData->EnemyData[WhichEnemy].LogicData.PositionY, FightData->EnemyData[WhichEnemy].LogicData.VelocityY, FightData->EnemyData[WhichEnemy].Loadable->WeightFactorComparedToStolarY);
FightVelocityHitLogicStandardY(FightData->EnemyData[WhichEnemy].LogicData.Hit, FightData->EnemyData[WhichEnemy].LogicData, FightData->EnemyData[WhichEnemy].FluxData.AnimationData, FightData->EnemyData[WhichEnemy].Loadable->AnimationHitAir, FightEnemyIdle(WhichEnemy));
}
}


if(FightData->EnemyData[WhichEnemy].LogicData.VelocityActiveX){
if(FightVelocityNoLongerInMotionX(FightData->EnemyData[WhichEnemy].LogicData.VelocityX, FightData->EnemyData[WhichEnemy].Loadable->WeightFactorComparedToStolarX)){
FightVelocityLogicDeActivateX(FightData->EnemyData[WhichEnemy].LogicData.VelocityActiveX, FightData->EnemyData[WhichEnemy].LogicData.VelocityX);
}
else{
FightVelocityPhysicsLogicStandardX(FightData->EnemyData[WhichEnemy].LogicData.VelocityActiveY, FightData->EnemyData[WhichEnemy].Given->PositionX, FightData->EnemyData[WhichEnemy].LogicData.VelocityX, FightData->EnemyData[WhichEnemy].Loadable->WeightFactorComparedToStolarX);
FightVelocityHitLogicStandardX(FightData->EnemyData[WhichEnemy].LogicData.Hit, FightData->EnemyData[WhichEnemy].LogicData, FightData->EnemyData[WhichEnemy].FluxData.AnimationData, FightData->EnemyData[WhichEnemy].Loadable->AnimationHitGround, FightEnemyIdle(WhichEnemy));
}
}

}
