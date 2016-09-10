#define GameOverScreenBackGroundBuiltUp		(FrameRate/5)
#define GameOverScreenAllBuiltUp		GameOverScreenBackGroundBuiltUp+(FrameRate/5)

uint8 PrintGameOverScreen(GraphicalUserInterFaceStruct* GraphicalUserInterFaceData){

maple_device_t *cont;
cont_state_t *st;

TransformationStruct TransformationData;

uint8 ButtonInputAllowed[ButtonAmount];
uint8 ReturnValue;
char OptionSelected;
short Ticks;
float AlphaValueBackGround, AlphaValueText;
float ScaleValueSelected, ScaleValueChangeValue;
float MovementBackGround;
char BackGroundColor;


for(ReturnValue = 0; ReturnValue<ButtonAmount; ReturnValue++) ButtonInputAllowed[ReturnValue] = 0;
AlphaValueText = 0.0f;
AlphaValueBackGround = 0.0f;
ScaleValueSelected = 1.0f;
MovementBackGround = 0.0f;
Ticks = 0;
OptionSelected = 0;
ReturnValue = 0;
BackGroundColor = WhiteColor;

while(!ReturnValue){

pvr_wait_ready();
pvr_scene_begin();
pvr_list_begin(PVR_LIST_TR_POLY);

DrawGameOverScreenBackGround(GraphicalUserInterFaceData, AlphaValueBackGround, &MovementBackGround, &BackGroundColor, &TransformationData);
DrawGameOverScreenOptions(GraphicalUserInterFaceData, AlphaValueText, OptionSelected, &ScaleValueSelected, &ScaleValueChangeValue, &TransformationData);

pvr_list_finish();
pvr_scene_finish();

if(Ticks <= GameOverScreenAllBuiltUp){

if(Ticks < GameOverScreenBackGroundBuiltUp) AlphaValueBackGround = Ticks/(float)GameOverScreenBackGroundBuiltUp;
else AlphaValueBackGround = 1.0f;

if(Ticks < GameOverScreenBackGroundBuiltUp) AlphaValueText = 0.0f;
else if(Ticks < GameOverScreenAllBuiltUp) AlphaValueText = (Ticks-GameOverScreenBackGroundBuiltUp)/(float)(GameOverScreenAllBuiltUp-GameOverScreenBackGroundBuiltUp);
else AlphaValueText = 1.0f;

Ticks++;
}

if((cont = maple_enum_dev(0, 0)) == NULL){
st = (cont_state_t *)maple_dev_status(cont);

if((((st->buttons & CONT_A) && ButtonInputAllowed[ButtonA]) || ((st->buttons & CONT_START) && ButtonInputAllowed[ButtonStart])) && !(OptionSelected & GameOverScreenOptionSelectedFlag)){
if(Ticks < GameOverScreenBackGroundBuiltUp) Ticks = GameOverScreenBackGroundBuiltUp;
else if(Ticks < GameOverScreenAllBuiltUp) Ticks = GameOverScreenAllBuiltUp;
else{
OptionSelected |= GameOverScreenOptionSelectedFlag;
}

if(st->buttons & CONT_A) ButtonInputAllowed[ButtonA] = 0;
else ButtonInputAllowed[ButtonStart] = 0;
}
if(!(st->buttons & CONT_A) && !ButtonInputAllowed[ButtonA]) ButtonInputAllowed[ButtonA] = 1;
if(!(st->buttons & CONT_START) && !ButtonInputAllowed[ButtonStart]) ButtonInputAllowed[ButtonStart] = 1;


if((st->buttons & CONT_B) && ButtonInputAllowed[ButtonB] && !(OptionSelected & GameOverScreenOptionSelectedFlag)){
OptionSelected = 0;
ButtonInputAllowed[ButtonB] = 0;
}
if(!(st->buttons & CONT_B) && !ButtonInputAllowed[ButtonB]) ButtonInputAllowed[ButtonB] = 1;


if((st->buttons & CONT_DPAD_UP) && ButtonInputAllowed[ButtonUp] && !(OptionSelected & GameOverScreenOptionSelectedFlag)){
OptionSelected--;
if(OptionSelected < 0) OptionSelected+=GameOverScreenOptionAmount;
ScaleValueSelected = 1.0f;
ButtonInputAllowed[ButtonUp] = 0;
}
if(!(st->buttons & CONT_DPAD_UP) && !ButtonInputAllowed[ButtonUp]) ButtonInputAllowed[ButtonUp] = 1;


if((st->buttons & CONT_DPAD_DOWN) && ButtonInputAllowed[ButtonDown] && !(OptionSelected & GameOverScreenOptionSelectedFlag)){
OptionSelected++;
if(OptionSelected >= GameOverScreenOptionAmount) OptionSelected-=GameOverScreenOptionAmount;
ScaleValueSelected = 1.0f;
ButtonInputAllowed[ButtonDown] = 0;
}
if(!(st->buttons & CONT_DPAD_DOWN) && !ButtonInputAllowed[ButtonDown]) ButtonInputAllowed[ButtonDown] = 1;


}




}
return(ReturnValue);
}