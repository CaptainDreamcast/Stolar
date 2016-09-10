typedef struct{

float x;
float y;

} Vector2D;

typedef struct{

Vector2D TopLeft;
Vector2D TopRight;
Vector2D DownLeft;
Vector2D DownRight;

} BoxStruct;

typedef struct ListStruct{

struct ListStruct* Previous;
struct ListStruct* Next;

void* Element;

} ListStruct;

typedef struct{

pvr_ptr_t Texture;
uint8 MovementX;
uint16 PositionX;
uint16 FinalPositionX;

} RedSpotGamesLightingStruct;

typedef struct{

uint8 ItemList[ItemAmountMaxOverall];
uint8 EquipmentList[ItemAmountMaxOverall];

uint16 ItemAmountMax;

} StolarItemStruct;

typedef struct{

uint8 AbilityList[OverallAbilityAmount];

} StolarAbilityStruct;

typedef struct{

short HealthMax;
short HealthNow;

uint8 Level;
uint8 Separator1[3];

uint8 Attack;
uint8 Defense;
uint8 Speed;
uint8 Luck;

uint16 Ability[AbilityAmount]; 

uint16 ExperienceNecessary;
uint16 ExperienceCurrent;

StolarItemStruct ItemData;
StolarAbilityStruct AbilityData;

} StolarDataStruct;

typedef struct{

uint16 TextureOffset;
uint16 FrameAmount;

float AnimationDurationInSeconds;

} AnimationStruct;

typedef struct{

uint8 ButtonInputAllowed;
uint8 ButtonIsLegit;
uint8 Separator1[2];

} ButtonInputStruct;

typedef struct{

uint16 ReactionAnimation;
uint8 ReactionFrame;
uint8 Active;

int DamagePending;

} StolarTakingDamageStruct;

typedef struct{

StolarDataStruct* StolarData;
AnimationStruct* StolarAnimationData;

float PositionX;
float PositionY;

float SizeX;
float SizeY;

uint16 CurrentAnimation;
uint8 CurrentFrame; //starts with "0";
uint8 AnimationTicks; //starts with "0";

float AnimationFactor;
float FactorBuildUp;

uint8 FaceDirection;
uint8 SpecialEvent;
short SpecialEventTicks;

uint8 EventInducedLoop;
uint8 Separator2[3];

float StagePositionZ;
float ScreenPositionZ;

float StoredUpVelocityX;
float StoredUpVelocityY;

float StoredUpVelocityZ;


StolarTakingDamageStruct* TakingDamageData;


} StolarFightStruct;

typedef struct{

uint16 SizeX;
uint16 SizeY;

short HealthMax;
short HealthNow;

uint8 Attack;
uint8 Defense;
uint8 Speed;
uint8 Luck;

uint8 ArtificialIntelligence;
uint8 TexturesNeeded;
short StackNeeded; //16

uint8 ExperienceGained;
uint8 AnimationAmount;
uint8 PaletteType;
uint8 PaletteIdentifier;

uint16 TextureSizeX;
uint16 TextureSizeY;

short HitOffset[HitOffsetDirections];

} EnemyDataStruct;

typedef struct{

EnemyDataStruct EnemyData;
AnimationStruct* EnemyAnimationData;

uint8 Active; // Has more flags-> !0 means drawn
uint8 FaceDirection;
uint16 PalettePosition;

float PositionX;
float PositionY;

float SizeX;
float SizeY;

uint16 CurrentAnimation;
uint8 CurrentFrame;
uint8 AnimationTicks;

pvr_ptr_t* Texture;
uint8* Stack;

float AnimationFactor;
float FactorBuildUp;
float StagePositionZ;
float ScreenPositionZ;

float StoredUpVelocityX;
float StoredUpVelocityY;
float StoredUpVelocityZ;
int DamagePending;

uint8 WhatIsHappeningHere;
uint8 ReactionFrame;
uint16 ReactionAnimation;

} EnemyFightStruct;



typedef struct{

uint16 StageSizeX;
uint16 StageSizeY;

uint16 StageSizeMinZ;
uint16 StageSizeMaxZ;

uint16 StagePositionX;
uint16 StagePositionY;

uint16 StolarStartPositionX;
uint16 StolarStartPositionY;

float StolarStartStagePositionZ;
float StolarStartScreenPositionZ;

uint16 StolarSizeX;
uint16 StolarSizeY;

uint16 StageIdentifier;
uint8 TextureAmount;
uint8 AnimationAmount;

float StolarSpeedX;
float StolarSpeedY;

float StolarStageSpeedZ;
float StolarScreenSpeedZ;

float StolarSizeChangeZ;
float Gravity;

float AirResistance;

} FightLocationDataStruct;

typedef struct{

FightLocationDataStruct LocationData;
AnimationStruct* AnimationData;

uint16* LayerSizeX;
uint16* LayerSizeY;

uint16* TextureSizeX;
uint16* TextureSizeY;

short* TexturePositionX;
short* TexturePositionY;

short* TexturePositionZ;
uint16* CurrentFrame;

uint8* Ticks;

float AnimationFactor;
float FactorBuildUp;

pvr_ptr_t* Texture;

} FightLocationStruct;

typedef struct{

uint8 Active;
uint8 Separator1[3];

vector_t PositionVector;

float ScaleValueX;
float ScaleValueY;
float RotationValueX;
float RotationValueY;
float RotationValueZ;

} TransformationStruct;


typedef struct{

uint8 Active;
uint8 Separator[3];

uint16 TextureSizeX;
uint16 TextureSizeY;

short FilledNow;
short FilledMax;

} AbilityStruct;


typedef struct{

uint16 HealthBackGroundTextureSizeX;
uint16 HealthBackGroundTextureSizeY;

uint16 HealthTextureSizeX;
uint16 HealthTextureSizeY;

uint16 PausePositionX;
uint16 PausePositionY;

uint16 PauseSizeX;
uint16 PauseSizeY;

} GraphicalUserInterFaceLoadStruct;

typedef struct{

GraphicalUserInterFaceLoadStruct GraphicalUserInterFaceLoadData;
AbilityStruct AbilityData[AbilityAmount];

pvr_ptr_t HealthBackGroundTexture;
pvr_ptr_t HealthTexture;

pvr_ptr_t ThresholdTexture;
pvr_ptr_t FinalBarTexture[AbilityAmount];
pvr_ptr_t AbilityTexture[AbilityAmount];

pvr_ptr_t DistortionTexture;
pvr_ptr_t ScanLineTexture;
pvr_ptr_t PauseTexture;

pvr_ptr_t EscalationTexture[EscalationTextureAmount];

pvr_ptr_t GameOverScreenTexture[GameOverScreenTextureAmount];
} GraphicalUserInterFaceStruct;

typedef struct{



} AbilityFightStruct;

typedef struct{

float ScanLinePositionY;
float ScanLineEndPositionY;

float DistortionPositionX;
float DistortionSpeedX;

uint16 TwitchTicks;
uint16 FlipTicks;
float ScanLineSpeedY;

} PauseStruct;

typedef struct{

short PositionX[EscalationDrawnAmount];
short PositionY[EscalationDrawnAmount];
short SpeedX;

uint8 CurrentFrame;
uint8 Ticks;

} EscalationStruct;

typedef struct{

uint8 Active;
uint8 Color;
uint16 Ticks;

float PositionX;
float PositionY;

char String[FloatingValueMaxLength];

} SingleFloatingValueStruct;


typedef struct{

uint8 Type;
uint8 Not;

} TileFlagParseLoadableStruct;


typedef struct{

TileFlagParseLoadableStruct* Loadable;

} TileFlagParseStruct;


typedef struct{

StoryFlagsAmountUnit WhichFlag;

} TileFlagSingleFlagLoadableSpecificStruct;


typedef struct{

TileFlagParseLoadableStruct General;
TileFlagSingleFlagLoadableSpecificStruct Specific;

} TileFlagSingleFlagLoadableStruct;


typedef struct{

TileFlagSingleFlagLoadableStruct* Loadable;

} TileFlagSingleFlagStruct;


typedef struct{

uint8 Amount;
uint8 Separator1;

} TileFlagCombinationLoadableSpecificStruct;


typedef struct{

TileFlagParseLoadableStruct General;
TileFlagCombinationLoadableSpecificStruct Specific;

} TileFlagCombinationLoadableStruct;


typedef struct{

TileFlagCombinationLoadableStruct* Loadable;
TileFlagParseStruct** FlagData;

} TileFlagCombinationStruct;

typedef struct{

uint8 FaceDirection;
uint8 Separator1[3];

float StartPositionX;
float StartStagePositionZ;

} OverWorldCrewLogicTileStruct;

typedef struct{

uint16 HealthMax;

} OverWorldCrewLogicFightStruct;

typedef struct{

OverWorldCrewLogicTileStruct Tile;
OverWorldCrewLogicFightStruct Fight;

} OverWorldCrewLogicStruct;

typedef struct{

pvr_ptr_t Texture;
uint8 NextUp;
uint8 MaximumAmount;
SingleFloatingValueStruct* SingleValueData;

} FloatingValueStruct;

typedef struct{

uint16 CurrentTile;
uint8 Hours;
uint8 Minutes;

uint8 Day;
uint8 Month;
uint16 Year;

uint8 Level;
uint8 Separator1[3];

} SaveHeaderStruct;

typedef struct{

OverWorldCrewLogicStruct CrewLogic[CrewSizeMaximum];


uint8 Seconds;
uint8 Frames;
uint8 LogEntryAmount;
uint8 CharacterEntryAmount;

uint8 CrewSize;
uint8 Separator1[3];

uint8 PlayerIsWhichCrewMember[PlayerAmountMaximum];
uint8 CrewMemberIdentifier[CrewSizeMaximum];
uint16 CrewMemberAbility[CrewSizeMaximum][AbilityAmount];

char CurrentObjectiveArray[CurrentObjectiveArrayMaximumLength];

float StagePositionX;
float StagePositionY;

float GoalPositionOnMapInRelationX;
float GoalPositionOnMapInRelationY;

uint8 StoryFlags[StoryFlagByteAmount];
uint8 SpecialEnemyFlags[SpecialEnemyFlagByteAmount];

} SaveCompressableStruct;

typedef struct{

uint64 LoadedTime;
SaveHeaderStruct* HeaderData;
SaveCompressableStruct* CompressableData;

} SaveStruct;

typedef struct{

uint8 Type;
uint8 Separator1[3];

float Factor;
float Constant;
float Displacement;

} InterPolationStruct;

typedef struct{

float Factor;
float Constant;

} TileMovementLogicSingleStruct;

typedef struct{

TileMovementLogicSingleStruct PositionY;
TileMovementLogicSingleStruct ScreenPositionZ;
TileMovementLogicSingleStruct SizeFactorX;
TileMovementLogicSingleStruct SizeFactorY;
TileMovementLogicSingleStruct SpeedFactorX;

} TileMovementLogicStruct;

typedef struct{

float StartValue;
float EndValue;

} TileMovementLoadableSingleStruct;

typedef struct{

TileMovementLoadableSingleStruct PositionY;
TileMovementLoadableSingleStruct ScreenPositionZ;
TileMovementLoadableSingleStruct SizeFactorX;
TileMovementLoadableSingleStruct SizeFactorY;
TileMovementLoadableSingleStruct SpeedFactorX;

} TileMovementLoadableStruct;

typedef TileMovementLogicSingleStruct LinearInterPolationSimpleStruct;

typedef struct{

uint16 LayOutSizeX;
uint16 LayOutSizeY;

} LayOutBufferHeaderStruct;

typedef struct{

TileMovementLoadableStruct Movement;

} TileHeaderStolarStruct;

typedef struct{

uint8 Outro;
uint8 Separator1[3];

} TileHeaderFightStruct;

typedef struct{

uint16 TileIdentifier;
uint8 LocationNameSize;
uint8 TileNameSize;

uint16 TileAbsoluteSizeX;
uint16 TileAbsoluteSizeY;

uint8 SpriteAmount;
uint8 PersonAmount;
uint8 AnimationAmount;
uint8 MusicAmount;	

uint8 MaximumActiveEventAmount;
uint8 ObjectAmount;
uint16 EventPlayerAmount;

float StagePositionStartZ;
float StagePositionEndZ;

float StageSpeedZ;
float TileAbsoluteStageSizeZ;

LayOutBufferHeaderStruct LayOutBuffer;

TileMovementLoadableStruct Movement;

TileHeaderFightStruct Fight;

} TileHeaderStruct;

typedef struct{

uint8 EntranceType;
uint8 FaceDirection;
uint8 IntroType;
uint8 DisplayLocation;

float PositionX;
float PositionY;
float SizeX;
float SizeY;
float SpeedX;
float StagePositionZ;
float ScreenPositionZ;

float StagePositionX;
float StagePositionY;
} EntranceStruct;

typedef struct{
uint16 ToWhichTile;
uint8 ToWhichEntrance;
uint8 ExitType;

uint8 OutroType;
uint8 Arrow;
uint8 WhichArrow;
uint8 ArrowColor;

float PositionX;
float PositionY;
float SizeX;
float SizeY;

float ArrowPositionX;
float ArrowPositionY;
float ArrowPositionZ;
float ArrowSizeFactor;

uint8 CheckedStoryFlagAmount;
uint8 UnCheckedStoryFlagAmount;
uint8 StoryFlagSeparator[2];
} ExitLoadableStruct;

typedef struct{

ExitLoadableStruct* Loadable;

StoryFlagsAmountUnit* CheckedStoryFlags;
StoryFlagsAmountUnit* UnCheckedStoryFlags;

} ExitStruct;


typedef struct{

uint8 EventButtons;
uint8 Separator1[3];

uint16 EventBufferSize;
uint16 WhichEvent;

} EventLoadableStruct;

typedef struct{

uint8 Load;
uint8 Active;

} EventLogicStruct;

typedef struct{

TileFlagParseStruct* Load;
TileFlagParseStruct* Active;

} EventFlagStruct;

typedef struct{

EventLoadableStruct* Loadable;
EventLogicStruct LogicData;
EventFlagStruct FlagData;
void* EventBuffer;

} EventStruct;

typedef struct{

uint16 Type;
uint8 Separator1[2];

uint32 Size;

} TileEventSingleLoadableGeneralStruct;

typedef struct{

BoxStruct Box;

} EventSelfLoadableStruct;

typedef struct{

EventSelfLoadableStruct* Loadable;
EventStruct EventData;

} EventSelfStruct;

typedef struct{
uint16 WhichTile;
uint16 WhichMusic;

uint8 Priority;
uint8 Separator1[3];

} LoadTileLoadableStruct;

typedef struct{
LoadTileLoadableStruct* Loadable;
} LoadTileStruct;

typedef struct{
uint16 WhichTile;
uint8 Separator1[2];
} DeLoadTileLoadableStruct;

typedef struct{

DeLoadTileLoadableStruct* Loadable;

} DeLoadTileStruct;

typedef struct{

uint8 WhichPlayer;

} EventKnowledgeStruct;

typedef struct{

uint16 WhichEvent;
uint8 EventHandled;

uint32 EventBufferSize;

EventKnowledgeStruct KnowledgeData;

} ActiveEventLogicStruct;


typedef struct{

} ActiveEventLogicSingleStruct;


typedef struct{

ActiveEventLogicStruct LogicData;
ActiveEventLogicSingleStruct LogicSingleData;

void* EventBufferPosition;
void* EventBufferStart;
void* EventTemporaryBuffer;

} ActiveEventStruct;

typedef struct{

uint8 Type;
uint8 Draw;
uint16 Identifier;

uint16 Speed;
uint16 CurrentFrame;

uint16 FrameAmount;
uint8 Separator1[2];

uint16 Ticks;
uint16 Duration;

uint16 TextureSizeX;
uint16 TextureSizeY;

float MovementX;
float MovementY;

float Up;
float Left;
float Down;
float Right;

float ScaleValue;
float AlphaValue;

float SizeX;
float SizeY;

vector_t PositionVector;
pvr_ptr_t* TexturePointer;

} EventSpecialAnimationActualStruct;

typedef struct{

uint16 EventSpecialAnimationAmount;
uint8 Separator1[2];

EventSpecialAnimationActualStruct* ActualData;

} EventSpecialAnimationStruct;

typedef struct{

StolarDataStruct* StolarData;
AnimationStruct* StolarAnimationData;
void* AnimationDataBuffer;

pvr_ptr_t* StolarTexture;

float PositionX;
float PositionY;

float SizeX;
float SizeY;

float SpeedX;

uint16 CurrentAnimation;
uint8 CurrentFrame; 
uint8 AnimationTicks; 

float AnimationFactor;
float FactorBuildUp;

uint8 FaceDirection;
uint8 EventInducedLoop;
uint8 Separator1[2];

float StagePositionZ;
float ScreenPositionZ;

} StolarOverWorldStruct;


typedef struct{


uint8 WhichSpecialAnimation;
uint8 BuildUp;
uint16 ArrayPosition;


float PositionX;
float PositionY;
float ScaleValue;
float* FontPositionX;
float FontPositionY;

} SpeechBubbleActiveStruct;

typedef struct{

uint8 TextureType;
uint8 WhichFont;
uint16 ArrayLength;

uint16 Identifier;
uint16 FrameAmount;

uint16 Speed;
uint8 RowAmount;
uint8 BuildUp;

uint16 FontSizeX;
uint16 FontSizeY;

uint8 FontColor;

float PositionX;
float PositionY;
float PositionZ;

float SizeX; 
float SizeY; 

float ScaleValue;
float FontPositionY;
float FontPositionZ;

float* FontPositionX;
char* ActualArray;

} SpeechBubbleStruct;

typedef struct{

uint8 WhichSpecialAnimation;

} SpriteActiveStruct;

typedef struct{

uint8 Active;
uint16 FrameAmount;

uint16 SpriteIdentifier;
uint8 FaceDirection;
uint8 EntranceType;

uint16 Speed;
uint16 StartFrame;
uint16 TextureSizeX;
uint16 TextureSizeY;

float Up;
float Left;
float Down;
float Right;

float SizeX;
float SizeY;

float PositionX;
float PositionY;
float PositionZ;

float ScaleValue;

pvr_ptr_t Texture;

} SpriteStruct;

typedef struct{

uint16 TextureSizeX;
uint16 TextureSizeY;

float InterLetterSpaceX;
float InterLetterSpaceY;

} FontHeaderStruct;

typedef struct{

float RelativeDrawOffsetUp;
float RelativeSizeX;
float RelativeSizeY;

float TextureFileOffsetLeft;
float TextureFileOffsetUp;
float TextureFileOffsetRight;
float TextureFileOffsetDown;

} FontSingleLetterStruct;

typedef struct{

FontHeaderStruct FontHeaderData;
FontSingleLetterStruct FontSingleLetterData[FontOverallLetterAmount];

} FontLoadableStruct;

typedef struct{

FontLoadableStruct* Loadable;
pvr_ptr_t Texture;

} FontStruct;

typedef struct{
uint8 DeLoadTileAmount;
uint8 Separator1[3];
} DeLoadTileFileHeaderStruct;

typedef struct{

uint16 AnimationAmount;
uint8 Separator1[2];

} StolarTextureFileHeaderStruct;

typedef struct{

uint8 ZoomOutType;
uint8 Separator[3];

} OverWorldZoomOutIntroHeaderStruct;

typedef struct{

float PositionX;
float PositionY;

} SaveShowStruct;

typedef struct{

uint16 BackGroundTextureSizeX;
uint16 BackGroundTextureSizeY;

uint16 ControllerTextureSizeX;
uint16 ControllerTextureSizeY;

uint16 VisualMemoryTextureSizeX;
uint16 VisualMemoryTextureSizeY;

uint16 SaveShowTextureSizeX;
uint16 SaveShowTextureSizeY;

uint16 SpecialOptionTextureSizeX;
uint16 SpecialOptionTextureSizeY;

uint16 VisualMemorySelectorTextureSizeX;
uint16 VisualMemorySelectorTextureSizeY;

uint16 SaveDrawFontSizeX[LoadGameSaveDrawAmount];
uint16 SaveDrawFontSizeY[LoadGameSaveDrawAmount];


uint8 SaveDrawFontColor[LoadGameSaveDrawAmount];
uint8 SaveDrawWhichFont[LoadGameSaveDrawAmount];

float SaveDrawChangeOffsetX;
float VisualMemoryFinalPositionY[VisualMemoryPerController];
float SaveShowStartPositionX[LoadGameSaveShowStartPositionAmount];
float SaveShowEndPositionX[LoadGameSaveShowStartPositionAmount];
float SaveDrawStartPositionX[LoadGameSaveShowStartPositionAmount];
float SaveDrawStartPositionY[LoadGameSaveShowStartPositionAmount];
float SaveDrawFontPositionZ;
float SaveDrawZoomFactor;


vector_t VisualMemoryStartVector[DreamcastVisualMemoryAmount];
vector_t VisualMemoryFinalVector[DreamcastVisualMemoryAmount];
vector_t SpecialOptionPositionVector[LoadGameSpecialOptionAmount];

} LoadScreenBackGroundLoadableStruct;

typedef struct{

LoadScreenBackGroundLoadableStruct* Loadable;
SaveShowStruct SaveShowData;

pvr_ptr_t BackGroundTexture;
pvr_ptr_t SaveShowTexture;
pvr_ptr_t ControllerTexture[LoadGameControllerTextureAmount];
pvr_ptr_t VisualMemoryTexture[LoadGameVisualMemoryTextureAmount];
pvr_ptr_t SpecialOptionTexture[LoadGameSpecialOptionAmount];
pvr_ptr_t SelectorTexture[LoadGameSelectorTransmorphTextureAmount];

TransformationStruct SelectedVisualMemoryTransformationData;

float BackGroundPositionX;

uint8 CurrentPort;
uint8 CurrentSlot;
uint8 WhichSelectorTexture;

vector_t VisualMemorySelectorPositionVector;

} LoadScreenBackGroundStruct;

typedef struct{

SaveHeaderStruct* Data;
uint16 WhichFile;

} SingleSaveStruct;

typedef struct{

uint8 Active;
uint8 Separator1;
uint16 SaveAmount;

float PositionX;
float PositionY;

SingleSaveStruct* SingleSaveData;

} LoadScreenVisualMemoryStruct;

typedef struct{

float PositionX;
float PositionY;

} LoadScreenControllerLoadableStruct;

typedef struct{

uint8 Active;

LoadScreenControllerLoadableStruct* Loadable;
LoadScreenVisualMemoryStruct LoadScreenVisualMemoryData[VisualMemoryPerController]; 
TransformationStruct TransformationData;

} LoadScreenControllerStruct;

typedef struct{
float Left;
float Right;
float Up;
float Down;
} PositionInFileStruct;

typedef struct{

char* ConfirmationArrayBeforeItemName[OverWorldMenuItemScreenConfirmationModeAmount];
char* ConfirmationArrayAfterItemName[OverWorldMenuItemScreenConfirmationModeAmount];
char* DescriptionArray;
char* Name;

} SingleItemHeaderStruct;

typedef struct{

uint8 Usable;
uint8 Deletable;
uint8 ItemType;

uint8 ConfirmationArrayBeforeItemNameLength[OverWorldMenuItemScreenConfirmationModeAmount];
uint8 ConfirmationArrayAfterItemNameLength[OverWorldMenuItemScreenConfirmationModeAmount];
uint16 DescriptionArrayLength;
uint8 NameLength;

uint16 SingleItemFlexibleDataLength;

} SingleItemHeaderLoadableStruct;

typedef struct{
uint8 Mode;
uint8 Confirmed;
} OverWorldMenuConfirmationModeStruct;

typedef struct{

uint8 HandActive;
uint8 HandFrame;
uint8 HandTouchedScreen;
uint8 Separator1;

float HandPositionX;

} OverWorldMenuBackGroundStruct;

typedef struct{

uint8 Stage;
uint8 ActiveScreen;
sint8 CaptureActiveScreen;

float ActiveScreenRotationSpeedY;

maple_device_t *cont;
cont_state_t *st;
TransformationStruct ActiveScreenTransformationData;
ButtonInputStruct ButtonInputData[ButtonAmount];

} OverWorldMenuLogicStruct;

typedef struct{
pvr_ptr_t ConfirmationMainBox;
pvr_ptr_t ConfirmationYes[OverWorldMenuConfirmationOptionAmount];
pvr_ptr_t ConfirmationNo[OverWorldMenuConfirmationOptionAmount];
} OverWorldMenuConfirmationTextureStruct;

typedef struct{

pvr_ptr_t BackGroundTexture;

} OverWorldMenuStatsScreenTextureStruct;

typedef struct{

float BackGroundPositionX;
float BackGroundPositionY;
float BackGroundPositionZ;

float MenuStolarPositionX;
float MenuStolarPositionY;
float MenuStolarPositionZ;

float MenuStolarSizeX;
float MenuStolarSizeY;

float LevelPositionX;
float LevelPositionY;
float HealthPositionX;
float HealthPositionY;
float AttackPositionX;
float AttackPositionY;
float DefensePositionX;
float DefensePositionY;
float SpeedPositionX;
float SpeedPositionY;
float LuckPositionX;
float LuckPositionY;
float ExperiencePositionX;
float ExperiencePositionY;

float FontPositionZ;
float FontSizeX;
float FontSizeY;

uint16 BackGroundTextureSizeX;
uint16 BackGroundTextureSizeY;

uint8 FontColor;
uint8 Font;

} OverWorldMenuStatsScreenLoadableStruct;


typedef struct{

float BackGroundPositionX;
float BackGroundPositionY;
float BackGroundPositionZ;

float PositionX;
float PositionY;
float PositionZ;

float SizeX;
float SizeY;

float IconPositionZ;

float FullZoomOutValueLeft;
float FullZoomOutValueRight;
float FullZoomOutValueUp;
float FullZoomOutValueDown;

float ZoomSpeedSixtyHertzX;
float ZoomSpeedSixtyHertzY;

float FullZoomInSizeX;
float FullZoomInSizeY;

float ScreenTraversalTimeInSecondsX;
float ScreenTraversalTimeInSecondsY;

uint16 BackGroundTextureSizeX;
uint16 BackGroundTextureSizeY;

uint16 TextureSizeX;
uint16 TextureSizeY;

uint16 IconTextureSizeX;
uint16 IconTextureSizeY;


} OverWorldMenuMapScreenLoadableStruct;

typedef struct{

uint8 CurrentPositionOnMapInRelationCalculated;

float CurrentPositionOnMapInRelationX;
float CurrentPositionOnMapInRelationY;

float Left;
float Right;
float Up;
float Down;

pvr_ptr_t BackGroundTexture;
pvr_ptr_t MapTexture;
pvr_ptr_t GoalIcon;
pvr_ptr_t StolarIcon;

} OverWorldMenuMapScreenStruct;

typedef struct{

float BackGroundPositionX;
float BackGroundPositionY;
float BackGroundPositionZ;

float ItemDrawStartPositionX;
float ItemDrawStartPositionY;
float ItemDrawEndPositionY;
float ItemDrawPositionZ;

float ItemDrawSizeX;
float ItemDrawSizeY;

float ScrollButtonPositionX;
float ScrollButtonStartPositionY;
float ScrollButtonPositionZ;

float ScrollButtonSizeX;
float ScrollButtonMinimumSizeY;
float ScrollButtonMaximumSizeY;

float ScrollableMovementPerSecondY;

float ItemDescriptionImageDrawPositionX;
float ItemDescriptionImageDrawPositionY;
float ItemDescriptionImageDrawPositionZ;

float ItemDescriptionImageDrawSizeX;
float ItemDescriptionImageDrawSizeY;

float ItemDescriptionTextDrawPositionX;
float ItemDescriptionTextDrawPositionY;
float ItemDescriptionTextDrawPositionZ;

float ItemDescriptionTextFontSizeX;
float ItemDescriptionTextFontSizeY;

float EquipmentDrawStartPositionX;
float EquipmentDrawStartPositionY;
float EquipmentDrawPositionZ;

float EquipmentDrawSizeX;
float EquipmentDrawSizeY;

uint16 ConfirmationArrayLengthMaximum;

uint16 BackGroundTextureSizeX;
uint16 BackGroundTextureSizeY;

uint16 ItemDrawTextureSizeX;
uint16 ItemDrawTextureSizeY;

uint16 ScrollButtonTextureSizeX;
uint16 ScrollButtonTextureSizeY;

uint8 ItemAmountPerRow;
uint8 DisplayedRowAmount;
uint8 ItemDescriptionTextFontColor;
uint8 ItemDescriptionTextWhichFont;

uint8 EquipmentAmount;
uint8 EquipmentAmountPerRow;

PositionInFileStruct SingleItemPositionInFile[OverallDistinguishableItemAmount];
SingleItemHeaderLoadableStruct SingleItemHeaderLoadableData[OverallDistinguishableItemAmount];

} OverWorldMenuItemScreenLoadableStruct;

typedef struct{

uint16 ItemSelected;

float DisplayedItemsUp;
float DisplayedItemsDown;

pvr_ptr_t BackGroundTexture;
pvr_ptr_t ScrollButtonTexture;
pvr_ptr_t AllItems;

OverWorldMenuConfirmationModeStruct ConfirmationMode;
SingleItemHeaderStruct SingleItemHeaderData[OverallDistinguishableItemAmount];
void* SingleItemFlexibleData[OverallDistinguishableItemAmount];

} OverWorldMenuItemScreenStruct;

typedef struct{

char* DescriptionArray;

} SingleAbilityHeaderStruct;

typedef struct{

uint8 WhichAbility;
uint16 DescriptionArrayLength;

} SingleAbilityHeaderLoadableStruct;


typedef struct{

float AbilityDrawStartPositionX;
float AbilityDrawStartPositionY;
float AbilityDrawEndPositionY;
float AbilityDrawPositionZ;

float SingleAbilityDrawSizeX;
float SingleAbilityDrawSizeY;

float ScrollButtonPositionX;
float ScrollButtonStartPositionY;
float ScrollButtonPositionZ;

float ScrollButtonSizeX;
float ScrollButtonMinimumSizeY;
float ScrollButtonMaximumSizeY;

float ScrollableMovementPerSecondY;

float AbilityDescriptionImageDrawPositionX;
float AbilityDescriptionImageDrawPositionY;
float AbilityDescriptionImageDrawPositionZ;

float AbilityDescriptionImageDrawSizeX;
float AbilityDescriptionImageDrawSizeY;

float AbilityDescriptionTextDrawPositionX;
float AbilityDescriptionTextDrawPositionY;
float AbilityDescriptionTextDrawPositionZ;

float AbilityDescriptionTextFontSizeX;
float AbilityDescriptionTextFontSizeY;

float EquippedAbilityBackGroundPositionX[(AbilityAmount-1)];
float EquippedAbilityBackGroundPositionY[(AbilityAmount-1)];
float EquippedAbilityBackGroundPositionZ;

float EquippedAbilityPositionX[(AbilityAmount-1)];
float EquippedAbilityPositionY[(AbilityAmount-1)];
float EquippedAbilityPositionZ;

float EquippedAbilityDrawSizeX;
float EquippedAbilityDrawSizeY;

uint8 AbilityAmountPerRow;
uint8 DisplayedRowAmount;
uint8 AbilityDescriptionTextFontColor;
uint8 AbilityDescriptionTextWhichFont;

uint16 AbilityDrawTextureSizeX;
uint16 AbilityDrawTextureSizeY;

uint16 ScrollButtonTextureSizeX;
uint16 ScrollButtonTextureSizeY;

uint16 EquippedAbilityBackGroundTextureSizeX;
uint16 EquippedAbilityBackGroundTextureSizeY;

PositionInFileStruct SingleAbilityPositionInFile[OverallAbilityAmount];
SingleAbilityHeaderLoadableStruct SingleAbilityHeaderLoadableData[OverallAbilityAmount];

} OverWorldMenuAbilityScreenLoadableStruct;

typedef struct{

float DisplayedAbilitiesUp;
float DisplayedAbilitiesDown;

uint8 AbilitySelected;
uint8 ActiveAbilitySelectedBoolean;
uint8 ActiveAbilitySelected;

SingleAbilityHeaderStruct SingleAbilityHeaderData[OverallAbilityAmount];

pvr_ptr_t AllAbilities;
pvr_ptr_t ScrollButtonTexture;
pvr_ptr_t EquippedAbilityBackGroundTexture[(AbilityAmount-1)];

} OverWorldMenuAbilityScreenStruct;


typedef struct{

float MainBackGroundPositionX;
float MainBackGroundPositionY;
float MainBackGroundPositionZ;

float MainOptionPositionX;
float MainOptionPositionY[OverWorldMenuDivaMainOptionAmount];
float MainOptionPositionZ;

float CurrentObjectiveArrayPositionX;
float CurrentObjectiveArrayPositionY;
float CurrentObjectiveArrayPositionZ;

float CurrentObjectiveArrayFontSizeX;
float CurrentObjectiveArrayFontSizeY;

float LogOptionBackGroundPositionX;
float LogOptionBackGroundPositionY;
float LogOptionBackGroundPositionZ;

float LogOptionDistanceY;

float LogOptionArrayPositionX;
float LogOptionArrayPositionY;
float LogOptionArrayPositionZ;

float LogOptionArrayFontSizeX;
float LogOptionArrayFontSizeY;

float LogEntryTitleArrayPositionX;
float LogEntryTitleArrayPositionY;
float LogEntryTitleArrayPositionZ;

float LogEntryTitleArrayFontSizeX;
float LogEntryTitleArrayFontSizeY;

float LogEntryActualArrayPositionX;
float LogEntryActualArrayPositionY;
float LogEntryActualArrayPositionZ;

float LogEntryActualArrayFontSizeX;
float LogEntryActualArrayFontSizeY;

float LogEntryActualArrayScreenDisplayAmount;
float LogEntryActualArrayDisplayMovementPerSecondY;

float SingleLogEntryMovementPerSecondX;

float CharacterEntryBackGroundPositionX;
float CharacterEntryBackGroundPositionY;
float CharacterEntryBackGroundPositionZ;

float CharacterEntryDistanceY;

float CharacterEntryTitleArrayPositionX;
float CharacterEntryTitleArrayPositionY;
float CharacterEntryTitleArrayPositionZ;

float CharacterEntryTitleArrayFontSizeX;
float CharacterEntryTitleArrayFontSizeY;

float CharacterPicturePositionX;
float CharacterPicturePositionY;
float CharacterPicturePositionZ;

float CharacterPictureSizeX;
float CharacterPictureSizeY;

float CharacterDescriptionPositionX;
float CharacterDescriptionPositionY;
float CharacterDescriptionPositionZ;

float CharacterDescriptionFontSizeX;
float CharacterDescriptionFontSizeY;

float CharacterDescriptionScreenDisplayAmount;
float CharacterDescriptionDisplayMovementPerSecondY;

float SingleCharacterEntryMovementPerSecondX;

float TheatreThumbnailDrawStartPositionX;
float TheatreThumbnailDrawStartPositionY;
float TheatreThumbnailDrawEndPositionY;
float TheatreThumbnailDrawPositionZ;

float TheatreThumbnailDrawSizeX;
float TheatreThumbnailDrawSizeY;

float TheatreThumbnailsScrollButtonPositionX;
float TheatreThumbnailsScrollButtonStartPositionY;
float TheatreThumbnailsScrollButtonPositionZ;

float TheatreThumbnailsScrollButtonSizeX;
float TheatreThumbnailsScrollButtonMinimumSizeY;
float TheatreThumbnailsScrollButtonMaximumSizeY;

float TheatreThumbnailsScrollableMovementPerSecondY;

float ExpansionDuration;

uint16 MainBackGroundTextureSizeX;
uint16 MainBackGroundTextureSizeY;

uint16 MainOptionTextureSizeX;
uint16 MainOptionTextureSizeY;

uint16 LogOptionBackGroundTextureSizeX;
uint16 LogOptionBackGroundTextureSizeY;

uint16 CharacterEntryBackGroundTextureSizeX;
uint16 CharacterEntryBackGroundTextureSizeY;

uint16 CharacterPictureTextureSizeX;
uint16 CharacterPictureTextureSizeY;

uint16 TheatreThumbnailDrawTextureSizeX;
uint16 TheatreThumbnailDrawTextureSizeY;

uint16 TheatreThumbnailsScrollButtonTextureSizeX;
uint16 TheatreThumbnailsScrollButtonTextureSizeY;

uint8 CurrentObjectiveArrayFontColor;
uint8 CurrentObjectiveArrayWhichFont;
uint8 LogOptionArrayFontColor;
uint8 LogOptionArrayWhichFont;

uint8 LogOptionDrawnAmount;

uint8 LogEntryTitleArrayFontColor;
uint8 LogEntryTitleArrayWhichFont;
uint8 LogEntryActualArrayFontColor;
uint8 LogEntryActualArrayWhichFont;

uint8 LogEntryActualArrayRowAmount[OverallLogEntryAmount];
uint8 CharacterDescriptionRowAmount[OverallCharacterEntryAmount];

uint8 CharacterEntryDrawnAmount;

uint8 CharacterEntryTitleArrayFontColor;
uint8 CharacterEntryTitleArrayWhichFont;
uint8 CharacterDescriptionFontColor;
uint8 CharacterDescriptionWhichFont;

uint8 TheatreThumbnailAmountPerRow;
uint8 TheatreThumbnailsDisplayedRowAmount;

PositionInFileStruct SingleTheatreThumbnailPositionInFile[TheatreThumbnailAmountOverall];

uint16 LogEntryTitleArrayLength[OverallLogEntryAmount];
uint16 LogEntryActualArrayLength[OverallLogEntryAmount];
uint16 CharacterEntryTitleArrayLength[OverallCharacterEntryAmount];
uint16 CharacterDescriptionLength[OverallCharacterEntryAmount];

} OverWorldMenuDivaScreenLoadableStruct;

typedef struct{

float LogEntryActualArrayDisplayedUp;
float LogEntryActualArrayDisplayedDown;

float LogEntryActualArraySwitchUpDisplayedUp;
float LogEntryActualArraySwitchUpDisplayedDown;

float LogEntryPositionX;
float LogEntrySwitchUpPositionX;

float CharacterDescriptionDisplayedUp;
float CharacterDescriptionDisplayedDown;

float CharacterDescriptionSwitchUpDisplayedUp;
float CharacterDescriptionSwitchUpDisplayedDown;

float CharacterEntryPositionX;
float CharacterEntrySwitchUpPositionX;

float DisplayedTheatreThumbnailsUp;
float DisplayedTheatreThumbnailsDown;

float ExpandStartPositionLeft;
float ExpandStartPositionRight;
float ExpandStartPositionUp;
float ExpandStartPositionDown;

float ExpandEndPositionLeft;
float ExpandEndPositionRight;
float ExpandEndPositionUp;
float ExpandEndPositionDown;

float ExpandPositionLeft;
float ExpandPositionRight;
float ExpandPositionUp;
float ExpandPositionDown;


uint8 ActiveScreenFlags;
uint8 ScreenInFront;
uint8 ScreenInBack;
uint8 ExpansionMode;


uint8 LogEntryAmount;
uint8 LogOptionDrawnUp;

uint8 LogEntrySelected;
uint8 LogEntrySwitchUp;

uint8 CharacterEntrySelected;
uint8 CharacterEntrySwitchUp;
uint8 CharacterEntryDrawnUp;
uint8 CharacterEntryAmount;

uint8 TheatreThumbnailSelected;
uint8 MainOptionSelected;

char* CurrentObjectiveArray;
TransformationStruct ExpansionTransformationData;

char* LogEntryTitleArray[OverallLogEntryAmount];
char* LogEntryActualArray[OverallLogEntryAmount];
char* CharacterEntryTitleArray[OverallCharacterEntryAmount];
char* CharacterDescription[OverallCharacterEntryAmount];

pvr_ptr_t MainBackGroundTexture;
pvr_ptr_t CharacterTexture[OverallCharacterEntryAmount];
pvr_ptr_t MainOptionTextures[OverWorldMenuDivaMainOptionAmount];
pvr_ptr_t LogOptionBackGroundTexture;
pvr_ptr_t CharacterEntryBackGroundTexture;
pvr_ptr_t TheatreThumbnailTextures;
pvr_ptr_t TheatreThumbnailsScrollButtonTexture;

} OverWorldMenuDivaScreenStruct;


typedef struct{

float BackGroundPositionX;
float BackGroundPositionY;
float BackGroundPositionZ;

float BackGroundStartRotationValue;
float BackGroundEndRotationValue;
float BackGroundBuildUpTime;

float HandStartPositionX;
float HandEndPositionX;
float HandPositionY;
float HandPositionZ;

float HandSwipeTime;

float ActiveScreenPositionX;
float ActiveScreenPositionY;
float ActiveScreenPositionZ;

float ActiveScreenSizeX;
float ActiveScreenSizeY;

float InactiveScreenLeft;
float InactiveScreenRight;
float InactiveScreenUp;
float InactiveScreenDown;

float ScreenDepthZ;

float ConfirmationMainBoxPositionX;
float ConfirmationMainBoxPositionY;
float ConfirmationMainBoxPositionZ;

float ConfirmationArrayPositionX;
float ConfirmationArrayPositionY;
float ConfirmationArrayPositionZ;

float ConfirmationArrayFontSizeX;
float ConfirmationArrayFontSizeY;

float ConfirmationYesPositionX;
float ConfirmationYesPositionY;
float ConfirmationYesPositionZ;

float ConfirmationNoPositionX;
float ConfirmationNoPositionY;
float ConfirmationNoPositionZ;

float ActiveScreenRotationDecreaseForSixtyHertz;

uint16 BackGroundTextureSizeX;
uint16 BackGroundTextureSizeY;

uint16 HandTextureSizeX;
uint16 HandTextureSizeY;

uint8 HandFrameAmount;
uint8 HandActivatesScreenRotationFrameSwipeRight;
uint8 HandActivatesScreenRotationFrameSwipeLeft;

uint16 InactiveScreenTextureSizeX;
uint16 InactiveScreenTextureSizeY;

uint16 ConfirmationMainBoxTextureSizeX;
uint16 ConfirmationMainBoxTextureSizeY;

uint16 ConfirmationYesTextureSizeX;
uint16 ConfirmationYesTextureSizeY;

uint16 ConfirmationNoTextureSizeX;
uint16 ConfirmationNoTextureSizeY;

uint8 ConfirmationArrayFontColor;
uint8 ConfirmationArrayWhichFont;

OverWorldMenuStatsScreenLoadableStruct StatsDataLoadable;
OverWorldMenuMapScreenLoadableStruct MapDataLoadable;
OverWorldMenuItemScreenLoadableStruct ItemDataLoadable;
OverWorldMenuAbilityScreenLoadableStruct AbilityDataLoadable;
OverWorldMenuDivaScreenLoadableStruct DivaDataLoadable;

} OverWorldMenuLoadableStruct;

typedef struct{

OverWorldMenuLoadableStruct* Loadable;
OverWorldMenuBackGroundStruct BackGroundData;
OverWorldMenuLogicStruct	 LogicData;


pvr_ptr_t BackGroundTexture;
pvr_ptr_t* HandTexture[OverWorldMenuHandSwipeAmount];
pvr_ptr_t InactiveScreenTextures[OverWorldMenuScreenAmount];
OverWorldMenuStatsScreenTextureStruct StatsTextures;
OverWorldMenuMapScreenStruct MapData;
OverWorldMenuItemScreenStruct ItemData;
OverWorldMenuAbilityScreenStruct AbilityData;
OverWorldMenuDivaScreenStruct DivaData;
OverWorldMenuConfirmationTextureStruct ConfirmationTextures;

TransformationStruct TransformationData;

} OverWorldMenuStruct;


typedef struct{

float TextureSizeX;
float TextureSizeY;

} SpeechBubbleTextureHeaderStruct;

typedef struct {

uint16 EnemyTextureSizeX;
uint16 EnemyTextureSizeY;

uint16 RevealTileNameTextureSizeX;
uint16 RevealTileNameTextureSizeY;

} OverWorldInterFaceLoadableStruct;


typedef struct{

pvr_ptr_t BlackOutTexture;
pvr_ptr_t BackGroundTexture;
pvr_ptr_t SelectScreenOptionTexture[HertzSelectScreenSelectOptionAmount];
pvr_ptr_t SelectScreenOptionSelectedTexture[HertzSelectScreenSelectOptionAmount];
pvr_ptr_t SelectScreenOptionDescriptionTexture[HertzSelectScreenSelectOptionAmount];
pvr_ptr_t TestTexture;
pvr_ptr_t* TestSecondTexture;
pvr_ptr_t* TestSecondPlusTexture;

} HertzSelectScreenTextureStruct;


typedef struct{

uint8 CurrentStage;
uint8 CurrentScreen;
uint8 SelectScreenOptionSelected;
uint8 ReturnFrameRate;

uint8 TestSecondsLeft;
uint8 TestSecondTicks;

float BlackOutAlpha;

ButtonInputStruct ButtonInputData[ButtonAmount];
cont_state_t *st;

} HertzSelectScreenLogicStruct;


typedef struct{

uint8 TestSecondPlusTextureAmount;
uint8 TestSecondAmount;
uint8 Separator1[2];

uint16 BlackOutTextureSizeX;
uint16 BlackOutTextureSizeY;

uint16 BackGroundTextureSizeX;
uint16 BackGroundTextureSizeY;

uint16 SelectScreenOptionTextureSizeX;
uint16 SelectScreenOptionTextureSizeY;

uint16 SelectScreenOptionDescriptionTextureSizeX;
uint16 SelectScreenOptionDescriptionTextureSizeY;

uint16 TestTextureSizeX;
uint16 TestTextureSizeY;

uint16 TestSecondTextureSizeX;
uint16 TestSecondTextureSizeY;

uint16 TestSecondPlusTextureSizeX;
uint16 TestSecondPlusTextureSizeY;

float BlackOutPositionZ;
float BlackOutTimeInSeconds;

float BackGroundPositionX;
float BackGroundPositionY;
float BackGroundPositionZ;

float SelectScreenOptionPositionX[HertzSelectScreenSelectOptionAmount];
float SelectScreenOptionPositionY[HertzSelectScreenSelectOptionAmount];
float SelectScreenOptionPositionZ;

float SelectScreenOptionDescriptionPositionX;
float SelectScreenOptionDescriptionPositionY;
float SelectScreenOptionDescriptionPositionZ;

float TestTexturePositionX;
float TestTexturePositionY;
float TestTexturePositionZ;

float TestSecondPositionX;
float TestSecondPositionY;
float TestSecondPositionZ;

float TestSecondPlusPositionX;
float TestSecondPlusPositionY;
float TestSecondPlusPositionZ;

} HertzSelectScreenLoadableStruct;


typedef struct{

HertzSelectScreenLoadableStruct* Loadable;
HertzSelectScreenLogicStruct LogicData;
HertzSelectScreenTextureStruct TextureData;

} HertzSelectScreenStruct;

typedef struct{

uint8 ReturnValue;
uint8 CurrentStage;
uint16 Ticks;

uint8 ForceBuildDown;

float AlphaValueBlackOut;

cont_state_t* st;
ButtonInputStruct ButtonInputData[ButtonAmount];

} DogmaScreenLogicStruct;

typedef struct{

pvr_ptr_t LogoTexture;
pvr_ptr_t BlackOutTexture;

} DogmaScreenTextureStruct;

typedef struct{

sfxhnd_t FullAlphaValueSpiralSoundEffect;
sfxhnd_t FullAlphaValueLogoSoundEffect;

} DogmaScreenSoundEffectStruct;

typedef struct{

uint16 LogoTextureSizeX;
uint16 LogoTextureSizeY;

uint16 BlackOutTextureSizeX;
uint16 BlackOutTextureSizeY;

uint32 StreamingLoadTime;

float LogoPositionX;
float LogoPositionY;
float LogoPositionZ;

float BlackOutPositionZ;

float LogoBuildUpTimeInSeconds;
float LogoBuildUpAfterWaitTimeInSeconds;
float BuildDownTimeInSeconds;

} DogmaScreenLoadableStruct;

typedef struct{

DogmaScreenLoadableStruct* Loadable;
DogmaScreenLogicStruct LogicData;
DogmaScreenTextureStruct TextureData;

} DogmaScreenStruct;

typedef struct{

sfxhnd_t RedSpotGamesSoundEffect;

} RedSpotScreenSoundEffectStruct;

typedef struct{

pvr_ptr_t BlackOutTexture;
pvr_ptr_t RedSpotTexture;
pvr_ptr_t BackGroundTexture;
pvr_ptr_t EffectTexture;

} RedSpotScreenTextureStruct;

typedef struct{

uint8 ReturnValue;
uint8 CurrentStage;
uint8 ForceBuildDown;

uint16 Ticks;

float EffectPositionX;

float AlphaValueBlackOut;
float AlphaValueBackGround;
float AlphaValueEffect;

float MovingArrayCurrentPositionX[RedSpotScreenMovingArrayAmount];

char* MovingArray[RedSpotScreenMovingArrayAmount];
TransformationStruct TransformationDataRedSpot;
cont_state_t* st;
ButtonInputStruct ButtonInputData[ButtonAmount];

} RedSpotScreenLogicStruct;

typedef struct{

uint8 MovingArrayColor;
uint8 MovingArrayWhichFont;
uint8 Separator1[2];

uint16 BlackOutTextureSizeX;
uint16 BlackOutTextureSizeY;

uint16 RedSpotTextureSizeX;
uint16 RedSpotTextureSizeY;

uint16 BackGroundTextureSizeX;
uint16 BackGroundTextureSizeY;

uint16 EffectTextureSizeX;
uint16 EffectTextureSizeY;

uint16 MovingArrayFontSizeX;
uint16 MovingArrayFontSizeY;

uint16 MovingArraySize[RedSpotScreenMovingArrayAmount];

uint32 StreamingLoadTime;

float BlackOutPositionZ;

float RedSpotPositionX;
float RedSpotPositionY;
float RedSpotPositionZ;

float RedSpotStartSizeX;
float RedSpotStartSizeY;

float BackGroundPositionX;
float BackGroundPositionY;
float BackGroundPositionZ;

float EffectStartPositionX;
float EffectFadeInEndPositionX;
float EffectFadeOutStartPositionX;
float EffectEndPositionX;
float EffectPositionY;
float EffectPositionZ;

float MovingArrayPositionZ;

float MovingArrayTraverseScreenTimeInSeconds;
float BuildDownTimeInSeconds;
float BuildUpTimeInSeconds;
float BuildUpAfterWaitTimeInSeconds;
float RedSpotExpandTimeInSeconds;
float BackGroundFadeInTimeInSeconds;
float BackGroundTimeInSeconds;
float EffectTimeInSeconds;

float RedSpotExpandStartValue;
float RedSpotExpandEndValue;

} RedSpotScreenLoadableStruct;


typedef struct{

RedSpotScreenLoadableStruct* Loadable;
RedSpotScreenLogicStruct LogicData;
RedSpotScreenTextureStruct TextureData;
RedSpotScreenSoundEffectStruct SoundEffectData;

} RedSpotScreenStruct;


typedef struct{

} TitleScreenSoundEffectStruct;


typedef struct{

pvr_ptr_t BlackOutTexture;
pvr_ptr_t BackGroundTexture;
pvr_ptr_t PressStartTexture;

} TitleScreenTextureStruct;


typedef struct{

uint8 MainLoop;
uint8 CurrentStage;
uint8 ReturnStage;

uint16 TicksUniversalReboot;

float AlphaValueBlackOut;

TransformationStruct TransformationDataZoomOut;
cont_state_t* st;
ButtonInputStruct ButtonInputData[ButtonAmount];

} TitleScreenLogicStruct;


typedef struct{

uint16 BlackOutTextureSizeX;
uint16 BlackOutTextureSizeY;

uint16 BackGroundTextureSizeX;
uint16 BackGroundTextureSizeY;

uint16 PressStartTextureSizeX;
uint16 PressStartTextureSizeY;

uint32 StreamingLoadTime;

float BlackOutPositionZ;

float BackGroundPositionX;
float BackGroundPositionY;
float BackGroundPositionZ;

float PressStartPositionX;
float PressStartPositionY;
float PressStartPositionZ;

float TimeInSecondsBuildUp;
float TimeInSecondsUniversalReboot;
float TimeInSecondsZoomOut;
float TimeInSecondsBuildDown;

} TitleScreenLoadableStruct;


typedef struct{

TitleScreenLoadableStruct* Loadable;
TitleScreenLogicStruct LogicData;

TitleScreenTextureStruct TextureData;
TitleScreenSoundEffectStruct SoundEffectData;

} TitleScreenStruct;


typedef struct{

uint32 Damage;

float ForceX;
float ForceY;
float ForceZ;

} FightAttackStruct;


typedef struct{

uint32 Defense;

float VelocityResistanceX;
float VelocityResistanceY;

} FightDefenseStruct;


typedef struct{

uint8 Draw;
uint8 Animate;

TransformationStruct TransformationData;

} TileObjectClassLogicStruct;

typedef struct{

TileObjectClassLogicStruct LogicData;

} TileObjectClassStruct;

typedef struct{

uint8 EventAmount;
uint8 CurrentFrame;
uint16 CurrentAnimation;

uint8 MovementType;
uint8 FaceDirection;
uint8 Separator1[2];

float PositionX;
float StagePositionZ;

float SizeX;
float SizeY;

float SpeedX;

float AnimationFactor;

} TileObjectInstanceLoadableStruct;

typedef struct{

uint8 Active;
uint8 Draw;
uint8 Animate;
uint8 MoveNot;

uint16 Ticks;

float PositionY;

float ScreenPositionZ;

float SizeX;
float SizeY;
float SpeedX;


TransformationStruct TransformationData;

} TileObjectInstanceLogicStruct;

typedef struct{

} TileObjectInstanceFluxStruct;

typedef struct{

TileFlagParseStruct* Active;

} TileObjectInstanceFlagStruct;

typedef struct{

TileObjectInstanceLoadableStruct* Loadable;
TileObjectInstanceLogicStruct LogicData;
TileObjectInstanceFluxStruct FluxData;
TileObjectInstanceFlagStruct FlagData;
EventStruct* EventData;

} TileObjectInstanceStruct;

typedef struct{

uint8 InstanceAmount;
uint8 TextureAmount;
uint16 AnimationAmount;

uint16 TextureSizeX;
uint16 TextureSizeY;

uint16 SingleTextureSizeX;
uint16 SingleTextureSizeY;

float EventRadius;

} TileObjectLoadableStruct;

typedef struct{

uint8 Load;

} TileObjectLogicStruct;

typedef struct{

TileFlagParseStruct* Load;

} TileObjectFlagStruct;

typedef struct{

TileObjectClassStruct* ClassData;
TileObjectLoadableStruct* Loadable;
TileObjectLogicStruct LogicData;
TileObjectFlagStruct FlagData;
TileObjectInstanceStruct* Instance;

AnimationStruct* AnimationData;
pvr_ptr_t* Texture;

} TileObjectStruct;



typedef struct{

uint16 TextureSizeX;
uint16 TextureSizeY;

} OverWorldLoadableSpeechBubbleStruct;

typedef struct{

uint16 BlackTextureSizeX;
uint16 BlackTextureSizeY;

} OverWorldLoadableTileIntroGeneralStruct;

typedef struct{

OverWorldLoadableTileIntroGeneralStruct General;

} OverWorldLoadableTileIntroStruct;

typedef struct{

OverWorldLoadableTileIntroStruct Intro;

} OverWorldLoadableTileStruct;

typedef struct{

float PositionX;
float PositionY;
float ScreenPositionZ;

float FilePositionLeft;
float FilePositionRight;

uint16 TextureSizeX;
uint16 TextureSizeY;

} OverWorldLoadableFightUserInterFaceHealthGeneralStruct;


typedef struct{

float PositionX;
float PositionY;
float ScreenPositionZ;

uint16 TextureSizeX;
uint16 TextureSizeY;

} OverWorldLoadableFightUserInterFaceHealthBackGroundStruct;


typedef struct{

OverWorldLoadableFightUserInterFaceHealthGeneralStruct General;
OverWorldLoadableFightUserInterFaceHealthBackGroundStruct BackGround;

} OverWorldLoadableFightUserInterFaceHealthStruct;


typedef struct{

uint16 TextureSizeX;
uint16 TextureSizeY;

float ScreenPositionZ;

} OverWorldLoadableFightUserInterFaceAbilitiesGeneralGaugeStruct;

typedef struct{

uint16 TextureSizeX;
uint16 TextureSizeY;

float ScreenPositionZ;

} OverWorldLoadableFightUserInterFaceAbilitiesGeneralBackGroundStruct;

typedef struct{

float ScreenPositionZ;

uint16 TextureSizeX;
uint16 TextureSizeY;
uint16 SingleTextureSizeX;
uint16 SingleTextureSizeY;

} OverWorldLoadableFightUserInterFaceAbilitiesGeneralAbilityStruct;


typedef struct{

OverWorldLoadableFightUserInterFaceAbilitiesGeneralGaugeStruct Gauge;
OverWorldLoadableFightUserInterFaceAbilitiesGeneralBackGroundStruct BackGround;
OverWorldLoadableFightUserInterFaceAbilitiesGeneralAbilityStruct Ability;

} OverWorldLoadableFightUserInterFaceAbilitiesGeneralStruct;


typedef struct{

float PositionX;
float PositionY;

} OverWorldLoadableFightUserInterFaceAbilitiesSpecificGaugeStruct;

typedef struct{

float PositionX;
float PositionY;

} OverWorldLoadableFightUserInterFaceAbilitiesSpecificBackGroundStruct;

typedef struct{

float PositionX;
float PositionY;
float ScreenPositionZ;

float SizeX;
float SizeY;

} OverWorldLoadableFightUserInterFaceAbilitiesSpecificAbilityStruct;


typedef struct{

OverWorldLoadableFightUserInterFaceAbilitiesSpecificGaugeStruct Gauge;
OverWorldLoadableFightUserInterFaceAbilitiesSpecificBackGroundStruct BackGround;
OverWorldLoadableFightUserInterFaceAbilitiesSpecificAbilityStruct Ability;

} OverWorldLoadableFightUserInterFaceAbilitiesSpecificStruct;


typedef struct{

OverWorldLoadableFightUserInterFaceAbilitiesGeneralStruct General;
OverWorldLoadableFightUserInterFaceAbilitiesSpecificStruct Specific[AbilityAmount];

} OverWorldLoadableFightUserInterFaceAbilitiesStruct;


typedef struct{

OverWorldLoadableFightUserInterFaceHealthStruct Health;
OverWorldLoadableFightUserInterFaceAbilitiesStruct Abilities;

} OverWorldLoadableFightUserInterFaceStruct;

typedef struct{

OverWorldLoadableFightUserInterFaceStruct UserInterFace;

} OverWorldLoadableFightStruct;

typedef struct{

OverWorldLoadableSpeechBubbleStruct SpeechBubbles[SpeechBubbleAmountOverall];
OverWorldLoadableTileStruct Tile;
OverWorldLoadableFightStruct Fight;

} OverWorldLoadableStruct;

typedef struct{

uint8 LoopOverWorld;
uint8 ReturnStage;
uint16 CurrentTile;

uint8 CurrentGamePlay;

uint8 PlayerAmount;
uint8 CrewSize;

} OverWorldLogicGeneralStruct;

typedef struct{

cont_state_t* st;
ButtonInputStruct ButtonInputData[ButtonAmount];

} OverWorldLogicInputStruct;

typedef struct{

uint8 StartFaceDirection;
uint16 StartAnimation;

float StartPositionX;
float StartStagePositionZ;

} OverWorldLogicStolarStruct;

typedef struct{

uint16 CurrentTrack;
void* AudioBuffer;

} OverWorldLogicMusicStruct;

typedef struct{

uint8 WhichController;
uint8 WhichCrewMember;

} OverWorldLogicPlayerGeneralStruct;

typedef struct{

cont_state_t* st;
ButtonInputStruct ButtonInputData[ButtonAmount];

} OverWorldLogicPlayerInputStruct;


typedef struct{

OverWorldLogicPlayerGeneralStruct General;
OverWorldLogicPlayerInputStruct Input;

} OverWorldLogicPlayerStruct;

typedef struct{

OverWorldLogicGeneralStruct General;
OverWorldLogicMusicStruct Music;
OverWorldLogicPlayerStruct* Player;

void* Passable;

} OverWorldLogicStruct;

typedef struct{

void* TransitionData;

} OverWorldFluxGeneralStruct;

typedef struct{

void* ThresholdTexture;

} OverWorldFluxUserInterFaceAbilitiesStruct;


typedef struct{

OverWorldFluxUserInterFaceAbilitiesStruct Abilities;

} OverWorldFluxFightUserInterFaceStruct;


typedef struct{

OverWorldFluxFightUserInterFaceStruct UserInterFace;

} OverWorldFluxFightStruct;


typedef struct{
OverWorldFluxGeneralStruct General;
OverWorldFluxFightStruct Fight;
} OverWorldFluxStruct;

typedef struct{

pvr_ptr_t Black;

} OverWorldTextureTileIntroGeneralStruct;

typedef struct{

OverWorldTextureTileIntroGeneralStruct General;

} OverWorldTextureTileIntroStruct;

typedef struct{

OverWorldTextureTileIntroStruct Intro;

} OverWorldTextureTileStruct;

typedef struct{

pvr_ptr_t Health;
pvr_ptr_t HealthBackGround;
pvr_ptr_t AbilityBackGround;

} OverWorldTextureFightUserInterFaceStruct;


typedef struct{

OverWorldTextureFightUserInterFaceStruct UserInterFace;

} OverWorldTextureFightStruct;

typedef struct{

pvr_ptr_t SpeechBubbleTexture[SpeechBubbleAmountOverall];
pvr_ptr_t Abilities;

OverWorldTextureTileStruct Tile;
OverWorldTextureFightStruct Fight;

} OverWorldTextureStruct;

typedef struct{

uint8 InstanceAmount;
uint8 TextureAmount;
uint16 AnimationAmount;

uint16 TextureSizeX;
uint16 TextureSizeY;
uint16 SingleTextureSizeX;
uint16 SingleTextureSizeY;

float SizeX;
float SizeY;
float SpeedX;

} OverWorldCrewLoadableGeneralStruct;

typedef struct{

float EventRadius;

} OverWorldCrewLoadableTileStruct;

typedef struct{

float InertiaX;
float InertiaY;
float InertiaZ;

} FightObjectInstanceLoadablePhysicsStruct;

typedef struct{

float LeftX;
float RightX;
float UpZ;
float DownZ;

} FightObjectInstanceLoadableHitOffsetStruct;


typedef struct{

uint8 PhysicsType;
uint8 OnGround;
uint8 Separator1[2];

FightObjectInstanceLoadablePhysicsStruct Physics;
FightObjectInstanceLoadableHitOffsetStruct HitOffset;

} OverWorldCrewLoadableFightStruct;

typedef struct{

OverWorldCrewLoadableGeneralStruct General;
OverWorldCrewLoadableTileStruct Tile;
OverWorldCrewLoadableFightStruct Fight;

} OverWorldCrewLoadableStruct;

typedef struct{

uint8 FunctionIndex;
uint8 TextureAtlasIndex;
uint16 FilledMax;

} OverWorldCrewFluxAbilityLoadableStruct;

typedef struct{

} OverWorldCrewFluxAbilityFluxStruct;

typedef struct{

OverWorldCrewFluxAbilityLoadableStruct* AbilityData;
OverWorldCrewFluxAbilityFluxStruct FluxData;

void* Loadable;

} OverWorldCrewFluxAbilityStruct;

typedef struct{

AnimationStruct* AnimationData;
OverWorldCrewFluxAbilityStruct Abilities[AbilityAmount];

} OverWorldCrewFluxStruct;

typedef struct{

OverWorldCrewLoadableStruct* Loadable;
OverWorldCrewLogicStruct LogicData;
OverWorldCrewFluxStruct FluxData;
pvr_ptr_t* Texture;

} OverWorldCrewStruct;

typedef struct{
OverWorldLoadableStruct* Loadable;
OverWorldLogicStruct LogicData;
OverWorldFluxStruct FluxData;
OverWorldTextureStruct TextureData;
OverWorldCrewStruct* CrewData;
} OverWorldStruct;


typedef struct{

uint8 LoopTile;
uint8 DrawFlags;
uint8 AnimationFlags;
uint8 EnableFlags;

uint8 StartMenu;
uint8 IntroFlag;
uint8 ObjectAmount;

TransformationStruct TransformationData;

} TileLogicGeneralStruct;

typedef struct{

uint8 Active;
uint8 Identifier;
uint8 NewGamePlay;
uint8 WhereExactly;

} TileLogicOutroStruct;

typedef struct{

float StagePositionX;
float StagePositionY;

TransformationStruct TransformationData;

TileMovementLogicStruct Movement;

} TileLogicBackGroundStruct;

typedef struct{

TileLogicGeneralStruct General;
TileLogicOutroStruct Outro;
TileLogicBackGroundStruct BackGround;

} TileLogicStruct;

typedef struct{

uint8 FrameAmount;
uint8 InstanceAmount;
uint8 Separator1[2];

uint16 TextureSizeX;
uint16 TextureSizeY;

AnimationStruct AnimationData;

} BackGroundHeaderLoadableStruct;

typedef struct{

uint8 Load;

} BackGroundHeaderLogicStruct;

typedef struct{

TileFlagParseStruct* Load;

} BackGroundHeaderFlagStruct;

typedef struct{

uint16 CurrentFrame;
uint8 Separator1[2];

float PositionX;
float PositionY;
float PositionZ;

float LayerSizeX;
float LayerSizeY;

float AnimationFactor;

} BackGroundHeaderInstanceLoadableStruct;

typedef struct{

uint8 Active;
uint8 Draw;
uint8 Animate;

uint16 Ticks;
uint16 CurrentAnimation;

TransformationStruct TransformationData;

} BackGroundHeaderInstanceLogicStruct;

typedef struct{

TileFlagParseStruct* Active;

} BackGroundHeaderInstanceFlagStruct;

typedef struct{

BackGroundHeaderInstanceLoadableStruct* Loadable;
BackGroundHeaderInstanceLogicStruct LogicData;
BackGroundHeaderInstanceFlagStruct FlagData;

} BackGroundHeaderInstanceStruct;

typedef struct{
BackGroundHeaderLoadableStruct* Loadable;
BackGroundHeaderLogicStruct LogicData;
BackGroundHeaderFlagStruct FlagData;
BackGroundHeaderInstanceStruct* Instance;

pvr_ptr_t* Texture;

} BackGroundHeaderStruct;

typedef struct{

uint8 CurrentAnimation;
uint8 CurrentFrame;
uint8 ArtificialIntelligence;
uint8 EventInducedLoop;

uint8 AnimationAmount;
uint8 Separator[3];

uint8 FlagSetAmountLoad;
uint8 FlagUnSetAmountLoad;
uint8 FlagSetAmountActive;
uint8 FlagUnSetAmountActive;

uint32 ArtificialIntelligenceBuffer;

uint16 TextureSizeX;
uint16 TextureSizeY;
uint16 SingleTextureSizeX;
uint16 SingleTextureSizeY;

float PositionX;
float PositionY;
float ScreenPositionZ;
float StagePositionZ;

float SizeX;
float SizeY;

float SpeedX;
float SpeedZ;

float AnimationFactor;

} PersonLoadableStruct;

typedef struct{

uint8 Active;
uint8 Load;

uint8 Draw;
uint8 Animate;
uint8 Ticks;
uint8 ArtificialIntelligenceEnabled;

TransformationStruct TransformationData;

//LOAD
TileMovementLogicStruct Movement;
//LOAD

} PersonLogicStruct;

typedef struct{

TileFlagParseStruct* Load;
TileFlagParseStruct* Active;

} PersonFlagStruct;

typedef struct{

PersonLoadableStruct* Loadable;
PersonLogicStruct LogicData;
PersonFlagStruct FlagData;
AnimationStruct* AnimationData;
pvr_ptr_t Texture;

} PersonStruct;

typedef struct{

uint8 CurrentAnimation;
uint8 CurrentFrame;
uint8 ArtificialIntelligence;
uint8 EventInducedLoop;

uint8 FlagSetAmountActive;
uint8 FlagUnSetAmountActive;
uint8 Separator1[2];

uint32 ArtificialIntelligenceBuffer;

float PositionX;
float PositionY;
float ScreenPositionZ;
float StagePositionZ;

float SizeX;
float SizeY;

float SpeedX;
float SpeedZ;

float AnimationFactor;

} NormalEnemyLoadableStruct;

typedef struct{

uint8 Active;

uint8 Draw;
uint8 Animate;
uint8 Ticks;
uint8 ArtificialIntelligenceEnabled;

TransformationStruct TransformationData;

} NormalEnemyLogicStruct;

typedef struct{

TileFlagParseStruct* Active;

} NormalEnemyFlagStruct;

typedef struct{

NormalEnemyLoadableStruct* Loadable;
NormalEnemyLogicStruct LogicData;
NormalEnemyFlagStruct FlagData;

} NormalEnemyStruct;

typedef struct{

uint8 CurrentAnimation;
uint8 CurrentFrame;
uint8 ArtificialIntelligence;
uint8 EventInducedLoop;

uint8 FlagSetAmountActive;
uint8 FlagUnSetAmountActive;

uint32 ArtificialIntelligenceBuffer;

float PositionX;
float PositionY;
float ScreenPositionZ;
float StagePositionZ;

float SizeX;
float SizeY;

float SpeedX;
float SpeedZ;

float AnimationFactor;

} SpecialEnemyLoadableStruct;

typedef struct{

uint8 Active;

uint8 Draw;
uint8 Animate;
uint8 Ticks;
uint8 ArtificialIntelligenceEnabled;

TransformationStruct TransformationData;

} SpecialEnemyLogicStruct;

typedef struct{

TileFlagParseStruct* Active;

} SpecialEnemyFlagStruct;

typedef struct{

SpecialEnemyLoadableStruct* Loadable;
SpecialEnemyLogicStruct LogicData;
SpecialEnemyFlagStruct FlagData;

} SpecialEnemyStruct;

typedef struct{

uint8 AnimationAmount;
uint8 FlagSetAmountLoad;
uint8 FlagUnSetAmountLoad;
uint8 Separator[1];

uint16 TextureSizeX;
uint16 TextureSizeY;
uint16 SingleTextureSizeX;
uint16 SingleTextureSizeY;

float AnimationFactor;

} TileSpriteLoadableStruct;

typedef struct{

uint8 Load;

} TileSpriteLogicStruct;

typedef struct{

TileFlagParseStruct* Load;

} TileSpriteFlagStruct;

typedef struct{

TileSpriteLoadableStruct* Loadable;
TileSpriteLogicStruct LogicData;
TileSpriteFlagStruct FlagData;
AnimationStruct* AnimationData;
pvr_ptr_t Texture;

} TileSpriteStruct;

typedef struct{

uint16 TrackIdentifier;

uint8 FlagSetAmountActive;
uint8 FlagUnSetAmountActive;

} TileMusicLoadableStruct;

typedef struct{

uint8 Active;

} TileMusicLogicStruct;

typedef struct{

TileFlagParseStruct* Active;

} TileMusicFlagStruct;

typedef struct{

TileMusicLoadableStruct* Loadable;
TileMusicLogicStruct LogicData;
TileMusicFlagStruct FlagData;

} TileMusicStruct;

typedef struct{

char* LocationName;
char* TileName;

} TileFluxGeneralStruct;

typedef struct{
void* Buffer;
} TileFluxOutroStruct;


typedef struct{

TileFluxGeneralStruct General;
TileFluxOutroStruct Outro;

} TileFluxStruct;

typedef struct{

uint16 EventAmount;
uint16 WhichObject;
uint16 WhichInstance;

} TilePlayerLogicStruct;

typedef struct{

TilePlayerLogicStruct LogicData;
EventSelfStruct* EventSelfData;

} TilePlayerStruct;


typedef struct{

TileHeaderStruct* TileHeaderData;
TileLogicStruct LogicData;
TileFluxStruct FluxData;

BackGroundHeaderStruct* BackGroundHeaderData;
TilePlayerStruct* PlayerData;
TileObjectStruct* ObjectData;
TileSpriteStruct* Sprites;
TileMusicStruct* MusicData;

ActiveEventStruct* ActiveEventData;

uint8** LayOutBuffer;

} TileStruct;

typedef struct{

uint8 WhoChanges;
uint8 WhoChangesExactly;

uint8 WhichAnimation;
uint8 StartFrame;
uint8 StartTicks;
uint8 EventInducedLoop;

} EventChangeAnimationStruct;

typedef struct{

float PixelMovementPerSecondX;
float PixelMovementPerSecondY;

} EventTemporaryScreenMovementStruct;

typedef struct{

float FinalPositionX;
float FinalPositionY;

float PixelMovementPerSecondX;
float PixelMovementPerSecondY;

} EventScreenMovementStruct;

typedef struct{

uint8 WhichTransformationData;
uint8 WhichObjectExactly;
uint8 WhichInstanceExactly;
uint8 Separator1;

TransformationStruct TransformationData;

} ForceTransformationDataStruct;

typedef struct{

float ScaleChangePerSecond;

} EventZoomTemporaryStruct;

typedef struct{

float PositionX;
float PositionY;
float PositionZ;

float ScaleValueEnd;
float ScaleChangePerSecond;

} EventZoomStruct;

typedef struct{

uint8 SpeechBubbleAmount;
uint8 SpriteAmount;

} EventSpeechLoadableHeaderStruct;

typedef struct{

uint8 RowAmount;
uint8 BuildUp;
uint16 ArrayLengthTotal;

uint8 SpeechBubbleType;
uint8 FontColor;
uint8 WhichFont;
uint8 Separator1;

float StartPositionX;
float StartPositionY;
float PositionZ;

float ScaleValue;

float FontPositionY;
float FontPositionZ;

float FontSizeX;
float FontSizeY;

} EventSpeechLoadableSpeechBubbleHeaderStruct;

typedef struct{

EventSpeechLoadableSpeechBubbleHeaderStruct* Header;
float* FontPositionX;
uint16* ArrayLength;
char** Array;

} EventSpeechLoadableSpeechBubbleStruct;

typedef struct{

uint8 WhichSprite;
uint8 Animation;
uint8 FaceLeft;
uint8 Separator1;

float StartPositionX;
float EndPositionX;
float PositionY;
float PositionZ;

float SizeX;
float SizeY;

float AlphaValueStart;
float ScaleValue;

float TimeInSecondsMoveIn;
float TimeInSecondsAlphaBuildUp;

} EventSpeechLoadableSpriteStruct;

typedef struct{

EventSpeechLoadableHeaderStruct* Header;
EventSpeechLoadableSpeechBubbleStruct* SpeechBubbles;
EventSpeechLoadableSpriteStruct* Sprites;

} EventSpeechLoadableStruct;

typedef struct{

uint8 BuildUp;
uint16 ArrayPosition;

float PositionX;
float PositionY;

float ScaleValue;

} EventSpeechLogicSpeechBubbleStruct;

typedef struct{

uint8 Active;
uint8 CurrentFrame;
uint16 Ticks;

float PositionX;
float PositionY;

float AlphaValue;
float ScaleValue;

} EventSpeechLogicSpriteStruct;

typedef struct{

EventSpeechLogicSpeechBubbleStruct* SpeechBubbles;
EventSpeechLogicSpriteStruct* Sprites;

} EventSpeechLogicStruct;

typedef struct{

uint8 ReturnValue;
uint8 BuildUpPhaseOver;
uint8 IsFirstFrame;

} EventSpeechUnStaticStruct;

typedef struct{

EventSpeechLoadableStruct Loadable;
EventSpeechLogicStruct* LogicData;
EventSpeechUnStaticStruct UnStatic;

} EventSpeechStruct;

typedef struct{

uint8 SpeechBubbleAmount;
uint8 HasRadius;
uint8 HasInput;
uint8 Separator1;

float RadiusSize;
float TimeInSecondsThereBeforeVanish;

} EventSpeechDynamicLoadableHeaderStruct;

typedef struct{

uint8 RowAmount;
uint8 BuildUp;
uint16 ArrayLengthTotal;

uint8 SpeechBubbleType;
uint8 FontColor;
uint8 WhichFont;
uint8 Separator1;

uint8 WhichObject;
uint8 WhichInstance;
uint8 Separator2[3];

float ScaleValue;

float FontPositionY;
float FontPositionZ;

float FontSizeX;
float FontSizeY;

} EventSpeechDynamicLoadableSpeechBubbleHeaderStruct;

typedef struct{

EventSpeechDynamicLoadableSpeechBubbleHeaderStruct* Header;
float* FontPositionX;
uint16* ArrayLength;
char** Array;

} EventSpeechDynamicLoadableSpeechBubbleStruct;

typedef struct{

EventSpeechDynamicLoadableHeaderStruct* Header;
EventSpeechDynamicLoadableSpeechBubbleStruct* SpeechBubbles;

} EventSpeechDynamicLoadableStruct;

typedef struct{

uint16 Ticks;
uint8 PlayerTalks;

} EventSpeechDynamicLogicGeneralStruct;

typedef struct{

uint8 BuildUp;
uint16 ArrayPosition;

float ScaleValue;

} EventSpeechDynamicLogicSpeechBubbleStruct;

typedef struct{

EventSpeechDynamicLogicGeneralStruct General;
EventSpeechDynamicLogicSpeechBubbleStruct* SpeechBubbles;

} EventSpeechDynamicLogicStruct;

typedef struct{

uint8 ReturnValue;
uint8 BuildUpPhaseOver;

vector_t RadiusCenter;

} EventSpeechDynamicUnStaticStruct;

typedef struct{

EventSpeechDynamicLoadableStruct Loadable;
EventSpeechDynamicLogicStruct* LogicData;
EventSpeechDynamicUnStaticStruct UnStatic;

} EventSpeechDynamicStruct;

typedef struct{

uint8 TileAmount;
uint8 MusicAmount;
uint8 Separator1[2];

} TileCleanUpOldTilesLoadableStruct;


typedef struct{

TileCleanUpOldTilesLoadableStruct* Loadable;
uint16* TileIdentifier;
uint16* MusicTrackIdentifier;

} TileCleanUpOldTilesStruct;


typedef struct{

uint8 TileAmount;
uint8 MusicAmount;
uint8 Separator1[2];

} TileAddNewTilesLoadableStruct;


typedef struct{

TileAddNewTilesLoadableStruct* Loadable;
uint16* TileIdentifier;
uint16* MusicTrackIdentifier;

} TileAddNewTilesStruct;


typedef struct{

uint8 Amount;

} ManipulateStoryFlagLoadableStruct;


typedef struct{

uint8 Set;
StoryFlagsAmountUnit WhichFlag;

} ManipulateStoryFlagSingleFlagStruct;


typedef struct{

ManipulateStoryFlagLoadableStruct* Loadable;
ManipulateStoryFlagSingleFlagStruct* SingleFlagData;

}  ManipulateStoryFlagStruct;


typedef struct{

uint8 IntroIdentifier;
uint8 Separator1[3];

} TileLogicIntroGeneralStruct;

typedef struct{

TileLogicIntroGeneralStruct General;
void* Specific;

} TileLogicIntroStruct;

typedef struct{

float FlipDurationInSeconds;
TransformationStruct TransformationData;

} TileLogicIntroFlipStruct;

typedef struct{

uint16 Ticks;
uint8 Separator1[2];

float ZoomOutStartValue;
float ZoomOutFinalValue;

float ZoomOutDurationInSeconds;

LinearInterPolationSimpleStruct LinearInterPolationData;
TransformationStruct TransformationData;

} TileLogicIntroZoomOutStruct;


typedef struct{

uint8 WhichStage;
uint8 Separator1[3];


uint8 PlayerFaceDirection;
uint8 Separator2[3];

float PlayerPositionX;
float PlayerStagePositionZ;


} FightLoadableGivenStruct;


typedef struct{

uint8 BackGroundObjectAmount;
uint8 Separator1;
uint16 ObjectAmount;

float SpeedX;
float SpeedZ;

float SizeFactor;

} FightLoadableStageGeneralStruct;


typedef struct{

float StageSizeX;
float StageSizeY;
float StageSizeZ;

float StartStagePositionX;
float StartStagePositionY;

float ScreenPositionStartZ;
float ScreenPositionEndZ;

float PositionStartY;
float PositionEndY;

} FightLoadableStageBackGroundStruct;

typedef struct{

float ResistanceGround;
float GravityConstant;

} FightLoadableStagePhysicsStruct;

typedef struct{

FightLoadableStageGeneralStruct General;
FightLoadableStageBackGroundStruct BackGround;
FightLoadableStagePhysicsStruct Physics;

} FightLoadableStageStruct;


typedef struct{

uint8 EnemyAmount;
uint8 EnemyObjectAmount;
uint8 Separator1[2];

} FightLoadableEnemiesGeneralStruct;


typedef struct{

FightLoadableEnemiesGeneralStruct General;

} FightLoadableEnemiesStruct;


typedef struct{

FightLoadableGivenStruct* Given;
FightLoadableStageStruct* Stage;
FightLoadableEnemiesStruct* Enemies;

} FightLoadableStruct;


typedef struct{

uint8 LoopFight;

uint8 ObjectAmount;

TransformationStruct TransformationData;

} FightLogicGeneralStruct;

typedef struct{

float StagePositionX;
float StagePositionY;

} FightLogicStageStruct;

typedef struct{

TransformationStruct GeneralTransformationData;

} FightLogicBackGroundStruct;

typedef struct{

uint8 ObjectStart;
uint8 ObjectEnd;

} FightLogicEnemiesGeneralStruct;

typedef struct{

FightLogicEnemiesGeneralStruct General;

} FightLogicEnemiesStruct;

typedef struct{

uint8 ObjectStart;
uint8 ObjectEnd;

} FightLogicObjectsGeneralStruct;

typedef struct{

FightLogicObjectsGeneralStruct General;

} FightLogicObjectsStruct;

typedef struct{

TransformationStruct TransformationData;

} FightLogicUserInterFaceStruct;

typedef struct{

FightLogicGeneralStruct General;
FightLogicStageStruct Stage;
FightLogicBackGroundStruct BackGround;
FightLogicEnemiesStruct Enemies;
FightLogicObjectsStruct Objects;
FightLogicUserInterFaceStruct UserInterFace;

} FightLogicStruct;


typedef struct{

FightAttackStruct* FightAttackedData;

} FightFluxStolarStruct;


typedef struct{

FightFluxStolarStruct Stolar;

} FightFluxStruct;


typedef struct{

uint8 OnGround;
uint8 Separator1[3];

float SizeX;
float SizeY;

FightObjectInstanceLoadablePhysicsStruct Physics;
FightObjectInstanceLoadableHitOffsetStruct HitOffset;

} FightEnemyLoadableStruct;


typedef struct{

uint8 EnemyIdentifier;
uint8 FaceDirection;
uint16 HealthMax;

float PositionX;
float StagePositionZ;

float SizeFactor;

} FightEnemyGivenStruct;


typedef struct{

uint8 CurrentFrame;
uint8 Separator1[3];

float PositionX;
float PositionY;
float PositionZ;

float LayerSizeX;
float LayerSizeY;

float AnimationFactor;

} FightBackGroundInstanceLoadableStruct;

typedef struct{

uint8 Active;
uint8 Animate;
uint8 Draw;

uint8 CurrentAnimation;
uint16 Ticks;

TransformationStruct TransformationData;

} FightBackGroundInstanceLogicStruct;

typedef struct{

FightBackGroundInstanceLoadableStruct* Loadable;
FightBackGroundInstanceLogicStruct LogicData;

} FightBackGroundInstanceStruct;

typedef struct{

uint8 FrameAmount;
uint8 InstanceAmount;
uint8 Separator1[2];

uint16 TextureSizeX;
uint16 TextureSizeY;

AnimationStruct AnimationData;

} FightBackGroundLoadableStruct;


typedef struct{

} FightBackGroundLogicStruct;


typedef struct{

FightBackGroundInstanceStruct* Instance;

FightBackGroundLoadableStruct* Loadable;
FightBackGroundLogicStruct LogicData;
pvr_ptr_t* Texture;

} FightBackGroundStruct;


typedef struct{

uint8 Stage;
uint8 Color;
uint16 Ticks;

float AlphaValue;

float PositionX;
float PositionY;
float ScreenPositionZ;

float FontSizeX;
float FontSizeY;

} FightFloatingValueLogicStruct;


typedef struct{

char* Array;

} FightFloatingValueFluxStruct;


typedef struct{

FightFloatingValueLogicStruct LogicData; 
FightFloatingValueFluxStruct FluxData; 

} FightFloatingValueStruct;

typedef struct{

uint8 Draw;
uint8 Animate;

TransformationStruct GeneralTransformationData;

} FightObjectClassLogicStruct;

typedef struct{

FightObjectClassLogicStruct LogicData;

} FightObjectClassStruct;

typedef struct{

uint8 Type;
uint8 Separator1[3];

} FightObjectInstanceLoadableBlockageStruct;

typedef struct{

uint8 IntelligenceAmount;
uint8 FaceDirection;
uint8 CurrentFrame;
uint8 OnGround;

uint16 CurrentAnimation;
uint8 Separator1[2];

float PositionX;
float PositionY;
float StagePositionZ;
float ScreenPositionZ;

float SizeX;
float SizeY;

float AnimationFactor;

FightObjectInstanceLoadablePhysicsStruct Physics;
FightObjectInstanceLoadableHitOffsetStruct HitOffset;
FightObjectInstanceLoadableBlockageStruct Blockage;

} FightObjectInstanceLoadableStruct;

typedef struct{

uint8 SemaphoreDraw;
uint8 SemaphoreAnimate;

uint16 Health;
uint16 Damage;

uint16 Ticks;

uint8 WhichInstance;

float VelocityX;
float VelocityY;
float VelocityZ;

float AccelerationX;
float AccelerationY;
float AccelerationZ;

float ForceX;
float ForceY;
float ForceZ;

TransformationStruct TransformationData;

} FightObjectInstanceLogicStruct;

typedef struct{

void* Blockage;

} FightObjectInstanceFluxStruct;

typedef struct{

uint8 IntelligenceType;
uint8 Semaphore;

} FightObjectInstanceIntelligenceLogicStruct;

typedef struct{

void* Buffer;
FightObjectInstanceIntelligenceLogicStruct LogicData;

} FightObjectInstanceIntelligenceStruct;

struct FightObjectStructReference;

typedef struct{

struct FightObjectStructReference* Object;

FightObjectInstanceLoadableStruct* Loadable;
FightObjectInstanceLogicStruct LogicData;
FightObjectInstanceFluxStruct FluxData;

FightObjectInstanceIntelligenceStruct* Intelligence;

} FightObjectInstanceStruct;

typedef struct{

uint8 InstanceAmount;
uint8 TextureAmount;
uint16 AnimationAmount;

uint8 PhysicsType;
uint8 Separator1[3];

uint16 TextureSizeX;
uint16 TextureSizeY;
uint16 SingleTextureSizeX;
uint16 SingleTextureSizeY;

} FightObjectLoadableStruct;

typedef struct{

uint8 WhichObject;

} FightObjectLogicStruct;

typedef struct{

AnimationStruct* AnimationData;

} FightObjectFluxStruct;

typedef struct FightObjectStructReference{

FightObjectClassStruct* ClassData;
FightObjectInstanceStruct* Instance;

FightObjectLoadableStruct* Loadable;
FightObjectLogicStruct LogicData;
FightObjectFluxStruct FluxData;
pvr_ptr_t* Texture;

} FightObjectStruct;

typedef struct{

uint8 WhichObject;
uint8 WhichInstance;

} FightPlayerLogicGeneralStruct;

typedef struct{

FightPlayerLogicGeneralStruct General;

} FightPlayerLogicStruct;

typedef struct{

pvr_ptr_t Gauge;

} FightPlayerAbilityTextureStruct;

typedef struct{

FightPlayerAbilityTextureStruct TextureData;

} FightPlayerAbilityStruct;

typedef struct{

FightPlayerLogicStruct LogicData;
FightPlayerAbilityStruct AbilityData[AbilityAmount];

} FightPlayerStruct;

typedef struct{

uint8 Active;
uint8 ActiveLast;

uint8 Red;
uint8 Green;
uint8 Blue;

uint16 FilledNow;
uint16 FilledLast;

} FightCrewAbilityLogicStruct;

typedef struct{

void* Buffer;

} FightCrewAbilityFluxStruct;

typedef struct{

FightCrewAbilityLogicStruct LogicData;
FightCrewAbilityFluxStruct FluxData;

} FightCrewAbilityStruct;

typedef struct{

FightCrewAbilityStruct AbilityData[AbilityAmount];

} FightCrewStruct;

typedef struct{

OverWorldStruct* OverWorldData;

FightLoadableStruct Loadable;
FightLogicStruct LogicData;
FightFluxStruct FluxData;
FightBackGroundStruct* BackGroundData;
FightObjectStruct* ObjectData;
FightPlayerStruct* PlayerData;
FightCrewStruct* CrewData;

} FightStruct;


typedef struct{

float PositionX;
float StagePositionZ;

} FightStagePositionVector;

typedef struct{

FightStagePositionVector TopLeft;
FightStagePositionVector BottomRight;

} FightCollisionDetectRectangleStruct2D;

typedef struct{

uint8 Red;
uint8 Green;
uint8 Blue;

} PaletteSingleValueStruct;

typedef struct{

uint16 AnimationIdentifier;
uint8 Separator1[2];

FightAttackStruct FightAttackData;

} VulgarDisplayOfPowerLoadableStruct;

typedef struct{

FightCollisionDetectRectangleStruct2D* OffsetData;

} VulgarDisplayOfPowerFluxStruct;

typedef struct{

uint8 Active;
ListStruct* EnemiesHitAlready;

} VulgarDisplayOfPowerLogicStruct;

typedef struct{

VulgarDisplayOfPowerLoadableStruct* Loadable;
VulgarDisplayOfPowerFluxStruct FluxData;
VulgarDisplayOfPowerLogicStruct LogicData;

} VulgarDisplayOfPowerStruct;

typedef struct{

uint8 BranchAmount;
uint8 Separator1[3];

} TileEventBranchHeaderStruct;

typedef struct{

uint32 BranchAddress;

} TileEventBranchSingleStruct;

typedef struct{

uint8 WhichPlayer;

} TileMovementTypePlayerLoadableStruct;

typedef struct{

TileMovementTypePlayerLoadableStruct* Loadable;

} TileMovementTypePlayerStruct;

typedef struct{

uint8 IntelligenceType;
uint8 Separator1[3];

} FightObjectsSingleObjectSingleInstanceIntelligenceHeaderStruct;

typedef struct{

FightObjectsSingleObjectSingleInstanceIntelligenceHeaderStruct* Header;

} FightObjectsSingleObjectSingleInstanceIntelligenceGeneralStruct;

typedef struct{

uint16 NewTile;
uint8 Outro;
uint8 Intro;

float StartPositionX;
float StartStagePositionZ;

} TileEventExitTileStruct;

typedef struct{
float DurationInSeconds;
} TileLogicIntroBlackInLoadableStruct;

typedef struct{
float AlphaValue;
} TileLogicIntroBlackInLogicStruct;

typedef struct{
TileLogicIntroBlackInLoadableStruct Loadable;
TileLogicIntroBlackInLogicStruct LogicData;
} TileLogicIntroBlackInStruct;


typedef struct{
float DurationInSeconds;
} TileLogicOutroBlackOutLoadableStruct;

typedef struct{
float AlphaValue;
} TileLogicOutroBlackOutLogicStruct;


typedef struct{

TileLogicOutroBlackOutLoadableStruct Loadable;
TileLogicOutroBlackOutLogicStruct LogicData;

} TileLogicOutroBlackOutStruct;

typedef struct{

float PositionStartX[SpeechinatorBuildDataSpeechBubbleRowAmountMaximum];
float PositionEndX[SpeechinatorBuildDataSpeechBubbleRowAmountMaximum];
float PositionStartY;

} SpeechinatorBuildDataSpeechBubbleRowStruct;

typedef struct{

FightAttackStruct FightAttackData;

} FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineLoadableStruct;

typedef struct{

FightCollisionDetectRectangleStruct2D* MeleeOffsetData;

} FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineFluxStruct;

typedef struct{

uint16 CurrentState;
uint16 Ticks;

float SpeedX;
float SpeedZ;

ListStruct* EnemiesHitAlready;

} FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineLogicStruct;

typedef struct{

FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineLoadableStruct Loadable;
FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineFluxStruct FluxData;
FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineLogicStruct LogicData;

} FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineStruct;

typedef struct{

uint16 TextureSizeX;
uint16 TextureSizeY;

float BoundDurationInSeconds;

FightAttackStruct FightAttackData;
AnimationStruct AnimationData;

} ComeOutSwingingLoadableStruct;

typedef struct{

uint8 Active;
uint8 BoundEnemyProcessedAmount;

ListStruct* EnemiesHitAlready;
ListStruct* BoundEnemyList;

} ComeOutSwingingLogicStruct;

typedef struct{

FightCollisionDetectRectangleStruct2D* OffsetData;

} ComeOutSwingingFluxStruct;

typedef struct{

ComeOutSwingingLoadableStruct* Loadable;
ComeOutSwingingLogicStruct LogicData;
ComeOutSwingingFluxStruct FluxData;

pvr_ptr_t* Texture;

} ComeOutSwingingStruct;

typedef struct{

uint8 WhichObject;
uint8 WhichInstance;
uint16 Ticks;

} ComeOutSwingingBoundEnemyStruct;

typedef struct{

uint8 Active;

} FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicLogicStruct;

typedef struct{

FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicLogicStruct LogicData;

} FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicStruct;

typedef FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicStruct FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicPlayerStruct;
typedef FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicStruct FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicEnemyStruct;


typedef struct __attribute__((packed)){

uint16 ActionAmount;
uint8 Separator1[14]; //16

uint8 ReservedSpace[16]; 
} StoryBoardUberHeaderStruct;

typedef struct __attribute__((packed)){

uint8 WhichAction;
uint8 WaitForButtonInput;
uint8 SoundTrack;
uint8 Separator1;

uint16 Duration;
uint8 Separator2[2];

uint8 TextureStructAmount;
uint8 TextStructAmount;
uint8 SoundEffectStructAmount;
uint8 Separator3;

uint8 Separator4[4]; //16

uint8 ReservedSpace[16]; 

} StoryBoardHeaderStruct;


typedef struct __attribute__((packed)){

uint8 TextureID;
uint8 TextureAction;
uint8 TextureNameID;
uint8 Separator1;

uint8 WhichFrame;
uint8 FrameAmount;
uint8 Speed;
uint8 Loop;

uint16 PositionX;
uint16 PositionY;

uint16 SizeX;
uint16 SizeY; //16

float TexturePositionX1;
float TexturePositionY1;
float TexturePositionX2;
float TexturePositionY2; //32

short MovementX;
short MovementY;

uint16 PositionZ;
uint8 Separator2[2];

int TextureSizeX;
int TextureSizeY; //48

uint8 ReservedSpace[16]; 

} StoryBoardTextureStruct;

typedef struct __attribute__((packed)){

uint8 TextID;
uint8 TextAction;
uint8 BuildUp;
uint8 BuildUpSpeed;

uint16 PositionX;
uint16 PositionY;

uint16 SizeX;
uint16 SizeY;

uint16 FontSizeX;
uint16 FontSizeY; //16

uint8 WhichFont;
uint8 Length;
uint16 Duration;

uint16 PositionZ;
uint8 BreakSizeX;
uint8 BreakSizeY;

uint8 FontColor;
uint8 Separator1[7]; //32

uint8 ReservedSpace[16]; 

char ActualText[StoryBoardMaximumTextSize];

} StoryBoardTextStruct;

typedef struct __attribute__((packed)){

uint8 SoundEffectID;
uint8 SoundEffectAction;
uint8 SoundEffectNameID;
uint8 Separator1;

uint16 SoundEffectPlayTime;


uint8 Separator2[10];

uint8 ReservedSpace[16]; 

} StoryBoardSoundEffectStruct;
