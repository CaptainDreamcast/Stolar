TileObjectClassStruct* TileLoadClassCreate(){
TileObjectClassStruct* ClassData;

ClassData = (TileObjectClassStruct*)malloc(sizeof(TileObjectClassStruct));
ClassData->LogicData.Draw = LogicActive;
ClassData->LogicData.Animate = LogicActive;
InitiateTransformationData((&ClassData->LogicData.TransformationData));

return(ClassData);
}