uint8 EventSpeech(EventFunctionArguments){

EventSpeechStruct EventSpeechData;

EventSpeechLoad(&EventSpeechData, TileData, EventKnowledgeData, EventBufferPointer, EventTemporaryBufferPointer);

EventSpeechDraw(&EventSpeechData, OverWorldData, TileData);
EventSpeechInput(&EventSpeechData, EventKnowledgeData, OverWorldData, TileData, EventTemporaryBufferPointer);

EventSpeechLoadableDeLoad(&EventSpeechData);

return(EventSpeechData.UnStatic.ReturnValue);
}