

void PalettesInitiate(){

char FileDir[NormalFileDirSize];
uint8 DirtyDeedsDoneDirtCheap;

pvr_set_pal_format(PVR_PAL_ARGB1555);

sprintf(FileDir, "%s/PALETTES/FONTS.pal", FileSystemUsed);
PaletteLoadFromFileFour(FileDir, PalettePositionFonts);

sprintf(FileDir, "%s/PALETTES/SPRITES.pal", FileSystemUsed);
PaletteLoadFromFileEight(FileDir, PalettePositionSprites);

for(DirtyDeedsDoneDirtCheap = YellowAbility; DirtyDeedsDoneDirtCheap < AbilityAmount; DirtyDeedsDoneDirtCheap++){
PaletteInitiateFightAbilityGauge(DirtyDeedsDoneDirtCheap);
}

}