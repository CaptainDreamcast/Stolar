float TileDistanceSquaredCompareInstances(TileObjectInstanceStruct* MainInstance, TileObjectInstanceStruct* OtherInstance){
return(Vector2DGetDistanceSquared(MainInstance->Loadable->PositionX, MainInstance->LogicData.PositionY, OtherInstance->Loadable->PositionX, OtherInstance->LogicData.PositionY));
}