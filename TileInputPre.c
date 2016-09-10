void TileInputPre(TileStruct* TileData, OverWorldStruct* OverWorldData){
maple_device_t* Controller;
uint8 WhichPlayer;

if((Controller = maple_enum_dev(OverWorldData->LogicData.Player[PlayerMain].General.WhichController, 0)) == NULL){
if(TileData->LogicData.General.EnableFlags & TileEnableFlagMenu) TileInputSetupMenu(TileData);
SetControllerToDummy(OverWorldData->LogicData.Player[PlayerMain].Input.st);
} 
else OverWorldData->LogicData.Player[PlayerMain].Input.st = (cont_state_t *)maple_dev_status(Controller);
CheckControllerLegitimacy(OverWorldData->LogicData.Player[PlayerMain].Input.ButtonInputData, OverWorldData->LogicData.Player[PlayerMain].Input.st);

for(WhichPlayer = PlayerMain+1; WhichPlayer < OverWorldData->LogicData.General.PlayerAmount; WhichPlayer++){
if((Controller = maple_enum_dev(OverWorldData->LogicData.Player[WhichPlayer].General.WhichController, 0)) == NULL){
SetControllerToDummy(OverWorldData->LogicData.Player[WhichPlayer].Input.st);
} 
else OverWorldData->LogicData.Player[WhichPlayer].Input.st = (cont_state_t *)maple_dev_status(Controller);
CheckControllerLegitimacy(OverWorldData->LogicData.Player[WhichPlayer].Input.ButtonInputData, OverWorldData->LogicData.Player[WhichPlayer].Input.st);
}

}