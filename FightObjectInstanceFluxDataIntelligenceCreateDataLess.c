FightObjectInstanceIntelligenceStruct FightObjectInstanceFluxDataIntelligenceCreateDataLess(uint8 IntelligenceType){

FightObjectInstanceIntelligenceStruct ReturnData;

ReturnData.LogicData.IntelligenceType = IntelligenceType;
ReturnData.LogicData.Semaphore = LogicActiveNot;

ReturnData.Buffer = NULL;

return(ReturnData);
}