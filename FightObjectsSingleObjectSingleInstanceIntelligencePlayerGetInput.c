void FightObjectsSingleObjectSingleInstanceIntelligencePlayerGetInput(FightObjectsSingleObjectSingleInstanceIntelligenceFunctionArguments){

maple_device_t* Controller;
uint8 WhichPlayer;

WhichPlayer = FightPlayerGetWhichPlayerFromObjectAndInstance(FightData, WhichObject, WhichInstance);

if((Controller = maple_enum_dev(FightData->OverWorldData->LogicData.Player[WhichPlayer].General.WhichController, 0)) == NULL){
SetControllerToDummy(FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st);
} 
else FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st = (cont_state_t *)maple_dev_status(Controller);
CheckControllerLegitimacy(FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.ButtonInputData, FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st);



}