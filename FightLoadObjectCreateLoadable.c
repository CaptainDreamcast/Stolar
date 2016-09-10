FightObjectLoadableStruct* FightLoadObjectCreateLoadableCrew(FightStruct* FightData, uint8 WhichCrewMember){
FightObjectLoadableStruct* Loadable;

Loadable = (FightObjectLoadableStruct*)malloc(sizeof(FightObjectLoadableStruct));

Loadable->InstanceAmount = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->General.InstanceAmount;

Loadable->TextureAmount = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->General.TextureAmount;
Loadable->AnimationAmount = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->General.AnimationAmount;

Loadable->TextureSizeX = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->General.TextureSizeX;
Loadable->TextureSizeY = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->General.TextureSizeY;
Loadable->SingleTextureSizeX = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->General.SingleTextureSizeX;
Loadable->SingleTextureSizeY = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->General.SingleTextureSizeY;

Loadable->PhysicsType = FightData->OverWorldData->CrewData[WhichCrewMember].Loadable->Fight.PhysicsType;


return(Loadable);
}