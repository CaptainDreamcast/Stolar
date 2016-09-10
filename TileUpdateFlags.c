#define TileUpdateFlagsCheckType(FlagType, Amount, FlagData)	{ \
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<Amount; DirtyDeedsDoneDirtCheap++){ \
FlagType = TileUpdateFlagsCheckSingle(FlagData); \
} \
}

#define TileUpdateFlagsCheckTypeAction(Amount, FlagData, Action)	{ \
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<Amount; DirtyDeedsDoneDirtCheap++){ \
if(TileUpdateFlagsCheckSingle(FlagData)){ \
Action; \
} \
} \
}


void TileUpdateFlagsLoad(TileStruct* TileData, OverWorldStruct* OverWorldData){

uint8 DirtyDeedsDoneDirtCheap, WhichObject, WhichInstance;

for(WhichObject=0; WhichObject < OverWorldData->LogicData.General.PlayerAmount; WhichObject++){
TileUpdateFlagsCheckType(TileData->PlayerData[WhichObject].EventSelfData[DirtyDeedsDoneDirtCheap].EventData.LogicData.Load, 
TileData->TileHeaderData->EventPlayerAmount, 
TileData->PlayerData[WhichObject].EventSelfData[DirtyDeedsDoneDirtCheap].EventData.FlagData.Load);
}

TileUpdateFlagsCheckType(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].LogicData.Load, TileData->TileHeaderData->AnimationAmount, 
TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].FlagData.Load);

TileUpdateFlagsCheckType(TileData->ObjectData[DirtyDeedsDoneDirtCheap].LogicData.Load, TileData->LogicData.General.ObjectAmount, 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].FlagData.Load);
for(WhichObject = 0; WhichObject < TileData->LogicData.General.ObjectAmount; WhichObject++){
for(WhichInstance = 0; WhichInstance < TileData->ObjectData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
TileUpdateFlagsCheckType(TileData->ObjectData[WhichObject].Instance[WhichInstance].EventData[DirtyDeedsDoneDirtCheap].LogicData.Load, 
TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->EventAmount, 
TileData->ObjectData[WhichObject].Instance[WhichInstance].EventData[DirtyDeedsDoneDirtCheap].FlagData.Load);
}
}



TileUpdateFlagsCheckType(TileData->Sprites[DirtyDeedsDoneDirtCheap].LogicData.Load, TileData->TileHeaderData->SpriteAmount, 
TileData->Sprites[DirtyDeedsDoneDirtCheap].FlagData.Load);


}

void TileUpdateFlagsActive(TileStruct* TileData, OverWorldStruct* OverWorldData){

uint8 DirtyDeedsDoneDirtCheap, WhichObject, WhichInstance;

for(WhichObject=0; WhichObject < OverWorldData->LogicData.General.PlayerAmount; WhichObject++){
TileUpdateFlagsCheckType(TileData->PlayerData[WhichObject].EventSelfData[DirtyDeedsDoneDirtCheap].EventData.LogicData.Active, 
TileData->TileHeaderData->EventPlayerAmount, 
TileData->PlayerData[WhichObject].EventSelfData[DirtyDeedsDoneDirtCheap].EventData.FlagData.Active);
}

for(WhichObject = 0; WhichObject < TileData->TileHeaderData->AnimationAmount; WhichObject++){
TileUpdateFlagsCheckType(TileData->BackGroundHeaderData[WhichObject].Instance[DirtyDeedsDoneDirtCheap].LogicData.Active, TileData->BackGroundHeaderData[WhichObject].Loadable->InstanceAmount, 
TileData->BackGroundHeaderData[WhichObject].Instance[DirtyDeedsDoneDirtCheap].FlagData.Active);
}

for(WhichObject = 0; WhichObject < TileData->LogicData.General.ObjectAmount; WhichObject++){
TileUpdateFlagsCheckType(TileData->ObjectData[WhichObject].Instance[DirtyDeedsDoneDirtCheap].LogicData.Active, TileData->ObjectData[WhichObject].Loadable->InstanceAmount, 
TileData->ObjectData[WhichObject].Instance[DirtyDeedsDoneDirtCheap].FlagData.Active);
for(WhichInstance = 0; WhichInstance < TileData->ObjectData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
TileUpdateFlagsCheckType(TileData->ObjectData[WhichObject].Instance[WhichInstance].EventData[DirtyDeedsDoneDirtCheap].LogicData.Active, 
TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->EventAmount, 
TileData->ObjectData[WhichObject].Instance[WhichInstance].EventData[DirtyDeedsDoneDirtCheap].FlagData.Active);
}
}


TileUpdateFlagsCheckTypeAction(TileData->TileHeaderData->MusicAmount, 
TileData->MusicData[DirtyDeedsDoneDirtCheap].FlagData.Active, 
{
if(OverWorldData->LogicData.Music.CurrentTrack != TileData->MusicData[DirtyDeedsDoneDirtCheap].Loadable->TrackIdentifier){
TileMusicPlay(OverWorldData, TileData->MusicData[DirtyDeedsDoneDirtCheap].Loadable->TrackIdentifier);
}
}
);


}
