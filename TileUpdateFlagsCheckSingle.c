uint8 TileUpdateFlagsCheckSingleFlag(TileFlagSingleFlagStruct* FlagSingleFlagData);
uint8 TileUpdateFlagsCheckCombination(TileFlagCombinationStruct* FlagCombinationData);

uint8 TileUpdateFlagsCheckSingle(TileFlagParseStruct* FlagData){
uint8 ReturnValue;

if(FlagData->Loadable->Type == TileFlagParseTypeSingleFlag){
ReturnValue = TileUpdateFlagsCheckSingleFlag((TileFlagSingleFlagStruct*)FlagData);
}
else{
ReturnValue = TileUpdateFlagsCheckCombination((TileFlagCombinationStruct*)FlagData);
}


if(FlagData->Loadable->Not) ReturnValue = LogicInvertSimple(ReturnValue);

return(ReturnValue);
}

uint8 TileUpdateFlagsCheckSingleFlag(TileFlagSingleFlagStruct* FlagSingleFlagData){
return(CheckFlagStory(FlagSingleFlagData->Loadable->Specific.WhichFlag));
}

uint8 TileUpdateFlagsCheckCombination(TileFlagCombinationStruct* FlagCombinationData){
uint8 ReturnValue;
uint8 DirtyDeedsDoneDirtCheap;


if(FlagCombinationData->Loadable->General.Type == TileFlagParseTypeCombinationOr){
ReturnValue = 0;
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < FlagCombinationData->Loadable->Specific.Amount; DirtyDeedsDoneDirtCheap++){
if(TileUpdateFlagsCheckSingle(FlagCombinationData->FlagData[DirtyDeedsDoneDirtCheap])){
ReturnValue = 1;
DirtyDeedsDoneDirtCheap = FlagCombinationData->Loadable->Specific.Amount;
}
}
}
else{
ReturnValue = 1;
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < FlagCombinationData->Loadable->Specific.Amount; DirtyDeedsDoneDirtCheap++){
if(!TileUpdateFlagsCheckSingle(FlagCombinationData->FlagData[DirtyDeedsDoneDirtCheap])){
ReturnValue = 0;
DirtyDeedsDoneDirtCheap = FlagCombinationData->Loadable->Specific.Amount;
}
}
}

return(ReturnValue);
}