uint8 TileEventCheckButtons(EventStruct* EventData, OverWorldStruct* OverWorldData, uint8 WhichPlayer){
uint8 ReturnValue;

if(
(EventData->Loadable->EventButtons == EventTypeButtonA && ButtonLegit(ButtonA, OverWorldData->LogicData.Player[WhichPlayer].Input.ButtonInputData)) ||
(EventData->Loadable->EventButtons == EventTypeButtonB && ButtonLegit(ButtonB, OverWorldData->LogicData.Player[WhichPlayer].Input.ButtonInputData)) ||
(EventData->Loadable->EventButtons == EventTypeButtonX && ButtonLegit(ButtonX, OverWorldData->LogicData.Player[WhichPlayer].Input.ButtonInputData)) ||
(EventData->Loadable->EventButtons == EventTypeButtonY && ButtonLegit(ButtonY, OverWorldData->LogicData.Player[WhichPlayer].Input.ButtonInputData)) ||
(EventData->Loadable->EventButtons == EventTypeNoButton)
){
ReturnValue = LogicActive;
}
else ReturnValue = LogicActiveNot;

return(ReturnValue);
}