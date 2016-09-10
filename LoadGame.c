


#define LoadGameConfirmNo						0
#define LoadGameConfirmYes					1

#define LoadGameConfirmPositionBits			0x1
#define LoadGameConfirmPositionBitPosition	(BitsPerByte-1)
#define LoadGameConfirmPositionMask			(LoadGameConfirmPositionBits<<LoadGameConfirmPositionBitPosition)

#define LoadGameGetConfirmPosition(x)		((x & LoadGameConfirmPositionMask) >> LoadGameConfirmPositionBitPosition)
#define LoadGameSetConfirmPosition(x, what)	{((x &= (~LoadGameConfirmPositionMask))); (x |= ((what & LoadGameConfirmPositionBits) << LoadGameConfirmPositionBitPosition));}

uint8 LoadGame(void** TransitionData){

maple_device_t *cont;
cont_state_t *st;

LoadScreenBackGroundStruct LoadScreenBackGroundData;
LoadScreenControllerStruct LoadScreenControllerData[DreamcastControllerAmount]; 

uint8 ReturnValue, ReadyToRock;
uint8 WhichPort, WhichSlot;
uint8 SpecialOptionSelected;
uint8 DirtyDeedsDoneDirtCheap;
uint8 ButtonInputAllowed[ButtonAmount];
short WhichSave;

LoadGameInitiate(&LoadScreenBackGroundData, LoadScreenControllerData, &WhichPort, &WhichSlot, &SpecialOptionSelected ,&WhichSave);

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap<ButtonAmount; DirtyDeedsDoneDirtCheap++) ButtonInputAllowed[DirtyDeedsDoneDirtCheap] = 0;
WhichSave = LoadGameNoSaveSelected;
ReadyToRock = LoadGameRock;
ReturnValue = 0;
while(ReadyToRock){


StreamingLoad(StreamingLoadStandardMagicValue);
LoadGameCheckAccessories(LoadScreenControllerData, &WhichPort, &WhichSlot, &SpecialOptionSelected);
ReadyToRock = LoadGameDraw(TransitionData, &LoadScreenBackGroundData, LoadScreenControllerData, WhichPort, WhichSlot, WhichSave, SpecialOptionSelected, ReadyToRock);
CheckControllerValidityWithoutSet(st, cont, ControllerPortPlayer1);

if(ReadyToRock != LoadGameRockOver){

if(ButtonPressedLeft(st) && ButtonInputAllowed[ButtonLeft]){

if(SpecialOptionSelected == LoadGameSpecialOptionUnSelected){

DirtyDeedsDoneDirtCheap = 1;
while(DirtyDeedsDoneDirtCheap){
if((WhichPort-1) < 0) {
WhichPort+=(DirtyDeedsDoneDirtCheap-1);
DirtyDeedsDoneDirtCheap = 0;
}
else WhichPort--;

if(!LoadScreenControllerData[WhichPort].Active || (!LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[FirstVisualMemory].Active && !LoadScreenControllerData[SecondVisualMemory].LoadScreenVisualMemoryData[1].Active)) DirtyDeedsDoneDirtCheap++;
else{
if(!LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot].Active) WhichSlot = (WhichSlot+1)%VisualMemoryPerController;
DirtyDeedsDoneDirtCheap = 0;
WhichSave = LoadGameNoSaveSelected;
}
}

}
else{
if(SpecialOptionSelected > 0) SpecialOptionSelected--;
else SpecialOptionSelected = (LoadGameSpecialOptionAmount-1);
}



ButtonInputAllowed[ButtonLeft] = 0;
}
else if(!ButtonPressedLeft(st) && ButtonInputAllowed[ButtonLeft]) ButtonInputAllowed[ButtonLeft] = 1;


if(ButtonPressedRight(st) && ButtonInputAllowed[ButtonRight]){

if(SpecialOptionSelected == LoadGameSpecialOptionUnSelected){
DirtyDeedsDoneDirtCheap = 1;
while(DirtyDeedsDoneDirtCheap){
if((WhichPort+1) >= DreamcastControllerAmount) {
WhichPort-=(DirtyDeedsDoneDirtCheap-1);
DirtyDeedsDoneDirtCheap = 0;
}
else WhichPort++;

if(!LoadScreenControllerData[WhichPort].Active || (!LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[FirstVisualMemory].Active && !LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[SecondVisualMemory].Active)) DirtyDeedsDoneDirtCheap++;
else{
if(!LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot].Active) WhichSlot = (WhichSlot+1)%VisualMemoryPerController;
DirtyDeedsDoneDirtCheap = 0;
WhichSave = LoadGameNoSaveSelected;
}
}
}
else SpecialOptionSelected = ((SpecialOptionSelected+1)%LoadGameSpecialOptionAmount);

ButtonInputAllowed[ButtonRight] = 0;
}
else if(!ButtonPressedRight(st) && !ButtonInputAllowed[ButtonRight]) ButtonInputAllowed[ButtonRight] = 1;


if(ButtonPressedUp(st) && ButtonInputAllowed[ButtonUp]){

if(SpecialOptionSelected == LoadGameSpecialOptionUnSelected){
if(WhichSave == LoadGameNoSaveSelected){
if(WhichSlot > 0 && LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot-1].Active) WhichSlot--;
}
else if(WhichSave > 0) WhichSave--;
}
else if(WhichPort != LoadGameWhichPortUnavailable && WhichSlot != LoadGameWhichSlotUnavailable) SpecialOptionSelected = LoadGameSpecialOptionUnSelected;


ButtonInputAllowed[ButtonUp] = 0;
}
else if(!ButtonPressedUp(st) && !ButtonInputAllowed[ButtonUp]) ButtonInputAllowed[ButtonUp] = 1;


if(ButtonPressedDown(st) && ButtonInputAllowed[ButtonDown]){

if(SpecialOptionSelected == LoadGameSpecialOptionUnSelected){
if(WhichSave == LoadGameNoSaveSelected){
if(WhichSlot < (VisualMemoryPerController-1) && LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot+1].Active) WhichSlot++;
}
else if(WhichSave < (LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot].SaveAmount-1)) WhichSave++;
}
else if(WhichPort != LoadGameWhichPortUnavailable && WhichSlot != LoadGameWhichSlotUnavailable) SpecialOptionSelected = LoadGameSpecialOptionUnSelected;

ButtonInputAllowed[ButtonDown] = 0;
}
else if(!ButtonPressedDown(st) && !ButtonInputAllowed[ButtonDown]) ButtonInputAllowed[ButtonDown] = 1;


if((ButtonPressedA(st) && ButtonInputAllowed[ButtonA]) || (ButtonPressedStart(st) && ButtonInputAllowed[ButtonStart])){

if(SpecialOptionSelected == LoadGameSpecialOptionUnSelected){
if(WhichSave == LoadGameNoSaveSelected){
if(LoadScreenControllerData[WhichPort].LoadScreenVisualMemoryData[WhichSlot].SaveAmount > 0) WhichSave = 0;
}
else{
if(ReadyToRock == LoadGameRockTheDeleteSong) ReadyToRock = LoadGameRockTheDeleteConfirm;
else if(ReadyToRock == LoadGameRock)  ReadyToRock = LoadGameRockTheLoadConfirm;
LoadGameSetConfirmPosition(SpecialOptionSelected, LoadGameConfirmNo);
}

}
else if(SpecialOptionSelected == LoadGameSpecialOptionNewGame){
ReturnValue = StartNewGameStage;
ReadyToRock = LoadGameRockOver;
}
else if(SpecialOptionSelected == LoadGameSpecialOptionDelete){
if(ReadyToRock != LoadGameRockTheDeleteSong) ReadyToRock = LoadGameRockTheDeleteSong;
else ReadyToRock = LoadGameRock;
}
else if(LoadGameGetConfirmPosition(SpecialOptionSelected) == LoadGameConfirmYes){
if(ReadyToRock == LoadGameRockTheLoadConfirm){
LoadGameLoadSingleSaveData(WhichPort, WhichSlot, WhichSave, LoadScreenControllerData);
ReadyToRock = LoadGameRockOver;
ReturnValue = TheGameIsOnStage;
}
else if(ReadyToRock == LoadGameRockTheDeleteConfirm){
LoadGameDeleteSingleSaveData(WhichPort, WhichSlot, WhichSave, LoadScreenControllerData);
ReadyToRock = LoadGameRockTheDeleteSong;
SpecialOptionSelected = LoadGameSpecialOptionUnSelected;
}
}
else if(LoadGameGetConfirmPosition(SpecialOptionSelected) == LoadGameConfirmNo){
if(ReadyToRock == LoadGameRockTheLoadConfirm) ReadyToRock = LoadGameRock;
else if(ReadyToRock == LoadGameRockTheDeleteConfirm) ReadyToRock = LoadGameRockTheDeleteSong;
SpecialOptionSelected = LoadGameSpecialOptionUnSelected;
}


if(ButtonPressedA(st)) ButtonInputAllowed[ButtonA] = 0;
else ButtonInputAllowed[ButtonStart] = 0;
}
if(!ButtonPressedA(st) && !ButtonInputAllowed[ButtonA]) ButtonInputAllowed[ButtonA] = 1;
if(!ButtonPressedStart(st) && !ButtonInputAllowed[ButtonStart]) ButtonInputAllowed[ButtonStart] = 1;


if(ButtonPressedB(st) && ButtonInputAllowed[ButtonB]){

if(ReadyToRock == LoadGameRockTheLoadConfirm) ReadyToRock = LoadGameRock;
else if(ReadyToRock == LoadGameRockTheDeleteConfirm) ReadyToRock = LoadGameRockTheDeleteSong;
else if(WhichSave == LoadGameNoSaveSelected) ReadyToRock = LoadGameRockOut;
else WhichSave = LoadGameNoSaveSelected;

ButtonInputAllowed[ButtonB] = 0;
}
else if(!ButtonPressedB(st) && !ButtonInputAllowed[ButtonB]) ButtonInputAllowed[ButtonB] = 1;

}

if ((st->buttons & (StairWayToHeaven)) == (StairWayToHeaven)){
ReadyToRock = LoadGameRockOver;
ReturnValue |= StairWayToHeavenIdentifier;
}

}


return(ReturnValue);
}