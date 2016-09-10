#define BitsPerByte				8
#define MinimumByteValue		0
#define MaximumByteValue		0xFF

#define RightMostBitInByte		0x1
#define LeftMostBitInByte		0x80

#define ScreenSizeX				640
#define ScreenSizeY				480

#define HexNumberValueOffset 			48

#define StairWayToHeaven			1550
#define StairWayToHeavenIdentifier		0xFF

#define ReturnValueNothingUnusual		1

#define HertzFifty					50
#define FiftyHertz					50
#define HertzSixty					60
#define SixtyHertz					60
#define HertzDifference			10

#define StolarPixelMode	PM_RGB565

#define StolarFiftyHertzCableMode	DM_640x480_PAL_IL
#define StolarSixtyHertzCableMode	DM_640x480_NTSC_IL
#define StolarSixtyHertzVideoGangsterAdapterMode	DM_640x480_VGA

#define D4C						DirtyDeedsDoneDirtCheap

#define LoadCurrentPointerPositionLegalStartValue	4

#define DummyValue				0.0f
#define DummyValueFloat		0.0f
#define DummyValueInteger		0

#define StandardValueW	1.0f

#define NormalFileDirSize			40
#define NormalMountPointSize			40

#define SoundPaddingValueStandard	128

#define WaveFileHeaderLengthPosition	0x4
#define WaveFileHeaderLengthAddition	0x8
#define WaveFileHeaderSize			0x2C

#define HeaderSizeKMG				64

#define TextureAtlasDrawSingleEntry	0

#define PlayerMain	0

#define PlayerAmountMinimum		1
#define PlayerAmountMaximum		4

#define CrewSizeMaximum			4

#define MusicStandardFileType		".ogg"
#define MusicTemporaryFileDir		"/ram/BGM.ogg"

#define BootUpStage				1
#define TitleScreenStage			2
#define StartNewGameStage			3
#define TheGameIsOnStage			4
#define LoadGameStage				5
#define FinalExitStage				13
#define BoringStage				44

#define FightPauseEverything			1
#define StolarIsMoreThanDead			2

#define OverWorldControllerUnPlugged		1
#define OverWorldBoringStage				44

#define NoAllocateTextureMemory			0
#define ReAllocateTextureMemory			1

#define TextureDrawReverseNot				0
#define TextureDrawReverse					1

#define OverallScreenPositionLeft	0
#define OverallScreenPositionUp 	0
#define OverallScreenPositionZ		640.0f

#define TileOverallScreenPositionZ	OverallScreenPositionZ

#define NormalSizeScaleValue		1.0f

#define FullLeftTexturePosition		0.0f
#define FullRightTexturePosition		1.0f
#define FullSmallTexturePosition		FullLeftTexturePosition
#define FullBigTexturePosition		FullRightTexturePosition

#define FullColorFloatValue 1.0f
#define NoColorFloatValue 0.0f

#define FontIncludedLetterOffset	0x20
#define FontOverallLetterAmount		95
#define IncludedLetterSetOffset	0x20


#define ArrayEndSymbol		'\0'

#define FontSizeBetweenLettersX(FontSizeX, WhichFont)	(FontSizeX + FontData[WhichFont].Loadable->FontHeaderData.InterLetterSpaceX)
#define FontSizeBetweenLettersY(FontSizeY, WhichFont)	(FontSizeY + FontData[WhichFont].Loadable->FontHeaderData.InterLetterSpaceY)

#define FontStandard		0

#define ArrayRealSizeWithoutEnd(x)	(x-1)

#define DogmaCompanySoundEffectAmount		2

#define SpiralPositionVector			4
#define SpiralVectorAmount			5

#define FileSizeDRI				192

#define DisplayBeep				1
#define DisplayNoBeep				0

#define AbilityAmount				4
#define OverallAbilityAmount			108

#define AbilityRed				0
#define AbilityYellow				1
#define AbilityGreen				2
#define AbilityBlue				3

#define RedAbility				AbilityRed
#define YellowAbility				AbilityYellow
#define GreenAbility				AbilityGreen
#define BlueAbility				AbilityBlue

#define PolygonCornerAmount			4

#define ZoomInIdentifier			(1<<0)
#define RotateXIdentifier			(1<<1)
#define RotateYIdentifier			(1<<2)
#define RotateZIdentifier			(1<<3)

#define NoRotationValue					0
#define QuarterRotationValue			(M_PI/2.0f)
#define HalfRotationValue				M_PI
#define ThreeQuarterRotationValue		(M_PI*3.0f/2.0f)
#define FullRotationValue					(M_PI*2.0f)

#define EnemyPositionZ				5
#define StolarPositionZ				6
#define FightHealthBackGroundPositionZ2 	7
#define FightHealthActualHealthPositionZ2 	8
#define FloatingValueTexturePositionZ		9

#define FightSecondGreatestPositionZ		10
#define FightGreatestPositionZ			11


#define MiddlePositionZ				5.0f
#define UnusedAnywayPositionZ		0.0f

#define WhiteTextureSizeX			64
#define WhiteTextureSizeY			64

#define StolarTextureSizeX			64
#define StolarTextureSizeY			64

#define PaletteBitsPerPixelFour	4
#define PaletteBitsPerPixelEight	8

#define PaletteEntryAmountBitsPerPixelFour	16
#define PaletteEntryAmountBitsPerPixelEight	256

#define PaletteEntryAmountBitsPerPixelAbilityGauges	PaletteEntryAmountBitsPerPixelFour

#define PalettePositionFonts		0
#define PalettePositionAbilityGaugesOffset	1

#define PalettePositionSprites	1



#define AbilityDrawSizeX			64
#define AbilityDrawSizeY			64

#define StolarAnimationFlag			(1<<0)
#define EnemyAnimationFlag			(1<<1)
#define StageAnimationFlag			(1<<2)
#define PersonAnimationFlag			(1<<3)
#define AnimateAll				0xFF

#define TileFaceRight				0
#define TileFaceLeft				1
#define TileDirectionAmount			2

#define FightFaceRight				0
#define FightFaceLeft				1
#define FightDirectionAmount			2

#define OverWorldFaceRight			0
#define OverWorldFaceLeft			1
#define OverWorldFaceDown			2
#define OverWorldFaceUp				3
#define OverWorldDirectionAmount		4

#define StolarIdleAnimation			0
#define StolarIdleAnimationRight		StolarIdleAnimation
#define StolarIdleAnimationLeft			1
#define StolarRunningAnimation			4
#define StolarTurnAroundAnimation		8
#define StolarNormalPunchAnimation		10
#define StolarSecondPunchAnimation		12
#define StolarThirdPunchAnimation		14
#define StolarGettingHitFromFrontAnimation	16
#define StolarGettingHitFromBehindAnimation	18
#define StolarNormalFallAnimation		20
#define StolarNormalAscendAnimation		22
#define StolarDeathAnimation			24

#define PlayerIdleAnimation			0
#define PlayerRunningAnimation			1
#define PlayerNormalPunchAnimation		2
#define PlayerHitAnimation	4
#define PlayerDeathAnimation			4

#define EnemyIdleAnimation			0
#define EnemyRunningAnimation		1
#define StandardEnemyHitAnimation		2
#define EnemyAttackMeleeAnimation	3
#define EnemyDeathAnimation			4

#define PersonIdleAnimation				0
#define PersonRunningAnimation		4

#define NormalEnemyIdleAnimation			0
#define NormalEnemyRunningAnimation		4

#define SpecialEnemyIdleAnimation			0
#define SpecialEnemyRunningAnimation		4

#define OverrideAnimation					MaximumByteValue

#define TileDrawEnemyAnimationAmount	10

#define EscalationTextureAmount			3
#define EscalationWhiteFlashDuration		5
#define EscalationDrawnAmount			2

#define HitOffsetRight				0
#define HitOffsetLeft				1
#define HitOffsetUp				2
#define HitOffsetDown				3
#define HitOffsetFront				4
#define HitOffsetBack				5
#define HitOffsetDirections			8

#define StolarHitOffsetRight			0
#define StolarHitOffsetLeft			0
#define StolarHitOffsetUp			0
#define StolarHitOffsetDown			0
#define StolarHitOffsetFront			0
#define StolarHitOffsetBack			0

#define ButtonA					0
#define ButtonB					1
#define ButtonX					2
#define ButtonY					3
#define ButtonL					4
#define ButtonR					5
#define ButtonUp				6
#define ButtonDown				7
#define ButtonLeft				8
#define ButtonRight				9
#define ButtonStart				10
#define ButtonAmount				11


#define RedAbilityIdentifier			1
#define RedAbilityFillUpMultiplicator		10

#define NoAbilityIdentifier			0

#define ScreenShakingThreshold			5

#define EnemyObliterated			0
#define EnemyActive				1
#define EnemyJustGotHit				2

#define StolarJustGotHit			EnemyJustGotHit

#define NoEvent					0
#define StolarYouAreAlreadyDead			1
#define StolarYouAreInvincible			2

#define StolarAirFrictionFactor			1.0f
#define StolarWeightFactor			1.0f
#define StolarDeathSlowness			0.25f

#define FloatingValueInActive			0
#define FloatingValueBuildUpStage		1
#define FloatingValueMaxLength			8

#define WhiteColor				0
#define RedColor				1
#define GreenColor				2
#define BlueColor				3
#define YellowColor				4
#define ColorAmountSansBlack			5
#define BlackColor				ColorAmountSansBlack
#define ColorAmount				6


#define ArtificialIntelligenceAmount		100

#define StoryFlagByteAmount			0x20
#define SpecialEnemyFlagByteAmount		0x20

#define NormalLocationNameSize			0x10
#define NormalTileNameSize			0x10

#define EventButtonMask				0x3
#define EventPersonLinkFlag			0x4

#define EventTypeNoButton			0x0
#define EventTypeButtonA			0x1
#define EventTypeButtonB			0x2
#define EventTypeButtonX			0x3
#define EventTypeButtonY			0x4

#define EventPersonLinkSizeX			20
#define EventPersonLinkSizeZ			20


#define UpLeftValue				0
#define DownRightValue				1
//#define FourValueRectangleValueAmount		2
#define UpRightValue				2
#define DownLeftValue				3
#define FourValueBoxValueAmount		4

#define GameOverScreenOptionSelectedFlag	(1<<7)
#define GameOverScreenOptionAmount		3
#define GameOverScreenBackGroundTextureSizeY	128
#define GameOverScreenBackGroundAmount		((ScreenSizeY/GameOverScreenBackGroundTextureSizeY)+2)

#define GameOverScreenTextureSizeX		512
#define GameOverScreenTextureSizeY		128

#define GameOverScreenBackGroundTexturePositionLeft	0.0f
#define GameOverScreenBackGroundTexturePositionRight	1.0f

#define GameOverScreenBackGroundMovement		3.0f

#define GameOverScreenBackGroundTexturePlus		0
#define GameOverScreenOtherTexture			1
#define GameOverScreenTextureAmount			2

#define GameOverScreenOptionRestart			0
#define GameOverScreenOptionExit			1
#define GameOverScreenOptionLoad			2
#define GameOverScreenOptionAmount			3

#define GameOverScreenRestartUpLeftX			0 
#define GameOverScreenRestartUpLeftY			0
#define GameOverScreenRestartUpRightX			0
#define GameOverScreenRestartUpRightY			0
#define GameOverScreenRestartDownLeftX			0
#define GameOverScreenRestartDownLeftY			0
#define GameOverScreenRestartDownRightX			0
#define GameOverScreenRestartDownRightY			0
#define GameOverScreenRestartPositionZ			0

#define GameOverScreenExitUpLeftX			0
#define GameOverScreenExitUpLeftY			0
#define GameOverScreenExitUpRightX			0
#define GameOverScreenExitUpRightY			0
#define GameOverScreenExitDownLeftX			0
#define GameOverScreenExitDownLeftY			0
#define GameOverScreenExitDownRightX			0
#define GameOverScreenExitDownRightY			0
#define GameOverScreenExitPositionZ			0

#define GameOverScreenLoadUpLeftX			0
#define GameOverScreenLoadUpLeftY			0
#define GameOverScreenLoadUpRightX			0
#define GameOverScreenLoadUpRightY			0
#define GameOverScreenLoadDownLeftX			0
#define GameOverScreenLoadDownLeftY			0
#define GameOverScreenLoadDownRightX			0
#define GameOverScreenLoadDownRightY			0
#define GameOverScreenLoadPositionZ			0

#define GameOverScreenSelectedPositionZ			0


#define GameOverScreenRestartTexturePositionLeft	0.0f
#define GameOverScreenRestartTexturePositionRight	1.0f
#define GameOverScreenRestartTexturePositionUp		0.0f
#define GameOverScreenRestartTexturePositionDown	1.0f

#define GameOverScreenExitTexturePositionLeft		0.0f
#define GameOverScreenExitTexturePositionRight		1.0f
#define GameOverScreenExitTexturePositionUp		0.0f
#define GameOverScreenExitTexturePositionDown		1.0f

#define GameOverScreenLoadTexturePositionLeft		0.0f
#define GameOverScreenLoadTexturePositionRight		1.0f
#define GameOverScreenLoadTexturePositionUp		0.0f
#define GameOverScreenLoadTexturePositionDown		1.0f

#define GameOverScreenMinimumScaleValue			0.5f	
#define GameOverScreenMaximumScaleValue			1.5f

#define NormalEnemyTexture							0
#define SpecialEnemyTexture							1
#define OverWorldEnemyTextureAmount					2

#define EventFunctionArguments						void* EventBufferPointer, void** EventTemporaryBufferPointer, EventKnowledgeStruct* EventKnowledgeData, TileStruct* TileData, OverWorldStruct* OverWorldData, void** TransitionData

#define EventBufferEventTypeOffset		0
#define EventBufferSizeOffset			2
#define EventBufferVoidDataOffset		4

#define InvalidEventIdentifier			0

#define EventSubEventGoesOn			MaximumByteValue
#define EventSubEventFinished			1
#define EventSubEventInitiateLoop		2
#define EventTileExitSubEvent			3
#define EventTotallyFinished				4


#define EventStolarAnimationChange			0
#define EventPersonAnimationChange			1
#define EventNormalEnemyAnimationChange	2
#define EventSpecialEnemyAnimationChange	3

#define EventTransformToStolar					0
#define EventTransformToPerson				1

#define EventTileExitIdentifier					2
#define EventSpeechIdentifier					6
#define EventSpeechDynamicIdentifier			7
#define EventFightStartIdentifier					8

#define SpeechBubbleAmountOverall			1

#define SpeechBubbleAmountOffset				0
#define SpriteAmountOffset						SpeechBubbleAmountOffset+1
#define SpeechBubbleBufferOffset				SpriteAmountOffset+1
#define SpriteBufferOffset						(SpeechBubbleBufferOffset+(sizeof(SpeechBubbleStruct)*DereferencePointerToType(uint8, EventBufferPointer+SpeechBubbleAmountOffset)))

#define SpeechBubbleTemporaryBufferOffset	0
#define SpriteTemporaryBufferOffset			(SpeechBubbleTemporaryBufferOffset+(sizeof(SpeechBubbleActiveStruct)*DereferencePointerToType(uint8, EventBufferPointer+SpeechBubbleAmountOffset)))

#define SpeechBubbleTypeAmount				2
#define SpeechBubbleTextureAmount			SpeechBubbleTypeAmount

#define SpriteDoNothing								0
#define SpriteMoveOnlyPartiallyIn					1
#define SpriteFadeIn									2

#define SpriteFaceRight								0
#define SpriteFaceLeft								1

#define SpriteDrawnDuringBuildUp					(1<<0)
#define SpriteDrawnDuringWait						(1<<1)

#define SpriteMoveOnlyPartiallyInMoveInSpace				20
#define StandardSpriteMoveInPartiallyMovementSpeedX	3

#define StandardSpriteFadeInChangeValuePerFrame		0.2f



#define ArtificialIntelligenceDoNothing				0
#define ArtificialIntelligenceWalkAround			1
#define ArtificialIntelligenceRunAround				2
#define ArtificialIntelligenceLookAround			3
#define ArtificialIntelligenceChaseStolar			4
#define ArtificialIntelligenceTowardsEvent			5

#define ArtificialIntelligenceBufferMovementX			0x0
#define ArtificialIntelligenceBufferMovementY			0x4
#define ArtificialIntelligenceBufferEvent			0x8


#define ArtificialIntelligenceMovementBits				0xF
#define ArtificialIntelligenceMovementBitMaskX			(ArtificialIntelligenceMovementBits << ArtificialIntelligenceBufferMovementX)
#define ArtificialIntelligenceMovementBitMaskY			(ArtificialIntelligenceMovementBits << ArtificialIntelligenceBufferMovementY)
#define ArtificialIntelligenceMovementBitsX(x)			(x&ArtificialIntelligenceMovementBits)
#define ArtificialIntelligenceMovementBitsY(x)			((x>>ArtificialIntelligenceBufferMovementY)&ArtificialIntelligenceMovementBits)
#define SetArtificialIntelligenceMovementBitsX(x, Value)	{((x &= (~ArtificialIntelligenceMovementBitMaskX))); (x |= (((Value)&ArtificialIntelligenceMovementBits) << ArtificialIntelligenceBufferMovementX));}
#define SetArtificialIntelligenceMovementBitsY(x, Value)	{((x &= (~ArtificialIntelligenceMovementBitMaskY))); (x |= (((Value)&ArtificialIntelligenceMovementBits) << ArtificialIntelligenceBufferMovementY));}
//#define SetArtificialIntelligenceMovementBitsX(x, Value)	x
//#define SetArtificialIntelligenceMovementBitsY(x, Value)	x


#define ArtificialIntelligenceEventBits					0xF
#define ArtificialIntelligenceFetchWhichEvent(x)		((x>>ArtificialIntelligenceBufferEvent)&ArtificialIntelligenceEventBits)



#define ArtificialIntelligenceMovementLeft			0
#define ArtificialIntelligenceNoMovementX			1
#define ArtificialIntelligenceMovementRight			2

#define ArtificialIntelligenceMovementUp			0
#define ArtificialIntelligenceNoMovementY			1
#define ArtificialIntelligenceMovementDown			2

#define ArtificialIntelligenceNormalWalkLeft			1
#define ArtificialIntelligenceNormalWalkRight			2
#define ArtificialIntelligenceNormalWalkUp			3
#define ArtificialIntelligenceNormalWalkDown			4
#define ArtificialIntelligenceNormalWalkNot			5
#define ArtificialIntelligenceNormalWalkingVariationAmount	5

#define ArtificialIntelligenceNoWalkingSpeedFactor	0
#define ArtificialIntelligenceWalkingSpeedFactor		1
#define ArtificialIntelligenceRunningSpeedFactor		2

#define ArtificialIntelligenceMovementMaximumRandomValue	(ArtificialIntelligenceNormalWalkingVariationAmount)-1

#define StolarChaseSpaceAmountX	0
#define StolarChaseSpaceAmountZ	0

#define EventChaseSpaceAmountX	0
#define EventChaseSpaceAmountZ	0

#define EventSpecialAnimationAmountInitialisationValue	5

#define EventSpecialAnimationTypeInActive			0
#define EventSpecialAnimationTypeSprite			1
#define EventSpecialAnimationTypeSpeechBubble	2
#define EventSpecialAnimationTypeRevealLocation	3
#define EventSpecialAnimationTypeArray			4

#define NoEntranceValue								0xFF

#define OverWorldFlagInitiationValue	0


#define TileLogicIntroFlipIdentifier			0
#define TileLogicIntroZoomOutIdentifier		1
#define TileLogicIntroBlackInIdentifier		2
#define TileLogicIntroNoneIdentifier			3

#define TileLogicOutroBlackOutIdentifier	2
#define TileLogicOutroNoneIdentifier		3

#define TileLogicIntroFlipDurationInSecondsStandard			2.0f

#define TileLogicIntroZoomOutStartValueStandard				300.0f
#define TileLogicIntroZoomOutFinalValueStandard				1.0f
#define TileLogicIntroZoomOutDurationInSecondsStandard		2.0f
#define TileLogicIntroZoomOutTypePosition				0
#define TileLogicIntroZoomOutTypeStolar				1

#define TileLogicIntroBlackInDurationInSecondsStandard		2.0f
#define TileLogicOutroBlackOutDurationInSecondsStandard		2.0f

#define TileLogicIntroNoneSize				0

#define DreamcastControllerAmount		4
#define FirstVisualMemory		0
#define SecondVisualMemory	1
#define VisualMemoryPerController			2
#define DreamcastVisualMemoryAmount	(DreamcastControllerAmount*VisualMemoryPerController)


#define ControllerPortPlayer1				0

#define FrameBufferFormat					(PVR_TXRFMT_RGB565 | PVR_TXRFMT_NONTWIDDLED)
#define FrameBufferSizeX					1024
#define FrameBufferSizeY					512


#define LoadGameNoControllerTexture						0
#define LoadGameControllerTexture							1
#define LoadGameControllerTextureAmount					2

#define LoadGameNoVisualMemoryTexture					0
#define LoadGameEmptyVisualMemoryTexture				1
#define LoadGameOkayVisualMemoryTexture				2
#define LoadGameVisualMemoryTextureAmount				3

#define LoadGameRockOver						0
//#define LoadGameRockIn						1
#define LoadGameRock							2
#define LoadGameRockTheDeleteSong			3
#define LoadGameRockTheDeleteConfirm		4
#define LoadGameRockTheLoadConfirm			5
#define LoadGameRockOut						6

#define LoadGameSaveShowStartPositionAmount	2

#define LoadGameSpecialOptionNewGame		0
#define LoadGameSpecialOptionDelete			1
#define LoadGameSpecialOptionAmount			2
#define LoadGameSpecialOptionUnSelected		LoadGameSpecialOptionAmount

#define LoadGameSelectorTransmorphTextureAmount		5

#define LoadGameWhichPortUnavailable		DreamcastControllerAmount
#define LoadGameWhichSlotUnavailable			VisualMemoryPerController

#define LoadGameNoSaveSelected				-1

#define LoadScreenPreviousBackGroundPositionZ	0
#define LoadScreenRealBackGroundPositionZ		1
#define LoadScreenControllerPositionZ				2
#define LoadScreenSpecialOptionPositionZ			2
#define LoadScreenVisualMemoryPositionZ			3
#define LoadScreenVisualMemorySelectorPositionZ	4
#define LoadScreenSaveShowPositionZ				5

#define LoadGameSaveDrawStatic 0
#define LoadGameSaveDrawChange 1
#define LoadGameSaveDrawAmount 2

#define ItemAmountMaxOverall	50
#define NoItemIdentifier			0
#define OverallDistinguishableItemAmount	108

#define OverallCharacterEntryAmount		21
#define OverallLogEntryAmount				21

#define AbilityAmountMaxOverall		OverallAbilityAmount

#define DrawRevealTileNameOver	0
#define DrawRevealTileNameOn		1

#define OverWorldLogicFlagDrawIntro							(1 << 0)
#define OverWorldLogicFlagMovementStolar					(1 << 1)
#define OverWorldLogicFlagEventCheck							(1 << 2)
#define OverWorldLogicFlagMovementArtificialIntelligence	(1 << 3)
#define OverWorldLogicFlagOpenTheMenu						(1 << 4)

#define OverWorldEventCheckEnabled							(OverWorldInterFaceData->OverWorldLogicData.SuperDrawFlags & OverWorldLogicFlagEventCheck)
#define EveryBodyJumpAroundEnabled							(OverWorldInterFaceData->OverWorldLogicData.SuperDrawFlags & OverWorldLogicFlagMovementArtificialIntelligence)
#define OverWorldOpenTheMenuEnabled						(OverWorldInterFaceData->OverWorldLogicData.SuperDrawFlags & OverWorldLogicFlagOpenTheMenu)
#define OverWorldRunStolarRunEnabled							(OverWorldInterFaceData->OverWorldLogicData.SuperDrawFlags & OverWorldLogicFlagMovementStolar)

#define OverWorldOpenTheMenuRequirements					(ButtonLegit(ButtonStart, OverWorldInterFaceData->ButtonInputData))

#define OverWorldLoadPlayerAmountStart						PlayerAmountMinimum

#define OverWorldGamePlayTile		0
#define OverWorldGamePlayFight	1

#define OverWorldMenuScreenAmount							5

#define OverWorldMenuStageFinished							0
#define OverWorldMenuStageBuildUp							1
#define OverWorldMenuStageRunning							2
#define OverWorldMenuStageBuildDown						3

#define OverWorldMenuStageFirst								OverWorldMenuStageBuildUp
#define OverWorldMenuStageLast								OverWorldMenuStageFinished

#define OverWorldHandActivismAllowed		(!OverWorldMenuData->BackGroundData.HandActive && OverWorldMenuData->LogicData.Stage > OverWorldMenuStageBuildUp)

#define OverWorldMenuHandTouchedScreenNot	0
#define OverWorldMenuHandTouchedScreen		1

#define OverWorldMenuHandInActive		0
#define OverWorldMenuHandSwipeRight	1
#define OverWorldMenuHandSwipeLeft		2
#define OverWorldMenuHandSwipeAmount	2

#define OverWorldMenuActiveScreenRotationStartValueForSixtyHertz	0.0f

#define OverWorldMenuInactiveScreenFormat			PVR_TXRFMT_ARGB4444



#define OverWorldMenuConfirmationModeInActive				0
#define OverWorldMenuConfirmUse								1
#define OverWorldMenuConfirmDelete							2
#define OverWorldMenuItemScreenConfirmationModeAmount	2

#define OverWorldMenuConfirmationNo				0
#define OverWorldMenuConfirmationYes			1
#define OverWorldMenuConfirmationOptionAmount	2

#define OverWorldMenuConfirmationModeActive(ConfirmationMode)	(ConfirmationMode.Mode)
#define OverWorldMenuConfirmationActivate(ConfirmationMode, x)	 {ConfirmationMode.Mode = x;}
#define OverWorldMenuConfirmationDisable(ConfirmationMode) {ConfirmationMode.Mode = OverWorldMenuConfirmationModeInActive;}
#define OverWorldMenuConfirmationMode(ConfirmationMode)	(ConfirmationMode.Mode)
#define OverWorldMenuConfirmed(ConfirmationMode)				(ConfirmationMode.Confirmed)
#define OverWorldMenuChangeConfirmation(ConfirmationMode)	{ConfirmationMode.Confirmed = (ConfirmationMode.Confirmed+1)%OverWorldMenuConfirmationOptionAmount;}

#define OverWorldMenuItemDeletable(ItemSelected)	(OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemHeaderLoadableData[StolarOverWorldData->StolarData->ItemData.ItemList[ItemSelected]].Deletable)
#define OverWorldMenuItemUsable(ItemSelected)	(OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemHeaderLoadableData[StolarOverWorldData->StolarData->ItemData.ItemList[ItemSelected]].Usable)


#define OverWorldMenuDivaScreenSingleLogScreenInitiate()	{ OverWorldMenuData->DivaData.LogEntryActualArrayDisplayedUp = 0.0f; OverWorldMenuData->DivaData.LogEntryActualArrayDisplayedDown = OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayScreenDisplayAmount;}
#define OverWorldMenuDivaScreenSingleCharacterScreenInitiate()	{ OverWorldMenuData->DivaData.CharacterDescriptionDisplayedUp = 0.0f; OverWorldMenuData->DivaData.CharacterDescriptionDisplayedDown = OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionScreenDisplayAmount;}

#define OverWorldMenuDivaMainOptionAmount		4

#define OverWorldMenuDivaScreenMainOptionParser(x)			(1 << x)

#define OverWorldMenuDivaMainScreenActiveFlag					(1 << 0)
#define OverWorldMenuDivaLogScreenActiveFlag					(1 << 1)
#define OverWorldMenuDivaCharacterScreenActiveFlag			(1 << 2)
#define OverWorldMenuDivaTheatreScreenActiveFlag				(1 << 3)
#define OverWorldMenuDivaSingleLogScreenActiveFlag			(1 << 4)
#define OverWorldMenuDivaSingleCharacterScreenActiveFlag		(1 << 5)
#define OverWorldMenuDivaNoScreenActiveFlag					(1 << 6)


#define TheatreThumbnailAmountOverall							0

#define OverWorldMenuUseItemNothing					0
#define OverWorldMenuUseItemButtonPressed			1
#define OverWorldMenuUseItemSelectedJustNow		2

#define OverWorldMenuDivaScreenNoExpand	0
#define OverWorldMenuDivaScreenExpand		1
#define OverWorldMenuDivaScreenDexpand	2

#define CurrentObjectiveArrayMaximumLength	32

#define HertzSelectScreenStageBuildUp		0
#define HertzSelectScreenStageNormal		1
#define HertzSelectScreenStageBuildDown	2
#define HertzSelectScreenStageFinished	3
#define HertzSelectScreenStageFirst		HertzSelectScreenStageBuildUp
#define HertzSelectScreenStageFinal		HertzSelectScreenStageFinished


#define HertzSelectScreenSelectScreen		0
#define HertzSelectScreenTestScreen		1
#define HertzSelectScreenFirstScreen		HertzSelectScreenSelectScreen

#define HertzSelectScreenSelectOptionFiftyHertz	0
#define HertzSelectScreenSelectOptionSixtyHertz	1
#define HertzSelectScreenSelectOptionTest		2
#define HertzSelectScreenSelectOptionAmount	3
#define HertzSelectScreenSelectOptionFirst		HertzSelectScreenSelectOptionFiftyHertz

#define DogmaScreenStageLogoBuildUp		0
#define DogmaScreenStageLogoBuildUpAfterWait 		1
#define DogmaScreenStageBuildDown	2
#define DogmaScreenStageFinished	3
#define DogmaScreenStageFirst		DogmaScreenStageLogoBuildUp

#define RedSpotScreenStageBuildUp	0
#define RedSpotScreenStageBuildUpAfterWait	1
#define RedSpotScreenStageRedSpotExpand	2
#define RedSpotScreenStageBackGroundFadeIn	3
#define RedSpotScreenStageBackGround	4
#define RedSpotScreenStageEffect	5
#define RedSpotScreenStageBuildDown	6
#define RedSpotScreenStageFinished	7
#define RedSpotScreenStageFirst	RedSpotScreenStageBuildUp

#define RedSpotScreenMovingArrayAmount	10

#define TitleScreenStageBuildUp			0
#define TitleScreenStageInputWait		1
#define TitleScreenStageBuildDown		2
#define TitleScreenStageZoomOut		3
#define TitleScreenStageFinished		4

#define TitleScreenStageFirst		TitleScreenStageBuildUp

#define EventInducedLoopValueNot		0
#define EventInducedLoopValueYes		1

#define NewFrameStandardValue	0
#define NewTicksStandardValue		0
#define NewDamageStandardValue		0
#define NewAbilityFilledNowStandardValue	0



#define AnimationFactorStandard		1.0f

#define FactorPositive					1
#define FactorNegative					-1

#define OverWorldLogicGeneralOverWorldLoopNot		0
#define OverWorldLogicGeneralOverWorldLoop			1

#define OverWorldLogicMusicCurrentTrackStartValue	0

#define TileLogicStartMenuNot			0
#define TileLogicStartMenu				1

#define TileLogicSingleActiveNot			0
#define TileLogicSingleActive				1

#define TileLogicSingleLoadNot			0
#define TileLogicSingleLoad				1

#define TileLogicSingleDrawNot			0
#define TileLogicSingleDraw				1

#define TileLogicSingleAnimateNot		0
#define TileLogicSingleAnimate			1

#define TileLogicArtificialIntelligenceEnabledNot		0
#define TileLogicArtificialIntelligenceEnabled			1

#define TileDrawAnimationReset		PlayerIdleAnimation
#define FightDrawAnimationReset	TileDrawAnimationReset	

#define LogicMovementNoMovement		0.0f

#define LogicActiveNot	0
#define LogicActive		1

#define FightLogicSingleActiveNot			0
#define FightLogicSingleActive				1

#define FightLogicEnemyHitNot				0
#define FightLogicEnemyHit					1

#define TileLogicFlagEverything			0xF
#define FightLogicFlagEverything			TileLogicFlagEverything

#define TileDrawFlagBackGround		(1<<0)
#define TileDrawFlagStolar				(1<<1)
#define TileDrawFlagPeople				(1<<2)
#define TileDrawFlagNormalEnemies		(1<<3)
#define TileDrawFlagSpecialEnemies	(1<<4)
#define TileDrawFlagNothing				0
#define TileDrawFlagEverything			TileLogicFlagEverything

#define TileAnimationFlagBackGround			TileDrawFlagBackGround
#define TileAnimationFlagStolar					TileDrawFlagStolar
#define TileAnimationFlagPeople					TileDrawFlagPeople
#define TileAnimationFlagNormalEnemies		TileDrawFlagNormalEnemies
#define TileAnimationFlagSpecialEnemies		TileDrawFlagSpecialEnemies
#define TileAnimationFlagNothing				TileDrawFlagNothing
#define TileAnimationFlagEverything				TileDrawFlagEverything

#define TileEnableFlagMenu						(1<<0)
#define TileEnableFlagEventCheck				(1<<1)
#define TileEnableFlagEventHandler				(1<<2)
#define TileEnableFlagMovementPlayer			(1<<3)
#define TileEnableFlagArtificialIntelligence		(1<<4)
#define TileEnableFlagNothing					0
#define TileEnableFlagEverything					TileLogicFlagEverything

#define FightDrawFlagBackGround				(1<<0)
#define FightDrawFlagStolar						(1<<1)
#define FightDrawFlagEnemies					(1<<2)
#define FightDrawFlagEverything			FightLogicFlagEverything

#define FightAnimationFlagBackGround			FightDrawFlagBackGround
#define FightAnimationFlagStolar					FightDrawFlagStolar
#define FightAnimationFlagEnemies				FightDrawFlagEnemies
#define FightAnimationFlagNothing				0
#define FightAnimationFlagEverything			FightLogicFlagEverything


#define FightEnableFlagStolarMovement			(1<<0)
#define FightEnableFlagNothing					0
#define FightEnableFlagEverything				FightLogicFlagEverything



#define ForceTransformationDataGeneral						0
#define ForceTransformationDataStolar							1
#define ForceTransformationDataBackGroundGeneral			2
#define ForceTransformationDataBackGroundSpecific			3
#define ForceTransformationDataPeopleGeneral				4
#define ForceTransformationDataPeopleSpecific				5
#define ForceTransformationDataNormalEnemiesGeneral		6
#define ForceTransformationDataNormalEnemiesSpecific		7
#define ForceTransformationDataSpecialEnemiesGeneral		8
#define ForceTransformationDataSpecialEnemiesSpecific		9

#define TileFlagParseTypeSingleFlag			0
#define TileFlagParseTypeCombinationOr	1
#define TileFlagParseTypeCombinationAnd	2

#define TileFlagLogicalNotNot		0
#define TileFlagLogicalNot			1

#define TileMovementInverseInterPolationPower	2

#define InterPolationTypeLogarithmic	0
#define InterPolationTypeNegativeQuadratic	1
#define InterPolationTypeQuadratic	2
#define InterPolationTypeNegativeLinear	3

#define LinearInterPolationNormalizedRange	1.0f
#define LinearInterPolationSmoothRange	1000.0f

#define FightDrawEnemyIdleAnimation		0

#define FightDrawAbilitiesThresholdToTexturePaletteOffsetTransparent	0
#define FightDrawAbilitiesThresholdToTexturePaletteOffsetOpaque		1

#define FightDrawTransformationDataPersonalAmount		2

#define FightCollisionCheckPlayerDependent	0
#define FightCollisionCheckEnemyDependent	FightCollisionCheckPlayerDependent

#define FightAbilityHittableNot	0
#define FightAbilityHittable		1

#define AbilityFunctionAmount	2

#define AbilityFunctionArguments	FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichPlayer, uint8 WhichAbility, uint8 WhichButton, uint32 ButtonFlags
#define AbilityLoadFunctionArguments		FightStruct* FightData, OverWorldStruct* OverWorldData, OverWorldCrewFluxAbilityStruct* OverWorldCrewFluxAbilityData


#define FightFloatingValueStageBuildUp			0
#define FightFloatingValueStageNormal			1
#define FightFloatingValueStageBuildDown		2
#define FightFloatingValueStageOver				3

#define FightEnemyIdle(WhichEnemy)		(FightData->EnemyData[WhichEnemy].LogicData.CurrentAnimation == FightData->EnemyData[WhichEnemy].Loadable->AnimationIdle || FightData->EnemyData[WhichEnemy].LogicData.CurrentAnimation == FightData->EnemyData[WhichEnemy].Loadable->AnimationMovement)

#define FightPhysicsVelocityStandardValueX	0.0f

#define PhysicsForceNot				0.0f
#define PhysicsAccelerationNot		0.0f
#define PhysicsVelocityNot			0.0f

#define TileMovementTypeArguments		TileStruct* TileData, OverWorldStruct* OverWorldData, uint8 WhichObject, uint8 WhichInstance

#define TileMovementTypeNothingIdentifier		0
#define TileMovementTypePlayerIdentifier	1
#define TileMovementTypeFollowPlayerIdentifier '?'
#define TileMovementTypeAmount	2

#define TileObjectFirst		0

#define FightObjectsSingleObjectSingleInstancePhysicsNormalIdentifier		0
#define FightObjectsSingleObjectSingleInstancePhysicsFunctionAmount		1

#define TileBackGroundInstanceAnimationValue	0
#define FightBackGroundInstanceAnimationValue	0

#define FightHealthEmpty								0

#define FightObjectsSingleObjectSingleInstanceIntelligenceFunctionArguments			FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichIntelligence

#define FightPlayerIntelligenceIdentifierMovement		2
#define FightPlayerIntelligenceIdentifierAbilities		3
#define FightPlayerIntelligenceAmount	7

#define FightEnemyIntelligenceIdentifierStateMachine		2
#define FightEnemyIntelligenceAmount	4


#define SpeechinatorBuildDataSpeechBubbleRowAmountMaximum	10

#define FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineDoNothing			0
#define FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineDeathAnimation	1
#define FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineStartWalking		2
#define FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineAttackMeleeAnimation		3
#define FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineAttackMeleeDeLoad		4

#define FightObjectsSingleObjectSingleInstanceBlockageFunctionNoneIdentifier		0
#define FightObjectsSingleObjectSingleInstanceBlockageFunctionBoxIdentifier		1

#define FightObjectsSingleObjectSingleInstanceBlockageFunctionAmount	2

typedef uint16 					StoryFlagsAmountUnit;
typedef char					sint8;
typedef signed short			sint16;
typedef signed long			sint32;
typedef signed long long		sint64;



#define StoryBoardMaximumTextSize			0x100
#define StoryBoardMaximumTextureAmount			6
#define StoryBoardMaximumTextAmount			3
#define StoryBoardMaximumSoundEffectAmount		2

#define StoryBoardDestroyTextureIdentifier		0
#define StoryBoardLoadTextureIdentifier			1
#define StoryBoardChangeTextureIdentifier		2

#define StoryBoardTextureStructIdentifier		0
#define StoryBoardTextStructIdentifier			1
#define StoryBoardSoundEffectStructIdentifier		2
#define StoryBoardStructAmount				3

#define StoryBoardDestroyTextIdentifier			0

#define StoryBoardDestroySoundEffectIdentifier		0

#define MaxCharsOnScreen 				2
#define CharacterOne 					0
#define CharacterTwo 					1
#define MaxCharsLoopValue 				1

#define NoAllocateTextureMemory 			0
#define ReAllocateTextureMemory 			1
#define PreAllocateTextureMemory 			1
