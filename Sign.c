sint8 SignFloat(float Value){
sint8 ReturnValue;

if(Value >= AbsoluteNeutralValue) ReturnValue = FactorPositive;
else ReturnValue = FactorNegative;

return(ReturnValue);
}