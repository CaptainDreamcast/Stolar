void CombineTransformationData(TransformationStruct* Output, TransformationStruct* Input){

if(Input->Active & ZoomInIdentifier){
if(Output->Active & ZoomInIdentifier){
Output->ScaleValueX *= Input->ScaleValueX;
Output->ScaleValueY *= Input->ScaleValueY;
}
else{
Output->ScaleValueX = Input->ScaleValueX;
Output->ScaleValueY = Input->ScaleValueY;
}
}

if(Input->Active & RotateXIdentifier){
if(Output->Active & RotateXIdentifier) Output->RotationValueX += Input->RotationValueX;
else Output->RotationValueX = Input->RotationValueX;
}
if(Input->Active & RotateYIdentifier){
if(Output->Active & RotateYIdentifier) Output->RotationValueY += Input->RotationValueY;
else Output->RotationValueY = Input->RotationValueY;
}
if(Input->Active & RotateZIdentifier){
if(Output->Active & RotateZIdentifier) Output->RotationValueZ += Input->RotationValueZ;
else Output->RotationValueZ = Input->RotationValueZ;
}

if(Input->Active) Output->PositionVector = Input->PositionVector;

Output->Active |= Input->Active;
}

TransformationStruct CombineMultipleTransformationData(uint8 Amount, ...){

TransformationStruct TransformationData;
va_list Argument;
uint8 DirtyDeedsDoneDirtCheap;

InitiateTransformationData((&TransformationData));

va_start(Argument, Amount); 
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < Amount;  DirtyDeedsDoneDirtCheap++){
CombineTransformationData(&TransformationData, va_arg(Argument, TransformationStruct*));
}
va_end(Argument);


return(TransformationData);
}