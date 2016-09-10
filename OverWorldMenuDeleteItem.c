#define OverWorldMenuDeleteItem(OverWorldMenuData, StolarOverWorldData)	DeleteItem(OverWorldMenuData, StolarOverWorldData, OverWorldMenuData->ItemData.ItemSelected)

void DeleteItem(OverWorldMenuStruct* OverWorldMenuData, StolarOverWorldStruct* StolarOverWorldData, uint8 WhichItem){

uint8 DirtyDeedsDoneDirtCheap;

for(DirtyDeedsDoneDirtCheap = WhichItem; DirtyDeedsDoneDirtCheap < (StolarOverWorldData->StolarData->ItemData.ItemAmountMax-1); DirtyDeedsDoneDirtCheap++){
StolarOverWorldData->StolarData->ItemData.ItemList[DirtyDeedsDoneDirtCheap] = StolarOverWorldData->StolarData->ItemData.ItemList[(DirtyDeedsDoneDirtCheap+1)];
}
StolarOverWorldData->StolarData->ItemData.ItemList[(StolarOverWorldData->StolarData->ItemData.ItemAmountMax-1)] = NoItemIdentifier;
}