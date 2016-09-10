#define NewGameStartTile				0
#define NewGameStartHours	0
#define NewGameStartMinutes	0

#define NewGameStartDay	0
#define NewGameStartMonth	0
#define NewGameStartYear	0

#define NewGameFaceDirection			TileFaceRight
#define NewGameStartSeconds			0
#define NewGameStartFrames			0

#define NewGameStartPositionX			40.0f
#define NewGameStartStagePositionZ	63.0f

#define NewGameStartStagePositionX			0.0f
#define NewGameStartStagePositionY			0.0f

#define NewGameStartHealthMax				100
#define NewGameStartLevel						1
#define NewGameStartAttack					1
#define NewGameStartDefense					0
#define NewGameStartSpeed						1
#define NewGameStartLuck						0
#define NewGameStartExperienceNecessary	100

#define NewGameCrewSize								1
#define NewGamePlayerIsWhichCrewMember			0
#define NewGameMainPlayerCrewMemberIdentifier	0 

uint8 StartNewGame(void** TransitionData){

uint16 DirtyDeedsDoneDirtCheap;

InitializeSaveData(); 

SaveData.HeaderData = (SaveHeaderStruct*)(malloc(sizeof(SaveHeaderStruct)));
SaveData.CompressableData = (SaveCompressableStruct*)(malloc(sizeof(SaveCompressableStruct)));

SaveData.HeaderData->CurrentTile = NewGameStartTile;
SaveData.HeaderData->Hours = NewGameStartHours;
SaveData.HeaderData->Minutes = NewGameStartMinutes;

SaveData.HeaderData->Day = NewGameStartDay;
SaveData.HeaderData->Month = NewGameStartMonth;
SaveData.HeaderData->Year = NewGameStartYear;
SaveData.HeaderData->Level = NewGameStartLevel;

SaveData.CompressableData->Seconds = NewGameStartSeconds;
SaveData.CompressableData->Frames = NewGameStartFrames;

SaveData.CompressableData->StagePositionX = NewGameStartStagePositionX;
SaveData.CompressableData->StagePositionY = NewGameStartStagePositionY;

SaveData.CompressableData->CrewSize = NewGameCrewSize;

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < PlayerAmountMaximum; DirtyDeedsDoneDirtCheap++){
SaveData.CompressableData->PlayerIsWhichCrewMember[DirtyDeedsDoneDirtCheap] = DummyValueInteger;
}
SaveData.CompressableData->PlayerIsWhichCrewMember[PlayerMain] = NewGamePlayerIsWhichCrewMember;

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < CrewSizeMaximum; DirtyDeedsDoneDirtCheap++){
SaveData.CompressableData->CrewMemberIdentifier[DirtyDeedsDoneDirtCheap] = DummyValueInteger;

SaveData.CompressableData->CrewMemberAbility[DirtyDeedsDoneDirtCheap][RedAbility] = NoAbilityIdentifier; 
SaveData.CompressableData->CrewMemberAbility[DirtyDeedsDoneDirtCheap][YellowAbility] = NoAbilityIdentifier;
SaveData.CompressableData->CrewMemberAbility[DirtyDeedsDoneDirtCheap][GreenAbility] = NoAbilityIdentifier;
SaveData.CompressableData->CrewMemberAbility[DirtyDeedsDoneDirtCheap][BlueAbility] = NoAbilityIdentifier;

SaveData.CompressableData->CrewLogic[DirtyDeedsDoneDirtCheap].Tile.StartPositionX = DummyValueFloat;
SaveData.CompressableData->CrewLogic[DirtyDeedsDoneDirtCheap].Tile.StartStagePositionZ = DummyValueFloat;
SaveData.CompressableData->CrewLogic[DirtyDeedsDoneDirtCheap].Fight.HealthMax = NewGameStartHealthMax;
}

SaveData.CompressableData->CrewMemberIdentifier[NewGamePlayerIsWhichCrewMember] = NewGameMainPlayerCrewMemberIdentifier;

SaveData.CompressableData->CrewMemberAbility[NewGamePlayerIsWhichCrewMember][RedAbility] = RedAbilityIdentifier; 
SaveData.CompressableData->CrewMemberAbility[NewGamePlayerIsWhichCrewMember][YellowAbility] = 2;
SaveData.CompressableData->CrewMemberAbility[NewGamePlayerIsWhichCrewMember][GreenAbility] = NoAbilityIdentifier;
SaveData.CompressableData->CrewMemberAbility[NewGamePlayerIsWhichCrewMember][BlueAbility] = NoAbilityIdentifier;

SaveData.CompressableData->CrewLogic[NewGamePlayerIsWhichCrewMember].Tile.FaceDirection = NewGameFaceDirection;
SaveData.CompressableData->CrewLogic[NewGamePlayerIsWhichCrewMember].Tile.StartPositionX = NewGameStartPositionX;
SaveData.CompressableData->CrewLogic[NewGamePlayerIsWhichCrewMember].Tile.StartStagePositionZ = NewGameStartStagePositionZ;


for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<StoryFlagByteAmount; DirtyDeedsDoneDirtCheap++) SaveData.CompressableData->StoryFlags[DirtyDeedsDoneDirtCheap] = 0;
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<SpecialEnemyFlagByteAmount; DirtyDeedsDoneDirtCheap++) SaveData.CompressableData->SpecialEnemyFlags[DirtyDeedsDoneDirtCheap] = 0;

(*TileLogicIntroInitiate[TileLogicIntroBlackInIdentifier])((TileLogicIntroStruct **)TransitionData);

StartNewGameSequence();

return(TheGameIsOnStage);
}