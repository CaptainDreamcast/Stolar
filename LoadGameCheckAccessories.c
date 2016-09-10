void LoadGameCheckAccessories(LoadScreenControllerStruct* LoadScreenControllerData, uint8* WhichPort, uint8* WhichSlot, uint8* SpecialOptionSelected){

uint8 NewPort;
uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse;

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < DreamcastControllerAmount; DirtyDeedsDoneDirtCheap++){
if(maple_enum_dev(DirtyDeedsDoneDirtCheap, 0) == NULL && LoadScreenControllerData[DirtyDeedsDoneDirtCheap].Active){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].Active = 0;
for(BurningDownTheHouse = 0; BurningDownTheHouse < VisualMemoryPerController; BurningDownTheHouse++) {
LoadGameDeActivateVisualMemoryData(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse]);
}
if(DirtyDeedsDoneDirtCheap == (*WhichPort)){
LoadGameFindNewPort((*WhichPort), (*WhichSlot), (*SpecialOptionSelected), NewPort);
}
}
else if(maple_enum_dev(DirtyDeedsDoneDirtCheap, 0) != NULL){
if(!LoadScreenControllerData[DirtyDeedsDoneDirtCheap].Active){
LoadScreenControllerData[DirtyDeedsDoneDirtCheap].Active = 1;
}

for(BurningDownTheHouse = 0; BurningDownTheHouse < VisualMemoryPerController; BurningDownTheHouse++){
if(maple_enum_dev(DirtyDeedsDoneDirtCheap, (BurningDownTheHouse+1)) == NULL && LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].Active){
LoadGameDeActivateVisualMemoryData(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse]);
if(DirtyDeedsDoneDirtCheap == (*WhichPort) && BurningDownTheHouse == (*WhichSlot)){
if(LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[((BurningDownTheHouse+1)%VisualMemoryPerController)].Active){
(*WhichSlot) = (((*WhichSlot)+1)%VisualMemoryPerController);
}
else{
LoadGameFindNewPort((*WhichPort), (*WhichSlot), (*SpecialOptionSelected), NewPort);
}
}
}
else if(maple_enum_dev(DirtyDeedsDoneDirtCheap, (BurningDownTheHouse+1)) != NULL && !LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse].Active){
LoadGameActivateVisualMemoryData(&LoadScreenControllerData[DirtyDeedsDoneDirtCheap].LoadScreenVisualMemoryData[BurningDownTheHouse], (*WhichPort), (*WhichSlot));
}
}
}

}


}