void FightArtificialIntelligence(FightStruct* FightData, OverWorldStruct* OverWorldData){

uint8 DirtyDeedsDoneDirtCheap;

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<FightData->Loadable.Enemies->General.EnemyAmount; DirtyDeedsDoneDirtCheap++){
if(FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.ArtificialIntelligenceActive){
(*FightArtificialIntelligenceFunction[FightData->EnemyData[DirtyDeedsDoneDirtCheap].LogicData.ArtificialIntelligenceFunction])(FightData, OverWorldData, DirtyDeedsDoneDirtCheap);
}
}

}