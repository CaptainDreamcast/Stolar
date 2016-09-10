FightObjectClassStruct* FightLoadClassCreate(){
FightObjectClassStruct* ClassData;

ClassData = (FightObjectClassStruct*)malloc(sizeof(FightObjectClassStruct));
ClassData->LogicData.Draw = LogicActive;
ClassData->LogicData.Animate = LogicActive;
InitiateTransformationData((&ClassData->LogicData.GeneralTransformationData));

return(ClassData);
}