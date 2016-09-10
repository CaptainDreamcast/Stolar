void Tile(OverWorldStruct* OverWorldData){

TileStruct TileData;

TileCleanUpOldTiles(OverWorldData);
TileAddNewTiles(OverWorldData);
TileLoad(&TileData, OverWorldData);
SoundPlay(1);

while(TileData.LogicData.General.LoopTile){

TileDrawStart(&TileData);
TileInputPre(&TileData, OverWorldData);
TileLogicPre(&TileData, OverWorldData);
TileEventCheck(&TileData, OverWorldData);
TileEventHandler(&TileData, OverWorldData);
TileMovement(&TileData, OverWorldData);
TileDraw(&TileData, OverWorldData);
TileDrawFinish();
TileLogicPost(&TileData, OverWorldData);
TileInputPost(&TileData, OverWorldData);
}

SoundStop(1);
TileDeLoad(&TileData, OverWorldData);

}