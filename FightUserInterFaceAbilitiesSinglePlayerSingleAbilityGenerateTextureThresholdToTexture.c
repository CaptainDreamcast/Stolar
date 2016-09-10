/* Linear/iterative twiddling algorithm from Marcus' tatest */
#define TWIDTAB(x) ( (x&1)|((x&2)<<1)|((x&4)<<2)|((x&8)<<3)|((x&16)<<4)| \
	((x&32)<<5)|((x&64)<<6)|((x&128)<<7)|((x&256)<<8)|((x&512)<<9) )
#define TWIDOUT(x, y) ( TWIDTAB((y)) | (TWIDTAB((x)) << 1) )




void FightUserInterFaceAbilitiesSinglePlayerSingleAbilityGenerateTextureThresholdToTexture(void* ThresholdTexture, void* FinalTexture, uint8 Threshold, uint16 w, uint16 h){

uint8 ValueTopLeft, ValueTopRight, ValueDownLeft, ValueDownRight;
int x, y, yout, min, mask;
uint8 * pixels;
uint16 * vtex;

min = ( ((w) < (h)) ? (w) : (h) );
mask = min - 1;

pixels = (uint8*)ThresholdTexture;
vtex = (uint16*)FinalTexture;

for(y = 0; y < h; y += 2) {
yout = y;

for(x = 0; x < w; x += 2) {

ValueTopRight = ( ((pixels[(x + (y * w))]) <= (Threshold)) ? (FightDrawAbilitiesThresholdToTexturePaletteOffsetOpaque) : (FightDrawAbilitiesThresholdToTexturePaletteOffsetTransparent) );
ValueDownRight = ( ((pixels[(x + ((y+1) * w))]) <= (Threshold)) ? (FightDrawAbilitiesThresholdToTexturePaletteOffsetOpaque) : (FightDrawAbilitiesThresholdToTexturePaletteOffsetTransparent) );
ValueTopLeft = ( ((pixels[((x+1) + (y * w))]) <= (Threshold)) ? (FightDrawAbilitiesThresholdToTexturePaletteOffsetOpaque) : (FightDrawAbilitiesThresholdToTexturePaletteOffsetTransparent) );
ValueDownLeft = ( ((pixels[((x+1) + ((y+1) * w))]) <= (Threshold)) ? (FightDrawAbilitiesThresholdToTexturePaletteOffsetOpaque) : (FightDrawAbilitiesThresholdToTexturePaletteOffsetTransparent) );

vtex[(TWIDOUT((x & mask) / 2, (yout & mask) / 2) + (x / min + yout / min)*min * min / 4)] = ((ValueTopRight) | ((ValueDownRight) << 4) | ((ValueTopLeft) << 8) | ((ValueDownLeft) << 12));

}
}

}
