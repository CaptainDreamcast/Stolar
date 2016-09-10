void SetupVectors(vector_t* FinalVector, float PositionX, float PositionY, float PositionZ, float SizeX, float SizeY){

SetSingleVector(FinalVector[0], PositionX, PositionY, PositionZ);
SetSingleVector(FinalVector[1], PositionX+SizeX, PositionY, PositionZ);
SetSingleVector(FinalVector[2], PositionX, PositionY+SizeY, PositionZ);
SetSingleVector(FinalVector[3], PositionX+SizeX, PositionY+SizeY, PositionZ);

}