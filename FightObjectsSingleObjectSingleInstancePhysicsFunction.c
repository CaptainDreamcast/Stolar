void FightObjectsSingleObjectSingleInstancePhysicsSubX(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

sint8 Factor;

FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX += FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationX;
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationX = PhysicsAccelerationNot;

if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->OnGround){
if(FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX < PhysicsVelocityNot) Factor = FactorNegative;
else Factor = FactorPositive;
if(Factor*FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX <= FightData->Loadable.Stage->Physics.ResistanceGround){
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX = PhysicsVelocityNot;
}
else FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX -= Factor*FightData->Loadable.Stage->Physics.ResistanceGround;
}

FightMovementX(FightData, WhichObject, WhichInstance, FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityX);

}



void FightObjectsSingleObjectSingleInstancePhysicsSubY(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityY += FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationY;
if(
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->OnGround && 
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityY < PhysicsVelocityNot
){
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->OnGround = LogicActiveNot;
}
if(
!FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->OnGround && 
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationY < FightData->Loadable.Stage->Physics.GravityConstant
){
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationY = FightData->Loadable.Stage->Physics.GravityConstant;
}

FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionY+= FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityY;
if(
!FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->OnGround && 
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->PositionY >= FightFromStagePositionReturnPositionY(FightData, FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->StagePositionZ)
){
FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->OnGround = LogicActive;
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityY = PhysicsVelocityNot;
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationY = PhysicsAccelerationNot;
}

}


void FightObjectsSingleObjectSingleInstancePhysicsSubZ(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

sint8 Factor;

FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ += FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationZ;
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationZ = PhysicsAccelerationNot;

if(FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->OnGround){
if(FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ < PhysicsVelocityNot) Factor = FactorNegative;
else Factor = FactorPositive;
if(Factor*FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ <= FightData->Loadable.Stage->Physics.ResistanceGround){
FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ = PhysicsVelocityNot;
}
else FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ -= Factor*FightData->Loadable.Stage->Physics.ResistanceGround;
}

FightMovementZ(FightData, WhichObject, WhichInstance, FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.VelocityZ);

}


void FightObjectsSingleObjectSingleInstancePhysicsNormal(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance){

FightObjectsSingleObjectSingleInstancePhysicsSubX(FightData, WhichObject, WhichInstance);
FightObjectsSingleObjectSingleInstancePhysicsSubY(FightData, WhichObject, WhichInstance);
FightObjectsSingleObjectSingleInstancePhysicsSubZ(FightData, WhichObject, WhichInstance);

}


void (*FightObjectsSingleObjectSingleInstancePhysicsFunction[FightObjectsSingleObjectSingleInstancePhysicsFunctionAmount])(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance) = {
FightObjectsSingleObjectSingleInstancePhysicsNormal
};