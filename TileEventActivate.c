
uint8 TileEventActivate(TileStruct* TileData, EventStruct* EventData, uint8 WhichPlayer){

uint8 DirtyDeedsDoneDirtCheap, ReturnValue;

ReturnValue = TileData->TileHeaderData->MaximumActiveEventAmount;

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->MaximumActiveEventAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->ActiveEventData[DirtyDeedsDoneDirtCheap].LogicData.WhichEvent == EventData->Loadable->WhichEvent){
ReturnValue = DirtyDeedsDoneDirtCheap;
DirtyDeedsDoneDirtCheap = TileData->TileHeaderData->MaximumActiveEventAmount+2;
}
}

if(DirtyDeedsDoneDirtCheap == TileData->TileHeaderData->MaximumActiveEventAmount){

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->MaximumActiveEventAmount; DirtyDeedsDoneDirtCheap++){

if(!TileData->ActiveEventData[DirtyDeedsDoneDirtCheap].LogicData.EventBufferSize){
TileData->ActiveEventData[DirtyDeedsDoneDirtCheap].LogicData.WhichEvent = EventData->Loadable->WhichEvent;
TileData->ActiveEventData[DirtyDeedsDoneDirtCheap].LogicData.EventHandled = 0;
TileData->ActiveEventData[DirtyDeedsDoneDirtCheap].LogicData.EventBufferSize = EventData->Loadable->EventBufferSize;
TileData->ActiveEventData[DirtyDeedsDoneDirtCheap].LogicData.KnowledgeData.WhichPlayer = WhichPlayer;
TileData->ActiveEventData[DirtyDeedsDoneDirtCheap].EventBufferPosition = EventData->EventBuffer;
TileData->ActiveEventData[DirtyDeedsDoneDirtCheap].EventBufferStart = EventData->EventBuffer;
TileData->ActiveEventData[DirtyDeedsDoneDirtCheap].EventTemporaryBuffer = NULL;

ReturnValue = DirtyDeedsDoneDirtCheap;
DirtyDeedsDoneDirtCheap = TileData->TileHeaderData->MaximumActiveEventAmount+1;
}
else if(DirtyDeedsDoneDirtCheap == (TileData->TileHeaderData->MaximumActiveEventAmount-1)){
TileData->ActiveEventData = (ActiveEventStruct*)(realloc(TileData->ActiveEventData, (sizeof(ActiveEventStruct)*(TileData->TileHeaderData->MaximumActiveEventAmount+1))));
InitiateSingleActiveEvent(TileData->ActiveEventData, TileData->TileHeaderData->MaximumActiveEventAmount);
TileData->TileHeaderData->MaximumActiveEventAmount++;
}
}

}

return(ReturnValue);
}
