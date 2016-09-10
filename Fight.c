void Fight(OverWorldStruct* OverWorldData) {

FightStruct FightData;

FightLoad(&FightData, OverWorldData);
SoundPlay(3);

while(FightData.LogicData.General.LoopFight){

FightDrawStart(&FightData);
FightUserInterFace(&FightData);
FightStage(&FightData);
FightBackGrounds(&FightData);
FightObjects(&FightData);
FightDrawFinish();

}

SoundStop(3);
FightDeLoad(&FightData);
}