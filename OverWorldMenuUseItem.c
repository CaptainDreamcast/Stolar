#define OverWorldMenuUseItemArguments			uint8 UseItemType, OverWorldMenuStruct* OverWorldMenuData, TileStruct* TileData, StolarOverWorldStruct* StolarOverWorldData, uint8 WhichItem, uint8 ItemType
#define OverWorldMenuUseItemFunctionAmount	1

#define OverWorldMenuItemTypeRegenerative		0

void OverWorldMenuUseItemRegenerative(OverWorldMenuUseItemArguments){

if(UseItemType == OverWorldMenuUseItemButtonPressed){
StolarRegainHealth((*((uint8*)(OverWorldMenuData->ItemData.SingleItemFlexibleData[ItemType]))));
DeleteItem(OverWorldMenuData, StolarOverWorldData, WhichItem);
}

}


void (*OverWorldMenuUseItem[OverWorldMenuUseItemFunctionAmount])(OverWorldMenuUseItemArguments) = 
{
OverWorldMenuUseItemRegenerative
};
