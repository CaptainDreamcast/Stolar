void EventSpeechDynamicDraw(EventSpeechDynamicStruct* EventSpeechDynamicData, TileStruct* TileData, OverWorldStruct* OverWorldData){

float PositionX, PositionY, PositionZ;
uint8 WhichSpeechBubble;

for(WhichSpeechBubble = 0; WhichSpeechBubble < EventSpeechDynamicData->Loadable.Header->SpeechBubbleAmount; WhichSpeechBubble++){

EventSpeechDynamicDrawSpeechBubblePositionGet(EventSpeechDynamicData, TileData, OverWorldData, WhichSpeechBubble, &PositionX, &PositionY, &PositionZ);
EventSpeechDrawSpeechBubbleGeneral(
OverWorldData, EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->SpeechBubbleType, 
PositionX, PositionY, PositionZ, 
EventSpeechDynamicData->LogicData->SpeechBubbles[WhichSpeechBubble].ArrayPosition, EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Array, 
EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].ArrayLength, 
EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].FontPositionX, EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontPositionY, 
EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontPositionZ, 
EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontSizeX, EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontSizeY, 
EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->FontColor, EventSpeechDynamicData->Loadable.SpeechBubbles[WhichSpeechBubble].Header->WhichFont
);
}

}