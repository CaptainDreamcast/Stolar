float TextureTypeMultiplierDispatch(uint32 TextureType){

uint8 ReturnValue;

if((TextureType & PVR_TXRFMT_ARGB4444) || (TextureType & PVR_TXRFMT_ARGB1555) || (PVR_TXRFMT_RGB565)) ReturnValue = 2.0f;
else if(TextureType & PVR_TXRFMT_PAL8BPP) ReturnValue = 1.0f;
else if(TextureType & PVR_TXRFMT_PAL4BPP) ReturnValue = 0.5f;
else {printf("\n\nTextureTypeMultiplierDispatch: Unidentified Type: (%lx)\n", TextureType); ReturnValue = 2.0f;}

return(ReturnValue);
}