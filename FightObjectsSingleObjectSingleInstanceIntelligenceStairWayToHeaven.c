void FightObjectsSingleObjectSingleInstanceIntelligenceStairWayToHeaven(FightObjectsSingleObjectSingleInstanceIntelligenceFunctionArguments){

uint8 WhichPlayer;

WhichPlayer = FightPlayerGetWhichPlayerFromObjectAndInstance(FightData, WhichObject, WhichInstance);

StairWayToHeavenCheck(FightData->OverWorldData->LogicData.Player[WhichPlayer].Input.st,
{
FightExitSet(FightData);
OverWorldExitSet(FightData->OverWorldData);
}
);

}