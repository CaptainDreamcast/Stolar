uint8 FightCollisionResultStolar(FightStruct* FightData, OverWorldStruct* OverWorldData){

uint16 FinalDamage;
uint8 Hit;

FinalDamage = FightCollisionResultDecreaseLife(FightData->FluxData.Stolar.FightAttackedData, &OverWorldData->Loadable->Stolar.FightDefenseData, &FightData->LogicData.Stolar.HealthNow);

ListAdd(&FightData->FloatingValueData, FightFloatingValueNew(FightData, OverWorldData, FinalDamage, FightStolarFetchCenterPositionX(FightData), FightStolarFetchTopPositionY(FightData), FightData->LogicData.Stolar.ScreenPositionZ));
Hit = FightCollisionResultMoved(FightData->FluxData.Stolar.FightAttackedData, &OverWorldData->Loadable->Stolar.FightDefenseData, FinalDamage, &FightData->LogicData.Stolar.VelocityX, &FightData->LogicData.Stolar.VelocityY);

return(Hit);
}