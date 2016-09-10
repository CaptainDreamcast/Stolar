

#define InterPolationGeneral()	{ \
if(InterPolationData->Type == InterPolationTypeLogarithmic) ReturnValue = InterPolationComputeLogarithmicInterPolation(Value, InterPolationData); \
else if(InterPolationData->Type == InterPolationTypeNegativeQuadratic) ReturnValue = InterPolationComputeNegativeQuadraticInterPolation(Value, InterPolationData); \
else if(InterPolationData->Type == InterPolationTypeQuadratic) ReturnValue = InterPolationComputeQuadraticInterPolation(Value, InterPolationData); \
else if(InterPolationData->Type == InterPolationTypeNegativeLinear) ReturnValue = InterPolationComputeNegativeLinearInterPolation(Value, InterPolationData); \
else{printf("InterPolationInteger: Unknown Type: (%d)\n", InterPolationData->Type); ReturnValue = 0;} \
}

sint32 InterPolationInteger(sint32 Value, InterPolationStruct* InterPolationData){
sint32 ReturnValue;

InterPolationGeneral();

return(ReturnValue);
}

float InterPolationFloat(float Value, InterPolationStruct* InterPolationData){
float ReturnValue;

InterPolationGeneral();

return(ReturnValue);
}