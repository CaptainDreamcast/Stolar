#define FightStolarPhysicsWeightFactorComparedToStolarX	1.0f
#define FightStolarPhysicsWeightFactorComparedToStolarY	1.0f

void FightStolarPhysics(FightStruct* FightData, OverWorldStruct* OverWorldData){

if(FightData->LogicData.Stolar.Hit){
FightData->LogicData.Stolar.Hit = FightCollisionResultStolar(FightData, OverWorldData);
}

if(FightData->LogicData.Stolar.VelocityActiveY){
if(FightVelocityNoLongerInMotionY(FightData->LogicData.Stolar.PositionY, FightData->LogicData.Stolar.VelocityY, FightData->LogicData.Stolar.StagePositionZ)){
FightVelocityLogicDeActivateY(FightData->LogicData.Stolar.VelocityActiveY, FightData->LogicData.Stolar.VelocityY);
}
else{
FightVelocityPhysicsLogicStandardY(FightData->LogicData.Stolar.PositionY, FightData->LogicData.Stolar.VelocityY, FightStolarPhysicsWeightFactorComparedToStolarY);
FightVelocityHitLogicStandardY(FightData->LogicData.Stolar.Hit, FightData->LogicData.Stolar, OverWorldData->FluxData.Stolar.AnimationData, OverWorldData->Loadable->Stolar.AnimationHitAir, FightStolarAnimationIsIdle(FightData));
}
}


if(FightData->LogicData.Stolar.VelocityActiveX){
if(FightVelocityNoLongerInMotionX(FightData->LogicData.Stolar.VelocityX, FightStolarPhysicsWeightFactorComparedToStolarX)){
FightVelocityLogicDeActivateX(FightData->LogicData.Stolar.VelocityActiveX, FightData->LogicData.Stolar.VelocityX);
}
else{
FightVelocityPhysicsLogicStandardX(FightData->LogicData.Stolar.VelocityActiveY, FightData->LogicData.Stolar.PositionX, FightData->LogicData.Stolar.VelocityX, FightStolarPhysicsWeightFactorComparedToStolarX);
FightVelocityHitLogicStandardX(FightData->LogicData.Stolar.Hit, FightData->LogicData.Stolar, OverWorldData->FluxData.Stolar.AnimationData, OverWorldData->Loadable->Stolar.AnimationHitGround, FightStolarAnimationIsIdle(FightData));
}
}

}