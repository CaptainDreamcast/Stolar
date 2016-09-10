

void TileMovementTypeNothing(TileMovementTypeArguments){

}





void (*TileMovementType[TileMovementTypeAmount])(TileMovementTypeArguments) = {
TileMovementTypeNothing, TileMovementTypePlayer
};
