#define FightArtificialIntelligenceFunctionArguments	FightStruct* FightData, OverWorldStruct* OverWorldData, uint8 WhichEnemy


void FightArtificialIntelligenceFunctionNothing(FightArtificialIntelligenceFunctionArguments){

if(FightData->EnemyData[WhichEnemy].LogicData.Hit){
FightData->EnemyData[WhichEnemy].LogicData.Hit = FightCollisionResultEnemyStandard(FightData, OverWorldData, WhichEnemy);
}


FightArtificialIntelligencePhysicsStandard(FightData, OverWorldData, WhichEnemy);


/*
if(FightEnemyIsIdle() && FightArtificialIntelligenceMovementLogical()){
FightArtificialIntelligenceMovementStandard();
}
if(FightEnemyIsIdle() && FightArtificialIntelligenceAttackLogical()){
FightArtificialIntelligenceAttack();
}
*/

FightData->EnemyData[WhichEnemy].LogicData.Hit = FightLogicEnemyHitNot;

}


#define FightArtificialIntelligenceFunctionAmount	1
void (*FightArtificialIntelligenceFunction[FightArtificialIntelligenceFunctionAmount])(FightArtificialIntelligenceFunctionArguments) = 
{
FightArtificialIntelligenceFunctionNothing
};
