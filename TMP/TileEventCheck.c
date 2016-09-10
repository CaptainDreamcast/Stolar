

void TileEventCheck(TileStruct* TileData, OverWorldStruct* OverWorldData){

uint8 DirtyDeedsDoneDirtCheap;

if(TileData->LogicData.General.EnableFlags & TileEnableFlagEventCheck){
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<TileData->TileHeaderData->EventAmount; DirtyDeedsDoneDirtCheap++){
if(
TileData->EventData[DirtyDeedsDoneDirtCheap].LogicData.Active && 
(
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->EventType & EventButtonMask) == EventTypeButtonA && ButtonLegit(ButtonA, OverWorldData->LogicData.Input.ButtonInputData)) ||
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->EventType & EventButtonMask) == EventTypeButtonB && ButtonLegit(ButtonB, OverWorldData->LogicData.Input.ButtonInputData)) ||
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->EventType & EventButtonMask) == EventTypeButtonX && ButtonLegit(ButtonX, OverWorldData->LogicData.Input.ButtonInputData)) ||
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->EventType & EventButtonMask) == EventTypeButtonY && ButtonLegit(ButtonY, OverWorldData->LogicData.Input.ButtonInputData)) ||
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->EventType & EventButtonMask) == EventTypeNoButton)
)
){

if(TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->EventType & EventPersonLinkFlag){
TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpLeftValue] = TileData->PersonData[TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->EventObjectLink].Loadable->PositionX-0.5*EventPersonLinkSizeX;
TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[UpLeftValue] = TileData->PersonData[TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->EventObjectLink].Loadable->StagePositionZ-0.5*EventPersonLinkSizeZ;
TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownRightValue] = TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpLeftValue]+EventPersonLinkSizeX;
TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownRightValue] = TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[UpLeftValue]+EventPersonLinkSizeZ;
}

if(
(
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownLeftValue] == TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownLeftValue]) && (TileData->LogicData.Stolar.PositionX > TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownLeftValue])) || 
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownLeftValue] != TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownLeftValue]) && (TileData->LogicData.Stolar.PositionX > (TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpLeftValue]+((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownLeftValue]-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpLeftValue])*((TileData->LogicData.Stolar.StagePositionZ-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[UpLeftValue])/(TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownLeftValue]-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[UpLeftValue]))))))
) &&
(
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownRightValue] == TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownRightValue]) && (TileData->LogicData.Stolar.PositionX < TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownRightValue])) || 
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownRightValue] != TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownRightValue]) && (TileData->LogicData.Stolar.PositionX < (TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpRightValue]+((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownRightValue]-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpRightValue])*((TileData->LogicData.Stolar.StagePositionZ-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[UpRightValue])/(TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownRightValue]-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[UpRightValue]))))))
) &&
(
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpLeftValue] == TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpRightValue]) && (TileData->LogicData.Stolar.StagePositionZ > TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[UpLeftValue])) || 
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpLeftValue] != TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpRightValue]) && (TileData->LogicData.Stolar.StagePositionZ > (TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[UpLeftValue]+((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[UpRightValue]-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[UpLeftValue])*((TileData->LogicData.Stolar.PositionX-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpLeftValue])/(TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpRightValue]-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[UpLeftValue]))))))
) &&
(
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownLeftValue] == TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownRightValue]) && (TileData->LogicData.Stolar.StagePositionZ < TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownLeftValue])) || 
((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownLeftValue] != TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownRightValue]) && (TileData->LogicData.Stolar.StagePositionZ < (TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownLeftValue]+((TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownRightValue]-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->StagePositionZ[DownLeftValue])*((TileData->LogicData.Stolar.PositionX-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownLeftValue])/(TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownRightValue]-TileData->EventData[DirtyDeedsDoneDirtCheap].Loadable->PositionX[DownLeftValue]))))))
)
) {

TileEventActivate(TileData, &TileData->EventData[DirtyDeedsDoneDirtCheap]);

}

}
}
}

}