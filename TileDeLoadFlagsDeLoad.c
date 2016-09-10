void TileDeLoadFlagsDeLoad(TileFlagParseStruct** FlagData){

TileFlagCombinationStruct* Combination;
uint8 DirtyDeedsDoneDirtCheap;

if((*FlagData)->Loadable->Type != TileFlagParseTypeSingleFlag){
Combination = (TileFlagCombinationStruct*)(*FlagData);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < Combination->Loadable->Specific.Amount; DirtyDeedsDoneDirtCheap++){
TileDeLoadFlags(Combination->FlagData[DirtyDeedsDoneDirtCheap]);
free(Combination->FlagData);
}
}

free((*FlagData));
}