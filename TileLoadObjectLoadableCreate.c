TileObjectLoadableStruct* TileLoadObjectLoadableCreateCrew(TileStruct* TileData, OverWorldStruct* OverWorldData, uint8 WhichCrewMember){
TileObjectLoadableStruct* Loadable;

Loadable = (TileObjectLoadableStruct*)malloc(sizeof(TileObjectLoadableStruct));

Loadable->InstanceAmount = OverWorldData->CrewData[WhichCrewMember].Loadable->General.InstanceAmount;
Loadable->TextureAmount = OverWorldData->CrewData[WhichCrewMember].Loadable->General.TextureAmount;
Loadable->AnimationAmount = OverWorldData->CrewData[WhichCrewMember].Loadable->General.AnimationAmount;

Loadable->TextureSizeX = OverWorldData->CrewData[WhichCrewMember].Loadable->General.TextureSizeX;
Loadable->TextureSizeY = OverWorldData->CrewData[WhichCrewMember].Loadable->General.TextureSizeY;

Loadable->SingleTextureSizeX = OverWorldData->CrewData[WhichCrewMember].Loadable->General.SingleTextureSizeX;
Loadable->SingleTextureSizeY = OverWorldData->CrewData[WhichCrewMember].Loadable->General.SingleTextureSizeY;

Loadable->EventRadius = OverWorldData->CrewData[WhichCrewMember].Loadable->Tile.EventRadius;


return(Loadable);
}

TileObjectInstanceLoadableStruct* TileLoadObjectInstanceLoadableCreatePlayer(TileStruct* TileData, OverWorldStruct* OverWorldData, uint8 WhichCrewMember, uint8 WhichObject, uint8 WhichInstance){
TileObjectInstanceLoadableStruct* Loadable;

Loadable = (TileObjectInstanceLoadableStruct*)malloc(sizeof(TileObjectInstanceLoadableStruct));

Loadable->EventAmount = 0;
Loadable->CurrentFrame = NewFrameStandardValue;
Loadable->CurrentAnimation = PlayerIdleAnimation;

Loadable->MovementType = TileMovementTypePlayerIdentifier;
Loadable->FaceDirection = OverWorldData->CrewData[WhichCrewMember].LogicData.Tile.FaceDirection;

Loadable->PositionX = OverWorldData->CrewData[WhichCrewMember].LogicData.Tile.StartPositionX;
Loadable->StagePositionZ = OverWorldData->CrewData[WhichCrewMember].LogicData.Tile.StartStagePositionZ;

Loadable->SizeX = OverWorldData->CrewData[WhichCrewMember].Loadable->General.SizeX;
Loadable->SizeY = OverWorldData->CrewData[WhichCrewMember].Loadable->General.SizeX;
Loadable->SpeedX = OverWorldData->CrewData[WhichCrewMember].Loadable->General.SpeedX;

Loadable->AnimationFactor = AnimationFactorStandard;

return(Loadable);
}

TileObjectInstanceLoadableStruct* TileLoadObjectInstanceLoadableCreateCrew(TileStruct* TileData, OverWorldStruct* OverWorldData, uint8 WhichCrewMember, uint8 WhichObject, uint8 WhichInstance){
TileObjectInstanceLoadableStruct* Loadable;

Loadable = (TileObjectInstanceLoadableStruct*)malloc(sizeof(TileObjectInstanceLoadableStruct));

Loadable->EventAmount = 0;
Loadable->CurrentFrame = NewFrameStandardValue;
Loadable->CurrentAnimation = PlayerIdleAnimation;

Loadable->MovementType = TileMovementTypeFollowPlayerIdentifier;
Loadable->FaceDirection = OverWorldData->CrewData[WhichCrewMember].LogicData.Tile.FaceDirection;

Loadable->PositionX = OverWorldData->CrewData[WhichCrewMember].LogicData.Tile.StartPositionX;
Loadable->StagePositionZ = OverWorldData->CrewData[WhichCrewMember].LogicData.Tile.StartStagePositionZ;

Loadable->SizeX = OverWorldData->CrewData[WhichCrewMember].Loadable->General.SizeX;
Loadable->SizeY = OverWorldData->CrewData[WhichCrewMember].Loadable->General.SizeX;
Loadable->SpeedX = OverWorldData->CrewData[WhichCrewMember].Loadable->General.SpeedX;

Loadable->AnimationFactor = AnimationFactorStandard;

return(Loadable);
}