void Transformation(vector_t* FinalVector, TransformationStruct* TransformationData){

uint8 BurningDownTheHouse;

if(TransformationData != NULL && TransformationData->Active){
mat_identity();
mat_translate(TransformationData->PositionVector.x, TransformationData->PositionVector.y, TransformationData->PositionVector.z);

if(TransformationData->Active & ZoomInIdentifier) mat_scale(TransformationData->ScaleValueX, TransformationData->ScaleValueY, 1.0f);
if(TransformationData->Active & RotateXIdentifier) mat_rotate_x(TransformationData->RotationValueX);
if(TransformationData->Active & RotateYIdentifier) mat_rotate_y(TransformationData->RotationValueY);
if(TransformationData->Active & RotateZIdentifier) mat_rotate_z(TransformationData->RotationValueZ);


for(BurningDownTheHouse=0; BurningDownTheHouse<PolygonCornerAmount; BurningDownTheHouse++){

FinalVector[BurningDownTheHouse].x -= TransformationData->PositionVector.x;
FinalVector[BurningDownTheHouse].y -= TransformationData->PositionVector.y;
FinalVector[BurningDownTheHouse].z -= TransformationData->PositionVector.z;

mat_trans_single3(FinalVector[BurningDownTheHouse].x, FinalVector[BurningDownTheHouse].y, FinalVector[BurningDownTheHouse].z);

}
}
}