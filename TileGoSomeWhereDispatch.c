void TileGoSomeWhereDispatch(TileStruct* TileData, OverWorldStruct* OverWorldData, uint8 WhichGamePlay, uint8 WhereExactly){

TileExitSet(TileData);

if(WhichGamePlay == OverWorldGamePlayTile){
TileInitiateSet(OverWorldData, WhereExactly);
}
else if(WhichGamePlay == OverWorldGamePlayFight){
FightInitiateSet(OverWorldData);
}
else{
printf("TileGoSomeWhereDispatch: Unknown WhichGamePlay: (%d)\n", WhichGamePlay);
}

}