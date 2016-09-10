#define AbsoluteNeutralValue	0

uint32 AbsoluteInteger(sint32 Value){
uint32 ReturnValue;

if(Value >= AbsoluteNeutralValue) ReturnValue = Value;
else ReturnValue = -Value;

return(ReturnValue);
}

float AbsoluteFloat(float Value){
float ReturnValue;

if(Value >= AbsoluteNeutralValue) ReturnValue = Value;
else ReturnValue = -Value;

return(ReturnValue);
}