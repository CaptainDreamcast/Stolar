

#define FightLogicAbilitiesSpecificDeLoad()		{  \
(*AbilityDeLoadFunction[OverWorldData->FluxData.Abilities[DirtyDeedsDoneDirtCheap].AbilityData->FunctionIndex])(FightData, OverWorldData, DirtyDeedsDoneDirtCheap); \
}

#define FightLogicAbilitiesDeLoad()	 { \
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < AbilityAmount; DirtyDeedsDoneDirtCheap++){ \
FightLogicAbilitiesSpecificDeLoad(); \
} \
}


#define FightLogicDeLoad()	{ \
FightLogicAbilitiesDeLoad(); \
}



void FightDeLoad(FightStruct* FightData, OverWorldStruct* OverWorldData){

uint8 DirtyDeedsDoneDirtCheap;


ListDestroyAndDeLoad(&FightData->FloatingValueData);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<FightData->Loadable.Enemies->General.EnemyAmount; DirtyDeedsDoneDirtCheap++){
free(FightData->EnemyData[DirtyDeedsDoneDirtCheap].Loadable);
}

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < FightData->Loadable.Stage->General.BackGroundAmount; DirtyDeedsDoneDirtCheap++){
free(FightData->BackGroundData[DirtyDeedsDoneDirtCheap].Texture);
}

free(FightData->BackGroundData);
FightLogicDeLoad();
free(FightData->Loadable.Stage);

free(FightData->EnemyData);

//?
free(OverWorldData->LogicData.Passable); 
//?

}
