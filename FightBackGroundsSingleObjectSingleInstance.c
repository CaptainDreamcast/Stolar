void FightBackGroundsSingleObjectSingleInstance(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

if(FightData->BackGroundData[WhichObject].Instance[WhichInstance].LogicData.Active){
FightBackGroundsSingleObjectSingleInstanceDraw(FightData, WhichObject, WhichInstance);
FightBackGroundsSingleObjectSingleInstanceAnimate(FightData, WhichObject, WhichInstance);
FightBackGroundsSingleObjectSingleInstanceLogic(FightData, WhichObject, WhichInstance);
}

}