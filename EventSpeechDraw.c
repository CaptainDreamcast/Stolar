void EventSpeechDraw(EventSpeechStruct* EventSpeechData, OverWorldStruct* OverWorldData, TileStruct* TileData){

uint8 DirtyDeedsDoneDirtCheap;

EventSpeechData->UnStatic.BuildUpPhaseOver = 1;
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EventSpeechData->Loadable.Header->SpeechBubbleAmount; DirtyDeedsDoneDirtCheap++){

EventSpeechDrawSpeechBubble(DirtyDeedsDoneDirtCheap, EventSpeechData, OverWorldData);

if(EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].BuildUp){
EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition++;
if(EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition >= EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->ArrayLengthTotal){
EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition = EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->ArrayLengthTotal;
EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].BuildUp = 0;
}
else EventSpeechData->UnStatic.BuildUpPhaseOver = 0;
}
}


for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EventSpeechData->Loadable.Header->SpriteAmount; DirtyDeedsDoneDirtCheap++){

if((!EventSpeechData->UnStatic.BuildUpPhaseOver && (EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].Active & SpriteDrawnDuringBuildUp)) || (EventSpeechData->UnStatic.BuildUpPhaseOver && (EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].Active & SpriteDrawnDuringWait))){

TextureAtlasDrawWithReverseSimplest(TileData->Sprites[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].WhichSprite].AnimationData[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].Animation].TextureOffset+EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].CurrentFrame, NULL, 
TileData->Sprites[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].WhichSprite].Texture, 
EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].PositionX, EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].PositionY, 
EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].PositionZ, 
EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].SizeX, EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].SizeY, 
TileData->Sprites[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].WhichSprite].Loadable->TextureSizeX, TileData->Sprites[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].WhichSprite].Loadable->TextureSizeY, 
TileData->Sprites[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].WhichSprite].Loadable->SingleTextureSizeX, TileData->Sprites[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].WhichSprite].Loadable->SingleTextureSizeY, 
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].FaceLeft);


AnimateWithAnimationFactorLoop(EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].Ticks, 
TileData->Sprites[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].WhichSprite].AnimationData[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].Animation].AnimationDurationInSeconds, 
TileData->Sprites[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].WhichSprite].Loadable->AnimationFactor, 
EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].CurrentFrame, 
TileData->Sprites[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].WhichSprite].AnimationData[EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].Animation].FrameAmount
);

LogicRawMovementUnknownDirectionFixedDuration(EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].PositionX, EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].TimeInSecondsMoveIn, EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].StartPositionX, EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].EndPositionX, {});
LogicAlphaBuildUp(EventSpeechData->LogicData->Sprites[DirtyDeedsDoneDirtCheap].AlphaValue, EventSpeechData->Loadable.Sprites[DirtyDeedsDoneDirtCheap].TimeInSecondsAlphaBuildUp, {});
}
}

}