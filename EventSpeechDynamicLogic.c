#define EventSpeechDynamicExit(EventSpeechDynamicData, EventKnowledgeData, TileData, EventTemporaryBufferPointer, NewReturnValue)	{ \
EventSpeechDynamicLogicDeLoad(EventSpeechDynamicData, EventKnowledgeData, TileData, EventTemporaryBufferPointer); \
EventSpeechDynamicData->UnStatic.ReturnValue = NewReturnValue; \
}

#define EventSpeechDynamicBranchSuccessful	1
#define EventSpeechDynamicBranchFail				0

void EventSpeechDynamicLogic(EventSpeechDynamicStruct* EventSpeechDynamicData, EventKnowledgeStruct* EventKnowledgeData, TileStruct* TileData, OverWorldStruct* OverWorldData, void** EventTemporaryBufferPointer){

uint8 DirtyDeedsDoneDirtCheap;
uint8 WhichObject, WhichInstance;

EventSpeechDynamicData->UnStatic.BuildUpPhaseOver = LogicActive;
Vector2DReset(&EventSpeechDynamicData->UnStatic.RadiusCenter.x, &EventSpeechDynamicData->UnStatic.RadiusCenter.z);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EventSpeechDynamicData->Loadable.Header->SpeechBubbleAmount; DirtyDeedsDoneDirtCheap++){

WhichInstance = EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->WhichInstance;
WhichObject = EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->WhichObject;

if(EventSpeechDynamicData->Loadable.Header->HasRadius){ 
Vector2DAdd(&EventSpeechDynamicData->UnStatic.RadiusCenter.x, &EventSpeechDynamicData->UnStatic.RadiusCenter.z, TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX, TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ);
}

if(EventSpeechDynamicData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].BuildUp){
EventSpeechDynamicData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition++;
if(EventSpeechDynamicData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition >= EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->ArrayLengthTotal){
EventSpeechDynamicData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition = EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->ArrayLengthTotal;
EventSpeechDynamicData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].BuildUp = 0;
}
else EventSpeechDynamicData->UnStatic.BuildUpPhaseOver = 0;
}
}
if(EventSpeechDynamicData->Loadable.Header->HasRadius){ 
Vector2DScale(&EventSpeechDynamicData->UnStatic.RadiusCenter.x, &EventSpeechDynamicData->UnStatic.RadiusCenter.z, ((float)(1.0f/DirtyDeedsDoneDirtCheap)));
}

if(!EventSpeechDynamicData->LogicData->General.PlayerTalks){
if(EventSpeechDynamicData->Loadable.Header->HasRadius){
if(
(Vector2DGetDistanceSquared(EventSpeechDynamicData->UnStatic.RadiusCenter.x, EventSpeechDynamicData->UnStatic.RadiusCenter.z, TileData->ObjectData[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichInstance].Loadable->PositionX, TileData->ObjectData[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichInstance].Loadable->StagePositionZ) 
 > 
Square(EventSpeechDynamicData->Loadable.Header->RadiusSize))
){
EventSpeechDynamicExit(EventSpeechDynamicData, EventKnowledgeData, TileData, EventTemporaryBufferPointer, EventSpeechDynamicBranchFail);
}
}
}

if(EventSpeechDynamicData->Loadable.Header->HasInput){
if(ButtonLegit(ButtonA, OverWorldData->LogicData.Player[EventKnowledgeData->WhichPlayer].Input.ButtonInputData)){
if(!EventSpeechDynamicData->UnStatic.BuildUpPhaseOver){
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<EventSpeechDynamicData->Loadable.Header->SpeechBubbleAmount; DirtyDeedsDoneDirtCheap++){
EventSpeechSpeechDynamicBubbleNoMoreBuildUp(DirtyDeedsDoneDirtCheap);
}
}
else{
EventSpeechDynamicExit(EventSpeechDynamicData, EventKnowledgeData, TileData, EventTemporaryBufferPointer, EventSpeechDynamicBranchSuccessful);
}
}
}
else{
if(EventSpeechDynamicData->UnStatic.BuildUpPhaseOver){
LogicCounter(EventSpeechDynamicData->LogicData->General.Ticks, EventSpeechDynamicData->Loadable.Header->TimeInSecondsThereBeforeVanish, 
{
EventSpeechDynamicExit(EventSpeechDynamicData, EventKnowledgeData, TileData, EventTemporaryBufferPointer, EventSpeechDynamicBranchSuccessful);
}
);
}
}

}