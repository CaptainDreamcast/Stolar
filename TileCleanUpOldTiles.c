#define TileCleanUpSingleTile(WhichTile)	{ \
sprintf(FileDir, "/ram/%d.del", WhichTile); \
StreamingLoadUnlink(FileDir); \
sprintf(FileDir, "/ram/%d.til", WhichTile); \
StreamingLoadUnlink(FileDir); \
sprintf(FileDir, "/ram/%d.add", WhichTile); \
StreamingLoadUnlink(FileDir); \
}

#define TileCleanUpSingleMusic(WhichTrack)	{ \
sprintf(FileDir, "/ram/%d.%s", WhichTrack, MusicStandardFileType); \
StreamingLoadUnlink(FileDir); \
}

void TileCleanUpOldTiles(OverWorldStruct* OverWorldData) {

TileCleanUpOldTilesStruct TileCleanUpOldTilesData;
char FileDir[NormalFileDirSize];
uint8 DirtyDeedsDoneDirtCheap;
uint32 CurrentPointerPosition;

sprintf(FileDir, "%s/TILES/%d.del", FileSystemUsed, OverWorldData->LogicData.General.CurrentTile);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/%d.del", OverWorldData->LogicData.General.CurrentTile);
FileToBuffer(FileDir, (void**)(&TileCleanUpOldTilesData.Loadable));
CurrentPointerPosition = (uint32)(TileCleanUpOldTilesData.Loadable+sizeof(TileCleanUpOldTilesLoadableStruct));
LoadSetThisToThatPointer(uint16*, TileCleanUpOldTilesData.TileIdentifier, (sizeof(uint16)*TileCleanUpOldTilesData.Loadable->TileAmount));
LoadSetThisToThatPointer(uint16*, TileCleanUpOldTilesData.MusicTrackIdentifier, (sizeof(uint16)*TileCleanUpOldTilesData.Loadable->MusicAmount));

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileCleanUpOldTilesData.Loadable->TileAmount; DirtyDeedsDoneDirtCheap++){
TileCleanUpSingleTile(TileCleanUpOldTilesData.TileIdentifier[DirtyDeedsDoneDirtCheap]);
}

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileCleanUpOldTilesData.Loadable->MusicAmount; DirtyDeedsDoneDirtCheap++){
TileCleanUpSingleMusic(TileCleanUpOldTilesData.MusicTrackIdentifier[DirtyDeedsDoneDirtCheap]);
}

free(TileCleanUpOldTilesData.Loadable);

}