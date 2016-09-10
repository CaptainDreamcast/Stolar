#define TileDrawObjectsClassInitiationValue	0
#define TileDrawTransformationDataGeneralAmount	2
#define TileDrawTransformationDataPersonalAmount	2

void TileDrawObjects(TileStruct* TileData, OverWorldStruct* OverWorldData){

TransformationStruct GeneralTransformationData, PersonalTransformationData;
uint32 ClassLast;
uint16 WhichEntry;
uint8 DirtyDeedsDoneDirtCheap, BurningDownTheHouse, WhichTexture;

ClassLast = TileDrawObjectsClassInitiationValue;

for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < TileData->LogicData.General.ObjectAmount; DirtyDeedsDoneDirtCheap++){

if(((uint32)TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData) != ClassLast) {
if(!TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData->LogicData.Draw){
ClassLast = ((uint32)TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData);
while(((uint32)TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData) == ClassLast && DirtyDeedsDoneDirtCheap < TileData->LogicData.General.ObjectAmount){
DirtyDeedsDoneDirtCheap++;
}
if(DirtyDeedsDoneDirtCheap == TileData->LogicData.General.ObjectAmount) break;
}

GeneralTransformationData = CombineMultipleTransformationData(TileDrawTransformationDataGeneralAmount, &TileData->LogicData.General.TransformationData, &TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData->LogicData.TransformationData);
ClassLast = ((uint32)TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData);
}

for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->InstanceAmount; BurningDownTheHouse++){
if(TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Active && TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Draw){

WhichEntry = (TileData->ObjectData[DirtyDeedsDoneDirtCheap].AnimationData[TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->CurrentAnimation].TextureOffset+TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->CurrentFrame);
WhichTexture = ((WhichEntry)/((TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeX/TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->SingleTextureSizeX)*(TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeY/TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->SingleTextureSizeY)));

PersonalTransformationData = CombineMultipleTransformationData(TileDrawTransformationDataPersonalAmount, &GeneralTransformationData, &TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.TransformationData);
TextureAtlasDrawWithReverseSimplest(
WhichEntry,
&PersonalTransformationData, 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].Texture[WhichTexture], 
TileObjectFetchLeftPositionScreenX(TileData, DirtyDeedsDoneDirtCheap, BurningDownTheHouse), 
TileObjectFetchTopPositionScreenY(TileData, DirtyDeedsDoneDirtCheap, BurningDownTheHouse), 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.ScreenPositionZ, 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.SizeX, 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.SizeY, 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeX, TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeY, 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->SingleTextureSizeX, TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->SingleTextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY, 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->FaceDirection
);
}
}

}


ClassLast = TileDrawObjectsClassInitiationValue;
for(DirtyDeedsDoneDirtCheap = 0; DirtyDeedsDoneDirtCheap < TileData->LogicData.General.ObjectAmount; DirtyDeedsDoneDirtCheap++){

if(((uint32)TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData) != ClassLast) {
if(!TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData->LogicData.Animate){
ClassLast = ((uint32)TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData);
while(((uint32)TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData) == ClassLast && DirtyDeedsDoneDirtCheap < TileData->LogicData.General.ObjectAmount){
DirtyDeedsDoneDirtCheap++;
}
if(DirtyDeedsDoneDirtCheap == TileData->LogicData.General.ObjectAmount) break;
}

ClassLast = ((uint32)TileData->ObjectData[DirtyDeedsDoneDirtCheap].ClassData);
}

for(BurningDownTheHouse = 0; BurningDownTheHouse < TileData->ObjectData[DirtyDeedsDoneDirtCheap].Loadable->InstanceAmount; BurningDownTheHouse++){
if(TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Active && TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Animate){

TileAnimateWithAnimationFactor(TileData->ObjectData[DirtyDeedsDoneDirtCheap].AnimationData, 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].LogicData.Ticks, 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->AnimationFactor, 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->CurrentFrame, 
TileData->ObjectData[DirtyDeedsDoneDirtCheap].Instance[BurningDownTheHouse].Loadable->CurrentAnimation);

}
}

}



}