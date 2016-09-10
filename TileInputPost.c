void TileInputPost(TileStruct* TileData, OverWorldStruct* OverWorldData) {
StairWayToHeavenCheck(OverWorldData->LogicData.Player[PlayerMain].Input.st,
{
TileExitSet(TileData);
OverWorldExitSet(OverWorldData);
}
);
}
