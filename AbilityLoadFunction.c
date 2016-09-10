#define FightAbilityHittable	1

void* VulgarDisplayOfPowerInitiate(AbilityLoadFunctionArguments){
VulgarDisplayOfPowerStruct* VulgarDisplayOfPowerData;

VulgarDisplayOfPowerData = (VulgarDisplayOfPowerStruct*)malloc(sizeof(VulgarDisplayOfPowerStruct));

VulgarDisplayOfPowerData->Loadable = (VulgarDisplayOfPowerLoadableStruct*)OverWorldCrewFluxAbilityData->Loadable;
VulgarDisplayOfPowerData->FluxData.OffsetData = (FightCollisionDetectRectangleStruct2D*)(OverWorldCrewFluxAbilityData->Loadable+sizeof(VulgarDisplayOfPowerLoadableStruct));

VulgarDisplayOfPowerData->LogicData.Active = FightLogicSingleActiveNot;
VulgarDisplayOfPowerData->LogicData.EnemiesHitAlready = ListCreate();

return(VulgarDisplayOfPowerData);
}

void* (*AbilityLoadFunction[AbilityFunctionAmount])(AbilityLoadFunctionArguments) = 
{
VulgarDisplayOfPowerInitiate, ComeOutSwingingInitiate
};
