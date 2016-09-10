


void HandleSingleEvent(ActiveEventStruct* ActiveEventData, TileStruct* TileData, OverWorldStruct* OverWorldData){

uint32 BurningDownTheHouse;

if(ActiveEventData->LogicData.EventBufferSize && !(ActiveEventData->LogicData.EventHandled)){
do{
if((BurningDownTheHouse = (*EventFunction[((TileEventSingleLoadableGeneralStruct*)(ActiveEventData->EventBufferPosition))->Type])(ActiveEventData->EventBufferPosition+sizeof(TileEventSingleLoadableGeneralStruct), &ActiveEventData->EventTemporaryBuffer, &ActiveEventData->LogicData.KnowledgeData, TileData, OverWorldData)) != EventSubEventGoesOn){
ActiveEventData->LogicData.EventHandled = 1;
ActiveEventData->EventBufferPosition += (sizeof(TileEventSingleLoadableGeneralStruct)+((TileEventSingleLoadableGeneralStruct*)(ActiveEventData->EventBufferPosition))->Size+sizeof(TileEventBranchHeaderStruct));
ActiveEventData->EventBufferPosition = (void*)(((uint32)ActiveEventData->EventBufferStart)+((TileEventBranchSingleStruct*)ActiveEventData->EventBufferPosition)[BurningDownTheHouse].BranchAddress);
if((ActiveEventData->EventBufferPosition-ActiveEventData->EventBufferStart) >= ActiveEventData->LogicData.EventBufferSize){
DisableActiveEvent(ActiveEventData);
BurningDownTheHouse = EventTotallyFinished;
}
}
} while(BurningDownTheHouse == EventSubEventInitiateLoop);
}

}

void TileEventHandler(TileStruct* TileData, OverWorldStruct* OverWorldData){

uint8 DirtyDeedsDoneDirtCheap;

if(TileData->LogicData.General.EnableFlags & TileEnableFlagEventHandler){
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->MaximumActiveEventAmount; DirtyDeedsDoneDirtCheap++) TileData->ActiveEventData[DirtyDeedsDoneDirtCheap].LogicData.EventHandled = 0;
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->MaximumActiveEventAmount; DirtyDeedsDoneDirtCheap++){
HandleSingleEvent(&TileData->ActiveEventData[DirtyDeedsDoneDirtCheap], TileData, OverWorldData);
}
}

}