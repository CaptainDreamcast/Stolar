#define TileDrawEnemiesTransformationDataGeneralAmount		2
#define TileDrawEnemiesTransformationDataPersonalAmount		2

#define TileDrawEnemiesResetAnimation(CurrentAnimation){ \
CurrentAnimation = EnemyIdleAnimation; \
}


#define DrawOverWorldEnemyType(Amount, NormalEnemyData, WhichTexture, NormalEnemies, TileDrawFlag, TileAnimationFlag) { \
 \
if(TileData->LogicData.General.DrawFlags & TileDrawFlag){ \
GeneralTransformationData = CombineMultipleTransformationData(TileDrawEnemiesTransformationDataGeneralAmount, TileData->LogicData.General.TransformationData, TileData->LogicData.NormalEnemies.TransformationData); \
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<Amount; DirtyDeedsDoneDirtCheap++){ \
if(TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Active && TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Draw){ \
PersonalTransformationData = CombineMultipleTransformationData(TileDrawEnemiesTransformationDataPersonalAmount, GeneralTransformationData, TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.TransformationData); \
TextureAtlasDrawSimplest( \
(OverWorldData->Loadable->Enemies.AnimationData[TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->CurrentAnimation].TextureOffset+TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->CurrentFrame), \
&PersonalTransformationData, \
OverWorldData->TextureData.WhichTexture, \
((TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->PositionX-(TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->SizeX/2))-TileData->LogicData.BackGround.StagePositionX), \
((TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->PositionY-TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->SizeY)-TileData->LogicData.BackGround.StagePositionY), \
TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->ScreenPositionZ, \
TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->SizeX, TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->SizeY, \
OverWorldData->Loadable->Enemies.TextureSizeX, OverWorldData->Loadable->Enemies.TextureSizeY, \
OverWorldData->Loadable->Enemies.SingleTextureSizeX, OverWorldData->Loadable->Enemies.SingleTextureSizeY, \
(PVR_TXRFMT_PAL8BPP | PVR_TXRFMT_8BPP_PAL(PalettePositionSprites)), PVR_LIST_TR_POLY); \
} \
} \
} \
 \
if(TileData->LogicData.General.AnimationFlags & TileAnimationFlag){ \
for(DirtyDeedsDoneDirtCheap=0; DirtyDeedsDoneDirtCheap<Amount; DirtyDeedsDoneDirtCheap++){ \
if(TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Active && TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Animate){ \
AnimateWithAnimationFactor(TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].LogicData.Ticks, \
OverWorldData->Loadable->Enemies.AnimationData[TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->CurrentAnimation].AnimationDurationInSeconds, \
TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->AnimationFactor, \
TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->CurrentFrame, \
OverWorldData->Loadable->Enemies.AnimationData[TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->CurrentAnimation].FrameAmount, \
{ \
TileDrawEnemiesResetAnimation(TileData->NormalEnemyData[DirtyDeedsDoneDirtCheap].Loadable->CurrentAnimation); \
} \
); \
} \
} \
} \
 \
}


void TileDrawEnemies(TileStruct* TileData, OverWorldStruct* OverWorldData){

TransformationStruct GeneralTransformationData, PersonalTransformationData;
uint8 DirtyDeedsDoneDirtCheap;

DrawOverWorldEnemyType(TileData->TileHeaderData->NormalEnemyAmount, NormalEnemyData, NormalEnemy, NormalEnemies, TileDrawFlagNormalEnemies, TileAnimationFlagNormalEnemies);
DrawOverWorldEnemyType(TileData->TileHeaderData->SpecialEnemyAmount, SpecialEnemyData, SpecialEnemy, SpecialEnemies, TileDrawFlagSpecialEnemies, TileAnimationFlagSpecialEnemies);

}