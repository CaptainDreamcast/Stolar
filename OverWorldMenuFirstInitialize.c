void OverWorldMenuFirstInitialize(OverWorldMenuStruct* OverWorldMenuData){

OverWorldMenuData->LogicData.ActiveScreen = 0;

OverWorldMenuData->MapData.CurrentPositionOnMapInRelationCalculated = 0;

OverWorldMenuData->MapData.Left = OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueLeft;
OverWorldMenuData->MapData.Right = OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueRight;
OverWorldMenuData->MapData.Up = OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueUp;
OverWorldMenuData->MapData.Down = OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueDown;

OverWorldMenuData->ItemData.ItemSelected = 0;
OverWorldMenuData->ItemData.DisplayedItemsUp = 0.0f;
OverWorldMenuData->ItemData.DisplayedItemsDown = OverWorldMenuData->ItemData.DisplayedItemsUp+OverWorldMenuData->Loadable->ItemDataLoadable.DisplayedRowAmount;
OverWorldMenuConfirmationModeInitialize(OverWorldMenuData->ItemData.ConfirmationMode);

OverWorldMenuData->AbilityData.AbilitySelected = 0;
OverWorldMenuData->AbilityData.ActiveAbilitySelectedBoolean = 0;
OverWorldMenuData->AbilityData.ActiveAbilitySelected = AbilityYellow;
OverWorldMenuData->AbilityData.DisplayedAbilitiesUp = 0.0f;
OverWorldMenuData->AbilityData.DisplayedAbilitiesDown = OverWorldMenuData->AbilityData.DisplayedAbilitiesUp+OverWorldMenuData->Loadable->AbilityDataLoadable.DisplayedRowAmount;


OverWorldMenuData->DivaData.LogEntryActualArrayDisplayedUp = 0.0f;
OverWorldMenuData->DivaData.LogEntryActualArrayDisplayedDown = OverWorldMenuData->DivaData.LogEntryActualArrayDisplayedUp+OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayScreenDisplayAmount;

OverWorldMenuData->DivaData.LogEntryActualArraySwitchUpDisplayedUp = 0.0f;
OverWorldMenuData->DivaData.LogEntryActualArraySwitchUpDisplayedDown = OverWorldMenuData->DivaData.LogEntryActualArraySwitchUpDisplayedUp+OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayScreenDisplayAmount;

OverWorldMenuData->DivaData.LogEntryPositionX = 0.0f;
OverWorldMenuData->DivaData.LogEntrySwitchUpPositionX = 0.0f;

OverWorldMenuData->DivaData.CharacterDescriptionDisplayedUp = 0.0f;
OverWorldMenuData->DivaData.CharacterDescriptionDisplayedDown = OverWorldMenuData->DivaData.CharacterDescriptionDisplayedUp+OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionScreenDisplayAmount;

OverWorldMenuData->DivaData.CharacterDescriptionSwitchUpDisplayedUp = 0.0f;
OverWorldMenuData->DivaData.CharacterDescriptionSwitchUpDisplayedDown = OverWorldMenuData->DivaData.CharacterDescriptionSwitchUpDisplayedUp+OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionScreenDisplayAmount;

OverWorldMenuData->DivaData.CharacterEntryPositionX = 0.0f; 
OverWorldMenuData->DivaData.CharacterEntrySwitchUpPositionX = 0.0f;

OverWorldMenuData->DivaData.DisplayedTheatreThumbnailsUp = 0.0f;
OverWorldMenuData->DivaData.DisplayedTheatreThumbnailsDown = OverWorldMenuData->DivaData.DisplayedTheatreThumbnailsUp+OverWorldMenuData->Loadable->DivaDataLoadable.TheatreThumbnailsDisplayedRowAmount;

OverWorldMenuData->DivaData.ExpandStartPositionLeft = 0.0f;
OverWorldMenuData->DivaData.ExpandStartPositionRight = 0.0f;
OverWorldMenuData->DivaData.ExpandStartPositionUp = 0.0f;
OverWorldMenuData->DivaData.ExpandStartPositionDown = 0.0f;

OverWorldMenuData->DivaData.ExpandEndPositionLeft = 0.0f;
OverWorldMenuData->DivaData.ExpandEndPositionRight = 0.0f;
OverWorldMenuData->DivaData.ExpandEndPositionUp = 0.0f;
OverWorldMenuData->DivaData.ExpandEndPositionDown = 0.0f;

OverWorldMenuData->DivaData.ExpandPositionLeft = 0.0f;
OverWorldMenuData->DivaData.ExpandPositionRight = 0.0f;
OverWorldMenuData->DivaData.ExpandPositionUp = 0.0f;
OverWorldMenuData->DivaData.ExpandPositionDown = 0.0f;


OverWorldMenuData->DivaData.ActiveScreenFlags = OverWorldMenuDivaMainScreenActiveFlag;
OverWorldMenuData->DivaData.ScreenInFront = OverWorldMenuDivaMainScreenActiveFlag;
OverWorldMenuData->DivaData.ScreenInBack = OverWorldMenuDivaMainScreenActiveFlag;
OverWorldMenuData->DivaData.ExpansionMode = OverWorldMenuDivaScreenNoExpand;


OverWorldMenuData->DivaData.LogEntryAmount = SaveData.CompressableData->LogEntryAmount;
OverWorldMenuData->DivaData.LogOptionDrawnUp = 0;

OverWorldMenuData->DivaData.LogEntrySelected = 0;
OverWorldMenuData->DivaData.LogEntrySwitchUp = 0;

OverWorldMenuData->DivaData.CharacterEntrySelected = 0;
OverWorldMenuData->DivaData.CharacterEntrySwitchUp = 0;
OverWorldMenuData->DivaData.CharacterEntryDrawnUp = 0;
OverWorldMenuData->DivaData.CharacterEntryAmount = SaveData.CompressableData->CharacterEntryAmount;

OverWorldMenuData->DivaData.TheatreThumbnailSelected = 0;
OverWorldMenuData->DivaData.MainOptionSelected = 0;

OverWorldMenuData->DivaData.CurrentObjectiveArray = SaveData.CompressableData->CurrentObjectiveArray;
OverWorldMenuData->DivaData.ExpansionTransformationData.Active = 0;


}