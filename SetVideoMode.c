
uint8 SetVideoModeAndFrameRate()
{
uint8 ReturnValue;

ReturnValue = ReturnValueNothingUnusual;
while(vid_check_cable() == CT_NONE);
if(vid_check_cable() == CT_VGA){SetVideoModeNeverForget(SixtyHertz, StolarSixtyHertzVideoGangsterAdapterMode);}
else{
if(flashrom_get_region() == FLASHROM_REGION_EUROPE){
FrameRate = HertzSelectScreen();
if(FrameRate == StairWayToHeavenIdentifier) ReturnValue = StairWayToHeavenIdentifier;
else if(FrameRate == SixtyHertz) vid_set_mode(StolarSixtyHertzCableMode, StolarPixelMode);
else vid_set_mode(StolarFiftyHertzCableMode, StolarPixelMode);
}
else {SetVideoModeNeverForget(SixtyHertz, StolarSixtyHertzCableMode)}
}

return(ReturnValue);
}
 