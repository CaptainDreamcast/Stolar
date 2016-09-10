void EventSpeechDynamicDrawSpeechBubblePositionGet(EventSpeechDynamicStruct* EventSpeechDynamicData, TileStruct* TileData, OverWorldStruct* OverWorldData, uint8 WhichSpeechBubble, float* PositionX, float* PositionY, float* PositionZ){

uint8 WhichObject, WhichInstance;

WhichObject = EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->WhichObject;
WhichInstance = EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->WhichInstance;

(*PositionX) = TileObjectFetchCenterPositionX(TileData, WhichObject, WhichInstance)-OverWorldData->Loadable->SpeechBubbles[EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->SpeechBubbleType].TextureSizeX;
(*PositionY) = TileObjectFetchTopPositionY(TileData, WhichObject, WhichInstance)-OverWorldData->Loadable->SpeechBubbles[EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->SpeechBubbleType].TextureSizeY;
(*PositionZ) = TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ScreenPositionZ;
}