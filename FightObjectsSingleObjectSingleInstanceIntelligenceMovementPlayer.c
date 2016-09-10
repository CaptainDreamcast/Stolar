#define FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayerCheckX(ButtonPressed, SpeedX, FaceDirectionNew)		{ \
if(ButtonPressed){ \
if(FightMovementX(FightData, WhichObject, WhichInstance, SpeedX)){ \
MovementActive = LogicActive; \
} \
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->FaceDirection = FaceDirectionNew; \
} \
}

#define FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayerCheckZ(ButtonPressed, SpeedZ)		{ \
if(ButtonPressed){ \
if( \
FightMovementZ(FightData, WhichObject, WhichInstance, SpeedZ) \
){ \
MovementActive = LogicActive; \
} \
} \
}



void FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayerCheckRunningStopped(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichPlayer, uint8* MovementActive){

if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation == PlayerRunningAnimation){
if(
!ButtonPressedUp(FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st) && 
!ButtonPressedDown(FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st) &&
!ButtonPressedLeft(FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st) &&
!ButtonPressedRight(FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st)
){
(*MovementActive) = LogicActiveNot;
}
}

}

void FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayerChooseAnimation(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichPlayer, uint8 MovementActive){


if(MovementActive){
if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation != PlayerRunningAnimation){
FightPlayerChangeAnimationSimplest(WhichPlayer, PlayerRunningAnimation); 
} 
}
else if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->CurrentAnimation == PlayerRunningAnimation){
FightPlayerChangeAnimationSimplest(WhichPlayer, PlayerIdleAnimation);
}

}


void FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayer(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichIntelligence){

uint8 WhichPlayer, MovementActive;

WhichPlayer = FightPlayerGetWhichPlayerFromObjectAndInstance(FightData, WhichObject, WhichInstance);

MovementActive = LogicActiveNot;
FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayerCheckX(ButtonPressedLeft(FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st), (-FightData->Loadable.Stage->General.SpeedX), FightFaceLeft);
FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayerCheckX(ButtonPressedRight(FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st), FightData->Loadable.Stage->General.SpeedX, FightFaceRight);

FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayerCheckZ(ButtonPressedUp(FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st), (-FightData->Loadable.Stage->General.SpeedZ));
FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayerCheckZ(ButtonPressedDown(FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st), FightData->Loadable.Stage->General.SpeedZ);

FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayerCheckRunningStopped(FightData, WhichObject, WhichInstance, WhichPlayer, &MovementActive);

FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayerChooseAnimation(FightData, WhichObject, WhichInstance, WhichPlayer, MovementActive);


}