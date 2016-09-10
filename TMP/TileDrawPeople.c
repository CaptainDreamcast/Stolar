#define TileDrawPeopleTransformationDataGeneralAmount		2
#define TileDrawPeopleTransformationDataPersonalAmount		2

#define TileDrawPeopleResetAnimation()	{}

void TileDrawPeople(TileStruct* TileData, OverWorldStruct* OverWorldData){

TransformationStruct GeneralTransformationData, PersonalTransformationData;
uint8 DirtyDeedsDoneDirtCheap;

if(TileData->LogicData.General.DrawFlags & TileDrawFlagPeople){

GeneralTransformationData = CombineMultipleTransformationData(TileDrawPeopleTransformationDataGeneralAmount, TileData->LogicData.General.TransformationData, TileData->LogicData.People.TransformationData);

for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->PersonAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Active && TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Draw){

PersonalTransformationData = CombineMultipleTransformationData(TileDrawPeopleTransformationDataPersonalAmount, GeneralTransformationData, TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.TransformationData);
TextureAtlasDrawSimplest((TileData->PersonData[DirtyDeedsDoneDirtCheap].AnimationData[TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->CurrentAnimation].TextureOffset+TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->CurrentFrame),
&PersonalTransformationData, 
TileData->PersonData[DirtyDeedsDoneDirtCheap].Texture, 
((TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->PositionX-(TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->SizeX/2))-TileData->LogicData.BackGround.StagePositionX), 
((TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->PositionY-TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->SizeY)-TileData->LogicData.BackGround.StagePositionY), 
TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->ScreenPositionZ, 
TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->SizeX, TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->SizeY, 
TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeX, TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->TextureSizeY, 
TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->SingleTextureSizeX, TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->SingleTextureSizeY, 
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY);

}
}
}


if(TileData->LogicData.General.AnimationFlags & TileAnimationFlagPeople){
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap < TileData->TileHeaderData->PersonAmount; DirtyDeedsDoneDirtCheap++){
if(TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Active && TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Animate){
AnimateWithAnimationFactor(TileData->PersonData[DirtyDeedsDoneDirtCheap].LogicData.Ticks, 
TileData->PersonData[DirtyDeedsDoneDirtCheap].AnimationData[TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->CurrentAnimation].AnimationDurationInSeconds, 
TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->AnimationFactor, 
TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->CurrentFrame, 
TileData->PersonData[DirtyDeedsDoneDirtCheap].AnimationData[TileData->PersonData[DirtyDeedsDoneDirtCheap].Loadable->CurrentAnimation].FrameAmount, 
{
TileDrawPeopleResetAnimation();
}
);
}
}
}


}