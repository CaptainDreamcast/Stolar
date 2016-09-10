uint8 OverWorld(void** TransitionData){
OverWorldStruct OverWorldData;

OverWorldLoad(&OverWorldData, TransitionData);

//
//OverWorldData.LogicData.General.CurrentGamePlay = OverWorldGamePlayFight;
//

while(OverWorldData.LogicData.General.LoopOverWorld){
(*OverWorldDispatch[OverWorldData.LogicData.General.CurrentGamePlay])(&OverWorldData);
}

OverWorldDeLoad(&OverWorldData, TransitionData);

return(OverWorldData.LogicData.General.ReturnStage);
}