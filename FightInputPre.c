void FightInputPre(FightStruct* FightData, OverWorldStruct* OverWorldData){
maple_device_t* Controller;

if((Controller = maple_enum_dev(0, 0)) == NULL){
SetControllerToDummy(OverWorldData->LogicData.Input.st);
} 
else OverWorldData->LogicData.Input.st = (cont_state_t *)maple_dev_status(Controller);
CheckControllerLegitimacy(OverWorldData->LogicData.Input.ButtonInputData, OverWorldData->LogicData.Input.st);

}