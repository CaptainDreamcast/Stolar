

void TileEventCheck(TileStruct* TileData, OverWorldStruct* OverWorldData){

uint8 WhichPlayer, WhichEvent, WhichObject, WhichInstance;

if(TileData->LogicData.General.EnableFlags & TileEnableFlagEventCheck){
for(WhichPlayer = 0; WhichPlayer < OverWorldData->LogicData.General.PlayerAmount; WhichPlayer++){

for(WhichEvent = 0; WhichEvent < TileData->PlayerData[WhichPlayer].LogicData.EventAmount; WhichEvent++){

if(
BoxCheckIfPointInside(&TileData->PlayerData[WhichPlayer].EventSelfData[WhichEvent].Loadable->Box, TileData->ObjectData[TileData->PlayerData[WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[WhichPlayer].LogicData.WhichInstance].Loadable->PositionX, TileData->ObjectData[TileData->PlayerData[WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[WhichPlayer].LogicData.WhichInstance].Loadable->StagePositionZ) &&
TileEventCheckButtons(&TileData->PlayerData[WhichPlayer].EventSelfData[WhichEvent].EventData, OverWorldData, WhichPlayer)
){
TileEventActivate(TileData, &TileData->PlayerData[WhichPlayer].EventSelfData[WhichEvent].EventData, WhichPlayer);
}
}

for(WhichObject = 0; WhichObject < TileData->LogicData.General.ObjectAmount; WhichObject++){
for(WhichInstance = 0; WhichInstance < TileData->ObjectData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
if(
(WhichObject != TileData->PlayerData[WhichPlayer].LogicData.WhichObject) &&
(TileDistanceSquaredCompareInstances(&TileData->ObjectData[TileData->PlayerData[WhichPlayer].LogicData.WhichObject].Instance[TileData->PlayerData[WhichPlayer].LogicData.WhichInstance], &TileData->ObjectData[WhichObject].Instance[WhichInstance]) < Square(TileData->ObjectData[WhichObject].Loadable->EventRadius))
){
for(WhichEvent = 0; WhichEvent < TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->EventAmount; WhichEvent++){
if(
TileData->ObjectData[WhichObject].Instance[WhichInstance].EventData[WhichEvent].LogicData.Active && 
TileEventCheckButtons(&TileData->ObjectData[WhichObject].Instance[WhichInstance].EventData[WhichEvent], OverWorldData, WhichPlayer)
){
TileEventActivate(TileData, &TileData->ObjectData[WhichObject].Instance[WhichInstance].EventData[WhichEvent], WhichPlayer);
}
}
}
}
}


}
}

}