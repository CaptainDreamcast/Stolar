void EventSpeechInput(EventSpeechStruct* EventSpeechData, EventKnowledgeStruct* EventKnowledgeData, OverWorldStruct* OverWorldData, TileStruct* TileData, void** EventTemporaryBufferPointer){

uint8 DirtyDeedsDoneDirtCheap;

if(!EventSpeechData->UnStatic.IsFirstFrame){
if(ButtonLegit(ButtonA, OverWorldData->LogicData.Player[EventKnowledgeData->WhichPlayer].Input.ButtonInputData)){
if(!EventSpeechData->UnStatic.BuildUpPhaseOver){
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<EventSpeechData->Loadable.Header->SpeechBubbleAmount; DirtyDeedsDoneDirtCheap++){
EventSpeechSpeechBubbleNoMoreBuildUp(DirtyDeedsDoneDirtCheap);
}
}
else{
EventSpeechLogicDeLoad(EventSpeechData, TileData, EventKnowledgeData, EventTemporaryBufferPointer);
EventSpeechData->UnStatic.ReturnValue = EventSubEventFinished;
}
}
}

}