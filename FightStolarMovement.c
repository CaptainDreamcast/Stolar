#define FightStolarMovementCheckX(ButtonPressed, SpeedX, FaceDirection)		{ \
if(ButtonPressed){ \
if(FightMovementX(FightData, &FightData->LogicData.Stolar.PositionX, SpeedX)){ \
if(FightData->LogicData.Stolar.CurrentAnimation != StolarRunningAnimation+FaceDirection){ \
StolarChangeFightAnimationSimplest(StolarRunningAnimation+FaceDirection); \
} \
} \
else if(FightData->LogicData.Stolar.CurrentAnimation != StolarIdleAnimation+FaceDirection){ \
StolarChangeFightAnimationSimplest(StolarIdleAnimation+FaceDirection); \
} \
} \
}

#define FightStolarMovementCheckZ(ButtonPressed, SpeedZ)		{ \
if(ButtonPressed){ \
if(FightMovementZ(FightData, &FightData->LogicData.Stolar.StagePositionZ, &FightData->LogicData.Stolar.ScreenPositionZ, &FightData->LogicData.Stolar.PositionY, SpeedZ)){ \
if(FightData->LogicData.Stolar.CurrentAnimation != StolarRunningAnimation+FightData->LogicData.Stolar.FaceDirection){ \
StolarChangeFightAnimationSimplest(StolarRunningAnimation+FightData->LogicData.Stolar.FaceDirection); \
} \
} \
else if(FightData->LogicData.Stolar.CurrentAnimation != StolarIdleAnimation+FightData->LogicData.Stolar.FaceDirection){ \
StolarChangeFightAnimationSimplest(StolarIdleAnimation+FightData->LogicData.Stolar.FaceDirection); \
} \
} \
}

void FightStolarMovement(FightStruct* FightData, OverWorldStruct* OverWorldData){

if(FightData->LogicData.General.EnableFlags & FightEnableFlagStolarMovement){

FightStolarMovementCheckX(ButtonPressedLeft(OverWorldData->LogicData.Input.st), (-FightData->Loadable.Stage->General.SpeedX), FightFaceLeft);
FightStolarMovementCheckX(ButtonPressedRight(OverWorldData->LogicData.Input.st), FightData->Loadable.Stage->General.SpeedX, FightFaceRight);

FightStolarMovementCheckZ(ButtonPressedUp(OverWorldData->LogicData.Input.st), (-FightData->Loadable.Stage->General.SpeedZ));
FightStolarMovementCheckZ(ButtonPressedDown(OverWorldData->LogicData.Input.st), FightData->Loadable.Stage->General.SpeedZ);

}

}