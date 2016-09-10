void TileMovementTypePlayer(TileMovementTypeArguments){
uint8 WhichPlayer;

if(TileData->LogicData.General.EnableFlags & TileEnableFlagMovementPlayer){
WhichPlayer = TilePlayerGetWhichPlayerFromObjectAndInstance(TileData, OverWorldData, WhichObject, WhichInstance);


if(ButtonPressedUp(OverWorldData->LogicData.Player[WhichPlayer].Input.st)){

if(CheckForOverWorldBorderY(TileData, &TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX, &TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.PositionY, &TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ScreenPositionZ, &TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ, TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeX, &TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SizeX, TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeY, &TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SizeY, TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SpeedX, &TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SpeedX, -TileData->TileHeaderData->StageSpeedZ, &TileData->LogicData.BackGround.Movement)){
if(TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != PlayerRunningAnimation){
TilePlayerChangeAnimationSimplest(WhichPlayer, PlayerRunningAnimation);
}
}
else if(TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != PlayerIdleAnimation){
TilePlayerChangeAnimationSimplest(WhichPlayer, PlayerIdleAnimation);
}

}
else if(ButtonPressedDown(OverWorldData->LogicData.Player[WhichPlayer].Input.st)){

if(CheckForOverWorldBorderY(TileData, &TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX, &TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.PositionY, &TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ScreenPositionZ, &TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ, TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeX, &TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SizeX, TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SizeY, &TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SizeY, TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SpeedX, &TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.SpeedX, TileData->TileHeaderData->StageSpeedZ, &TileData->LogicData.BackGround.Movement)){
if(TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != PlayerRunningAnimation){
TilePlayerChangeAnimationSimplest(WhichPlayer, PlayerRunningAnimation);
}
}
else if(TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != PlayerIdleAnimation){
TilePlayerChangeAnimationSimplest(WhichPlayer, PlayerIdleAnimation);
}

}

if(ButtonPressedLeft(OverWorldData->LogicData.Player[WhichPlayer].Input.st)){

if(CheckForOverWorldBorderX(TileData, &TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX, &TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ, -TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SpeedX)){
if(TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != PlayerRunningAnimation){
TilePlayerChangeAnimationSimplest(WhichPlayer, PlayerRunningAnimation);
}
}
else if(TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != PlayerIdleAnimation){
TilePlayerChangeAnimationSimplest(WhichPlayer, PlayerIdleAnimation);
}
TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection = TileFaceLeft;


}
else if(ButtonPressedRight(OverWorldData->LogicData.Player[WhichPlayer].Input.st)){

if(CheckForOverWorldBorderX(TileData, &TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionX, &TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ, TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->SpeedX)){
if(TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != PlayerRunningAnimation){
TilePlayerChangeAnimationSimplest(WhichPlayer, PlayerRunningAnimation);
}
}
else if(TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != PlayerIdleAnimation){
TilePlayerChangeAnimationSimplest(WhichPlayer, PlayerIdleAnimation);
}
TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection = TileFaceRight;

}

if(TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation == PlayerRunningAnimation){
if(
!ButtonPressedUp(OverWorldData->LogicData.Player[WhichPlayer].Input.st) && 
!ButtonPressedDown(OverWorldData->LogicData.Player[WhichPlayer].Input.st) &&
!ButtonPressedLeft(OverWorldData->LogicData.Player[WhichPlayer].Input.st) &&
!ButtonPressedRight(OverWorldData->LogicData.Player[WhichPlayer].Input.st)
){
TilePlayerChangeAnimationSimplest(WhichPlayer, PlayerIdleAnimation);
}
}


}
}
