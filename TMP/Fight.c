void Fight(void** TransitionData, OverWorldStruct* OverWorldData) {

FightStruct FightData;

FightLoad(&FightData, OverWorldData);

while(FightData.LogicData.General.LoopFight){

FightDrawStart(&FightData);
FightDraw(&FightData, OverWorldData);
FightInputPre(&FightData, OverWorldData);
FightLogicPre(&FightData, OverWorldData, TransitionData);
FightStolarPhysics(&FightData, OverWorldData);
FightStolarAbilities(&FightData, OverWorldData);
FightStolarMovement(&FightData, OverWorldData);
FightArtificialIntelligence(&FightData, OverWorldData);
FightDrawFinish();
FightLogicPost(&FightData, OverWorldData);
FightInputPost(&FightData, OverWorldData);
}

FightDeLoad(&FightData, OverWorldData);
}