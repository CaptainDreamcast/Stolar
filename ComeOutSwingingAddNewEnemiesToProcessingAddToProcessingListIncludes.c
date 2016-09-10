uint8 ComeOutSwingingAddNewEnemiesToProcessingAddToProcessingListIncludes(ListStruct* BoundEnemyList, FightObjectInstanceStruct* EnemyObjectInstanceData){

ComeOutSwingingBoundEnemyStruct* ComeOutSwingingBoundEnemyData;
uint8 ReturnValue;

ReturnValue = LogicActiveNot;
while(!ReturnValue && !ListEmpty(BoundEnemyList)){
ComeOutSwingingBoundEnemyData = (ComeOutSwingingBoundEnemyStruct*)BoundEnemyList->Element;
if(
ComeOutSwingingBoundEnemyData->WhichObject == EnemyObjectInstanceData->Object->LogicData.WhichObject && 
ComeOutSwingingBoundEnemyData->WhichInstance == EnemyObjectInstanceData->LogicData.WhichInstance
){
ReturnValue = LogicActive;
}
}

return(ReturnValue);
}