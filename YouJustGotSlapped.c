void YouJustGotSlapped(EnemyFightStruct* EnemyFightData, StolarFightStruct* StolarFightData, GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, uint16 AttackStrength, float FillUpMultiplicator, short HitBackStrengthX, short HitBackStrengthY, short HitBackStrengthZ){

uint8 DirtyDeedsDoneDirtCheap;

EnemyFightData->WhatIsHappeningHere = EnemyJustGotHit;
EnemyFightData->DamagePending = AttackStrength;
//EnemyFightData->ReactionAnimation = StolarFightData->CurrentAnimation;
//EnemyFightData->ReactionFrame = StolarFightData->CurrentFrame;

if((HitBackStrengthX < 0 && HitBackStrengthX < EnemyFightData->StoredUpVelocityX) || 
(HitBackStrengthX > 0 && HitBackStrengthX > EnemyFightData->StoredUpVelocityX)) EnemyFightData->StoredUpVelocityX = HitBackStrengthX;

if((HitBackStrengthY < 0 && HitBackStrengthY < EnemyFightData->StoredUpVelocityY) || 
(HitBackStrengthY > 0 && HitBackStrengthY > EnemyFightData->StoredUpVelocityY)) EnemyFightData->StoredUpVelocityY = HitBackStrengthY;

if((HitBackStrengthZ < 0 && HitBackStrengthZ < EnemyFightData->StoredUpVelocityZ) || 
(HitBackStrengthZ > 0 && HitBackStrengthZ > EnemyFightData->StoredUpVelocityZ)) EnemyFightData->StoredUpVelocityZ = HitBackStrengthZ;

for(DirtyDeedsDoneDirtCheap = 1; DirtyDeedsDoneDirtCheap<AbilityAmount; DirtyDeedsDoneDirtCheap++){

if(!GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap].Active){
GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap].FilledNow+=AttackStrength*FillUpMultiplicator;
if(GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap].FilledNow >= GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap].FilledMax){
GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap].Active = 1;
GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap].FilledNow = GraphicalUserInterFaceData->AbilityData[DirtyDeedsDoneDirtCheap].FilledMax;
}
}
}

}

void AcrossTheFaceMyFriend(uint8 WhichEnemy, EnemyFightStruct* EnemyFightData, StolarFightStruct* StolarFightData, uint16 AttackStrength, short HitBackStrengthX, short HitBackStrengthY, short HitBackStrengthZ){

StolarFightData->TakingDamageData[WhichEnemy].Active = 1;
StolarFightData->TakingDamageData[WhichEnemy].DamagePending = AttackStrength;

if((HitBackStrengthX < 0 && HitBackStrengthX < StolarFightData->StoredUpVelocityX) || 
(HitBackStrengthX > 0 && HitBackStrengthX > StolarFightData->StoredUpVelocityX)) StolarFightData->StoredUpVelocityX = HitBackStrengthX;

if((HitBackStrengthY < 0 && HitBackStrengthY < StolarFightData->StoredUpVelocityY) || 
(HitBackStrengthY > 0 && HitBackStrengthY > StolarFightData->StoredUpVelocityY)) StolarFightData->StoredUpVelocityY = HitBackStrengthY;

if((HitBackStrengthZ < 0 && HitBackStrengthZ < StolarFightData->StoredUpVelocityZ) || 
(HitBackStrengthZ > 0 && HitBackStrengthZ > StolarFightData->StoredUpVelocityZ)) StolarFightData->StoredUpVelocityZ = HitBackStrengthZ;

}

