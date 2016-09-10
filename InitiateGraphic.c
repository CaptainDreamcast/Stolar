uint8 InitiateGraphic() { 
uint8 ReturnValue;

InitiatePowerVR(); 

if(SetVideoModeAndFrameRate() == StairWayToHeavenIdentifier) ReturnValue = StairWayToHeavenIdentifier;
else{
PalettesInitiate();
FontInitiate(); 
ReturnValue = ReturnValueNothingUnusual; 
}

return(ReturnValue);
}
