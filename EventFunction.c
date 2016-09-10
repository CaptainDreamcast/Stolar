
uint8 ManipulateStoryFlag(EventFunctionArguments){

ManipulateStoryFlagStruct ManipulateStoryFlagData;
uint8 DirtyDeedsDoneDirtCheap;

ManipulateStoryFlagData.Loadable = (ManipulateStoryFlagLoadableStruct*)EventBufferPointer;
ManipulateStoryFlagData.SingleFlagData = (ManipulateStoryFlagSingleFlagStruct*)(EventBufferPointer+sizeof(ManipulateStoryFlagLoadableStruct));
EventInitialize();

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < ManipulateStoryFlagData.Loadable->Amount; DirtyDeedsDoneDirtCheap++){
if(ManipulateStoryFlagData.SingleFlagData[DirtyDeedsDoneDirtCheap].Set) SaveData.CompressableData->StoryFlags[ManipulateStoryFlagData.SingleFlagData[DirtyDeedsDoneDirtCheap].WhichFlag/BitsPerByte] |= ManipulateStoryFlagData.SingleFlagData[DirtyDeedsDoneDirtCheap].WhichFlag%BitsPerByte;
else SaveData.CompressableData->StoryFlags[ManipulateStoryFlagData.SingleFlagData[DirtyDeedsDoneDirtCheap].WhichFlag/BitsPerByte] &= ~(ManipulateStoryFlagData.SingleFlagData[DirtyDeedsDoneDirtCheap].WhichFlag%BitsPerByte);
}

TileUpdateFlagsActive(TileData, OverWorldData);

return(EventSubEventInitiateLoop);
}



uint8 EventChangeAnimation(EventFunctionArguments){

/*
EventChangeAnimationStruct* EventChangeAnimationData;

EventChangeAnimationData = (EventChangeAnimationStruct*)EventBufferPointer;
EventInitialize();


if(EventChangeAnimationData->WhoChanges == EventStolarAnimationChange){
StolarChangeAnimation(TileData->LogicData.Stolar, EventChangeAnimationData->WhichAnimation, EventChangeAnimationData->StartFrame, EventChangeAnimationData->StartTicks, EventChangeAnimationData->EventInducedLoop);
}
else if(EventChangeAnimationData->WhoChanges == EventPersonAnimationChange){
ChangeAnimationCrankArtificialIntelligence(TileData->PersonData[EventChangeAnimationData->WhoChangesExactly], EventChangeAnimationData->WhichAnimation, EventChangeAnimationData->StartFrame, EventChangeAnimationData->StartTicks, EventChangeAnimationData->EventInducedLoop);
}
else if(EventChangeAnimationData->WhoChanges == EventNormalEnemyAnimationChange){
ChangeAnimationCrankArtificialIntelligence(TileData->NormalEnemyData[EventChangeAnimationData->WhoChangesExactly], EventChangeAnimationData->WhichAnimation, EventChangeAnimationData->StartFrame, EventChangeAnimationData->StartTicks, EventChangeAnimationData->EventInducedLoop);
}
else if(EventChangeAnimationData->WhoChanges == EventSpecialEnemyAnimationChange){
ChangeAnimationCrankArtificialIntelligence(TileData->SpecialEnemyData[EventChangeAnimationData->WhoChangesExactly], EventChangeAnimationData->WhichAnimation, EventChangeAnimationData->StartFrame, EventChangeAnimationData->StartTicks, EventChangeAnimationData->EventInducedLoop);
}
*/

return(EventSubEventInitiateLoop);
}



uint8 ExitTile(EventFunctionArguments){

TileEventExitTileStruct* TileEventExitTileData;
uint8 WhichCrewMember;

TileEventExitTileData = (TileEventExitTileStruct*)EventBufferPointer;
(*TileLogicOutroInitiate[TileEventExitTileData->Outro])(TileData, OverWorldData, OverWorldGamePlayTile, TileEventExitTileData->NewTile);
(*TileLogicIntroInitiate[TileEventExitTileData->Intro])(((TileLogicIntroStruct**)(&OverWorldData->FluxData.General.TransitionData)));

TileData->ObjectData[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[EventKnowledgeData->WhichPlayer].LogicData.WhichInstance].LogicData.MoveNot++;
TilePlayerChangeAnimationSimplest(EventKnowledgeData->WhichPlayer, PlayerIdleAnimation);

for(WhichCrewMember = 0; WhichCrewMember < OverWorldData->LogicData.General.CrewSize; WhichCrewMember++){
OverWorldData->CrewData[WhichCrewMember].LogicData.Tile.StartPositionX = TileEventExitTileData->StartPositionX;
OverWorldData->CrewData[WhichCrewMember].LogicData.Tile.StartStagePositionZ = TileEventExitTileData->StartStagePositionZ;

}

return(EventSubEventFinished);
}



uint8 MoveScreen(EventFunctionArguments){

EventTemporaryScreenMovementStruct* EventTemporaryScreenMovementData;
EventScreenMovementStruct* EventScreenMovementData;

uint8 ReturnValue;

EventScreenMovementData = (EventScreenMovementStruct*)EventBufferPointer;
if((*EventTemporaryBufferPointer) == NULL){
EventInitialize();
(*EventTemporaryBufferPointer) = (void*)malloc(sizeof(EventTemporaryScreenMovementStruct));
EventTemporaryScreenMovementData = (EventTemporaryScreenMovementStruct*)(*EventTemporaryBufferPointer);
if(TileData->LogicData.BackGround.StagePositionX <= EventScreenMovementData->FinalPositionX) EventTemporaryScreenMovementData->PixelMovementPerSecondX = EventScreenMovementData->PixelMovementPerSecondX;
else EventTemporaryScreenMovementData->PixelMovementPerSecondX = -EventScreenMovementData->PixelMovementPerSecondX;
if(TileData->LogicData.BackGround.StagePositionY <= EventScreenMovementData->FinalPositionY) EventTemporaryScreenMovementData->PixelMovementPerSecondY = EventScreenMovementData->PixelMovementPerSecondY;
else EventTemporaryScreenMovementData->PixelMovementPerSecondY = -EventScreenMovementData->PixelMovementPerSecondY;

}
else EventTemporaryScreenMovementData = (*EventTemporaryBufferPointer);


if(EventTemporaryScreenMovementData->PixelMovementPerSecondX != LogicMovementNoMovement){
LogicRawMovementUnknownDirectionFixedSpeed(TileData->LogicData.BackGround.StagePositionX, EventTemporaryScreenMovementData->PixelMovementPerSecondX, 
EventScreenMovementData->FinalPositionX, {EventTemporaryScreenMovementData->PixelMovementPerSecondX = LogicMovementNoMovement;});
}
if(EventTemporaryScreenMovementData->PixelMovementPerSecondY != LogicMovementNoMovement){
LogicRawMovementUnknownDirectionFixedSpeed(TileData->LogicData.BackGround.StagePositionY, EventTemporaryScreenMovementData->PixelMovementPerSecondY, 
EventScreenMovementData->FinalPositionY, {EventTemporaryScreenMovementData->PixelMovementPerSecondY = LogicMovementNoMovement;});
}

if(EventTemporaryScreenMovementData->PixelMovementPerSecondX != LogicMovementNoMovement && EventTemporaryScreenMovementData->PixelMovementPerSecondY == LogicMovementNoMovement){
EventFinalize((*EventTemporaryBufferPointer));
ReturnValue = EventSubEventFinished;
}
else ReturnValue = EventSubEventGoesOn;

return(ReturnValue);
}



uint8 EventNewEvent(EventFunctionArguments){
EventInitialize();
HandleSingleEvent(&TileData->ActiveEventData[TileEventActivate(TileData, (EventStruct*)EventBufferPointer, PlayerMain)], TileData, OverWorldData);
return(EventSubEventInitiateLoop);
}


uint8 ForceTransformationData(EventFunctionArguments){

ForceTransformationDataStruct* ForceTransformationDataData;
ForceTransformationDataData = (ForceTransformationDataStruct*)EventBufferPointer;
EventInitialize();

if(ForceTransformationDataData->WhichTransformationData == ForceTransformationDataGeneral){
CombineTransformationData(&TileData->LogicData.General.TransformationData, &ForceTransformationDataData->TransformationData);
}
else if(ForceTransformationDataData->WhichTransformationData == ForceTransformationDataBackGroundGeneral){
CombineTransformationData(&TileData->LogicData.BackGround.TransformationData, &ForceTransformationDataData->TransformationData);
}
else if(ForceTransformationDataData->WhichTransformationData == ForceTransformationDataBackGroundSpecific){
CombineTransformationData(&TileData->BackGroundHeaderData[ForceTransformationDataData->WhichObjectExactly].Instance[ForceTransformationDataData->WhichInstanceExactly].LogicData.TransformationData, &ForceTransformationDataData->TransformationData);
}

return(EventSubEventInitiateLoop);
}



uint8 EventZoom(EventFunctionArguments){

uint8 ReturnValue;
EventZoomStruct* EventZoomData;
EventZoomTemporaryStruct* EventZoomTemporaryData;

EventZoomData = (EventZoomStruct*)EventBufferPointer;
if((*EventTemporaryBufferPointer) == NULL){
EventInitialize();
(*EventTemporaryBufferPointer) = (void*)malloc(sizeof(EventZoomTemporaryStruct));
EventZoomTemporaryData = (EventZoomTemporaryStruct*)(*EventTemporaryBufferPointer);
SetTransformationDataPositionVector((&TileData->LogicData.General.TransformationData), EventZoomData->PositionX, EventZoomData->PositionY, EventZoomData->PositionZ);
if(!TransformationDataIsZooming((&TileData->LogicData.General.TransformationData))){StartZoomingAdvanced((&TileData->LogicData.General.TransformationData), NormalSizeScaleValue);}
else printf("Warning: TransformationDataResettingActivePositionVector!\n");
if(GetScaleValue((&TileData->LogicData.General.TransformationData)) >= EventZoomData->ScaleValueEnd) EventZoomTemporaryData->ScaleChangePerSecond = EventZoomData->ScaleChangePerSecond;
else EventZoomTemporaryData->ScaleChangePerSecond = -EventZoomData->ScaleChangePerSecond;
}
else EventZoomTemporaryData = (EventZoomTemporaryStruct*)(*EventTemporaryBufferPointer);

ReturnValue = EventSubEventGoesOn;
LogicScaleUnknownDirectionFixedSpeed((&TileData->LogicData.General.TransformationData), EventZoomTemporaryData->ScaleChangePerSecond, EventZoomData->ScaleValueEnd, 
{
EventFinalize((*EventTemporaryBufferPointer));
ReturnValue = EventSubEventFinished;
}
);

return(ReturnValue);
}


#define EventFunctionAmount	9
uint8 (*EventFunction[EventFunctionAmount])() = 
{
ManipulateStoryFlag, EventChangeAnimation, ExitTile, MoveScreen, EventNewEvent, EventZoom, EventSpeech, EventSpeechDynamic, EventFightStart
};

