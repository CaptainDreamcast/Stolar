
#define ArtificialIntelligenceMovementItself(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, SpeedFactorX, SpeedFactorZ); { \
 \
if(ArtificialIntelligenceMovementBitsX(CurrentStruct.Loadable->ArtificialIntelligenceBuffer) == ArtificialIntelligenceMovementLeft){  \
  \
if(CheckForOverWorldBorderX(TileData, &CurrentStruct.Loadable->PositionX, &CurrentStruct.Loadable->StagePositionZ, -CurrentStruct.Loadable->SpeedX*SpeedFactorX)){  \
if(CurrentStruct.Loadable->CurrentAnimation != RunningAnimation+OverWorldFaceLeft){  \
ChangeAnimationSimplestArtificialIntelligence(CurrentStruct, RunningAnimation+OverWorldFaceLeft); \
}  \
}  \
else if(CurrentStruct.Loadable->CurrentAnimation != IdleAnimation+OverWorldFaceLeft){  \
ChangeAnimationSimplestArtificialIntelligence(CurrentStruct, IdleAnimation+OverWorldFaceLeft); \
}  \
  \
}  \
else if(ArtificialIntelligenceMovementBitsX(CurrentStruct.Loadable->ArtificialIntelligenceBuffer) == ArtificialIntelligenceMovementRight){  \
  \
if(CheckForOverWorldBorderX(TileData, &CurrentStruct.Loadable->PositionX, &CurrentStruct.Loadable->StagePositionZ, CurrentStruct.Loadable->SpeedX*SpeedFactorX)){  \
if(CurrentStruct.Loadable->CurrentAnimation != RunningAnimation+OverWorldFaceRight){  \
ChangeAnimationSimplestArtificialIntelligence(CurrentStruct, RunningAnimation+OverWorldFaceRight); \
}  \
}  \
else if(CurrentStruct.Loadable->CurrentAnimation != IdleAnimation+OverWorldFaceRight){  \
ChangeAnimationSimplestArtificialIntelligence(CurrentStruct, IdleAnimation+OverWorldFaceRight); \
}  \
  \
}  \
  \
if(ArtificialIntelligenceMovementBitsY(CurrentStruct.Loadable->ArtificialIntelligenceBuffer) == ArtificialIntelligenceMovementUp){  \
  \
if(CheckForOverWorldBorderY(TileData, &CurrentStruct.Loadable->PositionX, &CurrentStruct.Loadable->PositionY, &CurrentStruct.Loadable->ScreenPositionZ, &CurrentStruct.Loadable->StagePositionZ, &CurrentStruct.Loadable->SizeX, &CurrentStruct.Loadable->SizeY, &CurrentStruct.Loadable->SpeedX, -CurrentStruct.Loadable->SpeedZ*SpeedFactorZ,  TileMovementLogicData)){  \
if(CurrentStruct.Loadable->CurrentAnimation != RunningAnimation+OverWorldFaceUp){  \
ChangeAnimationSimplestArtificialIntelligence(CurrentStruct, RunningAnimation+OverWorldFaceUp); \
}  \
}  \
else if(CurrentStruct.Loadable->CurrentAnimation != IdleAnimation+OverWorldFaceUp){  \
ChangeAnimationSimplestArtificialIntelligence(CurrentStruct, IdleAnimation+OverWorldFaceUp); \
}  \
  \
}  \
else if(ArtificialIntelligenceMovementBitsY(CurrentStruct.Loadable->ArtificialIntelligenceBuffer) == ArtificialIntelligenceMovementDown){  \
  \
if(CheckForOverWorldBorderY(TileData, &CurrentStruct.Loadable->PositionX, &CurrentStruct.Loadable->PositionY, &CurrentStruct.Loadable->ScreenPositionZ, &CurrentStruct.Loadable->StagePositionZ, &CurrentStruct.Loadable->SizeX, &CurrentStruct.Loadable->SizeY, &CurrentStruct.Loadable->SpeedX, CurrentStruct.Loadable->SpeedZ*SpeedFactorZ,  TileMovementLogicData)){  \
if(CurrentStruct.Loadable->CurrentAnimation != RunningAnimation+OverWorldFaceDown){  \
ChangeAnimationSimplestArtificialIntelligence(CurrentStruct, RunningAnimation+OverWorldFaceDown); \
}  \
}  \
else if(CurrentStruct.Loadable->CurrentAnimation != IdleAnimation+OverWorldFaceDown){  \
ChangeAnimationSimplestArtificialIntelligence(CurrentStruct, IdleAnimation+OverWorldFaceDown); \
}  \
  \
} \
 \
 \
} 
 
//-------------------------------------------------------------------------------------------------------- 
 
#define ArtificialIntelligenceStandardMovementMacro(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, SpeedFactorX, SpeedFactorZ);   {    \
 \
srand(rtc_unix_secs());  \
RandomNumber = rand()%ArtificialIntelligenceMovementMaximumRandomValue;  \
  \
if(RandomNumber < ((ArtificialIntelligenceMovementMaximumRandomValue+1)/ArtificialIntelligenceNormalWalkingVariationAmount)*ArtificialIntelligenceNormalWalkLeft){  \
  \
RandomNumber = ArtificialIntelligenceMovementBitsX(CurrentStruct.Loadable->ArtificialIntelligenceBuffer);  \
if(RandomNumber > ArtificialIntelligenceMovementLeft) SetArtificialIntelligenceMovementBitsX(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, RandomNumber-1);  \
  \
}  \
else if(RandomNumber < ((ArtificialIntelligenceMovementMaximumRandomValue+1)/ArtificialIntelligenceNormalWalkingVariationAmount)*ArtificialIntelligenceNormalWalkRight){  \
  \
RandomNumber = ArtificialIntelligenceMovementBitsX(CurrentStruct.Loadable->ArtificialIntelligenceBuffer);  \
if(RandomNumber < ArtificialIntelligenceMovementRight) SetArtificialIntelligenceMovementBitsX(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, RandomNumber+1);  \
  \
}  \
else if(RandomNumber < ((ArtificialIntelligenceMovementMaximumRandomValue+1)/ArtificialIntelligenceNormalWalkingVariationAmount)*ArtificialIntelligenceNormalWalkUp){  \
  \
RandomNumber = ArtificialIntelligenceMovementBitsY(CurrentStruct.Loadable->ArtificialIntelligenceBuffer);  \
if(RandomNumber > ArtificialIntelligenceMovementUp) SetArtificialIntelligenceMovementBitsY(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, RandomNumber-1);  \
  \
}  \
else if(RandomNumber < ((ArtificialIntelligenceMovementMaximumRandomValue+1)/ArtificialIntelligenceNormalWalkingVariationAmount)*ArtificialIntelligenceNormalWalkDown){  \
  \
RandomNumber = ArtificialIntelligenceMovementBitsY(CurrentStruct.Loadable->ArtificialIntelligenceBuffer);  \
if(RandomNumber < ArtificialIntelligenceMovementDown) SetArtificialIntelligenceMovementBitsY(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, RandomNumber+1);  \
  \
}  \
  \
  \
ArtificialIntelligenceMovementItself(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, SpeedFactorX, SpeedFactorZ); \
 \
} 

//-------------------------------------------------------------------------------------------------------- 

#define ArtificialIntelligenceChaseStolarMacro(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, SpeedFactorX, SpeedFactorZ);   {    \
 \
if(TileData->LogicData.Stolar.PositionX < CurrentStruct.Loadable->PositionX-StolarChaseSpaceAmountX){  \
SetArtificialIntelligenceMovementBitsX(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, ArtificialIntelligenceMovementLeft);   \
} \
else if(TileData->LogicData.Stolar.PositionX > CurrentStruct.Loadable->PositionX+StolarChaseSpaceAmountX){  \
SetArtificialIntelligenceMovementBitsX(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, ArtificialIntelligenceMovementRight);   \
} \
 \
if(TileData->LogicData.Stolar.StagePositionZ < CurrentStruct.Loadable->StagePositionZ-StolarChaseSpaceAmountZ){  \
SetArtificialIntelligenceMovementBitsY(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, ArtificialIntelligenceMovementUp);   \
} \
else if(TileData->LogicData.Stolar.StagePositionZ > CurrentStruct.Loadable->StagePositionZ+StolarChaseSpaceAmountZ){  \
SetArtificialIntelligenceMovementBitsY(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, ArtificialIntelligenceMovementDown);   \
}  \
  \
ArtificialIntelligenceMovementItself(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, SpeedFactorX, SpeedFactorZ); \
 \
} 
 
//-------------------------------------------------------------------------------------------------------- 
 
#define ArtificialIntelligenceTowardsEventMacro(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, SpeedFactorX, SpeedFactorZ);   {    \
 \
RandomNumber = ArtificialIntelligenceFetchWhichEvent(CurrentStruct.Loadable->ArtificialIntelligenceBuffer); \
if(((TileData->EventData[RandomNumber].Loadable->PositionX[UpRightValue]+TileData->EventData[RandomNumber].Loadable->PositionX[DownRightValue])/2) < CurrentStruct.Loadable->PositionX+EventChaseSpaceAmountX){  \
SetArtificialIntelligenceMovementBitsX(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, ArtificialIntelligenceMovementLeft);   \
} \
else if(((TileData->EventData[RandomNumber].Loadable->PositionX[UpLeftValue]+TileData->EventData[RandomNumber].Loadable->PositionX[DownLeftValue])/2) < CurrentStruct.Loadable->PositionX-EventChaseSpaceAmountX){  \
SetArtificialIntelligenceMovementBitsX(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, ArtificialIntelligenceMovementRight);   \
} \
 \
if(((TileData->EventData[RandomNumber].Loadable->StagePositionZ[UpRightValue]+TileData->EventData[RandomNumber].Loadable->StagePositionZ[UpLeftValue])/2) < CurrentStruct.Loadable->StagePositionZ+EventChaseSpaceAmountZ){  \
SetArtificialIntelligenceMovementBitsY(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, ArtificialIntelligenceMovementUp);   \
} \
else if(((TileData->EventData[RandomNumber].Loadable->StagePositionZ[DownRightValue]+TileData->EventData[RandomNumber].Loadable->StagePositionZ[DownLeftValue])/2) < CurrentStruct.Loadable->StagePositionZ+EventChaseSpaceAmountZ){  \
SetArtificialIntelligenceMovementBitsY(CurrentStruct.Loadable->ArtificialIntelligenceBuffer, ArtificialIntelligenceMovementDown);   \
}  \
  \
ArtificialIntelligenceMovementItself(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, SpeedFactorX, SpeedFactorZ); \
 \
} 
 
//-------------------------------------------------------------------------------------------------------- 
 
#define CheckArtificialIntelligenceMacro(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation);	{ \
 \
if(CurrentStruct.LogicData.Active && CurrentStruct.LogicData.ArtificialIntelligenceEnabled){ \
if(CurrentStruct.Loadable->ArtificialIntelligence == ArtificialIntelligenceWalkAround){ \
ArtificialIntelligenceStandardMovementMacro(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, ArtificialIntelligenceWalkingSpeedFactor, ArtificialIntelligenceWalkingSpeedFactor); \
} \
else if(CurrentStruct.Loadable->ArtificialIntelligence == ArtificialIntelligenceRunAround){ \
ArtificialIntelligenceStandardMovementMacro(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, ArtificialIntelligenceRunningSpeedFactor, ArtificialIntelligenceRunningSpeedFactor); \
} \
else if(CurrentStruct.Loadable->ArtificialIntelligence == ArtificialIntelligenceLookAround){ \
ArtificialIntelligenceStandardMovementMacro(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, ArtificialIntelligenceNoWalkingSpeedFactor, ArtificialIntelligenceNoWalkingSpeedFactor); \
} \
else if(CurrentStruct.Loadable->ArtificialIntelligence == ArtificialIntelligenceChaseStolar){ \
ArtificialIntelligenceChaseStolarMacro(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, ArtificialIntelligenceWalkingSpeedFactor, ArtificialIntelligenceWalkingSpeedFactor); \
} \
else if(CurrentStruct.Loadable->ArtificialIntelligence == ArtificialIntelligenceTowardsEvent){ \
ArtificialIntelligenceTowardsEventMacro(CurrentStruct, TileMovementLogicData, IdleAnimation, RunningAnimation, ArtificialIntelligenceWalkingSpeedFactor, ArtificialIntelligenceWalkingSpeedFactor); \
} \
} \
 \
}
