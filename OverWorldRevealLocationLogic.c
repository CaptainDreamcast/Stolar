if(OverWorldInterFaceData->LogicData.RevealTileNameAndLocationPointer == RevealTileNameAndLocationPointerBeforeInitiation){

if(TileData->EntranceData[TileData->WhichEntrance].DisplayTileName) {
if(TileData->EntranceData[TileData->WhichEntrance].DisplayLocation) {
OverWorldInterFaceData->LogicData.RevealTileNameAndLocationPointer = malloc(sizeof(RevealTileNameStruct)+sizeof(RevealLocationStruct));
InitiateRevealLocationData(((RevealLocationStruct*)(OverWorldInterFaceData->LogicData.RevealTileNameAndLocationPointer+sizeof(RevealTileNameStruct))));
}
else {
OverWorldInterFaceData->LogicData.RevealTileNameAndLocationPointer = malloc(sizeof(RevealTileNameStruct));
OverWorldLogicEnableFullFunctionality(OverWorldInterFaceData->LogicData);
}
InitiateRevealTileNameData(((RevealTileNameStruct*)OverWorldInterFaceData->LogicData.RevealTileNameAndLocationPointer));
}
else{
OverWorldInterFaceData->LogicData.RevealTileNameAndLocationPointer = RevealTileNameAndLocationPointerAfterFinishing;
OverWorldLogicEnableFullFunctionality(OverWorldInterFaceData->LogicData);
}
}

if(TileData->EntranceData[TileData->WhichEntrance].DisplayLocation) DrawRevealLocationName(((RevealLocationStruct*)(OverWorldInterFaceData->LogicData.RevealTileNameAndLocationPointer+sizeof(RevealTileNameStruct))));
if(DrawRevealTileName(((RevealTileNameStruct*)OverWorldInterFaceData->LogicData.RevealTileNameAndLocationPointer)) == DrawRevealTileNameOver){
free(OverWorldInterFaceData->LogicData.RevealTileNameAndLocationPointer);
OverWorldInterFaceData->LogicData.RevealTileNameAndLocationPointer = RevealTileNameAndLocationPointerAfterFinishing;
OverWorldInterFaceData->OverWorldLogicData.SuperDrawFlags &= ~OverWorldLogicDrawRevealLocation;

if(TileData->EntranceData[TileData->WhichEntrance].DisplayLocation) {OverWorldLogicEnableFullFunctionality(OverWorldInterFaceData->LogicData);}
}
