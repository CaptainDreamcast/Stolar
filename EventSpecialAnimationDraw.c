void EventSpecialAnimationDraw(EventSpecialAnimationActualStruct* EventSpecialAnimationActualData, TransformationStruct* TransformationData){

vector_t FInalVector[PolygonCornerAmount];

SetupVectors(FinalVector, EventSpecialAnimationActualData->PositionVector.x, EventSpecialAnimationActualData->PositionVector.y, EventSpecialAnimationActualData->PositionVector.z, EventSpecialAnimationActualData->SizeX, EventSpecialAnimationActualData->SizeY);

if(TransformationData != NULL) Transformation(FinalVector, TransformationData);


DrawVectorTexture(
FinalVector, EventSpecialAnimationActualData->Texture[EventSpecialAnimationActualData->CurrentFrame], PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
EventSpecialAnimationActualData->TextureSizeX, 
EventSpecialAnimationActualData->TextureSizeY, 
EventSpecialAnimationActualData->AlphaValue, 1.0f, 1.0f, 1.0f,
EventSpecialAnimationActualData->Left, EventSpecialAnimationActualData->Right, EventSpecialAnimationActualData->Up, EventSpecialAnimationActualData->Down);



EventSpecialAnimationActualData->Ticks++;
if(EvenEventSpecialAnimationActualData->Duration != 0 && EventSpecialAnimationActualData->Ticks >= EvenEventSpecialAnimationActualData->Duration) EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Type = EventSpecialAnimationTypeInActive;
else if(EventSpecialAnimationActualData->Speed != 0 && (EventSpecialAnimationActualData->Ticks % EventSpecialAnimationActualData->Speed == 0)){
EventSpecialAnimationActualData->CurrentFrame++;
if(EventSpecialAnimationActualData->CurrentFrame >= EventSpecialAnimationActualData->FrameAmount){
EventSpecialAnimationActualData->CurrentFrame = 0;
}
}

EventSpecialAnimationActualData->PositionVector.x += EventSpecialAnimationActualData->MovementX;
EventSpecialAnimationActualData->PositionVector.y += EventSpecialAnimationActualData->MovementY;
}

