void EventSpeechDynamicLogicDeLoad(EventSpeechDynamicStruct* EventSpeechDynamicData, EventKnowledgeStruct* EventKnowledgeData, TileStruct* TileData, void** EventTemporaryBufferPointer){

//if(EventSpeechDynamicData->LogicData->General.PlayerTalks){
TileData->ObjectData[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichInstance].LogicData.MoveNot--;
//}
free(EventSpeechDynamicData->LogicData->SpeechBubbles);
EventFinalize((*EventTemporaryBufferPointer));


}