uint8 FightCollisionResultMoved(FightAttackStruct* FightAttackData, FightDefenseStruct* FightDefenseData, uint16 FinalDamage, float* VelocityX, float* VelocityY){

uint8 Hit;
float Factor;

Factor = (((float)FinalDamage)/FightAttackData->Attack);

Hit = LogicActiveNot;
if(FightAttackData->VelocityX*Factor > FightDefenseData->VelocityResistanceX){
(*VelocityX) = (FightAttackData->VelocityX*Factor)-FightDefenseData->VelocityResistanceX;
Hit = LogicActive;
}

if(FightAttackData->VelocityY*Factor > FightDefenseData->VelocityResistanceY){
(*VelocityY) = (FightAttackData->VelocityY*Factor)-FightDefenseData->VelocityResistanceY;
Hit = LogicActive;
}

return(Hit);
}