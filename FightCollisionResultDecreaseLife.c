uint16 FightCollisionResultDecreaseLife(FightAttackStruct* FightAttackData, FightDefenseStruct* FightDefenseData, uint16* Health){
uint16 FinalDamage;

if(FightAttackData->Attack >= FightDefenseData->Defense) FinalDamage = 0;
else FinalDamage = FightAttackData->Attack-FightDefenseData->Defense;

if((*Health) <= FinalDamage){
(*Health) = 0;
//SOMETHING
}
else (*Health)-=FinalDamage;

return(FinalDamage);
}