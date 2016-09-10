#define AbilityDeLoadFunctionArguments		FightStruct* FightData, OverWorldStruct* OverWorldData, uint8 WhichAbility

void VulgarDisplayOfPowerDeLoad(AbilityDeLoadFunctionArguments){
free(FightData->LogicData.Abilities.Specific[WhichAbility].Buffer);
}

void (*AbilityDeLoadFunction[AbilityFunctionAmount])(AbilityDeLoadFunctionArguments) = 
{
VulgarDisplayOfPowerDeLoad
};
