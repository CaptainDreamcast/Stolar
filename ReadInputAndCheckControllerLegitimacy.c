void ReadInputAndCheckControllerLegitimacy(ButtonInputStruct* ButtonInputData, cont_state_t** st){

maple_device_t *cont;

if((cont = maple_enum_dev(0, 0)) == NULL){
SetControllerToDummy((*st));
} 
else (*st) = (cont_state_t *)maple_dev_status(cont);

CheckControllerLegitimacy(ButtonInputData, (*st));

}