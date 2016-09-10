uint32 TileLoadFlagsLoad(uint32 CurrentPointerPosition, TileFlagParseStruct** FlagData){

TileFlagSingleFlagStruct* SingleFlag;
TileFlagCombinationStruct* Combination;
TileFlagParseLoadableStruct* TemporaryLoadable;
uint8 DirtyDeedsDoneDirtCheap;

TemporaryLoadable = (TileFlagParseLoadableStruct*)CurrentPointerPosition;
if(TemporaryLoadable->Type == TileFlagParseTypeSingleFlag){
(*FlagData) = (TileFlagParseStruct*)malloc(sizeof(TileFlagSingleFlagStruct));
SingleFlag = (TileFlagSingleFlagStruct*)(*FlagData);
LoadSetThisToThatPointer(TileFlagSingleFlagLoadableStruct*, SingleFlag->Loadable, sizeof(TileFlagSingleFlagLoadableStruct));
}
else{
(*FlagData) = (TileFlagParseStruct*)malloc(sizeof(TileFlagCombinationStruct));
Combination = (TileFlagCombinationStruct*)(*FlagData);
LoadSetThisToThatPointer(TileFlagCombinationLoadableStruct*, Combination->Loadable, sizeof(TileFlagCombinationLoadableStruct));
Combination->FlagData = (TileFlagParseStruct**)malloc(sizeof(TileFlagParseStruct*)*Combination->Loadable->Specific.Amount);
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < Combination->Loadable->Specific.Amount; DirtyDeedsDoneDirtCheap++){
TileLoadFlagsNoLegalStart(Combination->FlagData[DirtyDeedsDoneDirtCheap]);
}
}

return(CurrentPointerPosition);
}


uint32 TileLoadFlagsLoadDummyGeneral(uint32 CurrentPointerPosition, TileFlagParseStruct** FlagData, uint8 Type){

TileFlagCombinationStruct* Combination;

(*FlagData) = (TileFlagParseStruct*)malloc(sizeof(TileFlagCombinationStruct));
Combination = (TileFlagCombinationStruct*)(*FlagData);
Combination->Loadable = (TileFlagCombinationLoadableStruct*)malloc(sizeof(TileFlagCombinationLoadableStruct));

Combination->Loadable->General.Type = Type;
Combination->Loadable->General.Not = LogicActiveNot;
Combination->Loadable->Specific.Amount = 0;
Combination->FlagData = NULL;

return(CurrentPointerPosition);
}

uint32 TileLoadFlagsLoadDummyTrue(uint32 CurrentPointerPosition, TileFlagParseStruct** FlagData){
return(TileLoadFlagsLoadDummyGeneral(CurrentPointerPosition, FlagData, TileFlagParseTypeCombinationAnd));
}

uint32 TileLoadFlagsLoadDummyFalse(uint32 CurrentPointerPosition, TileFlagParseStruct** FlagData){
return(TileLoadFlagsLoadDummyGeneral(CurrentPointerPosition, FlagData, TileFlagParseTypeCombinationOr));
}


