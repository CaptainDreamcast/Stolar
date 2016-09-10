uint8 FightEscalation(pvr_ptr_t* StolarTexture, StolarFightStruct* StolarFightData, FightLocationStruct* FightLocationData, EnemyFightStruct* EnemyFightData, uint8 EnemyAmount, GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, AbilityFightStruct* AbilityFightData){

maple_device_t *cont;
cont_state_t *st;

EscalationStruct EscalationData;

uint8 ReturnValue;
uint8 ButtonInputAllowed;
uint8 FlashToWhite, Escalation;
float WhiteFlashTransparencyValue, WhiteFlashTransparencyChangeValue;

WhiteFlashTransparencyValue = 0.0f;
WhiteFlashTransparencyChangeValue = 0.2f;

EscalationData.PositionX[ImminentTextureIdentifier] = -EscalationTextureSizeX;
EscalationData.PositionX[EscalationTextureIdentifier] = ScreenSizeX;
EscalationData.PositionY[ImminentTextureIdentifier] = EscalationTexturePositionY;
EscalationData.PositionY[EscalationTextureIdentifier] = EscalationTexturePositionY+(EscalationTextureSizeY/2);
EscalationData.SpeedX = (((ScreenSizeX/2)-(FrameRate/2)) - EscalationData.PositionX[ImminentTextureIdentifier])/(EscalationPrimeDuration*FrameRate);
EscalationData.CurrentFrame = 0;
EscalationData.Ticks = 0;

FlashToWhite = 0;
Escalation = 1;
ButtonInputAllowed = 0;
ReturnValue = 0;
while(!ReturnValue){


pvr_wait_ready();
pvr_scene_begin();

pvr_list_begin(PVR_LIST_TR_POLY);

DrawFightBackGround(FightLocationData, NULL);
DrawStolar(StolarTexture[StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureOffset+StolarFightData->CurrentFrame], StolarFightData->PositionX, StolarFightData->PositionY, StolarFightData->ScreenPositionZ, StolarFightData->SizeX, StolarFightData->SizeY, NULL);
DrawFightEnemies(EnemyFightData, EnemyAmount, NULL);
DrawFightHealth(StolarFightData, GraphicalUserInterFaceData, NULL);
DrawFightAbilities(GraphicalUserInterFaceData, NULL);
if(Escalation){
if((Escalation = DrawFightEscalation(GraphicalUserInterFaceData, &EscalationData)) == 2) FlashToWhite = 1;
}
if(FlashToWhite) ReturnValue |= WhiteFlash(&WhiteFlashTransparencyValue, &WhiteFlashTransparencyChangeValue, EscalationWhiteFlashPositionZ);
pvr_list_finish();
pvr_scene_finish();


FightAnimate(StolarFightData, EnemyFightData, EnemyAmount, FightLocationData, AnimateAll);



if((cont = maple_enum_dev(0, 0)) != NULL){
st = (cont_state_t *)maple_dev_status(cont);
if ((st->buttons & (StairWayToHeaven)) == (StairWayToHeaven)) ReturnValue |= StairWayToHeavenIdentifier;
else if ((st->buttons & CONT_START) && ButtonInputAllowed){ 
if((ReturnValue = FightPause(GraphicalUserInterFaceData)) == BoringStage) ReturnValue = 0;
}

if(!(st->buttons & CONT_START) && !ButtonInputAllowed) ButtonInputAllowed = 1;

}




}

return(ReturnValue);
}