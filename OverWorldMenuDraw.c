#define OverWorldMenuDraw(TileData, StolarOverWorldData, OverWorldMenuData){ \
 \
OverWorldMenuDrawBackGroundAndFixedShizzle(OverWorldMenuData); \
OverWorldMenuDrawInactiveScreens(OverWorldMenuData); \
(*OverWorldMenuDrawActiveScreen[OverWorldMenuData->LogicData.ActiveScreen])(OverWorldMenuData, StolarOverWorldData); \
 \
}
