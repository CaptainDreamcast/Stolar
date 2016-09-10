void FightObjectsSingleObjectSingleInstance(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

FightObjectsSingleObjectSingleInstanceDraw(FightData, WhichObject, WhichInstance);
FightObjectsSingleObjectSingleInstanceAnimate(FightData, WhichObject, WhichInstance);
FightObjectsSingleObjectSingleInstanceIntelligence(FightData, WhichObject, WhichInstance);
FightObjectsSingleObjectSingleInstancePhysics(FightData, WhichObject, WhichInstance);

}