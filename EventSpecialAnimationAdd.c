uint8 EventSpecialAnimationAdd(
EventSpecialAnimationStruct* EventSpecialAnimationData, uint8 NewType, uint8 NewDraw, uint16 NewIdentifier, uint16 NewSpeed, uint16 NewCurrentFrame, uint16 NewFrameAmount, 
uint16 NewTicks, uint16 NewDuration, uint16 NewTextureSizeX, uint16 NewTextureSizeY, float NewMovementX, float NewMovementY, float NewUp, float NewLeft, float NewDown, float NewRight, 
float NewScaleValue, float NewAlphaValue, float NewSizeX, float NewSizeY, float NewPositionX, float NewPositionY, float NewPositionZ, pvr_ptr_t NewTexturePointer){

uint8 DirtyDeedsDoneDirtCheap, ReturnValue;

ReturnValue = 0;
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EventSpecialAnimationData->EventSpecialAnimationAmount; DirtyDeedsDoneDirtCheap++){
if(!EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Type){
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Type = NewType;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Draw = NewDraw;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Identifier = NewIdentifier;

EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Speed = NewSpeed;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].CurrentFrame = NewCurrentFrame ;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].FrameAmount = NewFrameAmount ;

EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Ticks = NewTicks;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Duration = NewDuration;

EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].TextureSizeX = NewTextureSizeX;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].TextureSizeY = NewTextureSizeY;

EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].MovementX = NewMovementX;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].MovementY = NewMovementY;

EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Up = NewUp;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Left = NewLeft;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Down = NewDown;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].Right = NewRight;

EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].ScaleValue = NewScaleValue;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].AlphaValue = NewAlphaValue;

EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].SizeX = NewSizeX;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].SizeY = NewSizeY;

EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].PositionVector.x = NewPositionX;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].PositionVector.y = NewPositionY;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].PositionVector.z = NewPositionZ;
EventSpecialAnimationData->ActualData[DirtyDeedsDoneDirtCheap].TexturePointer = NewTexturePointer;

ReturnValue = DirtyDeedsDoneDirtCheap;
DirtyDeedsDoneDirtCheap = EventSpecialAnimationData->EventSpecialAnimationAmount+1;
}
else if(DirtyDeedsDoneDirtCheap == EventSpecialAnimationData->EventSpecialAnimationAmount-1){
EventSpecialAnimationData->ActualData = (EventSpecialAnimationActualStruct*)(realloc(EventSpecialAnimationData->ActualData, sizeof(EventSpecialAnimationActualStruct)*(EventSpecialAnimationData->EventSpecialAnimationAmount+1)));
EventSpecialAnimationData->ActualData[EventSpecialAnimationData->EventSpecialAnimationAmount].Type = 0;
EventSpecialAnimationData->EventSpecialAnimationAmount++;
}

}

return(ReturnValue);
}