void DeLoadTile(DeLoadTileLoadableStruct* Loadable){

char FileDir[NormalFileDirSize];

sprintf(FileDir, "%s/TILES/%d.del", FileSystemUsed, Loadable->WhichTile);
StreamingLoadUnlink(FileDir);
sprintf(FileDir, "%s/TILES/%d.til.gz", FileSystemUsed, Loadable->WhichTile);
StreamingLoadUnlink(FileDir);

}