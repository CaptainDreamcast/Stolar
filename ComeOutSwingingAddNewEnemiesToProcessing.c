void ComeOutSwingingAddNewEnemiesToProcessing(FightStruct* FightData, ComeOutSwingingStruct* ComeOutSwingingData){

ListStruct* WorkingInputList;

WorkingInputList = ListGetWorkingList(ComeOutSwingingData->LogicData.EnemiesHitAlready, ComeOutSwingingData->LogicData.BoundEnemyProcessedAmount);

while(!ListEmpty(WorkingInputList)){
ComeOutSwingingAddNewEnemiesToProcessingAddToProcessingList(FightData, ComeOutSwingingData, WorkingInputList->Element);
WorkingInputList = WorkingInputList->Next;
}

}