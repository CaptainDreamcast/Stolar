void TileMovement(TileStruct* TileData, OverWorldStruct* OverWorldData){

uint8 WhichObject, WhichInstance;

for(WhichObject = 0; WhichObject < TileData->LogicData.General.ObjectAmount; WhichObject++){
for(WhichInstance = 0; WhichInstance < TileData->ObjectData[WhichObject].Loadable->InstanceAmount; WhichInstance++){
if(!TileData->ObjectData[WhichObject].Instance[WhichInstance].LogicData.MoveNot){
(*TileMovementType[TileData->ObjectData[WhichObject].Instance[WhichInstance].Loadable->MovementType])(TileData, OverWorldData, WhichObject, WhichInstance);
}
}
}

}