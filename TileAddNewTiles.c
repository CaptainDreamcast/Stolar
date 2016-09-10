#define TileAddSingleTile(WhichTile)	{ \
sprintf(FileDir, "%s/TILES/%d.del", FileSystemUsed, WhichTile); \
SetStreamingLoadFileSimplest(FileDir); \
sprintf(FileDir, "%s/TILES/%d.til", FileSystemUsed, WhichTile); \
SetStreamingLoadFileSimplest(FileDir); \
sprintf(FileDir, "%s/TILES/%d.add", FileSystemUsed, WhichTile); \
SetStreamingLoadFileSimplest(FileDir); \
}

#define TileAddSingleMusic(WhichTrack)	{ \
sprintf(FileDir, "%s/MUSIC/%d.%s", FileSystemUsed, WhichTrack, MusicStandardFileType); \
SetStreamingLoadFileSimplest(FileDir); \
}

void TileAddNewTiles(OverWorldStruct* OverWorldData) {

TileAddNewTilesStruct TileAddNewTilesData;
char FileDir[NormalFileDirSize];
uint8 DirtyDeedsDoneDirtCheap;
uint32 CurrentPointerPosition;

sprintf(FileDir, "%s/TILES/%d.add", FileSystemUsed, OverWorldData->LogicData.General.CurrentTile);
StreamingLoadFlush(FileDir);
sprintf(FileDir, "/ram/%d.add", OverWorldData->LogicData.General.CurrentTile);
FileToBuffer(FileDir, (void**)(&TileAddNewTilesData.Loadable));
CurrentPointerPosition = (uint32)(TileAddNewTilesData.Loadable+sizeof(TileAddNewTilesLoadableStruct));
LoadSetThisToThatPointer(uint16*, TileAddNewTilesData.TileIdentifier, (sizeof(uint16)*TileAddNewTilesData.Loadable->TileAmount));
LoadSetThisToThatPointer(uint16*, TileAddNewTilesData.MusicTrackIdentifier, (sizeof(uint16)*TileAddNewTilesData.Loadable->MusicAmount));

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileAddNewTilesData.Loadable->TileAmount; DirtyDeedsDoneDirtCheap++){
TileAddSingleTile(TileAddNewTilesData.TileIdentifier[DirtyDeedsDoneDirtCheap]);
}

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileAddNewTilesData.Loadable->MusicAmount; DirtyDeedsDoneDirtCheap++){
TileAddSingleMusic(TileAddNewTilesData.MusicTrackIdentifier[DirtyDeedsDoneDirtCheap]);
}

free(TileAddNewTilesData.Loadable);
}