void OverWorldMenuDrawInactiveScreens(OverWorldMenuStruct* OverWorldMenuData){

uint8 DirtyDeedsDoneDirtCheap;
TransformationStruct TransformationData;
vector_t FinalVector[PolygonCornerAmount];


SetTransformationDataPositionVector((&TransformationData), OverWorldMenuData->Loadable->ActiveScreenPositionX+(OverWorldMenuData->Loadable->ActiveScreenSizeX/2), OverWorldMenuData->Loadable->ActiveScreenPositionX+(OverWorldMenuData->Loadable->ActiveScreenSizeY/2), OverWorldMenuData->Loadable->ActiveScreenPositionZ+(OverWorldMenuData->Loadable->ScreenDepthZ/2))
StartRotationYAdvanced((&TransformationData), OverWorldMenuData->LogicData.ActiveScreenTransformationData.RotationValueY+(FullRotationValue/OverWorldMenuScreenAmount));
DirtyDeedsDoneDirtCheap =  (OverWorldMenuData->LogicData.ActiveScreen+1)%OverWorldMenuScreenAmount;
do{

SetupVectors(FinalVector, OverWorldMenuData->Loadable->ActiveScreenPositionX, OverWorldMenuData->Loadable->ActiveScreenPositionY, OverWorldMenuData->Loadable->ActiveScreenPositionZ, OverWorldMenuData->Loadable->ActiveScreenSizeX, OverWorldMenuData->Loadable->ActiveScreenSizeY);
Transformation(FinalVector, &TransformationData);

DrawVectorTexturePlus(
FinalVector, OverWorldMenuData->InactiveScreenTextures[DirtyDeedsDoneDirtCheap], OverWorldMenuInactiveScreenFormat, PVR_LIST_TR_POLY, 
OverWorldMenuData->Loadable->InactiveScreenTextureSizeX, 
OverWorldMenuData->Loadable->InactiveScreenTextureSizeY, 
1.0f, 1.0f, 1.0f, 1.0f, OverWorldMenuData->Loadable->InactiveScreenLeft, OverWorldMenuData->Loadable->InactiveScreenRight, OverWorldMenuData->Loadable->InactiveScreenUp, OverWorldMenuData->Loadable->InactiveScreenDown);

TransformationData.RotationValueY += (FullRotationValue/OverWorldMenuScreenAmount);
DirtyDeedsDoneDirtCheap = (DirtyDeedsDoneDirtCheap+1)%OverWorldMenuScreenAmount;
} while(DirtyDeedsDoneDirtCheap != OverWorldMenuData->LogicData.ActiveScreen);

}