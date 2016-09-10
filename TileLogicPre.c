void TileLogicPre(TileStruct* TileData, OverWorldStruct* OverWorldData) {

TileLogicFrameInitiate(TileData);
if(TileData->LogicData.General.IntroFlag) TileLogicIntro[((TileLogicIntroStruct*)OverWorldData->FluxData.General.TransitionData)->General.IntroIdentifier](TileData, OverWorldData); 
if(TileData->LogicData.Outro.Active) (*TileLogicOutro[TileData->LogicData.Outro.Identifier])(TileData, OverWorldData); 

}
