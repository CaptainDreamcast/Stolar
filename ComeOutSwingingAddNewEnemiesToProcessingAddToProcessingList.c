void ComeOutSwingingAddNewEnemiesToProcessingAddToProcessingList(FightStruct* FightData, ComeOutSwingingStruct* ComeOutSwingingData, void* Element){

ComeOutSwingingBoundEnemyStruct* BoundEnemyData;
FightObjectInstanceStruct* EnemyObjectInstanceData;

EnemyObjectInstanceData = (FightObjectInstanceStruct*)Element;

if(!ComeOutSwingingAddNewEnemiesToProcessingAddToProcessingListIncludes(ComeOutSwingingData->LogicData.BoundEnemyList, EnemyObjectInstanceData)){
BoundEnemyData = ComeOutSwingingAddNewEnemiesToProcessingAddToProcessingListBoundEnemyDataCreate(EnemyObjectInstanceData);
ListAdd(&ComeOutSwingingData->LogicData.BoundEnemyList, BoundEnemyData);
EnemyObjectInstanceData->Intelligence[FightEnemyIntelligenceIdentifierStateMachine].LogicData.Semaphore++;
}



ComeOutSwingingData->LogicData.BoundEnemyProcessedAmount++;
}