#define OverWorldMenuInput(TileData, StolarOverWorldData, OverWorldMenuData){ \
ReadInputAndCheckControllerLegitimacy(OverWorldMenuData->LogicData.ButtonInputData, &OverWorldMenuData->LogicData.st); \
OverWorldMenuInputGeneral(OverWorldMenuData); \
(*OverWorldMenuInputActiveScreen[OverWorldMenuData->LogicData.ActiveScreen])(OverWorldMenuData, TileData, StolarOverWorldData); \
}
