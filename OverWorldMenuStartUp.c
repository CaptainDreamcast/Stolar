void OverWorldMenuStartUp(OverWorldMenuStruct* OverWorldMenuData, TileStruct* TileData){

uint8 DirtyDeedsDoneDirtCheap;

OverWorldMenuLoadTextures(OverWorldMenuData);


OverWorldMenuData->LogicData.Stage = OverWorldMenuStageFirst;
OverWorldMenuData->LogicData.CaptureActiveScreen = 0;
OverWorldMenuData->LogicData.ActiveScreenRotationSpeedY = 0.0f;
DeActivateTransformationData((&OverWorldMenuData->LogicData.ActiveScreenTransformationData));
ResetButtonInputData(OverWorldMenuData->LogicData.ButtonInputData, DirtyDeedsDoneDirtCheap);

if(!OverWorldMenuData->MapData.CurrentPositionOnMapInRelationCalculated){
OverWorldMenuMapScreenParseCurrentTileToCurrentPositionOnMapInRelation(OverWorldMenuData, TileData);
}

StartRotationXAdvanced((&OverWorldMenuData->TransformationData), OverWorldMenuData->Loadable->BackGroundStartRotationValue);


}