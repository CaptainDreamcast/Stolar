void OverWorldMenuCaptureActiveScreen(OverWorldMenuStruct* OverWorldMenuData, StolarOverWorldStruct* StolarOverWorldData){

uint32 TextureSizeX, TextureSizeY;
uint8 ActiveFlagBuffer;

TextureSizeX = OverWorldMenuData->Loadable->InactiveScreenTextureSizeX;
TextureSizeY = OverWorldMenuData->Loadable->InactiveScreenTextureSizeY;

ActiveFlagBuffer = OverWorldMenuData->LogicData.ActiveScreenTransformationData.Active;
OverWorldMenuData->LogicData.ActiveScreenTransformationData.Active = 0;

pvr_scene_begin_txr(OverWorldMenuData->InactiveScreenTextures[OverWorldMenuData->LogicData.ActiveScreen], &TextureSizeX, &TextureSizeY);
pvr_list_begin(PVR_LIST_TR_POLY);
(*OverWorldMenuDrawActiveScreen[OverWorldMenuData->LogicData.ActiveScreen])(OverWorldMenuData, StolarOverWorldData);
pvr_list_finish();
pvr_scene_finish();

OverWorldMenuData->LogicData.ActiveScreenTransformationData.Active = ActiveFlagBuffer;

}