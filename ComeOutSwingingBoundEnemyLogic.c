void ComeOutSwingingBoundEnemyLogic(FightStruct* FightData, ComeOutSwingingStruct* ComeOutSwingingData){
ListStruct* BoundEnemyListBuffer;
ListStruct* BoundEnemyList;
ComeOutSwingingBoundEnemyStruct* BoundEnemyData;

BoundEnemyList = ComeOutSwingingData->LogicData.BoundEnemyList;
while(!ListEmpty(BoundEnemyList)){
BoundEnemyData = (ComeOutSwingingBoundEnemyStruct*)BoundEnemyList->Element;

FightObjectChangeAnimationSimplest(FightData->ObjectData[BoundEnemyData->WhichObject].Instance[BoundEnemyData->WhichInstance], StandardEnemyHitAnimation);

BoundEnemyData->Ticks++;
if(BoundEnemyData->Ticks > ComeOutSwingingData->Loadable->BoundDurationInSeconds*FrameRate){

FightData->ObjectData[BoundEnemyData->WhichObject].Instance[BoundEnemyData->WhichInstance].Intelligence[FightEnemyIntelligenceIdentifierStateMachine].LogicData.Semaphore--;


if(BoundEnemyList->Previous == NULL && BoundEnemyList->Next == NULL){
free(BoundEnemyList->Element);
free(ComeOutSwingingData->LogicData.BoundEnemyList);
ComeOutSwingingData->LogicData.BoundEnemyList = NULL;
BoundEnemyList = NULL;
}
else{
if(!ListEmpty(BoundEnemyList->Previous)) BoundEnemyList->Previous->Next = BoundEnemyList->Next;
else ComeOutSwingingData->LogicData.BoundEnemyList = BoundEnemyList->Next;

if(!ListEmpty(BoundEnemyList->Next)) BoundEnemyList->Next->Previous = BoundEnemyList->Previous;

BoundEnemyListBuffer = BoundEnemyList;
BoundEnemyList = BoundEnemyList->Next;
free(BoundEnemyListBuffer->Element);
free(BoundEnemyListBuffer);
}
}
else BoundEnemyList = BoundEnemyList->Next;

}

}