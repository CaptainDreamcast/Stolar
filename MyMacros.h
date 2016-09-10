#define ChangeAnimationBasic(CurrentAnimation, NewAnimation, CurrentFrame, NewFrame, Ticks, NewTicks, EventInducedLoopVariable, EventInducedLoopValue)	{ \
CurrentAnimation = NewAnimation; \
CurrentFrame = NewFrame; \
Ticks = NewTicks; \
EventInducedLoopVariable = EventInducedLoopValue; \
}
#define ChangeAnimationCrankArtificialIntelligence(Struct, NewAnimation, NewFrame, NewTicks, EventInducedLoopValue)	ChangeAnimationBasic(Struct.Loadable->CurrentAnimation, NewAnimation, Struct.Loadable->CurrentFrame, NewFrame, Struct.LogicData.Ticks, NewTicks, Struct.Loadable->EventInducedLoop, EventInducedLoopValue)
#define ChangeAnimationSimplestArtificialIntelligence(Struct, NewAnimation)	ChangeAnimationBasic(Struct.Loadable->CurrentAnimation, NewAnimation, Struct.Loadable->CurrentFrame, NewFrameStandardValue, Struct.LogicData.Ticks, NewTicksStandardValue, Struct.Loadable->EventInducedLoop, EventInducedLoopValueNot)
#define ChangeAnimationCrank(Location, WhichAnimation, StartFrame, StartTicks, EventInducedLoopValue) 	ChangeAnimationBasic(Location.CurrentAnimation, WhichAnimation, Location.CurrentFrame, StartFrame, Location.Ticks, StartTicks, Location.EventInducedLoop, EventInducedLoopValue)
#define ChangeAnimationSimple(Location, WhichAnimation) 	ChangeAnimationCrank(Location, WhichAnimation, NewFrameStandardValue, NewTicksStandardValue, EventInducedLoopValueNot)
#define StolarChangeAnimation(Location, WhichAnimation, StartFrame, StartTicks, EventInducedLoopValue); ChangeAnimationCrank(Location, WhichAnimation, StartFrame, StartTicks, EventInducedLoopValue);
#define StolarChangeAnimationSimple(Location, WhichAnimation); StolarChangeAnimation(Location, WhichAnimation, 0, 0, EventInducedLoopValueNot);
#define StolarChangeAnimationAdvanced(WhichAnimation, StartFrame); StolarChangeAnimation(StolarFightData, WhichAnimation, StartFrame, 0, EventInducedLoopValueNot);
#define StolarChangeAnimationSimplest(WhichAnimation); StolarChangeAnimation(StolarFightData, WhichAnimation, 0, 0, EventInducedLoopValueNot);
#define StolarChangeOverWorldAnimationSimplest(WhichAnimation); StolarChangeAnimation(TileData->LogicData.Stolar, WhichAnimation, 0, 0, EventInducedLoopValueNot);
#define StolarChangeFightAnimationSimplest(WhichAnimation); StolarChangeAnimation(FightData->LogicData.Stolar, WhichAnimation, 0, 0, EventInducedLoopValueNot);

#define TileChangeAnimationBasic(CurrentAnimation, NewAnimation, CurrentFrame, NewFrame, Ticks, NewTicks)	{ \
CurrentAnimation = NewAnimation; \
CurrentFrame = NewFrame; \
Ticks = NewTicks; \
}
#define FightChangeAnimationBasic(CurrentAnimation, NewAnimation, CurrentFrame, NewFrame, Ticks, NewTicks)		TileChangeAnimationBasic(CurrentAnimation, NewAnimation, CurrentFrame, NewFrame, Ticks, NewTicks)

#define TileObjectChangeAnimationSimplest(Struct, NewAnimation)				TileChangeAnimationBasic(Struct.Loadable->CurrentAnimation, NewAnimation, Struct.Loadable->CurrentFrame, NewFrameStandardValue, Struct.LogicData.Ticks, NewTicksStandardValue)
#define TilePlayerChangeAnimationSimplest(WhichPlayer, WhichAnimation)		TileObjectChangeAnimationSimplest(TileData->ObjectData[TileData->PlayerData[WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[WhichPlayer].LogicData.WhichInstance], WhichAnimation)
#define FightObjectChangeAnimationSimplest(Struct, NewAnimation)				FightChangeAnimationBasic(Struct.Loadable->CurrentAnimation, NewAnimation, Struct.Loadable->CurrentFrame, NewFrameStandardValue, Struct.LogicData.Ticks, NewTicksStandardValue)
#define FightPlayerChangeAnimationSimplest(WhichPlayer, WhichAnimation)		TileObjectChangeAnimationSimplest(FightData->ObjectData[FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject].Instance[FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance], WhichAnimation)
#define FightObjectChangeAnimationSimple(Struct, NewAnimation, NewFrame)	FightChangeAnimationBasic(Struct.Loadable->CurrentAnimation, NewAnimation, Struct.Loadable->CurrentFrame, NewFrame, Struct.LogicData.Ticks, NewTicksStandardValue)

#define SetSingleVector(FinalVector, ValueX, ValueY, ValueZ); {FinalVector.x = ValueX; FinalVector.y = ValueY; FinalVector.z = ValueZ; FinalVector.w = StandardValueW;}

#define SetTransformationDataPositionVector(TransformationData, ValueX, ValueY, ValueZ)	SetSingleVector(TransformationData->PositionVector, ValueX, ValueY, ValueZ)
#define GetScaleValue(TransformationData) 	GetScaleValueX(TransformationData)
#define GetScaleValueX(TransformationData) 	(TransformationData->ScaleValueX)
#define GetScaleValueY(TransformationData) 	(TransformationData->ScaleValueY)
#define GetRotationValueX(TransformationData)		(TransformationData->RotationValueX)
#define GetRotationValueY(TransformationData)		(TransformationData->RotationValueY)
#define GetRotationValueZ(TransformationData)		(TransformationData->RotationValueZ)
#define SetScaleValueAdvanced(TransformationData, ZoomFactor); {TransformationData->ScaleValueX = TransformationData->ScaleValueY = ZoomFactor;}
#define SetScaleValuePlusAdvanced(TransformationData, ZoomFactorX, ZoomFactorY); {TransformationData->ScaleValueX = ZoomFactorX; TransformationData->ScaleValueY = ZoomFactorY;}
#define SetRotationValueAdvancedX(TransformationData, RotationFactor)	{TransformationData->RotationValueX = RotationFactor;}
#define SetRotationValueAdvancedY(TransformationData, RotationFactor)	{TransformationData->RotationValueY = RotationFactor;}
#define SetRotationValueAdvancedZ(TransformationData, RotationFactor)		{TransformationData->RotationValueZ = RotationFactor;}
#define StartZoomingAdvanced(TransformationData, ZoomFactor); {TransformationData->Active |= ZoomInIdentifier; SetScaleValueAdvanced(TransformationData, ZoomFactor);}
#define StartRotationXAdvanced(TransformationData, RotationFactor); {TransformationData->Active |= RotateXIdentifier; SetRotationValueAdvancedX(TransformationData, RotationFactor);}
#define StartRotationYAdvanced(TransformationData, RotationFactor); {TransformationData->Active |= RotateYIdentifier; SetRotationValueAdvancedY(TransformationData, RotationFactor);}
#define StartRotationZAdvanced(TransformationData, RotationFactor); {TransformationData->Active |= RotateZIdentifier;SetRotationValueAdvancedZ(TransformationData, RotationFactor);}
#define StartZoomingPlusAdvanced(TransformationData, ZoomFactorX, ZoomFactorY); {TransformationData->Active |= ZoomInIdentifier; TransformationData->ScaleValueX = ZoomFactorX; TransformationData->ScaleValueY = ZoomFactorY;}
#define StartZooming(ZoomFactor) StartZoomingAdvanced(TransformationData, ZoomFactor)
#define StartRotationX(RotationFactor) StartRotationXAdvanced(TransformationData, RotationFactor)
#define StartRotationY(RotationFactor) StartRotationXAdvanced(TransformationData, RotationFactor)
#define StartRotationZ(RotationFactor) StartRotationXAdvanced(TransformationData, RotationFactor)
#define TransformationDataIsZooming(TransformationData)	(TransformationData->Active & ZoomInIdentifier)

#define DeActivateTransformationData(TransformationData)	{TransformationData->Active = 0;}
#define InitiateTransformationData(TransformationData)		DeActivateTransformationData(TransformationData)
#define InitiateTransformationDataWithPosition(TransformationData, ValueX, ValueY, ValueZ)	{ \
InitiateTransformationData(TransformationData); \
SetTransformationDataPositionVector(TransformationData, ValueX, ValueY, ValueZ); \
}

#define ColorToFloats(CurrentColor, Red, Green, Blue); { \
if(CurrentColor == WhiteColor){Red = Green = Blue = 1.0f;} \
else if(CurrentColor == RedColor){Red = 1.0f; Green = Blue = 0.0f;} \
else if(CurrentColor == GreenColor){Green = 1.0f; Red = Blue = 0.0f;} \
else if(CurrentColor == BlueColor){Red = Green = 0.0f; Blue = 1.0f;} \
else if(CurrentColor == YellowColor){Red = Green = 1.0f; Blue = 0.0f;} \
else{Red = Green = Blue = 0.0f;} \
}

#define SetupVectorAdvanced(FinalVector, UpLeftX, UpLeftY, UpRightX, UpRightY, DownLeftX, DownLeftY, DownRightX, DownRightY, PositionZ); { \
SetSingleVector(FinalVector[0],  UpLeftX, UpLeftY, PositionZ); \
SetSingleVector(FinalVector[1],  UpRightX, UpRightY, PositionZ); \
SetSingleVector(FinalVector[2],  DownLeftX, DownLeftY, PositionZ); \
SetSingleVector(FinalVector[3],  DownRightX, DownRightY, PositionZ); \
}


#define StolarAnimate(StolarFightData) { \
\
AnimationFactor = StolarFightData->AnimationFactor; \
\
if(AnimationFactor < 1.0f){ \
StolarFightData->AnimationFactor += StolarFightData->FactorBuildUp; \
if(StolarFightData->AnimationFactor >= 1.0f){ \
StolarFightData->AnimationFactor = 0.0f; \
AnimationFactor = 1.0f; \
} \
} \
\
if(AnimationFactor >= 1.0f){ \
do{ \
StolarFightData->AnimationTicks++; \
if(StolarFightData->AnimationTicks >= StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].Speed){ \
\
StolarFightData->AnimationTicks = 0; \
StolarFightData->CurrentFrame++; \
if(StolarFightData->CurrentFrame >= StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureAmount){ \
\
StolarFightData->CurrentAnimation = StolarIdleAnimationRight+StolarFightData->FaceDirection; \
StolarFightData->CurrentFrame = 0; \
} \
} \
AnimationFactor-=1.0f; \
} while(AnimationFactor > 0.0f); \
} \
\
}



#define StageAnimate(CurrentFrame, Ticks, OriginalAnimationFactor, FactorBuildUp, TextureAmount, Speed, OuterLoop, InnerLoop) { \
\
OuterLoop{ \
AnimationFactor = OriginalAnimationFactor; \
\
if(AnimationFactor < 1.0f){ \
OriginalAnimationFactor += FactorBuildUp; \
if(OriginalAnimationFactor >= 1.0f){ \
OriginalAnimationFactor = 0.0f; \
AnimationFactor = 1.0f; \
} \
} \
\
if(AnimationFactor >= 1.0f){ \
do{ \
\
\
InnerLoop{ \
if(TextureAmount > 1){ \
\
\
\
Ticks++; \
if(Ticks >= Speed){ \
 \
Ticks = 0; \
CurrentFrame++; \
if(CurrentFrame >= TextureAmount){ \
\
CurrentFrame = 0; \
\
} \
} \
\
} \
} \
\
AnimationFactor-=1.0f; \
} while(AnimationFactor > 0.0f); \
} \
\
} \
}



#define EnemiesAnimate(EnemyAmount, EnemyFightData, EnemyAnimationData) { \
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<EnemyAmount; DirtyDeedsDoneDirtCheap++){ \
\
AnimationFactor = EnemyFightData->AnimationFactor; \
\
if(AnimationFactor < 1.0f){ \
EnemyFightData->AnimationFactor += EnemyFightData->FactorBuildUp; \
if(EnemyFightData->AnimationFactor >= 1.0f){ \
EnemyFightData->AnimationFactor = 0.0f; \
AnimationFactor = 1.0f; \
} \
} \
\
if(AnimationFactor >= 1.0f){ \
do{ \
EnemyFightData->AnimationTicks++; \
if(EnemyFightData->AnimationTicks >= EnemyAnimationData[EnemyFightData->CurrentAnimation].Speed){ \
\
EnemyFightData->AnimationTicks = 0; \
EnemyFightData->CurrentFrame++; \
if(EnemyFightData->CurrentFrame >= EnemyAnimationData[EnemyFightData->CurrentAnimation].TextureAmount){ \
\
EnemyFightData->CurrentAnimation = EnemyIdleAnimation; \
EnemyFightData->CurrentFrame = 0; \
\
} \
} \
AnimationFactor-=1.0f; \
} while(AnimationFactor > 0.0f); \
} \
} \
\
\
}

#define 	SetControllerToDummy(st)	st=&DummyControllerState;

#define DisableActiveEvent(ActiveEventData);	{ \
ActiveEventData->LogicData.WhichEvent = InvalidEventIdentifier; \
ActiveEventData->LogicData.EventBufferSize = 0; \
ActiveEventData->EventBufferPosition = NULL; \
ActiveEventData->EventBufferStart = NULL; \
ActiveEventData->EventTemporaryBuffer = NULL; \
}

#define CopyOverTransformationData(TransformationDataPointer, NewTransformationDataPointer);	memcpy4(TransformationDataPointer, NewTransformationDataPointer, sizeof(TransformationStruct));

#define EventTransformToSomethingCheck(TransformToWhatRawPointer, TransformToWhatExactlyRawPointer, BackUpValuesRawPointer);	{ \
if(*((uint8*)(TransformToWhatRawPointer)) == EventTransformToStolar){ \
TransformationData->PositionVector.x = StolarOverWorldData->PositionX; \
TransformationData->PositionVector.y = StolarOverWorldData->PositionY; \
TransformationData->PositionVector.z = StolarOverWorldData->ScreenPositionZ; \
} \
else if(*((uint8*)(TransformToWhatRawPointer)) == EventTransformToPerson){ \
TransformationData->PositionVector.x = TileData->PersonData[*((uint8*)(TransformToWhatExactlyRawPointer))].Loadable->PositionX; \
TransformationData->PositionVector.y = TileData->PersonData[*((uint8*)(TransformToWhatExactlyRawPointer))].Loadable->PositionY; \
TransformationData->PositionVector.z = TileData->PersonData[*((uint8*)(TransformToWhatExactlyRawPointer))].Loadable->ScreenPositionZ; \
} \
else if(BackUpValuesRawPointer != NULL){ \
TransformationData->PositionVector.x = *((float*)(BackUpValuesRawPointer)); \
TransformationData->PositionVector.y = *((float*)(BackUpValuesRawPointer+sizeof(float))); \
TransformationData->PositionVector.z = *((float*)(BackUpValuesRawPointer+(sizeof(float)*2))); \
} \
 \
} 

#define DereferencePointerToType(Type, Pointer)		(*((Type*)(Pointer)))
#define ConvertPointerToType(Type, Pointer)			((Type*)(Pointer))

#define OverWorldDrawEveryThingStandardAndAnimate(TransformationData, AnimationFlags)	{ \
pvr_scene_begin(); \
pvr_list_begin(PVR_LIST_TR_POLY); \
 \
DrawOverWorldBackGround(TileData, TransformationData); \
DrawStolar(StolarOverWorldData->StolarTexture[StolarOverWorldData->StolarAnimationData[StolarOverWorldData->CurrentAnimation].TextureOffset+StolarOverWorldData->CurrentFrame], StolarOverWorldData->PositionX, StolarOverWorldData->PositionY, StolarOverWorldData->ScreenPositionZ, StolarOverWorldData->SizeX, StolarOverWorldData->SizeY, TransformationData); \
DrawOverWorldPeople(TileData, TransformationData); \
DrawOverWorldEnemies(TileData, OverWorldInterFaceData,  TransformationData); \
 \
pvr_list_finish(); \
pvr_scene_finish(); \
 \
OverWorldAnimate(TileData, StolarOverWorldData, AnimationFlags); \
}

#define CheckControllerValidity(st, cont, port, ReturnValue, ReturnValueValue)	{ \
 \
if((cont = maple_enum_dev(port, 0)) == NULL){ \
ReturnValue = ReturnValueValue; \
SetControllerToDummy(st); \
} \
else st = (cont_state_t *)maple_dev_status(cont); \
 \
}

#define CheckControllerValidityWithoutSet(st, cont, port)	{ \
 \
if((cont = maple_enum_dev(port, 0)) == NULL){ \
SetControllerToDummy(st); \
} \
else st = (cont_state_t *)maple_dev_status(cont); \
 \
}

#define CheckFlagGeneral(Flags, WhichFlag)		(Flags[((WhichFlag)/BitsPerByte)] & (LeftMostBitInByte>>((WhichFlag)%BitsPerByte)))
#define CheckFlagSpecialEnemy(WhichEnemy)		CheckFlagGeneral(SaveData.CompressableData->SpecialEnemyFlags, WhichEnemy)
#define CheckFlagStory(WhichFlag)					CheckFlagGeneral(SaveData.CompressableData->StoryFlags, WhichFlag)


#define InitiateSingleActiveEvent(ActiveEventData, ArrayPosition)	{ \
ActiveEventData[ArrayPosition].LogicData.WhichEvent = 0; \
ActiveEventData[ArrayPosition].LogicData.EventBufferSize = 0; \
}

#define InitiateSingleEventSpecialAnimationActualData(ActualData, ArrayPosition)	{ \
ActualData[ArrayPosition].Type = EventSpecialAnimationTypeInActive; \
}

#define EventInitialize()	{ \
 \
}

#define EventFinalize(EventTemporaryBufferPointer)	{ \
if(!IsNullified(EventTemporaryBufferPointer)){Nullify(EventTemporaryBufferPointer);} \
}

#define CheckInvalidFileHandler(InputFile, FileDir)	{ \
if(InputFile == FILEHND_INVALID) { \
printf("\nInvalid FileHandler\n\nFileDir: (%s)\n", FileDir); \
arch_menu(); \
} \
}

#define ReFudgealizeStolarOverWorldStruct(NewPositionX, NewPositionY, NewSizeX, NewSizeY, NewSpeedX, NewSpeedY, NewCurrentAnimation, NewCurrentFrame, NewAnimationTicks, NewAnimationFactor, NewFactorBuildUp, NewFaceDirection, NewEventInducedLoop, NewStagePositionZ, NewScreenPositionZ) { \
StolarOverWorldData->PositionX = NewPositionX; \
StolarOverWorldData->PositionY = NewPositionY; \
StolarOverWorldData->SizeX = NewSizeX; \
StolarOverWorldData->SizeY = NewSizeY; \
StolarOverWorldData->SpeedX = NewSpeedX; \
StolarOverWorldData->SpeedY = NewSpeedY; \
StolarOverWorldData->CurrentAnimation = NewCurrentAnimation; \
StolarOverWorldData->CurrentFrame = NewCurrentFrame; \
StolarOverWorldData->AnimationTicks = NewAnimationTicks; \
StolarOverWorldData->AnimationFactor = NewAnimationFactor; \
StolarOverWorldData->FactorBuildUp = NewFactorBuildUp; \
StolarOverWorldData->FaceDirection = NewFaceDirection; \
StolarOverWorldData->EventInducedLoop = NewEventInducedLoop; \
StolarOverWorldData->StagePositionZ = NewStagePositionZ; \
StolarOverWorldData->ScreenPositionZ = NewScreenPositionZ; \
}




#define FetchStolarOverWorldTopLeftPositionX(StolarOverWorldData)		(StolarOverWorldData->PositionX-(StolarOverWorldData->SizeX/2))
#define FetchStolarOverWorldTopLeftPositionY(StolarOverWorldData)		(StolarOverWorldData->PositionY-StolarOverWorldData->SizeY)

#define ButtonPressedA(st)		(st->buttons & CONT_A)
#define ButtonPressedB(st)		(st->buttons & CONT_B)
#define ButtonPressedX(st)		(st->buttons & CONT_X)
#define ButtonPressedY(st)		(st->buttons & CONT_Y)
#define ButtonPressedL(st)		(st->ltrig)
#define ButtonPressedR(st)		(st->rtrig)
#define ButtonPressedLeft(st)	((st->buttons & CONT_DPAD_LEFT) || (st->joyx <= -64))
#define ButtonPressedRight(st)	((st->buttons & CONT_DPAD_RIGHT) || (st->joyx >= 64))
#define ButtonPressedUp(st)		((st->buttons & CONT_DPAD_UP) || (st->joyy <= -64))
#define ButtonPressedDown(st)	((st->buttons & CONT_DPAD_DOWN) || (st->joyy >= 64))
#define ButtonPressedStart(st)	(st->buttons & CONT_START)
#define ButtonPressedAny(st)	((st->buttons) || (st->joyx) || (st->joyy))

#define ButtonLegit(WhichButton, ButtonInputData)	 (ButtonInputData[WhichButton].ButtonIsLegit)

#define GoHomeValueYouAreDrunk(PositionX, FinalPositionX, SpeedX)  { \
if(PositionX < FinalPositionX){ \
PositionX += SpeedX; \
if(PositionX >= FinalPositionX) PositionX = FinalPositionX; \
} \
else if(PositionX > FinalPositionX){ \
PositionX -=SpeedX; \
if(PositionX <= FinalPositionX) PositionX = FinalPositionX; \
} \
}

#define CopyMemory(To, From, Size)		memcpy4(To, From, Size)

#define Nullify(Pointer)	{free(Pointer); Pointer = NULL;}
#define IsNullified(Pointer)	(Pointer == NULL)

#define LoadGameDeActivateVisualMemoryData(WhichData) { \
WhichData.Active = 0; \
if(WhichData.SingleSaveData != NULL) Nullify(WhichData.SingleSaveData); \
}

#define LoadGameFindNewPort(WhichPort, WhichSlot, SpecialOptionSelected, NewPort) { \
NewPort = WhichPort; \
while(WhichPort != LoadGameWhichPortUnavailable && (!LoadScreenControllerData[NewPort].Active || (!LoadScreenControllerData[NewPort].LoadScreenVisualMemoryData[FirstVisualMemory].Active && !LoadScreenControllerData[NewPort].LoadScreenVisualMemoryData[SecondVisualMemory].Active))){ \
NewPort = ((NewPort+1)%DreamcastControllerAmount); \
if(NewPort == WhichPort){ \
WhichPort = LoadGameWhichPortUnavailable; \
WhichSlot = LoadGameWhichSlotUnavailable; \
if(SpecialOptionSelected == LoadGameSpecialOptionUnSelected) SpecialOptionSelected = LoadGameSpecialOptionNewGame; \
} \
} \
if(WhichPort != LoadGameWhichPortUnavailable && !LoadScreenControllerData[NewPort].LoadScreenVisualMemoryData[WhichSlot].Active) WhichSlot = ((WhichSlot+1)%VisualMemoryPerController); \
}

#define LoadTextureFromBufferPointer(CurrentPointerPosition, Texture) { \
Texture = pvr_mem_malloc(((kmg_header_t*)CurrentPointerPosition)->byte_count); \
TextureLoadBuffer((void*)(CurrentPointerPosition+sizeof(kmg_header_t)), &Texture, (int*)(&(((kmg_header_t*)CurrentPointerPosition)->width)), (int*)(&(((kmg_header_t*)CurrentPointerPosition)->height)), (int*)(&(((kmg_header_t*)CurrentPointerPosition)->byte_count)), NoAllocateTextureMemory); \
LoadTextureFromBufferPointerSkip(CurrentPointerPosition, Texture); \
}
#define LoadTextureFromBufferPointerSkip(CurrentPointerPosition, Texture) { \
CurrentPointerPosition += sizeof(kmg_header_t)+(((kmg_header_t*)CurrentPointerPosition)->byte_count); \
LoadCurrentPointerPositionSetToLegalStartValue(); \
}


#define LoadSoundEffectFromBufferPointer(CurrentPointerPosition, SoundEffect) { \
SoundEffect = snd_sfx_load_buffer((void*)CurrentPointerPosition); \
CurrentPointerPosition += (*((uint32*)(CurrentPointerPosition+WaveFileHeaderLengthPosition)))+WaveFileHeaderLengthAddition; \
LoadCurrentPointerPositionSetToLegalStartValue(); \
}


#define LoadBufferFromBufferPointer(Type, Variable, Size)	{ \
Variable = (Type)malloc(Size); \
CopyMemory(Variable, (void*)CurrentPointerPosition, Size); \
LoadBufferFromBufferPointerSkip(Type, Variable, Size); \
}
#define LoadBufferFromBufferPointerSkip(Type, Variable, Size)	{ \
CurrentPointerPosition += Size; \
LoadCurrentPointerPositionSetToLegalStartValue(); \
}

#define LoadCurrentPointerPositionSetToLegalStartValue()	{ \
while(CurrentPointerPosition%LoadCurrentPointerPositionLegalStartValue) CurrentPointerPosition++; \
}

#define TileLoadFlagsNoLegalStart(FlagData)		{ \
CurrentPointerPosition = TileLoadFlagsLoad(CurrentPointerPosition, &FlagData); \
}

#define TileLoadFlagsDummyTrue(FlagData)		{ \
TileLoadFlagsLoadDummyTrue(CurrentPointerPosition, &FlagData); \
}

#define TileLoadFlagsDummyFalse(FlagData)		{ \
TileLoadFlagsLoadDummyFalse(CurrentPointerPosition, &FlagData); \
}

#define TileLoadFlags(FlagData)		{ \
TileLoadFlagsNoLegalStart(FlagData); \
LoadCurrentPointerPositionSetToLegalStartValue(); \
}

#define TileDeLoadFlags(FlagData)	{ \
TileDeLoadFlagsDeLoad(&FlagData); \
}

#define TileDrawResetAnimation(CurrentAnimation)	{ \
CurrentAnimation = TileDrawAnimationReset; \
} \

#define FightDrawResetAnimation(CurrentAnimation)	{ \
CurrentAnimation = FightDrawAnimationReset; \
} \

#define FreeTexture(Texture)				pvr_mem_free(Texture)
#define FreeSoundEffect(SoundEffect)	snd_sfx_unload(SoundEffect)

#define LoadSetThisToThatPointer(Type, Variable, Size)	PreOverWorldLoadSetThisToThatPointer(Type, Variable, Size)

#define PreOverWorldLoadSetThisToThatPointer(Type, Variable, Size)	{ \
Variable = (Type)CurrentPointerPosition; \
CurrentPointerPosition+=Size; \
}


#define InitializeSaveData() { \
SaveData.LoadedTime = timer_ms_gettime64(); \
}

#define CheckSingleControllerLegitimacy(ButtonInputData, ButtonPressed) { \
if(ButtonInputData.ButtonIsLegit) ButtonInputData.ButtonIsLegit = 0; \
 \
if(ButtonInputData.ButtonInputAllowed && ButtonPressed){ \
ButtonInputData.ButtonIsLegit = 1; \
ButtonInputData.ButtonInputAllowed = 0; \
} \
else if(!ButtonInputData.ButtonInputAllowed && !ButtonPressed) ButtonInputData.ButtonInputAllowed = 1; \
}

#define ResetButtonInputData(ButtonInputData, DirtyDeedsDoneDirtCheap)	{ \
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<ButtonAmount; DirtyDeedsDoneDirtCheap++){ \
ButtonInputData[DirtyDeedsDoneDirtCheap].ButtonInputAllowed = 0; \
ButtonInputData[DirtyDeedsDoneDirtCheap].ButtonIsLegit = 0; \
} \
}

#define OverWorldMenuActivateHand(OverWorldMenuData, WhichSwipe, PositionX)	{ \
OverWorldMenuData->BackGroundData.HandFrame = 0; \
OverWorldMenuData->BackGroundData.HandPositionX = PositionX; \
OverWorldMenuData->BackGroundData.HandActive = WhichSwipe; \
}

#define SetupTransformAndDrawReverseSimplest(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List, Reverse)		SetupTransformAndDrawPlusPlus(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue, FullSmallTexturePosition, FullBigTexturePosition, FullSmallTexturePosition, FullBigTexturePosition, {DrawVectorTextureCheckReverse(FinalVector, Texture, Format, List, TextureSizeX, TextureSizeY, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue, FullSmallTexturePosition, FullBigTexturePosition, FullSmallTexturePosition, FullBigTexturePosition, Reverse);})
#define SetupTransformAndDrawReversePlus(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List, Alpha, Red, Green, Blue, Left, Right, Up, Down, Reverse)		SetupTransformAndDrawPlusPlus(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List, Alpha, Red, Green, Blue, Left, Right, Up, Down, {DrawVectorTextureCheckReverse(FinalVector, Texture, Format, List, TextureSizeX, TextureSizeY, Alpha, Red, Green, Blue, Left, Right, Up, Down, Reverse);})
#define SetupTransformAndDrawSimplest(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List) SetupTransformAndDrawPlus(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f)
#define SetupTransformAndDraw(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List, Alpha, Red, Green, Blue) SetupTransformAndDrawPlus(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List, Alpha, Red, Green, Blue, 0.0f, 1.0f, 0.0f, 1.0f)
#define SetupTransformAndDrawPlus(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List, Alpha, Red, Green, Blue, Left, Right, Up, Down)							SetupTransformAndDrawPlusPlus(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List, Alpha, Red, Green, Blue, Left, Right, Up, Down, {DrawVectorTexturePlus(FinalVector, Texture, Format, List, TextureSizeX, TextureSizeY, Alpha, Red, Green, Blue, Left, Right, Up, Down);})
#define SetupTransformAndDrawPlusPlus(FinalVector, TransformationData, Texture, PositionX, PositionY, PositionZ, SizeX, SizeY, TextureSizeX, TextureSizeY, Format, List, Alpha, Red, Green, Blue, Left, Right, Up, Down, DrawAction)	{ \
SetupVectors(FinalVector, PositionX, PositionY, PositionZ, SizeX, SizeY); \
Transformation(FinalVector, TransformationData); \
DrawAction \
}

#define CheckWhetherRectangleInRectangle(PositionX, PositionY, HalfSizeX, HalfSizeY, LeftBorder, RightBorder, UpperBorder, LowerBorder) ( \
(PositionX+HalfSizeX)  > LeftBorder && \
(PositionX-HalfSizeX)  < RightBorder && \
(PositionY+HalfSizeY)  > UpperBorder && \
(PositionY-HalfSizeY)  < LowerBorder \
)

#define OverWorldMenuDeActivateHand()	{ \
OverWorldMenuData->BackGroundData.HandActive = 0; \
OverWorldMenuData->BackGroundData.HandTouchedScreen = 0; \
}

#define StolarRegainHealth(HealthRegained)	{ \
StolarOverWorldData->StolarData->HealthNow+=HealthRegained; \
if(StolarOverWorldData->StolarData->HealthNow > StolarOverWorldData->StolarData->HealthMax) StolarOverWorldData->StolarData->HealthNow = StolarOverWorldData->StolarData->HealthMax; \
}

#define OverWorldMenuConfirmationModeInitialize(ConfirmationMode)	{ \
ConfirmationMode.Mode = OverWorldMenuConfirmationModeInActive; \
ConfirmationMode.Confirmed = OverWorldMenuConfirmationNo; \
}

#define OverWorldMenuMapScreenParseCurrentTileToCurrentPositionOnMapInRelation(OverWorldMenuData, TileData)	{ \
OverWorldMenuData->MapData.CurrentPositionOnMapInRelationX = TileData->TileHeaderData->TilePositionOnMapInRelationX; \
OverWorldMenuData->MapData.CurrentPositionOnMapInRelationY = TileData->TileHeaderData->TilePositionOnMapInRelationY; \
OverWorldMenuData->MapData.CurrentPositionOnMapInRelationCalculated = 1; \
}

#define OverWorldCurrentStolarTexture(StolarOverWorldData)	StolarOverWorldData->StolarTexture[StolarOverWorldData->StolarAnimationData[StolarOverWorldData->CurrentAnimation].TextureOffset+StolarOverWorldData->CurrentFrame]

#define OverWorldExitSet(OverWorldData)	{ \
OverWorldData->LogicData.General.LoopOverWorld = 0; \
OverWorldData->LogicData.General.ReturnStage = TitleScreenStage; \
}

#define SetVideoModeNeverForget(NewFrameRate, VideoMode)	{ \
FrameRate = NewFrameRate; \
vid_set_mode(VideoMode, StolarPixelMode); \
}

#define HertzSelectScreenParseSelectedOptionToReturnFrameRate(OptionSelected) (FiftyHertz+(OptionSelected*HertzDifference))

#define HertzParseSixtyHertzValue(Value)	((Value/SixtyHertz)*FrameRate)

#define StairWayToHeavenCheck(st, Action)	{ \
if((st->buttons & (StairWayToHeaven)) == (StairWayToHeaven)){ \
Action; \
} \
}

#define SoundEffectPlay(SoundEffect)	snd_sfx_play(SoundEffect, VolumeSFX, SoundPaddingValueStandard)

#define PrintVector(Vector, Name)	{ \
printf("\n"); \
printf(Name); \
printf("\n"); \
printf("x: (%f)\n", (double)Vector.x); \
printf("y: (%f)\n", (double)Vector.y); \
printf("z: (%f)\n", (double)Vector.z); \
}

#define IsPositive(x) 		(x >= 0)
#define IsNegative(x)		(x < 0)

#define LogicInvertSimple(Value)	((Value+1)%2)

#define LogicCounterInitiate(Ticks)		{ \
Ticks = 0; \
}

#define LogicCounter(Ticks, TimeInSeconds, Action)		{ \
Ticks++; \
if(Ticks >= (TimeInSeconds*FrameRate)){ \
Action; \
} \
}

#define LogicAlphaBuildUp(AlphaValue, TimeInSeconds, Action)		LogicAlphaGeneral(AlphaValue, TimeInSeconds, Action, +=, >=, FullColorFloatValue)
#define LogicAlphaBuildDown(AlphaValue, TimeInSeconds, Action)		LogicAlphaGeneral(AlphaValue, TimeInSeconds, Action, -=, <=, NoColorFloatValue)

#define LogicAlphaGeneral(AlphaValue, TimeInSeconds, Action, AddSymbol, EqualitySymbol, FinalValue)	{ \
AlphaValue AddSymbol (FullColorFloatValue/(TimeInSeconds*FrameRate)); \
if(AlphaValue EqualitySymbol FinalValue){ \
AlphaValue = FinalValue; \
Action; \
} \
}

#define LogicAlphaRisesWithPosition(AlphaValue, PositionX, StartPositionX, EndPositionX)			LogicAlphaMovementRelatedGeneral(AlphaValue, PositionX, StartPositionX, EndPositionX, 0.0f, 1.0f)
#define LogicAlphaFallsWithPosition(AlphaValue, PositionX, StartPositionX, EndPositionX)		LogicAlphaMovementRelatedGeneral(AlphaValue, PositionX, StartPositionX, EndPositionX, 1.0f, (-1.0f))

#define LogicAlphaMovementRelatedGeneral(AlphaValue, PositionX, StartPositionX, EndPositionX, RaidOutValue, ContraRaidOutValue)	{ \
if(PositionX >= StartPositionX && PositionX <= EndPositionX){ \
AlphaValue = RaidOutValue+((((PositionX-StartPositionX)/(EndPositionX-StartPositionX))*FullColorFloatValue)*ContraRaidOutValue); \
} \
} \

#define LogicRawMovementRight(PositionX, StartPositionX, EndPositionX, TimeInSeconds, Action)		LogicRawMovementGeneral(PositionX, StartPositionX, EndPositionX, TimeInSeconds, Action, EndPositionX, +=, >=)
#define LogicRawMovementLeft(PositionX, StartPositionX, EndPositionX, TimeInSeconds, Action)		LogicRawMovementGeneral(PositionX, EndPositionX, StartPositionX, TimeInSeconds, Action, EndPositionX, -=, <=)

#define LogicRawMovementGeneral(Position, SmallValue, BigValue, TimeInSeconds, Action, CheckValue, AdditionOperator, EqualityOperator)		{ \
Position AdditionOperator (BigValue-SmallValue)/(TimeInSeconds*FrameRate); \
if(Position EqualityOperator CheckValue){ \
Position = CheckValue; \
Action; \
} \
}


#define LogicRawMovementUnknownDirectionFixedSpeed(Position, PixelMovementPerSecond, CheckValue, Action)		LogicRawMovementUnknownDirectionGeneral(Position, CheckValue, Action, ((PixelMovementPerSecond)/(FrameRate)), IsPositive(PixelMovementPerSecond))
#define LogicRawMovementUnknownDirectionFixedDuration(Position, TimeInSeconds, StartValue, EndValue, Action)		LogicRawMovementUnknownDirectionGeneral(Position, EndValue, Action, ((EndValue-StartValue)/(TimeInSeconds*FrameRate)), (EndValue >= StartValue))
#define LogicRawMovementUnknownDirectionGeneral(Position, CheckValue, Action, Movement, PositiveMovementCheck)		{ \
Position += Movement; \
if((PositiveMovementCheck && Position >= CheckValue) || (!(PositiveMovementCheck) && Position <= CheckValue)){ \
Position = CheckValue; \
Action; \
} \
}

#define LogicExpand(TransformationData, ScaleTimeInSeconds, StartValue, EndValue, Action)	LogicScaleGeneral(TransformationData, ScaleTimeInSeconds, StartValue, EndValue, Action, EndValue, +, >=)
#define LogicDexpand(TransformationData, ScaleTimeInSeconds, StartValue, EndValue, Action)	LogicScaleGeneral(TransformationData, ScaleTimeInSeconds, EndValue, StartValue, Action, EndValue, -, <=)

#define LogicScaleGeneral(TransformationData, ScaleTimeInSeconds, SmallValue, BigValue, Action, CheckValue, AdditionOperator, EqualityOperator)	{ \
SetScaleValueAdvanced(TransformationData, GetScaleValue(TransformationData) AdditionOperator ((BigValue-SmallValue)/(ScaleTimeInSeconds*FrameRate))) \
if(GetScaleValue(TransformationData) EqualityOperator CheckValue){ \
SetScaleValueAdvanced(TransformationData, CheckValue); \
Action; \
} \
}

#define LogicScaleUnknownDirectionFixedSpeed(TransformationData, ScaleChangePerSecond, CheckValue, Action)	{ \
SetScaleValueAdvanced(TransformationData, ((GetScaleValue(TransformationData))+(ScaleChangePerSecond)/(FrameRate))); \
if((IsPositive(ScaleChangePerSecond) && GetScaleValue(TransformationData) >= CheckValue) || (IsNegative(ScaleChangePerSecond) && GetScaleValue(TransformationData) <= CheckValue)){ \
SetScaleValueAdvanced(TransformationData, CheckValue); \
Action; \
} \
}




#define SceneFinish(List) { \
pvr_list_finish(List); \
pvr_scene_finish(); \
}

#define BlackOutTextureDraw(FinalVector, TransformationData, Texture, PositionZ, TextureSizeX, TextureSizeY, AlphaValue)		{ \
SetupTransformAndDraw(FinalVector, TransformationData, Texture, \
OverallScreenPositionLeft, OverallScreenPositionUp, PositionZ, \
ScreenSizeX, ScreenSizeY, \
TextureSizeX, TextureSizeY, \
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, AlphaValue, FullColorFloatValue, FullColorFloatValue, FullColorFloatValue); \
}

#define FontGetCharacterEffectiveSizeFromArrayX(WhichFont, RealLetterToBeDrawn)		FontGetCharacterEffectiveSizeX(WhichFont, (RealLetterToBeDrawn-IncludedLetterSetOffset))
#define FontGetCharacterEffectiveSizeX(WhichFont, LetterToBeDrawn) 	(FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].RelativeSizeX*FontSizeX)
#define FontGetCharacterDrawSizeY(WhichFont, LetterToBeDrawn) 	(FontData[WhichFont].Loadable->FontSingleLetterData[LetterToBeDrawn].RelativeSizeY*FontSizeX)

#define FrameBufferLoadToTransitionData(TransitionData)	{ \
TransitionData = (void*)malloc(sizeof(pvr_ptr_t)); \
(*((pvr_ptr_t*)TransitionData)) = FrameBufferToTexture(); \
}

#define PrepareScreenForActiveTextureDeLoad()	{ \
pvr_wait_ready(); \
pvr_scene_begin(); \
pvr_scene_finish(); \
pvr_wait_ready(); \
}

#define FilePositionFromRectangle(Left, Right, Up, Down, TestLeft, TestRight, TestUp, TestDown, PositionX, PositionY, FullSizeX, FullSizeY)		{ \
FilePositionFromRectangleOneAxis(Left, Right, TestLeft, TestRight, PositionX, FullSizeX); \
FilePositionFromRectangleOneAxis(Up, Down, TestUp, TestDown, PositionY, FullSizeY); \
}

#define FilePositionFromRectangleOneAxis(Small, Big, TestSmall, TestBig, Position, FullSize)		{ \
if(Position < TestSmall){ \
Small = (TestSmall-Position)/(FullSizeX); \
Position = TestSmall; \
} \
else Small = FullSmallTexturePosition; \
if((PositionX+FullSizeX) > TestBig) Big = (TestBig-Position)/(FullSizeX); \
else Big = FullBigTexturePosition; \
}

#define AnimationUpdateAnimationFactor(AnimationFactor, Ticks, Value)		{ \
Ticks *= (Value/AnimationFactor); \
AnimationFactor = Value; \
}


#define TileDeActivateEverything(TileData)	{ \
TileData->LogicData.General.EnableFlags = TileEnableFlagNothing; \
TileData->LogicData.General.AnimationFlags = TileAnimationFlagNothing; \
}

#define TileInitiateSet(OverWorldData, WhichTile)	{ \
OverWorldData->LogicData.General.CurrentGamePlay = OverWorldGamePlayTile; \
OverWorldData->LogicData.General.CurrentTile = WhichTile; \
}

#define TileExitSet(TileData)	{ \
TileDeActivateEverything(TileData); \
TileData->LogicData.General.LoopTile = LogicActiveNot; \
}

#define FightDeActivateEverything(FightData)	{ \
 \
}

#define FightInitiateSet(OverWorldData)	{ \
OverWorldData->LogicData.General.CurrentGamePlay = OverWorldGamePlayFight; \
}

#define FightExitSet(FightData)	{ \
FightDeActivateEverything(FightData); \
FightData->LogicData.General.LoopFight = LogicActiveNot; \
}

#define TileInputSetupMenu(TileData)	{ \
TileData->LogicData.General.StartMenu = TileLogicStartMenu; \
}


#define TileMovementPreComputeLogarithmicInterPolation(TileMovementLoadableSingleData, TileMovementLogicSingleData)	 TileMovementPreComputeLogarithmicInterPolationAdvanced(TileMovementLogicSingleData->Factor, TileMovementLogicSingleData->Constant, TileMovementLoadableSingleData->StartValue, TileMovementLoadableSingleData->EndValue, ((TileData->TileHeaderData->StagePositionEndZ-TileData->TileHeaderData->StagePositionStartZ)))	
#define TileMovementPreComputeLogarithmicInterPolationAdvanced(Factor, Constant, StartValue, EndValue, Range)		{ \
if(StartValue == EndValue) Factor = 0; \
else Factor = (EndValue-StartValue)/(log(Range+1)); \
Constant = StartValue; \
} 

#define TileMovementPreComputeNegativeQuadraticInterPolation(TileMovementLoadableSingleData, TileMovementLogicSingleData)	TileMovementPreComputeGeneralQuadraticInterPolation(TileMovementLoadableSingleData, TileMovementLogicSingleData, TileMovementLoadableSingleData->EndValue, TileMovementLoadableSingleData->StartValue)
#define TileMovementPreComputeQuadraticInterPolation(TileMovementLoadableSingleData, TileMovementLogicSingleData)	TileMovementPreComputeGeneralQuadraticInterPolation(TileMovementLoadableSingleData, TileMovementLogicSingleData, TileMovementLoadableSingleData->StartValue, TileMovementLoadableSingleData->EndValue)
#define TileMovementPreComputeGeneralQuadraticInterPolation(TileMovementLoadableSingleData, TileMovementLogicSingleData, StartValue, EndValue)		{ \
TileMovementLogicSingleData->Factor = (EndValue-StartValue)/pow((TileData->TileHeaderData->StagePositionEndZ-TileData->TileHeaderData->StagePositionStartZ), TileMovementInverseInterPolationPower); \
TileMovementLogicSingleData->Constant = StartValue; \
}



#define TileMovementPreComputeLinearInterPolation(TileMovementLoadableSingleData, TileMovementLogicSingleData)					TileMovementPreComputeGeneralLinearInterPolation(TileMovementLoadableSingleData, TileMovementLogicSingleData, TileMovementLoadableSingleData->StartValue, TileMovementLoadableSingleData->EndValue)
#define TileMovementPreComputeNegativeLinearInterPolation(TileMovementLoadableSingleData, TileMovementLogicSingleData)			TileMovementPreComputeGeneralLinearInterPolation(TileMovementLoadableSingleData, TileMovementLogicSingleData, TileMovementLoadableSingleData->EndValue, TileMovementLoadableSingleData->StartValue)
#define TileMovementPreComputeGeneralLinearInterPolation(TileMovementLoadableSingleData, TileMovementLogicSingleData, SmallValue, BigValue)		{ \
TileMovementLogicSingleData->Factor = (BigValue-SmallValue)/(TileData->TileHeaderData->StagePositionEndZ - TileData->TileHeaderData->StagePositionStartZ); \
TileMovementLogicSingleData->Constant = SmallValue; \
}

#define InterPolationComputeLogarithmicInterPolation(x, InterPolationData)	TileMovementComputeLogarithmicInterPolationAdvanced((x+InterPolationData->Displacement), InterPolationData->Factor, InterPolationData->Constant)	
#define TileMovementComputeLogarithmicInterPolation(x, TileMovementLogicSingleData)	TileMovementComputeLogarithmicInterPolationAdvanced((x-TileData->TileHeaderData->StagePositionStartZ), TileMovementLogicSingleData->Factor, TileMovementLogicSingleData->Constant)
#define TileMovementComputeLogarithmicInterPolationAdvanced(x, Factor, Constant)	((Factor*log(x+1))+Constant)

#define InterPolationComputeNegativeQuadraticInterPolation(x, InterPolationData)	TileMovementComputeQuadraticInterPolationAdvanced((x+InterPolationData->Displacement), InterPolationData->Factor, InterPolationData->Constant)	
#define TileMovementComputeNegativeQuadraticInterPolation(x, TileMovementLogicSingleData)	TileMovementComputeQuadraticInterPolation(x, TileMovementLogicSingleData)
#define InterPolationComputeQuadraticInterPolation(x, InterPolationData)	TileMovementComputeQuadraticInterPolationAdvanced((x+InterPolationData->Displacement), InterPolationData->Factor, InterPolationData->Constant)	
#define TileMovementComputeQuadraticInterPolation(x, TileMovementLogicSingleData)	TileMovementComputeQuadraticInterPolationAdvanced((x-TileData->TileHeaderData->StagePositionStartZ), TileMovementLogicSingleData->Factor, TileMovementLogicSingleData->Constant)
#define TileMovementComputeQuadraticInterPolationAdvanced(x, Factor, Constant)	((Factor*pow(x, TileMovementInverseInterPolationPower))+Constant)

#define InterPolationComputeNegativeLinearInterPolation(x, InterPolationData)	TileMovementComputeNegativeLinearInterPolationAdvanced((x+InterPolationData->Displacement), InterPolationData->Factor, InterPolationData->Constant)	
#define TileMovementComputeLinearInterPolation(x, TileMovementLogicSingleData)		TileMovementComputeNegativeLinearInterPolation(x, TileMovementLogicSingleData)
#define TileMovementComputeNegativeLinearInterPolation(x, TileMovementLogicSingleData)		TileMovementComputeNegativeLinearInterPolationAdvanced(x, TileMovementLogicSingleData->Factor, TileMovementLogicSingleData->Constant)
#define TileMovementComputeNegativeLinearInterPolationAdvanced(x, Factor, Constant)		((Factor*x)+Constant)

#define TilePlayerFetchLeftPositionScreenX(TileData, WhichPlayer)				TileFetchPositionScreenX(TileData, TilePlayerFetchLeftPositionX(TileData, WhichPlayer))
#define TilePlayerFetchTopPositionScreenY(TileData, WhichPlayer)				TileFetchPositionScreenX(TileData, TilePlayerFetchTopPositionY(TileData, WhichPlayer))

#define TilePlayerFetchLeftPositionX(TileData, WhichPlayer) 						TileObjectFetchLeftPositionX(TileData, TileData->PlayerData[WhichPlayer].LogicData.WhichObject, TileData->PlayerData[WhichPlayer].LogicData.WhichInstance)
#define TilePlayerFetchTopPositionY(TileData, WhichPlayer) 						TileObjectFetchTopPositionY(TileData, TileData->PlayerData[WhichPlayer].LogicData.WhichObject, TileData->PlayerData[WhichPlayer].LogicData.WhichInstance)

#define TileObjectFetchCenterPositionX(TileData, WhichObject, WhichInstance)	(TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX)
#define TileObjectFetchLeftPositionX(TileData, WhichObject, WhichInstance)		(TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX-(TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SizeX/2))
#define TileObjectFetchTopPositionY(TileData, WhichObject, WhichInstance)		(TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.PositionY-TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SizeY)

#define TileObjectFetchLeftPositionScreenX(TileData, WhichObject, WhichInstance)		TileFetchPositionScreenX(TileData, TileObjectFetchLeftPositionX(TileData, WhichObject, WhichInstance))
#define TileObjectFetchTopPositionScreenY(TileData, WhichObject, WhichInstance)		TileFetchPositionScreenY(TileData, TileObjectFetchTopPositionY(TileData, WhichObject, WhichInstance))

#define FightObjectFetchLeftPositionX(FightData, WhichObject, WhichInstance)		(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX-(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeX/2))
#define FightObjectFetchTopPositionY(FightData, WhichObject, WhichInstance)		(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionY-FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeY)
#define FightObjectFetchRightPositionX(FightData, WhichObject, WhichInstance)		(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX+(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeX/2))
#define FightObjectFetchDownPositionY(FightData, WhichObject, WhichInstance)		(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionY)


#define FightObjectFetchLeftPositionScreenX(FightData, WhichObject, WhichInstance)		FightFetchPositionScreenX(FightData, FightObjectFetchLeftPositionX(FightData, WhichObject, WhichInstance))
#define FightObjectFetchTopPositionScreenY(FightData, WhichObject, WhichInstance)		FightFetchPositionScreenY(FightData, FightObjectFetchTopPositionY(FightData, WhichObject, WhichInstance))


#define TileFetchPositionScreenX(TileData, x)			(x-TileData->LogicData.BackGround.StagePositionX)
#define TileFetchPositionScreenY(TileData, x)			(x-TileData->LogicData.BackGround.StagePositionY)

#define FightFetchPositionScreenX(FightData, x)			(x-FightData->LogicData.Stage.StagePositionX)
#define FightFetchPositionScreenY(FightData, x)			(x-FightData->LogicData.Stage.StagePositionY)

#define FightStolarFetchLeftPositionX(FightData)			(FightData->LogicData.Stolar.PositionX-(FightData->LogicData.Stolar.SizeX/2))
#define FightStolarFetchCenterPositionX(FightData)			(FightData->LogicData.Stolar.PositionX)
#define FightStolarFetchTopPositionY(FightData)			(FightData->LogicData.Stolar.PositionY-FightData->LogicData.Stolar.SizeY)
#define FightStolarFetchLeftPositionScreenX(FightData)	FightFetchPositionScreenX(FightData, FightStolarFetchLeftPositionX(FightData))
#define FightStolarFetchTopPositionScreenY(FightData)	FightFetchPositionScreenY(FightData, FightStolarFetchTopPositionY(FightData))

#define FightEnemyFetchCenterPositionX(FightData, WhichEnemy)		(FightData->EnemyData[WhichEnemy].Given->PositionX)
#define FightEnemyFetchTopPositionY(FightData, WhichEnemy)			(FightData->EnemyData[WhichEnemy].LogicData.PositionY-FightData->EnemyData[WhichEnemy].Given->SizeY)

#define FightPlayerAnimationIsIdle(FightData, WhichPlayer)			(FightData->ObjectData[FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject].Instance[FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance].Loadable->CurrentAnimation == PlayerIdleAnimation || FightData->ObjectData[FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject].Instance[FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance].Loadable->CurrentAnimation == PlayerRunningAnimation)


#define FightVelocityNoLongerInMotionX(VelocityX, WeightFactorComparedToStolarX)	((VelocityX >= FightPhysicsVelocityStandardValueX && VelocityX-(HertzParseSixtyHertzValue(FightData->Loadable.Stage->General.VelocityChangeForStolarX)*WeightFactorComparedToStolarX) <= FightPhysicsVelocityStandardValueX) || \
																								(VelocityX < FightPhysicsVelocityStandardValueX && VelocityX+(HertzParseSixtyHertzValue(FightData->Loadable.Stage->General.VelocityChangeForStolarX)*WeightFactorComparedToStolarX) >= FightPhysicsVelocityStandardValueX))

#define FightVelocityNoLongerInMotionY(PositionY, VelocityY, StagePositionZ)	(PositionY+VelocityY >= FightFromStagePositionReturnPositionY(FightData, StagePositionZ))

#define FightVelocityLogicDeActivateX(VelocityActiveX, VelocityX)	{ \
VelocityActiveX = LogicActiveNot; \
VelocityX = FightPhysicsVelocityStandardValueX; \
}

#define FightVelocityLogicDeActivateY(VelocityActiveY, VelocityY)	{ \
VelocityActiveY = LogicActiveNot; \
VelocityY = DummyValueFloat; \
}

#define FightVelocityPhysicsLogicStandardX(VelocityActiveY, PositionX, VelocityX, WeightFactorComparedToStolarX)	{ \
PositionX += VelocityX; \
if(!VelocityActiveY){ \
if(VelocityX >= FightPhysicsVelocityStandardValueX) VelocityX -= (HertzParseSixtyHertzValue(FightData->Loadable.Stage->General.VelocityChangeForStolarX)*WeightFactorComparedToStolarX); \
else VelocityX += (HertzParseSixtyHertzValue(FightData->Loadable.Stage->General.VelocityChangeForStolarX)*WeightFactorComparedToStolarX); \
} \
}

#define FightVelocityPhysicsLogicStandardY(PositionY, VelocityY, WeightFactorComparedToStolarY)	{ \
PositionY += VelocityY; \
VelocityY += (HertzParseSixtyHertzValue(FightData->Loadable.Stage->General.VelocityChangeForStolarY)*WeightFactorComparedToStolarY); \
}

#define FightVelocityHitLogicStandardX(Hit, LogicData, AnimationData, AnimationHitGround, Idle)		{ \
if(Hit){ \
ChangeAnimationSimple(LogicData, AnimationHitGround); \
Hit = LogicActiveNot; \
} \
else if(Idle){ \
ChangeAnimationCrank(LogicData, AnimationHitGround, \
(AnimationData[AnimationHitGround].FrameAmount-1), \
NewTicksStandardValue, EventInducedLoopValueNot); \
} \
}

#define FightVelocityHitLogicStandardY(Hit, LogicData, AnimationData, AnimationHitAir, Idle)	{ \
if(Hit){ \
ChangeAnimationSimple(LogicData, AnimationHitAir); \
Hit = LogicActiveNot; \
} \
else if(Idle){ \
ChangeAnimationCrank(LogicData, AnimationHitAir, \
(AnimationData[AnimationHitAir].FrameAmount-1), \
NewTicksStandardValue, EventInducedLoopValueNot); \
} \
}


#define EventSpeechSpeechBubbleNoMoreBuildUp(DirtyDeedsDoneDirtCheap)	EventSpeechSpeechBubbleNoMoreBuildUpGeneral(EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].BuildUp, EventSpeechData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition, EventSpeechData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->ArrayLengthTotal)
#define EventSpeechSpeechDynamicBubbleNoMoreBuildUp(DirtyDeedsDoneDirtCheap)	EventSpeechSpeechBubbleNoMoreBuildUpGeneral(EventSpeechDynamicData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].BuildUp, EventSpeechDynamicData->LogicData->SpeechBubbles[DirtyDeedsDoneDirtCheap].ArrayPosition, EventSpeechDynamicData->Loadable.SpeechBubbles[DirtyDeedsDoneDirtCheap].Header->ArrayLengthTotal)

#define EventSpeechSpeechBubbleNoMoreBuildUpGeneral(BuildUp, ArrayPosition, ArrayLengthTotal)	{ \
BuildUp = LogicActiveNot; \
ArrayPosition = ArrayLengthTotal; \
}

#define FightObjectInstanceFluxDataIntelligenceAdd(CurrentIntelligence, WhichIntelligence)	{ \
FightData->ObjectData[WhichObject].Instance[WhichInstance].Intelligence[CurrentIntelligence] = WhichIntelligence; \
CurrentIntelligence++; \
}


