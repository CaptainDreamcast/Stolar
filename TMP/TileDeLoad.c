void TileDeLoad(TileStruct* TileData){

uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->MusicAmount; DirtyDeedsDoneDirtCheap++){
TileDeLoadFlags(TileData->MusicData[DirtyDeedsDoneDirtCheap].FlagData.Active);
}
if(TileData->TileHeaderData->MusicAmount > 0) free(TileData->MusicData);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->EventAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->EventData[DirtyDeedsDoneDirtCheap].LogicData.Load){
free(TileData->EventData[DirtyDeedsDoneDirtCheap].EventBuffer);
TileDeLoadFlags(TileData->EventData[DirtyDeedsDoneDirtCheap].FlagData.Load);
TileDeLoadFlags(TileData->EventData[DirtyDeedsDoneDirtCheap].FlagData.Active);
}
}
if(TileData->TileHeaderData->EventAmount > 0) free(TileData->EventData);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->SpriteAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->Sprites[DirtyDeedsDoneDirtCheap].LogicData.Load){
FreeTexture(TileData->Sprites[DirtyDeedsDoneDirtCheap].Texture);
free(TileData->Sprites[DirtyDeedsDoneDirtCheap].AnimationData);
TileDeLoadFlags(TileData->Sprites[DirtyDeedsDoneDirtCheap].FlagData.Load);
}
}
if(TileData->TileHeaderData->SpriteAmount > 0) free(TileData->Sprites);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->SpecialEnemyAmount; DirtyDeedsDoneDirtCheap++){
TileDeLoadFlags(TileData->SpecialEnemyData[DirtyDeedsDoneDirtCheap].FlagData.Active);
}
if(TileData->TileHeaderData->SpecialEnemyAmount > 0) free(TileData->SpecialEnemyData);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->NormalEnemyAmount; DirtyDeedsDoneDirtCheap++){
TileDeLoadFlags(TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].FlagData.Active);
}
if(TileData->TileHeaderData->NormalEnemyAmount > 0) free(TileData->NormalEnemyData);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->PersonAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Load){
FreeTexture(TileData->PersonData[DirtyDeedsDoneDirtCheap].Texture);
free(TileData->PersonData[DirtyDeedsDoneDirtCheap].AnimationData);
TileDeLoadFlags(TileData->PersonData[DirtyDeedsDoneDirtCheap].FlagData.Load);
TileDeLoadFlags(TileData->PersonData[DirtyDeedsDoneDirtCheap].FlagData.Active);
}
}
if(TileData->TileHeaderData->PersonAmount > 0) free(TileData->PersonData);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->AnimationAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].LogicData.Load){
for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Loadable->FrameAmount; BurningDownTheHouse++){
FreeTexture(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Texture[BurningDownTheHouse]);
TileDeLoadFlags(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].FlagData.Load);
TileDeLoadFlags(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].FlagData.Active);
}
free(TileData->BackGroundHeaderData[DirtyDeedsDoneDirtCheap].Texture);
}
}
if(TileData->TileHeaderData->AnimationAmount > 0) free(TileData->BackGroundHeaderData);

free(TileData->ActiveEventData);
free(TileData->LayOutBuffer);
free(TileData->TileHeaderData);

}