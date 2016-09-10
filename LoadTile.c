void LoadTile(LoadTileLoadableStruct* Loadable){

char FileDir[NormalFileDirSize];

sprintf(FileDir, "%s/TILES/%d.del", FileSystemUsed, Loadable->WhichTile);
SetStreamingLoadFile(FileDir, Loadable->Priority);
sprintf(FileDir, "%s/TILES/%d.til.gz", FileSystemUsed, Loadable->WhichTile);
SetStreamingLoadFile(FileDir, Loadable->Priority);

}