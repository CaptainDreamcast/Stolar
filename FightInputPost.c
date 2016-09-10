void FightInputPost(FightStruct* FightData, OverWorldStruct* OverWorldData) {
StairWayToHeavenCheck(OverWorldData->LogicData.Input.st,
{
FightExitSet(FightData);
OverWorldExitSet(OverWorldData);
}
);
}
