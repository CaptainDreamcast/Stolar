

void CheckControllerLegitimacy(ButtonInputStruct* ButtonInputData, cont_state_t* st){

CheckSingleControllerLegitimacy(ButtonInputData[ButtonA], ButtonPressedA(st));
CheckSingleControllerLegitimacy(ButtonInputData[ButtonB], ButtonPressedB(st));
CheckSingleControllerLegitimacy(ButtonInputData[ButtonX], ButtonPressedX(st));
CheckSingleControllerLegitimacy(ButtonInputData[ButtonY], ButtonPressedY(st));
CheckSingleControllerLegitimacy(ButtonInputData[ButtonL], ButtonPressedL(st));
CheckSingleControllerLegitimacy(ButtonInputData[ButtonR], ButtonPressedR(st));
CheckSingleControllerLegitimacy(ButtonInputData[ButtonUp], ButtonPressedUp(st));
CheckSingleControllerLegitimacy(ButtonInputData[ButtonDown], ButtonPressedDown(st));
CheckSingleControllerLegitimacy(ButtonInputData[ButtonLeft], ButtonPressedLeft(st));
CheckSingleControllerLegitimacy(ButtonInputData[ButtonRight], ButtonPressedRight(st));
CheckSingleControllerLegitimacy(ButtonInputData[ButtonStart], ButtonPressedStart(st));

}