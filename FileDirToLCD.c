void FileDirToLCD(char FileDir[], uint8 Beep){

file_t InputFile;
uint8 VisualDisplayBuffer[FileSizeDRI];
maple_device_t *DisplayAddress;

InputFile = fs_open(FileDir, O_RDONLY);
fs_read(InputFile, VisualDisplayBuffer, FileSizeDRI);
fs_close(InputFile);

DisplayAddress = maple_enum_type(0, MAPLE_FUNC_LCD);
if(DisplayAddress){
vmu_draw_lcd(DisplayAddress, VisualDisplayBuffer);
}

if(Beep){
DisplayAddress = maple_enum_type(0, MAPLE_FUNC_CLOCK);
if(DisplayAddress){
vmu_beep_raw(DisplayAddress, 0x000065f0);
pvr_wait_ready();
vmu_beep_raw(DisplayAddress, 0);
}
}
}
