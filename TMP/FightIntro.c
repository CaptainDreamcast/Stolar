
#define FightIntroFlipDuration	2

#define FightIntroFlip		0
#define FightIntroAmount	1


uint8 FightFlipStart(pvr_ptr_t* StolarTexture, StolarFightStruct* StolarFightData, FightLocationStruct* FightLocationData, EnemyFightStruct* EnemyFightData, uint8 EnemyAmount, GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, AbilityFightStruct* AbilityFightData){

maple_device_t *cont;
cont_state_t *st;

TransformationStruct TransformationData;

uint8 ReturnValue;
float RotationChangeValue;
uint8 ButtonInputAllowed;

TransformationData.Active = RotateYIdentifier;
TransformationData.PositionVector.x = 320.0f;
TransformationData.PositionVector.y = 240.0f;
TransformationData.PositionVector.z = MiddlePositionZ;
TransformationData.RotationValueY = M_PI/2;
RotationChangeValue = TransformationData.RotationValueY/(FrameRate*FightIntroFlipDuration);

ButtonInputAllowed = 0;
ReturnValue = 0;
while(!ReturnValue){


pvr_wait_ready();
pvr_scene_begin();

pvr_list_begin(PVR_LIST_TR_POLY);

DrawFightBackGround(FightLocationData, &TransformationData);
DrawStolar(StolarTexture[StolarFightData->StolarAnimationData[StolarFightData->CurrentAnimation].TextureOffset+StolarFightData->CurrentFrame], StolarFightData->PositionX, StolarFightData->PositionY, StolarFightData->ScreenPositionZ, StolarFightData->SizeX, StolarFightData->SizeY, &TransformationData);
DrawFightEnemies(EnemyFightData, EnemyAmount, &TransformationData);
DrawFightHealth(StolarFightData, GraphicalUserInterFaceData, &TransformationData);
DrawFightAbilities(GraphicalUserInterFaceData, &TransformationData);

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

TransformationData.RotationValueY -= RotationChangeValue;
if(TransformationData.RotationValueY < 0.0f) ReturnValue |= BoringStage;



}

return(ReturnValue);
}

uint8 (*FightIntro[FightIntroAmount])(pvr_ptr_t* StolarTexture, StolarFightStruct* StolarFightData, FightLocationStruct* FightLocationData, EnemyFightStruct EnemyFightData[], uint8 EnemyAmount, GraphicalUserInterFaceStruct* GraphicalUserInterFaceData, AbilityFightStruct* AbilityFightData) = 
{
FightFlipStart
};



