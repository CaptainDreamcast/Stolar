#define OverWorldMenuStatsArraySize	20
#define OverWorldMenuMapRelationToFixedPositionX(x) (OverWorldMenuData->Loadable->MapDataLoadable.PositionX+((x-OverWorldMenuData->MapData.Left)*((OverWorldMenuData->Loadable->MapDataLoadable.SizeY)/(OverWorldMenuData->MapData.Right-OverWorldMenuData->MapData.Left))))
#define OverWorldMenuMapRelationToFixedPositionY(x) (OverWorldMenuData->Loadable->MapDataLoadable.PositionY+((x-OverWorldMenuData->MapData.Up)*((OverWorldMenuData->Loadable->MapDataLoadable.SizeY)/(OverWorldMenuData->MapData.Down-OverWorldMenuData->MapData.Up))))

#define OverWorldMenuDrawActiveScreenArguments		OverWorldMenuStruct* OverWorldMenuData, StolarOverWorldStruct* StolarOverWorldData

void OverWorldMenuDrawStatsScreen(OverWorldMenuDrawActiveScreenArguments){

vector_t FinalVector[PolygonCornerAmount];
char StatsArray[OverWorldMenuStatsArraySize];
uint8 Color;

SetupVectors(FinalVector, OverWorldMenuData->Loadable->StatsDataLoadable.BackGroundPositionX, OverWorldMenuData->Loadable->StatsDataLoadable.BackGroundPositionY, OverWorldMenuData->Loadable->StatsDataLoadable.BackGroundPositionZ, OverWorldMenuData->Loadable->StatsDataLoadable.BackGroundTextureSizeX, OverWorldMenuData->Loadable->StatsDataLoadable.BackGroundTextureSizeY);
Transformation(FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData));

DrawVectorTexture(
FinalVector, 
OverWorldMenuData->StatsTextures.BackGroundTexture, PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 
OverWorldMenuData->Loadable->StatsDataLoadable.BackGroundTextureSizeX, 
OverWorldMenuData->Loadable->StatsDataLoadable.BackGroundTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f);


DrawStolar(OverWorldCurrentStolarTexture(StolarOverWorldData), 
OverWorldMenuData->Loadable->StatsDataLoadable.MenuStolarPositionX, OverWorldMenuData->Loadable->StatsDataLoadable.MenuStolarPositionY, 
OverWorldMenuData->Loadable->StatsDataLoadable.MenuStolarPositionZ, 
OverWorldMenuData->Loadable->StatsDataLoadable.MenuStolarSizeX, OverWorldMenuData->Loadable->StatsDataLoadable.MenuStolarSizeX, 
&OverWorldMenuData->LogicData.ActiveScreenTransformationData);


sprintf(StatsArray, "%d", StolarOverWorldData->StolarData->Level);
DrawArrayToScreen(StatsArray, OverWorldMenuData->Loadable->StatsDataLoadable.LevelPositionX, OverWorldMenuData->Loadable->StatsDataLoadable.LevelPositionY, OverWorldMenuData->Loadable->StatsDataLoadable.FontPositionZ, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeX, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeY, OverWorldMenuData->Loadable->StatsDataLoadable.FontColor, OverWorldMenuData->Loadable->StatsDataLoadable.Font, &OverWorldMenuData->LogicData.ActiveScreenTransformationData);

sprintf(StatsArray, "%d/%d", StolarOverWorldData->StolarData->HealthNow, StolarOverWorldData->StolarData->HealthMax);
if(StolarOverWorldData->StolarData->HealthNow > (StolarOverWorldData->StolarData->HealthMax/2)) Color = GreenColor;
else if(StolarOverWorldData->StolarData->HealthNow > (StolarOverWorldData->StolarData->HealthMax/4)) Color = YellowColor;
else Color = RedColor;
DrawArrayToScreen(StatsArray, OverWorldMenuData->Loadable->StatsDataLoadable.HealthPositionX, OverWorldMenuData->Loadable->StatsDataLoadable.HealthPositionY, OverWorldMenuData->Loadable->StatsDataLoadable.FontPositionZ, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeX, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeY, Color, OverWorldMenuData->Loadable->StatsDataLoadable.Font, &OverWorldMenuData->LogicData.ActiveScreenTransformationData);

sprintf(StatsArray, "%d", StolarOverWorldData->StolarData->Attack);
DrawArrayToScreen(StatsArray, OverWorldMenuData->Loadable->StatsDataLoadable.AttackPositionX, OverWorldMenuData->Loadable->StatsDataLoadable.AttackPositionY, OverWorldMenuData->Loadable->StatsDataLoadable.FontPositionZ, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeX, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeY, OverWorldMenuData->Loadable->StatsDataLoadable.FontColor, OverWorldMenuData->Loadable->StatsDataLoadable.Font, &OverWorldMenuData->LogicData.ActiveScreenTransformationData);

sprintf(StatsArray, "%d", StolarOverWorldData->StolarData->Defense);
DrawArrayToScreen(StatsArray, OverWorldMenuData->Loadable->StatsDataLoadable.DefensePositionX, OverWorldMenuData->Loadable->StatsDataLoadable.DefensePositionY, OverWorldMenuData->Loadable->StatsDataLoadable.FontPositionZ, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeX, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeY, OverWorldMenuData->Loadable->StatsDataLoadable.FontColor, OverWorldMenuData->Loadable->StatsDataLoadable.Font, &OverWorldMenuData->LogicData.ActiveScreenTransformationData);

sprintf(StatsArray, "%d", StolarOverWorldData->StolarData->Speed);
DrawArrayToScreen(StatsArray, OverWorldMenuData->Loadable->StatsDataLoadable.SpeedPositionX, OverWorldMenuData->Loadable->StatsDataLoadable.SpeedPositionY, OverWorldMenuData->Loadable->StatsDataLoadable.FontPositionZ, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeX, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeY, OverWorldMenuData->Loadable->StatsDataLoadable.FontColor, OverWorldMenuData->Loadable->StatsDataLoadable.Font, &OverWorldMenuData->LogicData.ActiveScreenTransformationData);

sprintf(StatsArray, "%d", StolarOverWorldData->StolarData->Luck);
DrawArrayToScreen(StatsArray, OverWorldMenuData->Loadable->StatsDataLoadable.LuckPositionX, OverWorldMenuData->Loadable->StatsDataLoadable.LuckPositionY, OverWorldMenuData->Loadable->StatsDataLoadable.FontPositionZ, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeX, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeY, OverWorldMenuData->Loadable->StatsDataLoadable.FontColor, OverWorldMenuData->Loadable->StatsDataLoadable.Font, &OverWorldMenuData->LogicData.ActiveScreenTransformationData);

sprintf(StatsArray, "%d/%d", StolarOverWorldData->StolarData->ExperienceCurrent, StolarOverWorldData->StolarData->ExperienceNecessary);
DrawArrayToScreen(StatsArray, OverWorldMenuData->Loadable->StatsDataLoadable.ExperiencePositionX, OverWorldMenuData->Loadable->StatsDataLoadable.ExperiencePositionY, OverWorldMenuData->Loadable->StatsDataLoadable.FontPositionZ, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeX, OverWorldMenuData->Loadable->StatsDataLoadable.FontSizeY, OverWorldMenuData->Loadable->StatsDataLoadable.FontColor, OverWorldMenuData->Loadable->StatsDataLoadable.Font, &OverWorldMenuData->LogicData.ActiveScreenTransformationData);


}


void OverWorldMenuDrawMapScreen(OverWorldMenuDrawActiveScreenArguments){

vector_t FinalVector[PolygonCornerAmount];

SetupTransformAndDrawSimplest(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->MapData.BackGroundTexture, OverWorldMenuData->Loadable->MapDataLoadable.BackGroundPositionX, OverWorldMenuData->Loadable->MapDataLoadable.BackGroundPositionY, 
OverWorldMenuData->Loadable->MapDataLoadable.BackGroundPositionZ, OverWorldMenuData->Loadable->MapDataLoadable.BackGroundTextureSizeX, OverWorldMenuData->Loadable->MapDataLoadable.BackGroundTextureSizeY,
OverWorldMenuData->Loadable->MapDataLoadable.BackGroundTextureSizeX, OverWorldMenuData->Loadable->MapDataLoadable.BackGroundTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

SetupTransformAndDrawPlus(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->MapData.MapTexture, OverWorldMenuData->Loadable->MapDataLoadable.PositionX, OverWorldMenuData->Loadable->MapDataLoadable.PositionY, 
OverWorldMenuData->Loadable->MapDataLoadable.PositionZ, OverWorldMenuData->Loadable->MapDataLoadable.SizeX, OverWorldMenuData->Loadable->MapDataLoadable.SizeY, 
OverWorldMenuData->Loadable->MapDataLoadable.TextureSizeX, OverWorldMenuData->Loadable->MapDataLoadable.TextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 1.0f, 1.0f, 1.0f, 1.0f, 
OverWorldMenuData->MapData.Left, OverWorldMenuData->MapData.Right, OverWorldMenuData->MapData.Up, OverWorldMenuData->MapData.Down);

if(
CheckWhetherRectangleInRectange(
OverWorldMenuData->MapData.CurrentPositionOnMapInRelationX, OverWorldMenuData->MapData.CurrentPositionOnMapInRelationY, 
((OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeX/2)*((OverWorldMenuData->MapData.Right - OverWorldMenuData->MapData.Left)/(OverWorldMenuData->Loadable->MapDataLoadable.SizeX))), 
((OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeY/2)*((OverWorldMenuData->MapData.Down - OverWorldMenuData->MapData.Up)/(OverWorldMenuData->Loadable->MapDataLoadable.SizeY))), 
OverWorldMenuData->MapData.Left, OverWorldMenuData->MapData.Right, OverWorldMenuData->MapData.Up, OverWorldMenuData->MapData.Down
)
){
SetupTransformAndDrawSimplest(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->MapData.StolarIcon, (OverWorldMenuMapRelationToFixedPositionX(OverWorldMenuData->MapData.CurrentPositionOnMapInRelationX)-(OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeX/2)), (OverWorldMenuMapRelationToFixedPositionY(OverWorldMenuData->MapData.CurrentPositionOnMapInRelationY)-(OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeY/2)), 
OverWorldMenuData->Loadable->MapDataLoadable.IconPositionZ, OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeX, OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeY,
OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeX, OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);
}

if(
CheckWhetherRectangleInRectange(
SaveData.CompressableData->GoalPositionOnMapInRelationX, SaveData.CompressableData->GoalPositionOnMapInRelationY, 
((OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeX/2)*((OverWorldMenuData->MapData.Right - OverWorldMenuData->MapData.Left)/(OverWorldMenuData->Loadable->MapDataLoadable.SizeX))), 
((OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeY/2)*((OverWorldMenuData->MapData.Down - OverWorldMenuData->MapData.Up)/(OverWorldMenuData->Loadable->MapDataLoadable.SizeY))), 
OverWorldMenuData->MapData.Left, OverWorldMenuData->MapData.Right, OverWorldMenuData->MapData.Up, OverWorldMenuData->MapData.Down
)
){
SetupTransformAndDrawSimplest(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->MapData.GoalIcon, (OverWorldMenuMapRelationToFixedPositionX(SaveData.CompressableData->GoalPositionOnMapInRelationX)-(OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeX/2)), (OverWorldMenuMapRelationToFixedPositionY(SaveData.CompressableData->GoalPositionOnMapInRelationY)-(OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeY/2)), 
OverWorldMenuData->Loadable->MapDataLoadable.IconPositionZ, OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeX, OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeY,
OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeX, OverWorldMenuData->Loadable->MapDataLoadable.IconTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);
}

}

#define OverWorldMenuDrawScrollListLogic(IconSelected, IconAmountPerRow, DisplayedIconsUp, DisplayedIconsDown, DisplayedRowAmount, ScrollableMovementPerSecondY, IconAmountMax) { \
if((IconSelected/IconAmountPerRow) < DisplayedIconsUp){ \
DisplayedIconsUp -= ScrollableMovementPerSecondY/FrameRate; \
if(DisplayedIconsUp < 0) DisplayedIconsUp = 0; \
DisplayedIconsDown = DisplayedIconsUp+DisplayedRowAmount; \
} \
else if(((IconSelected/IconAmountPerRow)+1) > DisplayedIconsDown){ \
DisplayedIconsDown += ScrollableMovementPerSecondY/FrameRate; \
if(DisplayedIconsDown > ((IconAmountMax-1)/IconAmountPerRow)) DisplayedIconsDown = ((IconAmountMax-1)/IconAmountPerRow); \
DisplayedIconsUp = DisplayedIconsDown-DisplayedRowAmount; \
} \
}


void OverWorldMenuDrawItemScreen(OverWorldMenuDrawActiveScreenArguments){

vector_t FinalVector[PolygonCornerAmount];
uint8 DirtyDeedsDoneDirtCheap;
char Array[OverWorldMenuData->Loadable->ItemDataLoadable.ConfirmationArrayLengthMaximum];

SetupTransformAndDrawSimplest(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->ItemData.BackGroundTexture, OverWorldMenuData->Loadable->ItemDataLoadable.BackGroundPositionX, OverWorldMenuData->Loadable->ItemDataLoadable.BackGroundPositionY, 
OverWorldMenuData->Loadable->ItemDataLoadable.BackGroundPositionZ, OverWorldMenuData->Loadable->ItemDataLoadable.BackGroundTextureSizeX, OverWorldMenuData->Loadable->ItemDataLoadable.BackGroundTextureSizeY,
OverWorldMenuData->Loadable->ItemDataLoadable.BackGroundTextureSizeX, OverWorldMenuData->Loadable->ItemDataLoadable.BackGroundTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);


IconListScrollableDraw(
OverWorldMenuData->ItemData.DisplayedItemsUp, OverWorldMenuData->ItemData.DisplayedItemsDown, 
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawStartPositionX, OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawStartPositionY, 
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawEndPositionY, OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawPositionZ,
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawSizeX, OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawSizeY, 
OverWorldMenuData->Loadable->ItemDataLoadable.ScrollButtonPositionX, OverWorldMenuData->Loadable->ItemDataLoadable.ScrollButtonStartPositionY, 
OverWorldMenuData->Loadable->ItemDataLoadable.ScrollButtonPositionZ, OverWorldMenuData->Loadable->ItemDataLoadable.ScrollButtonSizeX,
OverWorldMenuData->Loadable->ItemDataLoadable.ScrollButtonMinimumSizeY, OverWorldMenuData->Loadable->ItemDataLoadable.ScrollButtonMaximumSizeY, 
OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemPositionInFile, StolarOverWorldData->StolarData->ItemData.ItemList, 
OverWorldMenuData->Loadable->ItemDataLoadable.ItemAmountPerRow, StolarOverWorldData->StolarData->ItemData.ItemAmountMax, ItemAmountMaxOverall, 
OverWorldMenuData->Loadable->ItemDataLoadable.DisplayedRowAmount, 
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawTextureSizeX, OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawTextureSizeY,
OverWorldMenuData->Loadable->ItemDataLoadable.ScrollButtonTextureSizeX, OverWorldMenuData->Loadable->ItemDataLoadable.ScrollButtonTextureSizeY,
OverWorldMenuData->ItemData.AllItems, OverWorldMenuData->ItemData.ScrollButtonTexture,
(&OverWorldMenuData->LogicData.ActiveScreenTransformationData));


OverWorldMenuDrawScrollListLogic(
OverWorldMenuData->ItemData.ItemSelected, OverWorldMenuData->Loadable->ItemDataLoadable.ItemAmountPerRow, 
OverWorldMenuData->ItemData.DisplayedItemsUp, OverWorldMenuData->ItemData.DisplayedItemsDown, 
OverWorldMenuData->Loadable->ItemDataLoadable.DisplayedRowAmount, OverWorldMenuData->Loadable->ItemDataLoadable.ScrollableMovementPerSecondY, 
StolarOverWorldData->StolarData->ItemData.ItemAmountMax);

SetupTransformAndDrawPlus(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->ItemData.AllItems, 
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionImageDrawPositionX, 
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionImageDrawPositionY, 
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionImageDrawPositionZ, 
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionImageDrawSizeX, OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionImageDrawSizeY,
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawTextureSizeX, OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 1.0f, 1.0f, 1.0f, 1.0f, 
OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemPositionInFile[StolarOverWorldData->StolarData->ItemData.ItemList[OverWorldMenuData->ItemData.ItemSelected]].Left, 
OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemPositionInFile[StolarOverWorldData->StolarData->ItemData.ItemList[OverWorldMenuData->ItemData.ItemSelected]].Right, 
OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemPositionInFile[StolarOverWorldData->StolarData->ItemData.ItemList[OverWorldMenuData->ItemData.ItemSelected]].Up, 
OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemPositionInFile[StolarOverWorldData->StolarData->ItemData.ItemList[OverWorldMenuData->ItemData.ItemSelected]].Down
);


DrawArrayToScreen(
OverWorldMenuData->ItemData.SingleItemHeaderData[StolarOverWorldData->StolarData->ItemData.ItemList[OverWorldMenuData->ItemData.ItemSelected]].DescriptionArray, 
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionTextDrawPositionX, OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionTextDrawPositionY,
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionTextDrawPositionZ,
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionTextFontSizeX, OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionTextFontSizeY,
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionTextFontColor, OverWorldMenuData->Loadable->ItemDataLoadable.ItemDescriptionTextWhichFont, 
(&OverWorldMenuData->LogicData.ActiveScreenTransformationData)
);

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < OverWorldMenuData->Loadable->ItemDataLoadable.EquipmentAmount; DirtyDeedsDoneDirtCheap++){

SetupTransformAndDrawPlus(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->ItemData.AllItems, 
OverWorldMenuData->Loadable->ItemDataLoadable.EquipmentDrawStartPositionX+((DirtyDeedsDoneDirtCheap%OverWorldMenuData->Loadable->ItemDataLoadable.EquipmentAmountPerRow)*OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawSizeX), 
OverWorldMenuData->Loadable->ItemDataLoadable.EquipmentDrawStartPositionY+(OverWorldMenuData->Loadable->ItemDataLoadable.EquipmentDrawSizeY*(DirtyDeedsDoneDirtCheap/OverWorldMenuData->Loadable->ItemDataLoadable.EquipmentAmountPerRow)), 
OverWorldMenuData->Loadable->ItemDataLoadable.EquipmentDrawPositionZ, 
OverWorldMenuData->Loadable->ItemDataLoadable.EquipmentDrawSizeX, OverWorldMenuData->Loadable->ItemDataLoadable.EquipmentDrawSizeY,
OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawTextureSizeX, OverWorldMenuData->Loadable->ItemDataLoadable.ItemDrawTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 1.0f, 1.0f, 1.0f, 1.0f, 
OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemPositionInFile[StolarOverWorldData->StolarData->ItemData.EquipmentList[DirtyDeedsDoneDirtCheap]].Left, 
OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemPositionInFile[StolarOverWorldData->StolarData->ItemData.EquipmentList[DirtyDeedsDoneDirtCheap]].Right, 
OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemPositionInFile[StolarOverWorldData->StolarData->ItemData.EquipmentList[DirtyDeedsDoneDirtCheap]].Up, 
OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemPositionInFile[StolarOverWorldData->StolarData->ItemData.EquipmentList[DirtyDeedsDoneDirtCheap]].Down
);

}


if(OverWorldMenuConfirmationModeActive(OverWorldMenuData->ItemData.ConfirmationMode)){

SetupTransformAndDrawSimplest(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->ConfirmationTextures.ConfirmationMainBox, 
OverWorldMenuData->Loadable->ConfirmationMainBoxPositionX, OverWorldMenuData->Loadable->ConfirmationMainBoxPositionY, 
OverWorldMenuData->Loadable->ConfirmationMainBoxPositionZ, 
OverWorldMenuData->Loadable->ConfirmationMainBoxTextureSizeX, OverWorldMenuData->Loadable->ConfirmationMainBoxTextureSizeY,
OverWorldMenuData->Loadable->ConfirmationMainBoxTextureSizeX, OverWorldMenuData->Loadable->ConfirmationMainBoxTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

sprintf(Array, "%s%s%s", OverWorldMenuData->ItemData.SingleItemHeaderData[StolarOverWorldData->StolarData->ItemData.ItemList[OverWorldMenuData->ItemData.ItemSelected]].ConfirmationArrayBeforeItemName[OverWorldMenuConfirmationMode(OverWorldMenuData->ItemData.ConfirmationMode)], OverWorldMenuData->ItemData.SingleItemHeaderData[StolarOverWorldData->StolarData->ItemData.ItemList[OverWorldMenuData->ItemData.ItemSelected]].Name, OverWorldMenuData->ItemData.SingleItemHeaderData[StolarOverWorldData->StolarData->ItemData.ItemList[OverWorldMenuData->ItemData.ItemSelected]].ConfirmationArrayAfterItemName[OverWorldMenuConfirmationMode(OverWorldMenuData->ItemData.ConfirmationMode)]);
DrawArrayToScreen(
Array, 
OverWorldMenuData->Loadable->ConfirmationArrayPositionX, OverWorldMenuData->Loadable->ConfirmationArrayPositionY,
OverWorldMenuData->Loadable->ConfirmationArrayPositionZ,
OverWorldMenuData->Loadable->ConfirmationArrayFontSizeX, OverWorldMenuData->Loadable->ConfirmationArrayFontSizeY,
OverWorldMenuData->Loadable->ConfirmationArrayFontColor, OverWorldMenuData->Loadable->ConfirmationArrayWhichFont, 
(&OverWorldMenuData->LogicData.ActiveScreenTransformationData)
);

SetupTransformAndDrawSimplest(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->ConfirmationTextures.ConfirmationYes[OverWorldMenuConfirmed(OverWorldMenuData->ItemData.ConfirmationMode)], 
OverWorldMenuData->Loadable->ConfirmationYesPositionX, OverWorldMenuData->Loadable->ConfirmationYesPositionY, 
OverWorldMenuData->Loadable->ConfirmationYesPositionZ, 
OverWorldMenuData->Loadable->ConfirmationYesTextureSizeX, OverWorldMenuData->Loadable->ConfirmationYesTextureSizeY,
OverWorldMenuData->Loadable->ConfirmationYesTextureSizeX, OverWorldMenuData->Loadable->ConfirmationYesTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

SetupTransformAndDrawSimplest(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->ConfirmationTextures.ConfirmationNo[OverWorldMenuConfirmed(OverWorldMenuData->ItemData.ConfirmationMode)],  
OverWorldMenuData->Loadable->ConfirmationNoPositionX, OverWorldMenuData->Loadable->ConfirmationNoPositionY, 
OverWorldMenuData->Loadable->ConfirmationNoPositionZ, 
OverWorldMenuData->Loadable->ConfirmationNoTextureSizeX, OverWorldMenuData->Loadable->ConfirmationNoTextureSizeY,
OverWorldMenuData->Loadable->ConfirmationNoTextureSizeX, OverWorldMenuData->Loadable->ConfirmationNoTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

}

}

#define OverWorldMenuDrawEquippedAbility(WhichAbility) { \
SetupTransformAndDrawSimplest( \
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), \
OverWorldMenuData->AbilityData.EquippedAbilityBackGroundTexture[(WhichAbility-1)], \
OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityBackGroundPositionX[(WhichAbility-1)], OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityBackGroundPositionY[(WhichAbility-1)], \
OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityBackGroundPositionZ, \
OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityBackGroundTextureSizeX, OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityBackGroundTextureSizeY, \
OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityBackGroundTextureSizeX, OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityBackGroundTextureSizeY, \
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY); \
SetupTransformAndDrawPlus( \
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), \
OverWorldMenuData->AbilityData.AllAbilities, \
OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityPositionX[(WhichAbility-1)], OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityPositionY[(WhichAbility-1)], \
OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityPositionZ, \
OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityDrawSizeX, OverWorldMenuData->Loadable->AbilityDataLoadable.EquippedAbilityDrawSizeY, \
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDrawTextureSizeX, OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDrawTextureSizeY, \
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 1.0f, 1.0f, 1.0f, 1.0f, \
OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityPositionInFile[StolarOverWorldData->StolarData->AbilityData.AbilityList[StolarOverWorldData->StolarData->Ability[WhichAbility]]].Left, \
OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityPositionInFile[StolarOverWorldData->StolarData->AbilityData.AbilityList[StolarOverWorldData->StolarData->Ability[WhichAbility]]].Right, \
OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityPositionInFile[StolarOverWorldData->StolarData->AbilityData.AbilityList[StolarOverWorldData->StolarData->Ability[WhichAbility]]].Up, \
OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityPositionInFile[StolarOverWorldData->StolarData->AbilityData.AbilityList[StolarOverWorldData->StolarData->Ability[WhichAbility]]].Down \
); \
}

void OverWorldMenuDrawAbilityScreen(OverWorldMenuDrawActiveScreenArguments){

vector_t FinalVector[PolygonCornerAmount];
uint8 DirtyDeedsDoneDirtCheap;

IconListScrollableDraw(
OverWorldMenuData->AbilityData.DisplayedAbilitiesUp, OverWorldMenuData->AbilityData.DisplayedAbilitiesDown, 
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDrawStartPositionX, OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDrawStartPositionY, 
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDrawEndPositionY, OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDrawPositionZ,
OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityDrawSizeX, OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityDrawSizeY, 
OverWorldMenuData->Loadable->AbilityDataLoadable.ScrollButtonPositionX, OverWorldMenuData->Loadable->AbilityDataLoadable.ScrollButtonStartPositionY, 
OverWorldMenuData->Loadable->AbilityDataLoadable.ScrollButtonPositionZ, OverWorldMenuData->Loadable->AbilityDataLoadable.ScrollButtonSizeX,
OverWorldMenuData->Loadable->AbilityDataLoadable.ScrollButtonMinimumSizeY, OverWorldMenuData->Loadable->AbilityDataLoadable.ScrollButtonMaximumSizeY, 
OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityPositionInFile, StolarOverWorldData->StolarData->AbilityData.AbilityList, 
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityAmountPerRow, AbilityAmountMaxOverall, AbilityAmountMaxOverall, 
OverWorldMenuData->Loadable->AbilityDataLoadable.DisplayedRowAmount, 
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDrawTextureSizeX, OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDrawTextureSizeY,
OverWorldMenuData->Loadable->AbilityDataLoadable.ScrollButtonTextureSizeX, OverWorldMenuData->Loadable->AbilityDataLoadable.ScrollButtonTextureSizeY,
OverWorldMenuData->AbilityData.AllAbilities, OverWorldMenuData->AbilityData.ScrollButtonTexture,
(&OverWorldMenuData->LogicData.ActiveScreenTransformationData));

OverWorldMenuDrawScrollListLogic(
OverWorldMenuData->AbilityData.AbilitySelected, OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityAmountPerRow, 
OverWorldMenuData->AbilityData.DisplayedAbilitiesUp, OverWorldMenuData->AbilityData.DisplayedAbilitiesDown, 
OverWorldMenuData->Loadable->AbilityDataLoadable.DisplayedRowAmount, OverWorldMenuData->Loadable->AbilityDataLoadable.ScrollableMovementPerSecondY, 
AbilityAmountMaxOverall);


SetupTransformAndDrawPlus(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->AbilityData.AllAbilities, 
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionImageDrawPositionX, 
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionImageDrawPositionY, 
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionImageDrawPositionZ, 
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionImageDrawSizeX, OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionImageDrawSizeY,
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDrawTextureSizeX, OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDrawTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY, 1.0f, 1.0f, 1.0f, 1.0f, 
OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityPositionInFile[StolarOverWorldData->StolarData->AbilityData.AbilityList[OverWorldMenuData->AbilityData.AbilitySelected]].Left, 
OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityPositionInFile[StolarOverWorldData->StolarData->AbilityData.AbilityList[OverWorldMenuData->AbilityData.AbilitySelected]].Right, 
OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityPositionInFile[StolarOverWorldData->StolarData->AbilityData.AbilityList[OverWorldMenuData->AbilityData.AbilitySelected]].Up, 
OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityPositionInFile[StolarOverWorldData->StolarData->AbilityData.AbilityList[OverWorldMenuData->AbilityData.AbilitySelected]].Down
);

DrawArrayToScreen(
OverWorldMenuData->AbilityData.SingleAbilityHeaderData[StolarOverWorldData->StolarData->AbilityData.AbilityList[OverWorldMenuData->AbilityData.AbilitySelected]].DescriptionArray, 
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionTextDrawPositionX, OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionTextDrawPositionY,
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionTextDrawPositionZ,
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionTextFontSizeX, OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionTextFontSizeY,
OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionTextFontColor, OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityDescriptionTextWhichFont, 
(&OverWorldMenuData->LogicData.ActiveScreenTransformationData)
);

for(DirtyDeedsDoneDirtCheap = AbilityYellow; DirtyDeedsDoneDirtCheap < AbilityAmount; DirtyDeedsDoneDirtCheap++){
OverWorldMenuDrawEquippedAbility(DirtyDeedsDoneDirtCheap);
}



}

#define OverWorldMenuDivaScreenSwitchUpLogic(EntryPositionX, SwitchUpPositionX, EntryMovementPerSecondX) { \
if(EntryPositionX > SwitchUpPositionX){ \
EntryPositionX -= EntryMovementPerSecondX/FrameRate; \
SwitchUpPositionX -= EntryMovementPerSecondX/FrameRate; \
if(EntryPositionX < 0.0f) EntryPositionX = SwitchUpPositionX = 0.0f; \
} \
else{ \
EntryPositionX += EntryMovementPerSecondX/FrameRate; \
SwitchUpPositionX += EntryMovementPerSecondX/FrameRate; \
if(EntryPositionX > 0.0f) EntryPositionX = SwitchUpPositionX = 0.0f; \
} \
}

#define OverWorldMenuDivaScreenSingleLogScreenDraw(WhichEntry, EntryPositionX, DisplayedUp, DisplayedDown) { \
DrawArrayToScreen( \
OverWorldMenuData->DivaData.LogEntryTitleArray[WhichEntry], \
OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryTitleArrayPositionX+EntryPositionX, \
OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryTitleArrayPositionY, \
OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryTitleArrayPositionZ, \
OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryTitleArrayFontSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryTitleArrayFontSizeY, \
OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryTitleArrayFontColor, OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryTitleArrayWhichFont, \
TransformationData \
); \
DrawArrayToScreenPlus( \
OverWorldMenuData->DivaData.LogEntryActualArray[WhichEntry], \
OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayPositionX+EntryPositionX, \
OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayPositionY, \
OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayPositionZ, \
OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayFontSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayFontSizeY, \
OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayFontColor, OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayWhichFont, \
TransformationData, DisplayedUp, DisplayedDown \
); \
}

#define OverWorldMenuDivaScreenSingleCharacterScreenDraw(WhichCharacter, EntryPositionX, DisplayedUp, DisplayedDown) { \
SetupTransformAndDrawSimplest( \
FinalVector, TransformationData,  \
OverWorldMenuData->DivaData.CharacterTexture[WhichCharacter], \
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterPicturePositionX+EntryPositionX, \
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterPicturePositionY, \
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterPicturePositionZ, \
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterPictureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.CharacterPictureSizeY, \
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterPictureTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.CharacterPictureTextureSizeY, \
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY); \
DrawArrayToScreenPlus( \
OverWorldMenuData->DivaData.CharacterDescription[WhichCharacter], \
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionPositionX+EntryPositionX, \
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionPositionY, \
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionPositionZ, \
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionFontSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionFontSizeY, \
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionFontColor, OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionWhichFont, \
TransformationData, DisplayedUp, DisplayedDown \
); \
}



void OverWorldMenuDrawDivaScreen(OverWorldMenuDrawActiveScreenArguments){

TransformationStruct* TransformationData;
vector_t FinalVector[PolygonCornerAmount];
uint8 DirtyDeedsDoneDirtCheap;

//if(OverWorldMenuData->LogicData.ActiveScreenTransformationData.Active && OverWorldMenuData->DivaData.ExpansionTransformationData.Active){
CombineTransformationData(&OverWorldMenuData->DivaData.ExpansionTransformationData, &OverWorldMenuData->LogicData.ActiveScreenTransformationData);
//}

if(OverWorldMenuData->DivaData.ActiveScreenFlags & OverWorldMenuDivaMainScreenActiveFlag){


SetupTransformAndDrawSimplest(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->DivaData.MainBackGroundTexture, 
OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundPositionX, OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundPositionY, 
OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundPositionZ, 
OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundTextureSizeY,
OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < OverWorldMenuDivaMainOptionAmount; DirtyDeedsDoneDirtCheap++){
SetupTransformAndDrawSimplest(
FinalVector, (&OverWorldMenuData->LogicData.ActiveScreenTransformationData), 
OverWorldMenuData->DivaData.MainOptionTextures[DirtyDeedsDoneDirtCheap], 
OverWorldMenuData->Loadable->DivaDataLoadable.MainOptionPositionX, OverWorldMenuData->Loadable->DivaDataLoadable.MainOptionPositionY[DirtyDeedsDoneDirtCheap], 
OverWorldMenuData->Loadable->DivaDataLoadable.MainOptionPositionZ, 
OverWorldMenuData->Loadable->DivaDataLoadable.MainOptionTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.MainOptionTextureSizeY,
OverWorldMenuData->Loadable->DivaDataLoadable.MainOptionTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.MainOptionTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);
}

DrawArrayToScreen(
OverWorldMenuData->DivaData.CurrentObjectiveArray, 
OverWorldMenuData->Loadable->DivaDataLoadable.CurrentObjectiveArrayPositionX, OverWorldMenuData->Loadable->DivaDataLoadable.CurrentObjectiveArrayPositionY,
OverWorldMenuData->Loadable->DivaDataLoadable.CurrentObjectiveArrayPositionZ,
OverWorldMenuData->Loadable->DivaDataLoadable.CurrentObjectiveArrayFontSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.CurrentObjectiveArrayFontSizeY,
OverWorldMenuData->Loadable->DivaDataLoadable.CurrentObjectiveArrayFontColor, OverWorldMenuData->Loadable->DivaDataLoadable.CurrentObjectiveArrayWhichFont, 
(&OverWorldMenuData->LogicData.ActiveScreenTransformationData)
);

}
if(OverWorldMenuData->DivaData.ActiveScreenFlags & OverWorldMenuDivaLogScreenActiveFlag){

if(OverWorldMenuData->DivaData.ScreenInFront == OverWorldMenuDivaLogScreenActiveFlag) TransformationData = &OverWorldMenuData->DivaData.ExpansionTransformationData;
else TransformationData = &OverWorldMenuData->LogicData.ActiveScreenTransformationData;

if(OverWorldMenuData->DivaData.LogEntrySelected < OverWorldMenuData->DivaData.LogOptionDrawnUp) OverWorldMenuData->DivaData.LogOptionDrawnUp = OverWorldMenuData->DivaData.LogEntrySelected;
else if(OverWorldMenuData->DivaData.LogEntrySelected >= OverWorldMenuData->DivaData.LogOptionDrawnUp+OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionDrawnAmount) OverWorldMenuData->DivaData.LogOptionDrawnUp = (OverWorldMenuData->DivaData.LogEntrySelected+1)-OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionDrawnAmount;

for(DirtyDeedsDoneDirtCheap=OverWorldMenuData->DivaData.LogOptionDrawnUp; (DirtyDeedsDoneDirtCheap<OverWorldMenuData->DivaData.LogOptionDrawnUp+OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionDrawnAmount) && (DirtyDeedsDoneDirtCheap < OverWorldMenuData->DivaData.LogEntryAmount); DirtyDeedsDoneDirtCheap++){

SetupTransformAndDrawSimplest(
FinalVector, TransformationData, 
OverWorldMenuData->DivaData.LogOptionBackGroundTexture, 
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionBackGroundPositionX, 
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionBackGroundPositionY+(OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionDistanceY*(DirtyDeedsDoneDirtCheap-OverWorldMenuData->DivaData.LogOptionDrawnUp)), 
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionBackGroundPositionZ, 
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionBackGroundTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionBackGroundTextureSizeY,
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionBackGroundTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionBackGroundTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

DrawArrayToScreen(
OverWorldMenuData->DivaData.LogEntryTitleArray[DirtyDeedsDoneDirtCheap], 
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionArrayPositionX, 
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionArrayPositionY+(OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionDistanceY*(DirtyDeedsDoneDirtCheap-OverWorldMenuData->DivaData.LogOptionDrawnUp)),
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionArrayPositionZ,
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionArrayFontSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionArrayFontSizeY,
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionArrayFontColor, OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionArrayWhichFont, 
TransformationData
);

}

}
if(OverWorldMenuData->DivaData.ActiveScreenFlags & OverWorldMenuDivaSingleLogScreenActiveFlag){

if(OverWorldMenuData->DivaData.ScreenInFront == OverWorldMenuDivaSingleLogScreenActiveFlag) TransformationData = &OverWorldMenuData->DivaData.ExpansionTransformationData;
else TransformationData = &OverWorldMenuData->LogicData.ActiveScreenTransformationData;


OverWorldMenuDivaScreenSingleLogScreenDraw(OverWorldMenuData->DivaData.LogEntrySelected, OverWorldMenuData->DivaData.LogEntryPositionX, OverWorldMenuData->DivaData.LogEntryActualArrayDisplayedUp, OverWorldMenuData->DivaData.LogEntryActualArrayDisplayedDown);

if(OverWorldMenuData->DivaData.LogEntryPositionX != OverWorldMenuData->DivaData.LogEntrySwitchUpPositionX){
OverWorldMenuDivaScreenSingleLogScreenDraw(OverWorldMenuData->DivaData.LogEntrySwitchUp, OverWorldMenuData->DivaData.LogEntrySwitchUpPositionX, OverWorldMenuData->DivaData.LogEntryActualArraySwitchUpDisplayedUp, OverWorldMenuData->DivaData.LogEntryActualArraySwitchUpDisplayedDown);
OverWorldMenuDivaScreenSwitchUpLogic(OverWorldMenuData->DivaData.LogEntryPositionX, OverWorldMenuData->DivaData.LogEntrySwitchUpPositionX, OverWorldMenuData->Loadable->DivaDataLoadable.SingleLogEntryMovementPerSecondX);
}

}
if(OverWorldMenuData->DivaData.ActiveScreenFlags & OverWorldMenuDivaCharacterScreenActiveFlag){

if(OverWorldMenuData->DivaData.ScreenInFront == OverWorldMenuDivaCharacterScreenActiveFlag) TransformationData = &OverWorldMenuData->DivaData.ExpansionTransformationData;
else TransformationData = &OverWorldMenuData->LogicData.ActiveScreenTransformationData;


if(OverWorldMenuData->DivaData.CharacterEntrySelected < OverWorldMenuData->DivaData.CharacterEntryDrawnUp) OverWorldMenuData->DivaData.CharacterEntryDrawnUp = OverWorldMenuData->DivaData.CharacterEntrySelected;
else if(OverWorldMenuData->DivaData.CharacterEntrySelected >= OverWorldMenuData->DivaData.CharacterEntryDrawnUp+OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryDrawnAmount) OverWorldMenuData->DivaData.CharacterEntryDrawnUp = (OverWorldMenuData->DivaData.CharacterEntrySelected+1)-OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryDrawnAmount;

for(DirtyDeedsDoneDirtCheap=OverWorldMenuData->DivaData.CharacterEntryDrawnUp; (DirtyDeedsDoneDirtCheap<OverWorldMenuData->DivaData.CharacterEntryDrawnUp+OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryDrawnAmount) && (DirtyDeedsDoneDirtCheap < OverWorldMenuData->DivaData.CharacterEntryAmount); DirtyDeedsDoneDirtCheap++){

SetupTransformAndDrawSimplest(
FinalVector, TransformationData, 
OverWorldMenuData->DivaData.CharacterEntryBackGroundTexture, 
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryBackGroundPositionX, 
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryBackGroundPositionY+(OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryDistanceY*(DirtyDeedsDoneDirtCheap-OverWorldMenuData->DivaData.CharacterEntryDrawnUp)), 
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryBackGroundPositionZ, 
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryBackGroundTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryBackGroundTextureSizeY,
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryBackGroundTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryBackGroundTextureSizeY,
PVR_TXRFMT_ARGB4444, PVR_LIST_TR_POLY);

DrawArrayToScreen(
OverWorldMenuData->DivaData.CharacterEntryTitleArray[DirtyDeedsDoneDirtCheap], 
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryTitleArrayPositionX, 
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryTitleArrayPositionY+(OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryDistanceY*(DirtyDeedsDoneDirtCheap-OverWorldMenuData->DivaData.CharacterEntryDrawnUp)),
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryTitleArrayPositionZ,
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryTitleArrayFontSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryTitleArrayFontSizeY,
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryTitleArrayFontColor, OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryTitleArrayWhichFont, 
TransformationData
);

}


}
if(OverWorldMenuData->DivaData.ActiveScreenFlags & OverWorldMenuDivaSingleCharacterScreenActiveFlag){

if(OverWorldMenuData->DivaData.ScreenInFront == OverWorldMenuDivaSingleCharacterScreenActiveFlag) TransformationData = &OverWorldMenuData->DivaData.ExpansionTransformationData;
else TransformationData = &OverWorldMenuData->LogicData.ActiveScreenTransformationData;


OverWorldMenuDivaScreenSingleCharacterScreenDraw(OverWorldMenuData->DivaData.CharacterEntrySelected, OverWorldMenuData->DivaData.CharacterEntryPositionX, OverWorldMenuData->DivaData.CharacterDescriptionDisplayedUp, OverWorldMenuData->DivaData.CharacterDescriptionDisplayedDown);

if(OverWorldMenuData->DivaData.CharacterEntryPositionX != OverWorldMenuData->DivaData.CharacterEntrySwitchUpPositionX){
OverWorldMenuDivaScreenSingleCharacterScreenDraw(OverWorldMenuData->DivaData.CharacterEntrySwitchUp, OverWorldMenuData->DivaData.CharacterEntrySwitchUpPositionX, OverWorldMenuData->DivaData.CharacterDescriptionSwitchUpDisplayedUp, OverWorldMenuData->DivaData.CharacterDescriptionSwitchUpDisplayedDown);
OverWorldMenuDivaScreenSwitchUpLogic(OverWorldMenuData->DivaData.CharacterEntryPositionX, OverWorldMenuData->DivaData.CharacterEntrySwitchUpPositionX, OverWorldMenuData->Loadable->DivaDataLoadable.SingleCharacterEntryMovementPerSecondX);
}

}
if(OverWorldMenuData->DivaData.ActiveScreenFlags & OverWorldMenuDivaTheatreScreenActiveFlag){

if(OverWorldMenuData->DivaData.ScreenInFront == OverWorldMenuDivaTheatreScreenActiveFlag) TransformationData = &OverWorldMenuData->DivaData.ExpansionTransformationData;
else TransformationData = &OverWorldMenuData->LogicData.ActiveScreenTransformationData;

IconListScrollableDraw(
OverWorldMenuData->DivaData.DisplayedTheatreThumbnailsUp, OverWorldMenuData->DivaData.DisplayedTheatreThumbnailsDown, 
OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailDrawStartPositionX, OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailDrawStartPositionY, 
OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailDrawEndPositionY, OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailDrawPositionZ,
OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailDrawSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailDrawSizeY, 
OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsScrollButtonPositionX, OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsScrollButtonStartPositionY, 
OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsScrollButtonPositionZ, OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsScrollButtonSizeX,
OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsScrollButtonMinimumSizeY, OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsScrollButtonMaximumSizeY, 
OverWorldMenuData->Loadable->DivaDataLoadable.SingleTheatreThumbnailPositionInFile, NULL, 
OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailAmountPerRow, TheatreThumbnailAmountOverall, TheatreThumbnailAmountOverall, 
OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsDisplayedRowAmount, 
OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailDrawTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailDrawTextureSizeY,
OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsScrollButtonTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsScrollButtonTextureSizeY,
OverWorldMenuData->DivaData.TheatreThumbnailTextures, OverWorldMenuData->DivaData.TheatreThumbnailsScrollButtonTexture,
TransformationData);

OverWorldMenuDrawScrollListLogic(
OverWorldMenuData->DivaData.TheatreThumbnailSelected, OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailAmountPerRow, 
OverWorldMenuData->DivaData.DisplayedTheatreThumbnailsUp, OverWorldMenuData->DivaData.DisplayedTheatreThumbnailsDown, 
OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsDisplayedRowAmount, OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsScrollableMovementPerSecondY, 
TheatreThumbnailAmountOverall);

}


}

void (*OverWorldMenuDrawActiveScreen[OverWorldMenuScreenAmount])(OverWorldMenuDrawActiveScreenArguments) = 
{
OverWorldMenuDrawStatsScreen, 
OverWorldMenuDrawMapScreen, 
OverWorldMenuDrawItemScreen, 
OverWorldMenuDrawAbilityScreen, 
OverWorldMenuDrawDivaScreen
};
