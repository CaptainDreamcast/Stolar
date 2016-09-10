void EventSpeechDynamicLoad(EventSpeechDynamicStruct* EventSpeechDynamicData, EventKnowledgeStruct* EventKnowledgeData, TileStruct* TileData,  void* EventBuffer, void** EventTemporaryBuffer){


uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse, WhichObject, WhichInstance;
uint32 CurrentPointerPosition;

CurrentPointerPosition = (uint32)(EventBuffer);
LoadSetThisToThatPointer(EventSpeechDynamicLoadableHeaderStruct*, EventSpeechDynamicData->Loadable.Header, sizeof(EventSpeechDynamicLoadableHeaderStruct));

EventSpeechDynamicData->Loadable.SpeechBubbles = (EventSpeechDynamicLoadableSpeechBubbleStruct*)malloc(sizeof(EventSpeechDynamicLoadableSpeechBubbleStruct)*EventSpeechDynamicData->Loadable.Header->SpeechBubbleAmount);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < EventSpeechDynamicData->Loadable.Header->SpeechBubbleAmount; DirtyDeedsDoneDirtCheap++){
LoadCurrentPointerPositionSetToLegalStartValue();
LoadSetThisToThatPointer(EventSpeechDynamicLoadableSpeechBubbleHeaderStruct*, EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header, sizeof(EventSpeechDynamicLoadableSpeechBubbleHeaderStruct));
LoadSetThisToThatPointer(float*, EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].FontPositionX, (sizeof(float)*EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->RowAmount));
LoadSetThisToThatPointer(uint16*, EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayLength, (sizeof(uint16)*EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->RowAmount));
EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Array = (char**)malloc(sizeof(char*)*EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->RowAmount);
for(BurningDownTheHouse = 0; BurningDownTheHouse < EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->RowAmount; BurningDownTheHouse++){
LoadSetThisToThatPointer(char*, EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Array[BurningDownTheHouse], EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayLength[BurningDownTheHouse]);
}
}

if((*EventTemporaryBuffer) == NULL){
EventInitialize();
(*EventTemporaryBuffer) = (void*)malloc(sizeof(EventSpeechDynamicLogicStruct));
EventSpeechDynamicData->LogicData = (EventSpeechDynamicLogicStruct*)(*EventTemporaryBuffer);
EventSpeechDynamicData->LogicData->SpeechBubbles = (EventSpeechDynamicLogicSpeechBubbleStruct*)malloc(sizeof(EventSpeechDynamicLogicSpeechBubbleStruct)*EventSpeechDynamicData->Loadable.Header->SpeechBubbleAmount);

EventSpeechDynamicData->LogicData->General.Ticks = NewTicksStandardValue;
EventSpeechDynamicData->LogicData->General.PlayerTalks = LogicActiveNot;

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EventSpeechDynamicData->Loadable.Header->SpeechBubbleAmount; DirtyDeedsDoneDirtCheap++){

WhichInstance = EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->WhichInstance;
WhichObject = EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->WhichObject;

if(WhichObject == TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichObject && WhichInstance == TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichInstance){
EventSpeechDynamicData->LogicData->General.PlayerTalks = LogicActive;
}

EventSpeechDynamicData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ScaleValue = EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->ScaleValue;

if((EventSpeechDynamicData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].BuildUp = EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->BuildUp)){
EventSpeechDynamicData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition = 0;
}
else EventSpeechDynamicData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition = EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->ArrayLengthTotal;
}

//if(EventSpeechDynamicData->LogicData->General.PlayerTalks){
TileData->ObjectData[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichInstance].LogicData.MoveNot++;
//
TilePlayerChangeAnimationSimplest(EventKnowledgeData->WhichPlayer, PlayerIdleAnimation);
//
//}

}
else EventSpeechDynamicData->LogicData = (EventSpeechDynamicLogicStruct*)(*EventTemporaryBuffer);

EventSpeechDynamicData->UnStatic.ReturnValue = EventSubEventGoesOn;


}
