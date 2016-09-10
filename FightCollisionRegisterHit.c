void FightCollisionRegisterHitEnemy(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, FightAttackStruct* FightAttackData, uint8 EnemyFaceDirection){
if(EnemyFaceDirection == FightFaceRight) FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ForceX += FightAttackData->ForceX;
else FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ForceX -= FightAttackData->ForceX;
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ForceY += FightAttackData->ForceY;
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ForceZ += FightAttackData->ForceZ;
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.Damage += FightAttackData->Damage;
}