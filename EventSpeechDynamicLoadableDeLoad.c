void EventSpeechDynamicLoadableDeLoad(EventSpeechDynamicStruct* EventSpeechDynamicData){

uint8 DirtyDeedsDoneDirtCheap;

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < EventSpeechDynamicData->Loadable.Header->SpeechBubbleAmount; DirtyDeedsDoneDirtCheap++){
free(EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Array);
}
free(EventSpeechDynamicData->Loadable.SpeechBubbles);

}