void EventSpeechLogicDeLoad(EventSpeechStruct* EventSpeechData, TileStruct* TileData, EventKnowledgeStruct* EventKnowledgeData, void** EventTemporaryBufferPointer){

TileData->ObjectData[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichInstance].LogicData.MoveNot--;
free(EventSpeechData->LogicData->SpeechBubbles);
free(EventSpeechData->LogicData->Sprites);
EventFinalize((*EventTemporaryBufferPointer));

}