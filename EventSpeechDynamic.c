uint8 EventSpeechDynamic(EventFunctionArguments){

EventSpeechDynamicStruct EventSpeechDynamicData;

EventSpeechDynamicLoad(&EventSpeechDynamicData, EventKnowledgeData, TileData, EventBufferPointer, EventTemporaryBufferPointer);

EventSpeechDynamicDraw(&EventSpeechDynamicData, TileData, OverWorldData);
EventSpeechDynamicLogic(&EventSpeechDynamicData, EventKnowledgeData, TileData, OverWorldData, EventTemporaryBufferPointer);

EventSpeechDynamicLoadableDeLoad(&EventSpeechDynamicData);

return(EventSpeechDynamicData.UnStatic.ReturnValue);
}
