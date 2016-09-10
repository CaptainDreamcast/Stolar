float FightDistanceSquaredCompareInstances(FightObjectInstanceStruct* MainInstance, FightObjectInstanceStruct* OtherInstance){
return(Vector2DGetDistanceSquared(MainInstance->Loadable->PositionX, MainInstance->Loadable->PositionY, OtherInstance->Loadable->PositionX, OtherInstance->Loadable->PositionY));
}