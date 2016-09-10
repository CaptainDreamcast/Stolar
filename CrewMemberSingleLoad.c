#define CrewMemberSingleLoadLogicTileInitiate()		{ \
CrewData->LogicData.Tile.FaceDirection = CrewLogicData->Tile.FaceDirection; \
CrewData->LogicData.Tile.StartPositionX = CrewLogicData->Tile.StartPositionX; \
CrewData->LogicData.Tile.StartStagePositionZ = CrewLogicData->Tile.StartStagePositionZ; \
}

#define CrewMemberSingleLoadLogicFightInitiate()		{ \
CrewData->LogicData.Fight.HealthMax = CrewLogicData->Fight.HealthMax; \
}

#define CrewMemberSingleLoadLogicInitiate()		{ \
CrewMemberSingleLoadLogicTileInitiate(); \
CrewMemberSingleLoadLogicFightInitiate(); \
}

void CrewMemberSingleLoad(OverWorldCrewStruct* CrewData, uint8 CrewMemberIdentifier, uint16* AbilityIdentifier, OverWorldCrewLogicStruct* CrewLogicData){

char FileDir[NormalFileDirSize];
uint32 CurrentPointerPosition, FinalBufferSize;
uint8 DirtyDeedsDoneDirtCheap;

sprintf(FileDir, "%s/CREW/%d.crw.gz", FileSystemUsed, CrewMemberIdentifier);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/%d.crw.gz", CrewMemberIdentifier);

CompressedFileToBuffer(FileDir, (void**)(&CrewData->Loadable));
CurrentPointerPosition = ((uint32)CrewData->Loadable)+sizeof(OverWorldCrewLoadableStruct);
LoadSetThisToThatPointer(AnimationStruct*, CrewData->FluxData.AnimationData, sizeof(AnimationStruct)*CrewData->Loadable->General.AnimationAmount);

FinalBufferSize = CurrentPointerPosition-((uint32)CrewData->Loadable);

CrewData->Texture = (pvr_ptr_t*)malloc(sizeof(pvr_ptr_t)*CrewData->Loadable->General.TextureAmount);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < CrewData->Loadable->General.TextureAmount; DirtyDeedsDoneDirtCheap++){
LoadTextureFromBufferPointer(CurrentPointerPosition, CrewData->Texture[DirtyDeedsDoneDirtCheap]);
}

CrewData->Loadable = realloc(CrewData->Loadable, FinalBufferSize);

CrewMemberSingleLoadLogicInitiate();

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < AbilityAmount; DirtyDeedsDoneDirtCheap++){
AbilitySingleLoad(&CrewData->FluxData.Abilities[DirtyDeedsDoneDirtCheap], AbilityIdentifier[DirtyDeedsDoneDirtCheap]);
}

}