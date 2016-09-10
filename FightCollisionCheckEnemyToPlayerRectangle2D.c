#define FightCollisionCheckEnemyToPlayerRectangleAddEnemyDependencyRight2D(RectangleData)	{ \
FightCollisionCheckRectangleAddDependencyRight2D(WhichObject, WhichInstance, RectangleData); \
}


#define FightCollisionCheckEnemyToPlayerRectangleAddEnemyDependencyLeft2D(RectangleData)	{ \
FightCollisionCheckRectangleAddDependencyLeft2D(WhichObject, WhichInstance, RectangleData); \
}

void FightCollisionCheckEnemyToPlayerRectangle2D(FightStruct* FightData, uint8 FightCollisionType, uint8 WhichObject, uint8 WhichInstance, FightCollisionDetectRectangleStruct2D RectangleData, FightAttackStruct* FightAttackData, ListStruct** EnemiesHitAlready){

FightCollisionDetectRectangleStruct2D CompareRectangle;
float PositionBuffer;
uint8 WhichPlayer, PlayerObject, PlayerInstance;

/*
printf("RectangleData.TopLeft.PositionX: (%f)\n", RectangleData.TopLeft.PositionX);
printf("RectangleData.TopLeft.StagePositionZ: (%f)\n", RectangleData.TopLeft.StagePositionZ);
printf("RectangleData.BottomRight.PositionX: (%f)\n", RectangleData.BottomRight.PositionX);
printf("RectangleData.BottomRight.StagePositionZ: (%f)\n", RectangleData.BottomRight.StagePositionZ);
*/

if(FightCollisionType == FightCollisionCheckEnemyDependent){
if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection == FightFaceRight){
FightCollisionCheckEnemyToPlayerRectangleAddEnemyDependencyRight2D(RectangleData);
}
else{
FightCollisionCheckEnemyToPlayerRectangleAddEnemyDependencyLeft2D(RectangleData);
}
}


for(WhichPlayer = 0; WhichPlayer < FightData->OverWorldData->LogicData.General.PlayerAmount; WhichPlayer++){

PlayerObject = FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject;
PlayerInstance = FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance;

/*
printf("PositionX: (%f)\n", FightObjectFetchLeftPositionX(FightData, PlayerObject, PlayerInstance));
printf("StagePositionZ: (%f)\n", FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->StagePositionZ);
printf("LeftX: (%f)\n", FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.LeftX);
printf("UpZ: (%f)\n", FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.UpZ);
printf("RightX: (%f)\n", FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.RightX);
printf("DownZ: (%f)\n", FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.DownZ);
*/

if(FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->FaceDirection == FightFaceRight){
CompareRectangle = FightCollisionDetectRectangleCreate2D(
FightObjectFetchLeftPositionX(FightData, PlayerObject, PlayerInstance)+FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.LeftX, 
FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->StagePositionZ+FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.UpZ,
FightObjectFetchLeftPositionX(FightData, PlayerObject, PlayerInstance)+FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.RightX, 
FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->StagePositionZ+FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.DownZ
);
}
else{
CompareRectangle = FightCollisionDetectRectangleCreate2D(
FightObjectFetchRightPositionX(FightData, PlayerObject, PlayerInstance)-FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.RightX,
FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->StagePositionZ+FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.UpZ,
FightObjectFetchRightPositionX(FightData, PlayerObject, PlayerInstance)-FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.LeftX,  
FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->StagePositionZ+FightData->ObjectData[PlayerObject].Instance[PlayerInstance].Loadable->HitOffset.DownZ
);
}


if(FightCollisionDetectRectangleCheck2D(RectangleData, CompareRectangle)){
if(EnemiesHitAlready == NULL || !FightCollisionRegisterEnemyHitAlready(FightData, PlayerObject, PlayerInstance, (*EnemiesHitAlready))){
FightCollisionRegisterHitEnemy(FightData, PlayerObject, PlayerInstance, FightAttackData, FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection);
if(EnemiesHitAlready != NULL) FightCollisionRegisterAddEnemyToHitAlreadyList(FightData, PlayerObject, PlayerInstance, EnemiesHitAlready);
}
}

}

}