void FightObjectsSingleObjectSingleInstanceIntelligenceForcesToAccelerationSingle(float* Force, float* Acceleration, float Inertia){

sint8 Factor;

Factor = SignFloat((*Force));
if((Factor*(*Force)) > Inertia){
(*Acceleration) = (*Force)-(Factor*Inertia);
}

(*Force) = PhysicsForceNot;
}

void FightObjectsSingleObjectSingleInstanceIntelligenceForcesToAcceleration(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, uint8 WhichIntelligence){

FightObjectsSingleObjectSingleInstanceIntelligenceForcesToAccelerationSingle(&FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ForceX, &FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationX, FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->Physics.InertiaX);
FightObjectsSingleObjectSingleInstanceIntelligenceForcesToAccelerationSingle(&FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ForceY, &FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationY, FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->Physics.InertiaY);
FightObjectsSingleObjectSingleInstanceIntelligenceForcesToAccelerationSingle(&FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.ForceZ, &FightData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.AccelerationZ, FightData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->Physics.InertiaZ);

}