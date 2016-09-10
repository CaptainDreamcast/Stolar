#define OverWorldMenuInputActiveScreenArguments		OverWorldMenuStruct* OverWorldMenuData, TileStruct* TileData, StolarOverWorldStruct* StolarOverWorldData


void OverWorldMenuInputStatsScreen(OverWorldMenuInputActiveScreenArguments){}


#define OverWorldMenuIInputMapZoomAction(CheckValue, CheckValueChecksForThis, ZoomSpeedSixtyHertzX, ZoomSpeedSixtyHertzY, LeftFinalValue, RightFinalValue, UpFinalValue, DownFinalValue)	{ \
if(CheckValue != CheckValueChecksForThis){ \
OverWorldMenuData->MapData.Left -= (ZoomSpeedSixtyHertzX*(SixtyHertz/FrameRate)); \
OverWorldMenuData->MapData.Right += (ZoomSpeedSixtyHertzX*(SixtyHertz/FrameRate)); \
OverWorldMenuData->MapData.Up -= (ZoomSpeedSixtyHertzY*(SixtyHertz/FrameRate)); \
OverWorldMenuData->MapData.Down += (ZoomSpeedSixtyHertzY*(SixtyHertz/FrameRate)); \
if(CheckValue <= CheckValueChecksForThis){ \
OverWorldMenuData->MapData.Left = LeftFinalValue; \
OverWorldMenuData->MapData.Right = RightFinalValue; \
OverWorldMenuData->MapData.Up = UpFinalValue; \
OverWorldMenuData->MapData.Down = DownFinalValue; \
} \
} \
}

#define OverWorldMenuInputMapMovementAction(CheckerValue, CheckedAgainst, BorderValue, OtherValue, Size, FullSize, Border, Speed){ \
if(BorderValue != Border){ \
OtherValue += ((Size/FullSize)*Speed*FrameRate); \
BorderValue += ((Size/FullSize)*Speed*FrameRate); \
if(CheckerValue > CheckedAgainst){ \
OtherValue -= (BorderValue-Border); \
BorderValue = Border; \
} \
} \
}



void OverWorldMenuInputMapScreen(OverWorldMenuInputActiveScreenArguments){

if(ButtonPressedX(OverWorldMenuData->LogicData.st)){
if(OverWorldMenuData->MapData.Left != OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueLeft || OverWorldMenuData->MapData.Right != OverWorldMenuData->MapData.Right){
OverWorldMenuData->MapData.Left -= (OverWorldMenuData->Loadable->MapDataLoadable.ZoomSpeedSixtyHertzX*(SixtyHertz/FrameRate));
if(OverWorldMenuData->MapData.Left < OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueLeft){
OverWorldMenuData->MapData.Right += (OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueLeft-OverWorldMenuData->MapData.Left);
OverWorldMenuData->MapData.Left = OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueLeft;
}
OverWorldMenuData->MapData.Right += (OverWorldMenuData->Loadable->MapDataLoadable.ZoomSpeedSixtyHertzX*(SixtyHertz/FrameRate));
if(OverWorldMenuData->MapData.Right > OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueRight){
OverWorldMenuData->MapData.Left -= (OverWorldMenuData->MapData.Right-OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueRight);
if(OverWorldMenuData->MapData.Left < OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueLeft) OverWorldMenuData->MapData.Left = OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueLeft;
OverWorldMenuData->MapData.Right = OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueRight;
}
OverWorldMenuData->MapData.Up -= (OverWorldMenuData->Loadable->MapDataLoadable.ZoomSpeedSixtyHertzY*(SixtyHertz/FrameRate));
if(OverWorldMenuData->MapData.Up < OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueUp){
OverWorldMenuData->MapData.Down += (OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueUp-OverWorldMenuData->MapData.Up);
OverWorldMenuData->MapData.Up = OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueUp;
}
OverWorldMenuData->MapData.Down += (OverWorldMenuData->Loadable->MapDataLoadable.ZoomSpeedSixtyHertzY*(SixtyHertz/FrameRate));
if(OverWorldMenuData->MapData.Down > OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueDown){
OverWorldMenuData->MapData.Up -= (OverWorldMenuData->MapData.Down-OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueDown);
if(OverWorldMenuData->MapData.Up < OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueUp) OverWorldMenuData->MapData.Up = OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueUp;
OverWorldMenuData->MapData.Down = OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueDown;
}
}
}
else if(ButtonPressedY(OverWorldMenuData->LogicData.st)){
OverWorldMenuIInputMapZoomAction((OverWorldMenuData->MapData.Right-OverWorldMenuData->MapData.Left), OverWorldMenuData->Loadable->MapDataLoadable.FullZoomInSizeX, 
(-OverWorldMenuData->Loadable->MapDataLoadable.ZoomSpeedSixtyHertzX), (-OverWorldMenuData->Loadable->MapDataLoadable.ZoomSpeedSixtyHertzY), 
((OverWorldMenuData->MapData.Left+((OverWorldMenuData->MapData.Right-OverWorldMenuData->MapData.Left)/2))-(OverWorldMenuData->Loadable->MapDataLoadable.FullZoomInSizeX/2)), 
((OverWorldMenuData->MapData.Left+((OverWorldMenuData->MapData.Right-OverWorldMenuData->MapData.Left)/2))+(OverWorldMenuData->Loadable->MapDataLoadable.FullZoomInSizeX/2)), 
((OverWorldMenuData->MapData.Up+((OverWorldMenuData->MapData.Down-OverWorldMenuData->MapData.Up)/2))-(OverWorldMenuData->Loadable->MapDataLoadable.FullZoomInSizeY/2)), 
((OverWorldMenuData->MapData.Up+((OverWorldMenuData->MapData.Down-OverWorldMenuData->MapData.Up)/2))+(OverWorldMenuData->Loadable->MapDataLoadable.FullZoomInSizeY/2)));
}

if(ButtonPressedLeft(OverWorldMenuData->LogicData.st)){
OverWorldMenuInputMapMovementAction((-OverWorldMenuData->MapData.Left), (-OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueLeft), 
OverWorldMenuData->MapData.Left, OverWorldMenuData->MapData.Right, (OverWorldMenuData->MapData.Right-OverWorldMenuData->MapData.Left), 
(OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueRight-OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueLeft), 
OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueLeft, (-OverWorldMenuData->Loadable->MapDataLoadable.ScreenTraversalTimeInSecondsX));
}
else if(ButtonPressedRight(OverWorldMenuData->LogicData.st)){
OverWorldMenuInputMapMovementAction(OverWorldMenuData->MapData.Right, OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueRight, 
OverWorldMenuData->MapData.Right, OverWorldMenuData->MapData.Left, (OverWorldMenuData->MapData.Right-OverWorldMenuData->MapData.Left), 
(OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueRight-OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueLeft), 
OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueRight, OverWorldMenuData->Loadable->MapDataLoadable.ScreenTraversalTimeInSecondsX);
}
if(ButtonPressedUp(OverWorldMenuData->LogicData.st)){
OverWorldMenuInputMapMovementAction((-OverWorldMenuData->MapData.Up), (-OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueUp), 
OverWorldMenuData->MapData.Up, OverWorldMenuData->MapData.Down, (OverWorldMenuData->MapData.Down-OverWorldMenuData->MapData.Up), 
(OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueDown-OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueUp), 
OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueUp, (-OverWorldMenuData->Loadable->MapDataLoadable.ScreenTraversalTimeInSecondsY));
}
else if(ButtonPressedDown(OverWorldMenuData->LogicData.st)){
OverWorldMenuInputMapMovementAction(OverWorldMenuData->MapData.Down, OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueDown, 
OverWorldMenuData->MapData.Down, OverWorldMenuData->MapData.Up, (OverWorldMenuData->MapData.Down-OverWorldMenuData->MapData.Up), 
(OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueDown-OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueUp), 
OverWorldMenuData->Loadable->MapDataLoadable.FullZoomOutValueDown, OverWorldMenuData->Loadable->MapDataLoadable.ScreenTraversalTimeInSecondsY);
}



}

void OverWorldMenuInputItemScreen(OverWorldMenuInputActiveScreenArguments){

if(ButtonLegit(ButtonRight, OverWorldMenuData->LogicData.ButtonInputData)){
if(((OverWorldMenuData->ItemData.ItemSelected%OverWorldMenuData->Loadable->ItemDataLoadable.ItemAmountPerRow) == (OverWorldMenuData->Loadable->ItemDataLoadable.ItemAmountPerRow-1)) ||
(OverWorldMenuData->ItemData.ItemSelected == (StolarOverWorldData->StolarData->ItemData.ItemAmountMax-1))
){ 
OverWorldMenuData->ItemData.ItemSelected = (OverWorldMenuData->ItemData.ItemSelected/OverWorldMenuData->Loadable->ItemDataLoadable.ItemAmountPerRow)*OverWorldMenuData->Loadable->ItemDataLoadable.ItemAmountPerRow;
}
else{
OverWorldMenuData->ItemData.ItemSelected++;
}
}
else if(ButtonLegit(ButtonLeft, OverWorldMenuData->LogicData.ButtonInputData)){
if((OverWorldMenuData->ItemData.ItemSelected%OverWorldMenuData->Loadable->ItemDataLoadable.ItemAmountPerRow) == 0){
OverWorldMenuData->ItemData.ItemSelected+=OverWorldMenuData->Loadable->ItemDataLoadable.ItemAmountPerRow;
if(OverWorldMenuData->ItemData.ItemSelected >= StolarOverWorldData->StolarData->ItemData.ItemAmountMax) OverWorldMenuData->ItemData.ItemSelected = (StolarOverWorldData->StolarData->ItemData.ItemAmountMax-1);
}
else{
OverWorldMenuData->ItemData.ItemSelected++;
}
}

if(ButtonLegit(ButtonDown, OverWorldMenuData->LogicData.ButtonInputData)){
OverWorldMenuData->ItemData.ItemSelected+=OverWorldMenuData->Loadable->ItemDataLoadable.ItemAmountPerRow;
if(OverWorldMenuData->ItemData.ItemSelected >= StolarOverWorldData->StolarData->ItemData.ItemAmountMax) OverWorldMenuData->ItemData.ItemSelected = (StolarOverWorldData->StolarData->ItemData.ItemAmountMax-1);
}
else if(ButtonLegit(ButtonUp, OverWorldMenuData->LogicData.ButtonInputData)){
if(OverWorldMenuData->ItemData.ItemSelected < OverWorldMenuData->Loadable->ItemDataLoadable.ItemAmountPerRow) OverWorldMenuData->ItemData.ItemSelected = 0;
else OverWorldMenuData->ItemData.ItemSelected-=OverWorldMenuData->Loadable->ItemDataLoadable.ItemAmountPerRow;
}

if(ButtonLegit(ButtonA, OverWorldMenuData->LogicData.ButtonInputData)){
if(!OverWorldMenuConfirmationModeActive(OverWorldMenuData->ItemData.ConfirmationMode) && OverWorldMenuItemUsable(OverWorldMenuData->ItemData.ItemSelected)){
OverWorldMenuConfirmationActivate(OverWorldMenuData->ItemData.ConfirmationMode, OverWorldMenuConfirmUse);
}
else if(!OverWorldMenuConfirmed(OverWorldMenuData->ItemData.ConfirmationMode)){
OverWorldMenuConfirmationDisable(OverWorldMenuData->ItemData.ConfirmationMode);
}
else{
if(OverWorldMenuConfirmationMode(OverWorldMenuData->ItemData.ConfirmationMode) == OverWorldMenuConfirmUse){
OverWorldMenuUseItem[OverWorldMenuData->Loadable->ItemDataLoadable.SingleItemHeaderLoadableData[StolarOverWorldData->StolarData->ItemData.ItemList[OverWorldMenuData->ItemData.ItemSelected]].ItemType](OverWorldMenuUseItemButtonPressed, OverWorldMenuData, TileData, StolarOverWorldData, OverWorldMenuData->ItemData.ItemSelected, StolarOverWorldData->StolarData->ItemData.ItemList[OverWorldMenuData->ItemData.ItemSelected]);
}
else{
OverWorldMenuDeleteItem(OverWorldMenuData, StolarOverWorldData);
}
}
}

if(ButtonLegit(ButtonX, OverWorldMenuData->LogicData.ButtonInputData)){
if(!OverWorldMenuConfirmationModeActive(OverWorldMenuData->ItemData.ConfirmationMode) && OverWorldMenuItemDeletable(OverWorldMenuData->ItemData.ItemSelected)){
OverWorldMenuConfirmationActivate(OverWorldMenuData->ItemData.ConfirmationMode, OverWorldMenuConfirmUse);
}
}

}


#define OverWorldMenuInputAbilityScreenButtonAbilityAssignment(WhichButton, AbilityColor) { \
if(ButtonLegit(WhichButton, OverWorldMenuData->LogicData.ButtonInputData) && OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityHeaderLoadableData[StolarOverWorldData->StolarData->AbilityData.AbilityList[OverWorldMenuData->AbilityData.AbilitySelected]].WhichAbility != NoAbilityIdentifier){ \
StolarOverWorldData->StolarData->Ability[AbilityColor] = OverWorldMenuData->Loadable->AbilityDataLoadable.SingleAbilityHeaderLoadableData[StolarOverWorldData->StolarData->AbilityData.AbilityList[OverWorldMenuData->AbilityData.AbilitySelected]].WhichAbility; \
} \
}

void OverWorldMenuInputAbilityScreen(OverWorldMenuInputActiveScreenArguments){


if(OverWorldMenuData->AbilityData.ActiveAbilitySelectedBoolean){

if((ButtonLegit(ButtonX, OverWorldMenuData->LogicData.ButtonInputData) && OverWorldMenuData->AbilityData.ActiveAbilitySelected == AbilityYellow) || 
(ButtonLegit(ButtonY, OverWorldMenuData->LogicData.ButtonInputData) && OverWorldMenuData->AbilityData.ActiveAbilitySelected == AbilityGreen) || 
(ButtonLegit(ButtonB, OverWorldMenuData->LogicData.ButtonInputData) && OverWorldMenuData->AbilityData.ActiveAbilitySelected == AbilityBlue)){
StolarOverWorldData->StolarData->Ability[OverWorldMenuData->AbilityData.ActiveAbilitySelected] = NoAbilityIdentifier;
}

if(ButtonLegit(ButtonRight, OverWorldMenuData->LogicData.ButtonInputData)){
OverWorldMenuData->AbilityData.ActiveAbilitySelected++;
if(OverWorldMenuData->AbilityData.ActiveAbilitySelected >= AbilityAmount) OverWorldMenuData->AbilityData.ActiveAbilitySelected = AbilityYellow;
}
else if(ButtonLegit(ButtonLeft, OverWorldMenuData->LogicData.ButtonInputData)){
if(OverWorldMenuData->AbilityData.ActiveAbilitySelected == AbilityYellow) OverWorldMenuData->AbilityData.ActiveAbilitySelected = (AbilityAmount-1);
else OverWorldMenuData->AbilityData.ActiveAbilitySelected--;
}

if(ButtonLegit(ButtonDown, OverWorldMenuData->LogicData.ButtonInputData)){
OverWorldMenuData->AbilityData.ActiveAbilitySelectedBoolean = 0;
OverWorldMenuData->AbilityData.AbilitySelected += (((uint8)(OverWorldMenuData->AbilityData.DisplayedAbilitiesUp))*OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityAmountPerRow);
}
else if(ButtonLegit(ButtonUp, OverWorldMenuData->LogicData.ButtonInputData)){
OverWorldMenuData->AbilityData.ActiveAbilitySelectedBoolean = 0;
OverWorldMenuData->AbilityData.AbilitySelected += (((uint8)(OverWorldMenuData->AbilityData.DisplayedAbilitiesDown))*OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityAmountPerRow);
if(OverWorldMenuData->AbilityData.AbilitySelected >=  AbilityAmountMaxOverall) OverWorldMenuData->AbilityData.AbilitySelected-=OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityAmountPerRow;
}

}
else{

OverWorldMenuInputAbilityScreenButtonAbilityAssignment(ButtonX, AbilityYellow);
OverWorldMenuInputAbilityScreenButtonAbilityAssignment(ButtonY, AbilityGreen);
OverWorldMenuInputAbilityScreenButtonAbilityAssignment(ButtonB, AbilityBlue);

if(ButtonLegit(ButtonRight, OverWorldMenuData->LogicData.ButtonInputData)){
OverWorldMenuData->AbilityData.AbilitySelected = (OverWorldMenuData->AbilityData.AbilitySelected+1)%AbilityAmountMaxOverall;
}
else if(ButtonLegit(ButtonLeft, OverWorldMenuData->LogicData.ButtonInputData)){
if(OverWorldMenuData->AbilityData.AbilitySelected == 0) OverWorldMenuData->AbilityData.AbilitySelected = AbilityAmountMaxOverall-1;
else OverWorldMenuData->AbilityData.AbilitySelected--;
}

if(ButtonLegit(ButtonDown, OverWorldMenuData->LogicData.ButtonInputData)){
OverWorldMenuData->AbilityData.AbilitySelected+=OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityAmountPerRow;
if(OverWorldMenuData->AbilityData.AbilitySelected >= AbilityAmountMaxOverall){
OverWorldMenuData->AbilityData.AbilitySelected %= OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityAmountPerRow;
OverWorldMenuData->AbilityData.ActiveAbilitySelectedBoolean = 1;
}
}
else if(ButtonLegit(ButtonUp, OverWorldMenuData->LogicData.ButtonInputData)){

if((OverWorldMenuData->AbilityData.AbilitySelected/OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityAmountPerRow) == 0){
OverWorldMenuData->AbilityData.AbilitySelected %= OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityAmountPerRow;
OverWorldMenuData->AbilityData.ActiveAbilitySelectedBoolean = 1;
}
else OverWorldMenuData->AbilityData.AbilitySelected -= OverWorldMenuData->Loadable->AbilityDataLoadable.AbilityAmountPerRow;

}


}

}

#define OverWorldMenuDivaScreenInputOneDirectionalList(EntrySelected, EntryAmount) { \
if(ButtonLegit(ButtonDown, OverWorldMenuData->LogicData.ButtonInputData)){ \
if(EntrySelected < (EntryAmount-1)) EntrySelected++; \
} \
else if(ButtonLegit(ButtonUp, OverWorldMenuData->LogicData.ButtonInputData)){ \
if(EntrySelected > 0) EntrySelected--; \
} \
}

#define OverWorldMenuDivaScreenSwitchUpAndScrollInput(EntryPositionX, SwitchUpPositionX, EntrySelected, EntrySwitchUp, EntryAmount, DisplayedUp, DisplayedDown, DisplayedDownFinal, ScreenDisplayAmount, DisplayMovementPerSecondY) { \
if(ButtonLegit(ButtonRight, OverWorldMenuData->LogicData.ButtonInputData)){ \
if(EntryPositionX <= SwitchUpPositionX){ \
EntrySwitchUp = EntrySelected; \
EntrySelected = (EntrySelected+1)%EntryAmount; \
EntryPositionX+=ScreenSizeX; \
DisplayedUp = 0.0f; \
DisplayedDown = ScreenDisplayAmount; \
} \
} \
else if(ButtonLegit(ButtonLeft, OverWorldMenuData->LogicData.ButtonInputData)){ \
if(EntryPositionX >= SwitchUpPositionX){ \
EntrySwitchUp = EntrySelected; \
if(EntrySelected == 0) EntrySelected = (EntryAmount-1); \
else EntrySelected--; \
EntryPositionX-=ScreenSizeX; \
DisplayedUp = 0.0f; \
DisplayedDown = ScreenDisplayAmount; \
} \
} \
if(EntryPositionX == 0.0f){ \
if(ButtonLegit(ButtonDown, OverWorldMenuData->LogicData.ButtonInputData)){ \
DisplayedDown+=(DisplayMovementPerSecondY/FrameRate); \
if(DisplayedDown > DisplayedDownFinal) DisplayedDown = DisplayedDownFinal; \
DisplayedUp = DisplayedDown-ScreenDisplayAmount; \
if(DisplayedUp < 0.0f){ DisplayedUp = 0.0f; DisplayedDown = ScreenDisplayAmount;} \
} \
else if(ButtonLegit(ButtonUp, OverWorldMenuData->LogicData.ButtonInputData)){ \
DisplayedUp-=(DisplayMovementPerSecondY/FrameRate); \
if(DisplayedUp < 0.0f) DisplayedUp = 0.0f; \
DisplayedDown = DisplayedUp+ScreenDisplayAmount; \
} \
} \
}


void OverWorldMenuInputDivaScreen(OverWorldMenuInputActiveScreenArguments){

if(!OverWorldMenuData->DivaData.ExpansionTransformationData.Active){

if(OverWorldMenuData->DivaData.ActiveScreenFlags & OverWorldMenuDivaMainScreenActiveFlag){

if(ButtonLegit(ButtonDown, OverWorldMenuData->LogicData.ButtonInputData)){
OverWorldMenuData->DivaData.MainOptionSelected = (OverWorldMenuData->DivaData.MainOptionSelected+1)%OverWorldMenuDivaMainOptionAmount;
}
else if(ButtonLegit(ButtonUp, OverWorldMenuData->LogicData.ButtonInputData)){
if(OverWorldMenuData->DivaData.MainOptionSelected == 0) OverWorldMenuData->DivaData.MainOptionSelected = OverWorldMenuDivaMainOptionAmount-1;
else OverWorldMenuData->DivaData.MainOptionSelected--;
}

if(ButtonLegit(ButtonA, OverWorldMenuData->LogicData.ButtonInputData)){
OverWorldMenuDivaScreenExpandFromTo(OverWorldMenuData, 
OverWorldMenuDivaMainScreenActiveFlag, OverWorldMenuDivaScreenMainOptionParser(OverWorldMenuData->DivaData.MainOptionSelected), 
OverWorldMenuData->Loadable->DivaDataLoadable.MainOptionPositionX, OverWorldMenuData->Loadable->DivaDataLoadable.MainOptionPositionY[OverWorldMenuData->DivaData.MainOptionSelected], 
OverWorldMenuData->Loadable->DivaDataLoadable.MainOptionTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.MainOptionTextureSizeY, 
OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundPositionX, OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundPositionY, 
OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundTextureSizeY);
}

}
else if(OverWorldMenuData->DivaData.ActiveScreenFlags & OverWorldMenuDivaLogScreenActiveFlag){

OverWorldMenuDivaScreenInputOneDirectionalList(OverWorldMenuData->DivaData.LogEntrySelected, OverWorldMenuData->DivaData.LogEntryAmount);

if(ButtonLegit(ButtonA, OverWorldMenuData->LogicData.ButtonInputData)){
OverWorldMenuDivaScreenExpandFromTo(OverWorldMenuData, 
OverWorldMenuDivaLogScreenActiveFlag, OverWorldMenuDivaSingleLogScreenActiveFlag, 
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionBackGroundPositionX, 
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionBackGroundPositionY+(OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionDistanceY*(OverWorldMenuData->DivaData.LogEntrySelected-OverWorldMenuData->DivaData.LogOptionDrawnUp)), 
OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionBackGroundTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.LogOptionBackGroundTextureSizeY, 
OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundPositionX, OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundPositionY, 
OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundTextureSizeY);
OverWorldMenuDivaScreenSingleLogScreenInitiate();
}

}

else if(OverWorldMenuData->DivaData.ActiveScreenFlags & OverWorldMenuDivaSingleLogScreenActiveFlag){

OverWorldMenuDivaScreenSwitchUpAndScrollInput(OverWorldMenuData->DivaData.LogEntryPositionX, OverWorldMenuData->DivaData.LogEntrySwitchUpPositionX, OverWorldMenuData->DivaData.LogEntrySelected, OverWorldMenuData->DivaData.LogEntrySwitchUp, OverWorldMenuData->DivaData.LogEntryAmount, OverWorldMenuData->DivaData.LogEntryActualArrayDisplayedUp, OverWorldMenuData->DivaData.LogEntryActualArrayDisplayedDown, OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayRowAmount[OverWorldMenuData->DivaData.LogEntrySelected], OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayScreenDisplayAmount, OverWorldMenuData->Loadable->DivaDataLoadable.LogEntryActualArrayDisplayMovementPerSecondY);

}
else if(OverWorldMenuData->DivaData.ActiveScreenFlags & OverWorldMenuDivaCharacterScreenActiveFlag){

OverWorldMenuDivaScreenInputOneDirectionalList(OverWorldMenuData->DivaData.CharacterEntrySelected, OverWorldMenuData->DivaData.CharacterEntryAmount);

if(ButtonLegit(ButtonA, OverWorldMenuData->LogicData.ButtonInputData)){
OverWorldMenuDivaScreenExpandFromTo(OverWorldMenuData, 
OverWorldMenuDivaCharacterScreenActiveFlag, OverWorldMenuDivaSingleCharacterScreenActiveFlag, 
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryBackGroundPositionX, 
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryBackGroundPositionY+(OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryDistanceY*(OverWorldMenuData->DivaData.CharacterEntrySelected-OverWorldMenuData->DivaData.CharacterEntryDrawnUp)), 
OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryBackGroundTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.CharacterEntryBackGroundTextureSizeY, 
OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundPositionX, OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundPositionY, 
OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundTextureSizeX, OverWorldMenuData->Loadable->DivaDataLoadable.MainBackGroundTextureSizeY);
OverWorldMenuDivaScreenSingleCharacterScreenInitiate();
}

}
else if(OverWorldMenuData->DivaData.ActiveScreenFlags & OverWorldMenuDivaSingleCharacterScreenActiveFlag){

OverWorldMenuDivaScreenSwitchUpAndScrollInput(OverWorldMenuData->DivaData.CharacterEntryPositionX, OverWorldMenuData->DivaData.CharacterEntrySwitchUpPositionX, OverWorldMenuData->DivaData.CharacterEntrySelected, OverWorldMenuData->DivaData.CharacterEntrySwitchUp, OverWorldMenuData->DivaData.CharacterEntryAmount, OverWorldMenuData->DivaData.CharacterDescriptionDisplayedUp, OverWorldMenuData->DivaData.CharacterDescriptionDisplayedDown, OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionRowAmount[OverWorldMenuData->DivaData.CharacterEntrySelected], OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionScreenDisplayAmount, OverWorldMenuData->Loadable->DivaDataLoadable.CharacterDescriptionDisplayMovementPerSecondY);

}



}

}

void (*OverWorldMenuInputActiveScreen[OverWorldMenuScreenAmount])(OverWorldMenuInputActiveScreenArguments) = 
{
OverWorldMenuInputStatsScreen, 
OverWorldMenuInputMapScreen, 
OverWorldMenuInputItemScreen, 
OverWorldMenuInputAbilityScreen, 
OverWorldMenuInputDivaScreen
};