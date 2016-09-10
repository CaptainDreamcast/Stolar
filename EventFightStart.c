uint8 EventFightStart(EventFunctionArguments){

//uint32 CurrentPointerPosition, Size;

if(!TileLogicOutroActive(TileData)){
//Size = sizeof(FightLoadableGivenStruct)+sizeof(FightLoadableEnemiesStruct)+(sizeof(FightEnemyGivenStruct)*(((FightLoadableEnemiesStruct*)(EventBufferPointer+sizeof(FightLoadableGivenStruct)))->General.EnemyAmount));
//CurrentPointerPosition = (uint32)EventBufferPointer;
//LoadBufferFromBufferPointer(void*, OverWorldData->LogicData.Passable, Size);
EventInitialize();

TileData->ObjectData[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichInstance].LogicData.MoveNot++;
TilePlayerChangeAnimationSimplest(EventKnowledgeData->WhichPlayer, PlayerIdleAnimation);

(*TileLogicOutroInitiate[TileData->TileHeaderData->Fight.Outro])(TileData, OverWorldData, OverWorldGamePlayFight, DummyValueInteger);
FightInitiateSet(OverWorldData);
}


return(EventTileExitSubEvent);
}