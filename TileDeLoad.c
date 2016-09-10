#define TileDeLoadSingleEventDeLoad(EventData)		{ \
if(EventData.LogicData.Load){ \
free(EventData.EventBuffer); \
} \
TileDeLoadFlags(EventData.FlagData.Load); \
TileDeLoadFlags(EventData.FlagData.Active); \
}

void TileDeLoad(TileStruct* TileData, OverWorldStruct* OverWorldData){

TileObjectClassStruct* CurrentClass;
uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse, WhichEvent;

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->MusicAmount; DirtyDeedsDoneDirtCheap++){
TileDeLoadFlags(TileData->MusicData[DirtyDeedsDoneDirtCheap].FlagData.Active);
}
if(TileData->TileHeaderData->MusicAmount > 0) free(TileData->MusicData);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->SpriteAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->Sprites[DirtyDeedsDoneDirtCheap].LogicData.Load){
FreeTexture(TileData->Sprites[DirtyDeedsDoneDirtCheap].Texture);
free(TileData->Sprites[DirtyDeedsDoneDirtCheap].AnimationData);
}
TileDeLoadFlags(TileData->Sprites[DirtyDeedsDoneDirtCheap].FlagData.Load);
}
if(TileData->TileHeaderData->SpriteAmount > 0) free(TileData->Sprites);

if(TileData->LogicData.General.ObjectAmount > 0) CurrentClass = TileData->ObjectData[TileObjectFirst].ClassData;
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->LogicData.General.ObjectAmount; DirtyDeedsDoneDirtCheap++){

if(TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData != CurrentClass){
free(CurrentClass);
CurrentClass = TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData;
}

if(TileData->ObjectData[DirtyDeedsDoneDirtCheap].LogicData.Load){
for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->TextureAmount; BurningDownTheHouse++){
FreeTexture(TileData->ObjectData[DirtyDeedsDoneDirtCheap].Texture[BurningDownTheHouse]);
}
free(TileData->ObjectData[DirtyDeedsDoneDirtCheap].Texture);
free(TileData->ObjectData[DirtyDeedsDoneDirtCheap].AnimationData);
}
TileDeLoadFlags(TileData->ObjectData[DirtyDeedsDoneDirtCheap].FlagData.Load);
for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->InstanceAmount; BurningDownTheHouse++){
TileDeLoadFlags(TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].FlagData.Active);

for(WhichEvent=0; WhichEvent<TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->EventAmount; WhichEvent++){
TileDeLoadSingleEventDeLoad(TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].EventData[WhichEvent]);
}
if(TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->EventAmount > 0) free(TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].EventData);


}
if(TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->InstanceAmount > 0) free(TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance);
}
if(TileData->LogicData.General.ObjectAmount > 0){
free(CurrentClass);
free(TileData->ObjectData);
}


for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->AnimationAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].LogicData.Load){
for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->FrameAmount; BurningDownTheHouse++){
FreeTexture(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Texture[BurningDownTheHouse]);
}
free(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Texture);
}
TileDeLoadFlags(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].FlagData.Load);
for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->InstanceAmount; BurningDownTheHouse++){
TileDeLoadFlags(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].FlagData.Active);
}
if(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->InstanceAmount > 0) free(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Instance);
}
if(TileData->TileHeaderData->AnimationAmount > 0) free(TileData->BackGroundHeaderData);


for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < OverWorldData->LogicData.General.PlayerAmount; DirtyDeedsDoneDirtCheap++){
for(WhichEvent = 0; WhichEvent < TileData->TileHeaderData->EventPlayerAmount; WhichEvent++){
TileDeLoadSingleEventDeLoad(TileData->PlayerData[DirtyDeedsDoneDirtCheap].EventSelfData[WhichEvent].EventData);	
}
free(TileData->PlayerData[DirtyDeedsDoneDirtCheap].EventSelfData);

}
free(TileData->PlayerData);


free(TileData->ActiveEventData);
free(TileData->LayOutBuffer);
free(TileData->TileHeaderData);

}