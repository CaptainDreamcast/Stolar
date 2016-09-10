
void TileArtificialIntelligence(TileStruct* TileData, OverWorldStruct* OverWorldData){

uint8 DirtyDeedsDoneDirtCheap;
uint32 RandomNumber;

if(TileData->LogicData.General.EnableFlags & TileEnableFlagArtificialIntelligence){
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->PersonAmount; DirtyDeedsDoneDirtCheap++){
CheckArtificialIntelligenceMacro(TileData->PersonData[DirtyDeedsDoneDirtCheap], (&TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Movement), PersonIdleAnimation, PersonRunningAnimation);
}

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->NormalEnemyAmount; DirtyDeedsDoneDirtCheap++){
CheckArtificialIntelligenceMacro(TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap], (&TileData->LogicData.NormalEnemies.Movement), NormalEnemyIdleAnimation, NormalEnemyRunningAnimation);
}

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->SpecialEnemyAmount; DirtyDeedsDoneDirtCheap++){
CheckArtificialIntelligenceMacro(TileData->SpecialEnemyData[DirtyDeedsDoneDirtCheap], (&TileData->LogicData.SpecialEnemies.Movement), SpecialEnemyIdleAnimation, SpecialEnemyRunningAnimation);
}
}

}