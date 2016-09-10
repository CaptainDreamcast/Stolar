void TileMovementStolar(TileStruct* TileData, OverWorldStruct* OverWorldData){

if(TileData->LogicData.General.EnableFlags & TileEnableFlagMovementStolar){

if(ButtonPressedUp(OverWorldData->LogicData.Input.st)){

if(CheckForOverWorldBorderY(TileData, &TileData->LogicData.Stolar.PositionX, &TileData->LogicData.Stolar.PositionY, &TileData->LogicData.Stolar.ScreenPositionZ, &TileData->LogicData.Stolar.StagePositionZ, &TileData->LogicData.Stolar.SizeX, &TileData->LogicData.Stolar.SizeY, &TileData->LogicData.Stolar.SpeedX, -TileData->TileHeaderData->StageSpeedZ, &TileData->LogicData.Stolar.Movement)){
if(TileData->LogicData.Stolar.CurrentAnimation != StolarRunningAnimation+OverWorldFaceUp){
StolarChangeOverWorldAnimationSimplest(StolarRunningAnimation+OverWorldFaceUp);
}
}
else if(TileData->LogicData.Stolar.CurrentAnimation != StolarIdleAnimation+OverWorldFaceUp){
StolarChangeOverWorldAnimationSimplest(StolarIdleAnimation+OverWorldFaceUp);
}

}
else if(ButtonPressedDown(OverWorldData->LogicData.Input.st)){

if(CheckForOverWorldBorderY(TileData, &TileData->LogicData.Stolar.PositionX, &TileData->LogicData.Stolar.PositionY, &TileData->LogicData.Stolar.ScreenPositionZ, &TileData->LogicData.Stolar.StagePositionZ, &TileData->LogicData.Stolar.SizeX, &TileData->LogicData.Stolar.SizeY, &TileData->LogicData.Stolar.SpeedX, TileData->TileHeaderData->StageSpeedZ, &TileData->LogicData.Stolar.Movement)){
if(TileData->LogicData.Stolar.CurrentAnimation != StolarRunningAnimation+OverWorldFaceDown){
StolarChangeOverWorldAnimationSimplest(StolarRunningAnimation+OverWorldFaceDown);
}
}
else if(TileData->LogicData.Stolar.CurrentAnimation != StolarIdleAnimation+OverWorldFaceDown){
StolarChangeOverWorldAnimationSimplest(StolarIdleAnimation+OverWorldFaceDown);
}

}

if(ButtonPressedLeft(OverWorldData->LogicData.Input.st)){

if(CheckForOverWorldBorderX(TileData, &TileData->LogicData.Stolar.PositionX, &TileData->LogicData.Stolar.StagePositionZ, -TileData->LogicData.Stolar.SpeedX)){
if(TileData->LogicData.Stolar.CurrentAnimation != StolarRunningAnimation+OverWorldFaceLeft){
StolarChangeOverWorldAnimationSimplest(StolarRunningAnimation+OverWorldFaceLeft);
}
}
else if(TileData->LogicData.Stolar.CurrentAnimation != StolarIdleAnimation+OverWorldFaceLeft){
StolarChangeOverWorldAnimationSimplest(StolarIdleAnimation+OverWorldFaceLeft);
}

}
else if(ButtonPressedRight(OverWorldData->LogicData.Input.st)){

if(CheckForOverWorldBorderX(TileData, &TileData->LogicData.Stolar.PositionX, &TileData->LogicData.Stolar.StagePositionZ, TileData->LogicData.Stolar.SpeedX)){
if(TileData->LogicData.Stolar.CurrentAnimation != StolarRunningAnimation+OverWorldFaceRight){
StolarChangeOverWorldAnimationSimplest(StolarRunningAnimation+OverWorldFaceRight);
}
}
else if(TileData->LogicData.Stolar.CurrentAnimation != StolarIdleAnimation+OverWorldFaceRight){
StolarChangeOverWorldAnimationSimplest(StolarIdleAnimation+OverWorldFaceLeft);
}

}

}
}