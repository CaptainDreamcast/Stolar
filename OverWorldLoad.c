#define OverWorldLogicGeneralInitiate()	{ \
OverWorldData->LogicData.General.LoopOverWorld = OverWorldLogicGeneralOverWorldLoop; \
OverWorldData->LogicData.General.ReturnStage = TitleScreenStage; \
OverWorldData->LogicData.General.CurrentTile = SaveData.HeaderData->CurrentTile; \
OverWorldData->LogicData.General.CurrentGamePlay = OverWorldGamePlayTile; \
OverWorldData->LogicData.General.PlayerAmount = OverWorldLoadPlayerAmountStart; \
OverWorldData->LogicData.General.CrewSize = SaveData.CompressableData->CrewSize; \
}


#define OverWorldLogicMusicInitiate()	{ \
OverWorldData->LogicData.Music.CurrentTrack = OverWorldLogicMusicCurrentTrackStartValue; \
OverWorldData->LogicData.Music.AudioBuffer = NULL; \
}

#define OverWorldLogicPlayerGeneralInitiate(WhichPlayer)	{ \
OverWorldData->LogicData.Player[WhichPlayer].General.WhichController = WhichPlayer; \
OverWorldData->LogicData.Player[WhichPlayer].General.WhichCrewMember = SaveData.CompressableData->PlayerIsWhichCrewMember[WhichPlayer]; \
}

#define OverWorldLogicPlayerInputInitiate(WhichPlayer)	{ \
OverWorldData->LogicData.Player[WhichPlayer].Input.st = NULL; \
ResetButtonInputData(OverWorldData->LogicData.Player[WhichPlayer].Input.ButtonInputData, BurningDownTheHouse); \
}

#define OverWorldLogicPlayerInitiate(WhichPlayer)	{ \
OverWorldLogicPlayerGeneralInitiate(WhichPlayer); \
OverWorldLogicPlayerInputInitiate(WhichPlayer); \
}

#define OverWorldLogicInitiate()		{ \
OverWorldLogicGeneralInitiate(); \
OverWorldLogicMusicInitiate(); \
OverWorldData->LogicData.Player = (OverWorldLogicPlayerStruct*)malloc(sizeof(OverWorldLogicPlayerStruct)*OverWorldData->LogicData.General.PlayerAmount); \
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < OverWorldData->LogicData.General.PlayerAmount; DirtyDeedsDoneDirtCheap++){ \
OverWorldLogicPlayerInitiate(DirtyDeedsDoneDirtCheap); \
} \
OverWorldData->LogicData.Passable = NULL; \
}


void OverWorldLoad(OverWorldStruct* OverWorldData, void** TransitionData){

char FileDir[NormalFileDirSize];
uint32 CurrentPointerPosition;
uint32 FinalBufferSize;
uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;

sprintf(FileDir, "%s/GENERAL/OVERHEAVEN.owl.gz", FileSystemUsed);
CompressedFileToBuffer(FileDir, (void**)(&OverWorldData->Loadable));
CurrentPointerPosition = ((uint32)OverWorldData->Loadable)+sizeof(OverWorldLoadableStruct);


LoadCurrentPointerPositionSetToLegalStartValue();

FinalBufferSize = CurrentPointerPosition-((uint32)OverWorldData->Loadable);

LoadCurrentPointerPositionSetToLegalStartValue();
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < SpeechBubbleAmountOverall; DirtyDeedsDoneDirtCheap++){
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldData->TextureData.SpeechBubbleTexture[DirtyDeedsDoneDirtCheap]);
}

LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldData->TextureData.Abilities);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldData->TextureData.Tile.Intro.General.Black);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldData->TextureData.Fight.UserInterFace.Health);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldData->TextureData.Fight.UserInterFace.HealthBackGround);
LoadTextureFromBufferPointer(CurrentPointerPosition, OverWorldData->TextureData.Fight.UserInterFace.AbilityBackGround);

LoadBufferFromBufferPointer(void*, OverWorldData->FluxData.Fight.UserInterFace.Abilities.ThresholdTexture, (OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeX*OverWorldData->Loadable->Fight.UserInterFace.Abilities.General.Gauge.TextureSizeY));
OverWorldData->FluxData.General.TransitionData = (*TransitionData);

OverWorldLogicInitiate();

OverWorldData->Loadable = realloc(OverWorldData->Loadable, FinalBufferSize);

OverWorldData->CrewData = (OverWorldCrewStruct*)malloc(sizeof(OverWorldCrewStruct)*OverWorldData->LogicData.General.CrewSize);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < OverWorldData->LogicData.General.CrewSize; DirtyDeedsDoneDirtCheap++){
CrewMemberSingleLoad(&OverWorldData->CrewData[DirtyDeedsDoneDirtCheap], SaveData.CompressableData->CrewMemberIdentifier[DirtyDeedsDoneDirtCheap], SaveData.CompressableData->CrewMemberAbility[DirtyDeedsDoneDirtCheap], &SaveData.CompressableData->CrewLogic[DirtyDeedsDoneDirtCheap]);
}

}
