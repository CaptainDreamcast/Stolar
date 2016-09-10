#define FightCollisionCheckPlayerToEnemyRectangleAddPlayerDependencyRight2D(WhichPlayer, RectangleData)	{ \
FightCollisionCheckRectangleAddDependencyRight2D(FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject, FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance, RectangleData); \
}

#define FightCollisionCheckRectangleAddDependencyRight2D(WhichObject, WhichInstance, RectangleData)	{ \
RectangleData.TopLeft.PositionX += FightObjectFetchLeftPositionX(FightData, WhichObject, WhichInstance); \
RectangleData.TopLeft.StagePositionZ += FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ; \
RectangleData.BottomRight.PositionX += FightObjectFetchLeftPositionX(FightData, WhichObject, WhichInstance); \
RectangleData.BottomRight.StagePositionZ += FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ; \
}

#define FightCollisionCheckPlayerToEnemyRectangleAddPlayerDependencyLeft2D(WhichPlayer, RectangleData)	{ \
FightCollisionCheckRectangleAddDependencyLeft2D(FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject, FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance, RectangleData); \
}

#define FightCollisionCheckRectangleAddDependencyLeft2D(WhichObject, WhichInstance, RectangleData)	{ \
PositionBuffer = RectangleData.TopLeft.PositionX; \
RectangleData.TopLeft.PositionX = FightObjectFetchRightPositionX(FightData, WhichObject, WhichInstance)-RectangleData.BottomRight.PositionX; \
RectangleData.TopLeft.StagePositionZ += FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ; \
RectangleData.BottomRight.PositionX = FightObjectFetchRightPositionX(FightData, WhichObject, WhichInstance)-PositionBuffer; \
RectangleData.BottomRight.StagePositionZ += FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ; \
}

uint8 FightCollisionCheckPlayerToEnemyRectangle2D(FightStruct* FightData, uint8 FightCollisionType, uint8 WhichPlayer, FightCollisionDetectRectangleStruct2D RectangleData, FightAttackStruct* FightAttackData, ListStruct** EnemiesHitAlready){

FightCollisionDetectRectangleStruct2D CompareRectangle;
float PositionBuffer;
uint8 WhichObject, WhichInstance;
uint8 ReturnValue;

/*
printf("RectangleData.TopLeft.PositionX: (%f)\n", RectangleData.TopLeft.PositionX);
printf("RectangleData.TopLeft.StagePositionZ: (%f)\n", RectangleData.TopLeft.StagePositionZ);
printf("RectangleData.BottomRight.PositionX: (%f)\n", RectangleData.BottomRight.PositionX);
printf("RectangleData.BottomRight.StagePositionZ: (%f)\n", RectangleData.BottomRight.StagePositionZ);
*/

if(FightCollisionType == FightCollisionCheckPlayerDependent){
if(FightData->ObjectData[FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject].Instance[FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance].Loadable->FaceDirection == FightFaceRight){
FightCollisionCheckPlayerToEnemyRectangleAddPlayerDependencyRight2D(WhichPlayer, RectangleData);
}
else{
FightCollisionCheckPlayerToEnemyRectangleAddPlayerDependencyLeft2D(WhichPlayer, RectangleData);
}
}


ReturnValue = LogicActiveNot;
for(WhichObject = FightData->LogicData.Enemies.General.ObjectStart; WhichObject < FightData->LogicData.Enemies.General.ObjectEnd; WhichObject++){
for(WhichInstance = 0; WhichInstance < FightData->ObjectData[WhichObject].Loadable->InstanceAmount; WhichInstance++){

/*
printf("PositionX: (%f)\n", FightObjectFetchLeftPositionX(FightData, WhichObject, WhichInstance));
printf("StagePositionZ: (%f)\n", FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ);
printf("LeftX: (%f)\n", FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.LeftX);
printf("UpZ: (%f)\n", FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.UpZ);
printf("RightX: (%f)\n", FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.RightX);
printf("DownZ: (%f)\n", FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.DownZ);
*/

if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection == FightFaceRight){
CompareRectangle = FightCollisionDetectRectangleCreate2D(
FightObjectFetchLeftPositionX(FightData, WhichObject, WhichInstance)+FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.LeftX, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ+FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.UpZ,
FightObjectFetchLeftPositionX(FightData, WhichObject, WhichInstance)+FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.RightX, 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ+FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.DownZ
);
}
else{
CompareRectangle = FightCollisionDetectRectangleCreate2D(
FightObjectFetchRightPositionX(FightData, WhichObject, WhichInstance)-FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.RightX,
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ+FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.UpZ,
FightObjectFetchRightPositionX(FightData, WhichObject, WhichInstance)-FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.LeftX,  
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ+FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->HitOffset.DownZ
);
}
if(FightCollisionDetectRectangleCheck2D(RectangleData, CompareRectangle)){
if(EnemiesHitAlready == NULL || !FightCollisionRegisterEnemyHitAlready(FightData, WhichObject, WhichInstance, (*EnemiesHitAlready))){
FightCollisionRegisterHitEnemy(FightData, WhichObject, WhichInstance, FightAttackData, FightData->ObjectData[FightData->PlayerData[WhichPlayer].LogicData.General.WhichObject].Instance[FightData->PlayerData[WhichPlayer].LogicData.General.WhichInstance].Loadable->FaceDirection);
if(EnemiesHitAlready != NULL) FightCollisionRegisterAddEnemyToHitAlreadyList(FightData, WhichObject, WhichInstance, EnemiesHitAlready);
FightCollisionCheckPlayerIncreaseAbilities(FightData, WhichPlayer, FightAttackData);
ReturnValue = LogicActive;
}
}
}

}

return(ReturnValue);
}