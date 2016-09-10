#define ScanLineDuration 2
#define DistortionDuration 1

uint8 FightPause(GraphicalUserInterFaceStruct* GraphicalUserInterFaceData){

maple_device_t *cont;
cont_state_t *st;

pvr_ptr_t BackGroundTexture;
PauseStruct PauseData;

uint8 ButtonInputAllowed;
uint8 ReturnValue;

PauseData.ScanLinePositionY = ScreenSizeY;
PauseData.ScanLineEndPositionY = -ScreenSizeY/2;
PauseData.ScanLineSpeedY = (ScreenSizeY*1.5)/(FrameRate*ScanLineDuration);

PauseData.DistortionPositionX = 0;
PauseData.DistortionSpeedX = (DistortionTextureSizeX-1)/(FrameRate*DistortionDuration);

PauseData.TwitchTicks = 0;
PauseData.FlipTicks = 0;

pvr_wait_ready();
BackGroundTexture = FrameBufferToTexture();

ButtonInputAllowed = 0;
ReturnValue = 0;
while(!ReturnValue){

pvr_wait_ready();
pvr_scene_begin();
pvr_list_begin(PVR_LIST_TR_POLY);

DrawFrame(BackGroundTexture, 1024, 512);
DrawPauseScreen(GraphicalUserInterFaceData, &PauseData);

pvr_list_finish();
pvr_scene_finish();


if((cont = maple_enum_dev(0, 0)) != NULL){
st = (cont_state_t *)maple_dev_status(cont);
if ((st->buttons & (StairWayToHeaven)) == (StairWayToHeaven)) ReturnValue |= StairWayToHeavenIdentifier;
else if((st->buttons & CONT_START) && ButtonInputAllowed) ReturnValue = BoringStage;

if(!(st->buttons & CONT_START) && !ButtonInputAllowed) ButtonInputAllowed = 1;
}

}

pvr_mem_free(BackGroundTexture);
return(ReturnValue);
}