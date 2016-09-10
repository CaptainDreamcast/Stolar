void EventSpeechLoad(EventSpeechStruct* EventSpeechData, TileStruct* TileData, EventKnowledgeStruct* EventKnowledgeData, void* EventBuffer, void** EventTemporaryBuffer){

uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;
uint32 CurrentPointerPosition;

CurrentPointerPosition = (uint32)(EventBuffer);
LoadSetThisToThatPointer(EventSpeechLoadableHeaderStruct*, EventSpeechData->Loadable.Header, sizeof(EventSpeechLoadableHeaderStruct));

EventSpeechData->Loadable.SpeechBubbles = (EventSpeechLoadableSpeechBubbleStruct*)malloc(sizeof(EventSpeechLoadableSpeechBubbleStruct)*EventSpeechData->Loadable.Header->SpeechBubbleAmount);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < EventSpeechData->Loadable.Header->SpeechBubbleAmount; DirtyDeedsDoneDirtCheap++){
LoadCurrentPointerPositionSetToLegalStartValue();
LoadSetThisToThatPointer(EventSpeechLoadableSpeechBubbleHeaderStruct*, EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header, sizeof(EventSpeechLoadableSpeechBubbleHeaderStruct));
LoadSetThisToThatPointer(float*, EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].FontPositionX, (sizeof(float)*EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->RowAmount));
LoadSetThisToThatPointer(uint16*, EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayLength, (sizeof(uint16)*EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->RowAmount));
EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Array = (char**)malloc(sizeof(char*)*EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->RowAmount);
for(BurningDownTheHouse = 0; BurningDownTheHouse < EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->RowAmount; BurningDownTheHouse++){
LoadSetThisToThatPointer(char*, EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Array[BurningDownTheHouse], EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayLength[BurningDownTheHouse]);
}
}
LoadSetThisToThatPointer(EventSpeechLoadableSpriteStruct*, EventSpeechData->Loadable.Sprites, (sizeof(EventSpeechLoadableSpriteStruct)*EventSpeechData->Loadable.Header->SpriteAmount));

if((*EventTemporaryBuffer) == NULL){
EventInitialize();
(*EventTemporaryBuffer) = (void*)malloc(sizeof(EventSpeechLogicStruct));
EventSpeechData->LogicData = (EventSpeechLogicStruct*)(*EventTemporaryBuffer);
EventSpeechData->LogicData->SpeechBubbles = (EventSpeechLogicSpeechBubbleStruct*)malloc(sizeof(EventSpeechLogicSpeechBubbleStruct)*EventSpeechData->Loadable.Header->SpeechBubbleAmount);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EventSpeechData->Loadable.Header->SpeechBubbleAmount; DirtyDeedsDoneDirtCheap++){

EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].PositionX = EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->StartPositionX;
EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].PositionY = EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->StartPositionY;
EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ScaleValue = EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->ScaleValue;

if((EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].BuildUp = EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->BuildUp)){
EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition = 0;
}
else EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition = EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->ArrayLengthTotal;
}

EventSpeechData->LogicData->Sprites = (EventSpeechLogicSpriteStruct*)malloc(sizeof(EventSpeechLogicSpriteStruct)*EventSpeechData->Loadable.Header->SpriteAmount);
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EventSpeechData->Loadable.Header->SpriteAmount; DirtyDeedsDoneDirtCheap++){
EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].PositionX = EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].StartPositionX;
EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].PositionY = EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].PositionY;
EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].AlphaValue = EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].AlphaValueStart;
EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].ScaleValue = EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].ScaleValue;
EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].CurrentFrame = NewFrameStandardValue;
}

TileData->ObjectData[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichInstance].LogicData.MoveNot++;

EventSpeechData->UnStatic.IsFirstFrame = LogicActive;
}
else{
EventSpeechData->LogicData = (EventSpeechLogicStruct*)(*EventTemporaryBuffer);
EventSpeechData->UnStatic.IsFirstFrame = LogicActiveNot;
}
EventSpeechData->UnStatic.ReturnValue = EventSubEventGoesOn;
}