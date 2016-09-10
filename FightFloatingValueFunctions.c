#define FightDamageNeutralValue	0

float FightFloatingValueScaleSize(FightStruct* FightData, OverWorldStruct* OverWorldData, sint16 Value){
return(InterPolationInteger(AbsoluteInteger(Value), &OverWorldData->Loadable->Fight.UserInterFace.FloatingValues.InterPolation));
}

FightFloatingValueStruct* FightFloatingValueNew(FightStruct* FightData, OverWorldStruct* OverWorldData, sint16 Value, float NewPositionX, float NewPositionY, float NewScreenPositionZ){
FightFloatingValueStruct* FloatingValue;
FloatingValue = (FightFloatingValueStruct*)malloc(sizeof(FightFloatingValueStruct));

FloatingValue->LogicData.Stage = FightFloatingValueStageBuildUp;
if(Value <= FightDamageNeutralValue) FloatingValue->LogicData.Color = RedColor;
else FloatingValue->LogicData.Color = GreenColor;
FloatingValue->LogicData.Ticks = NewTicksStandardValue;

FloatingValue->LogicData.AlphaValue = NoColorFloatValue;

FloatingValue->LogicData.PositionX = NewPositionX;
FloatingValue->LogicData.PositionY = NewPositionY;
FloatingValue->LogicData.ScreenPositionZ = NewScreenPositionZ;

FloatingValue->LogicData.FontSizeX = FightFloatingValueScaleSize(FightData, OverWorldData, Value);
FloatingValue->LogicData.FontSizeY = FightFloatingValueScaleSize(FightData, OverWorldData, Value);

if(Value <= FightDamageNeutralValue) sprintf(FloatingValue->FluxData.Array, "-%d", -Value);
else sprintf(FloatingValue->FluxData.Array, "+%d", Value);

return(FloatingValue);
}