void EventSpeechLoadableDeLoad(EventSpeechStruct* EventSpeechData){

uint8 DirtyDeedsDoneDirtCheap;

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < EventSpeechData->Loadable.Header->SpeechBubbleAmount; DirtyDeedsDoneDirtCheap++){
free(EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Array);
}
free(EventSpeechData->Loadable.SpeechBubbles);

}