#define CheckBorderNoMovement	0
#define CheckBorderMovement	1

#define CheckForOverWorldBorderPropositionPossible					0
#define CheckForOverWorldBorderPropositionImpossibleNoMovement 	1
#define CheckForOverWorldBorderPropositionImpossibleBlock 			2

#define CheckForOverWorldBorderLayOutBufferParse(PositionX, PositionZ)		(TileData->LayOutBuffer[PositionZ][(PositionX/BitsPerByte)] & (PositionX%BitsPerByte))

uint8 CheckForOverWorldBorderX(TileStruct* TileData, float* PositionX, float* StagePositionZ, float SpeedX){

uint16 LayOutBufferArrayPositionCurrentX;
uint16 LayOutBufferArrayPositionProposedX;
sint16 LayOutBufferArrayPositionCheckX;
uint16 LayOutBufferArrayPositionCurrentZ;

uint8 PropositionImpossible;
uint8 ReturnValue;

LayOutBufferArrayPositionCurrentX = (((TileData->TileHeaderData->LayOutBuffer.LayOutSizeX*BitsPerByte)-1)/((float)(TileData->TileHeaderData->TileAbsoluteSizeX)))*(*PositionX);
LayOutBufferArrayPositionCurrentZ = ((TileData->TileHeaderData->LayOutBuffer.LayOutSizeY-1)/(TileData->TileHeaderData->StagePositionEndZ-TileData->TileHeaderData->StagePositionStartZ))*((*StagePositionZ)-TileData->TileHeaderData->StagePositionStartZ);

if((*PositionX)+SpeedX < 0){ 
LayOutBufferArrayPositionProposedX = 0;
SpeedX = -(*PositionX);
}
else if((*PositionX)+SpeedX >= TileData->TileHeaderData->TileAbsoluteSizeX){ 
LayOutBufferArrayPositionProposedX = (TileData->TileHeaderData->LayOutBuffer.LayOutSizeX*BitsPerByte)-1;
SpeedX = TileData->TileHeaderData->TileAbsoluteSizeX-(*PositionX);
}
else{
LayOutBufferArrayPositionProposedX = (((TileData->TileHeaderData->LayOutBuffer.LayOutSizeX*BitsPerByte)-1)/((float)(TileData->TileHeaderData->TileAbsoluteSizeX)))*((*PositionX)+SpeedX);
}

PropositionImpossible = CheckForOverWorldBorderPropositionPossible;
LayOutBufferArrayPositionCheckX = LayOutBufferArrayPositionCurrentX;
while(
((SpeedX >= 0 && LayOutBufferArrayPositionCheckX <= LayOutBufferArrayPositionProposedX) ||
(SpeedX < 0 && LayOutBufferArrayPositionCheckX >= LayOutBufferArrayPositionProposedX)) &&
!PropositionImpossible){

if(CheckForOverWorldBorderLayOutBufferParse(LayOutBufferArrayPositionCheckX, LayOutBufferArrayPositionCurrentZ)){
if(LayOutBufferArrayPositionCheckX != LayOutBufferArrayPositionCurrentX){
if(SpeedX >= 0) LayOutBufferArrayPositionCheckX--;
else LayOutBufferArrayPositionCheckX++;
PropositionImpossible = CheckForOverWorldBorderPropositionImpossibleBlock;
}
else PropositionImpossible = CheckForOverWorldBorderPropositionImpossibleNoMovement;
}
else if(SpeedX >= 0) LayOutBufferArrayPositionCheckX++;
else LayOutBufferArrayPositionCheckX--;
}

if(PropositionImpossible != CheckForOverWorldBorderPropositionImpossibleNoMovement){

if(PropositionImpossible == CheckForOverWorldBorderPropositionImpossibleBlock){ 
(*PositionX) = (((float)TileData->TileHeaderData->TileAbsoluteSizeX)/((TileData->TileHeaderData->LayOutBuffer.LayOutSizeX*BitsPerByte)-1))*LayOutBufferArrayPositionCheckX;
}
else (*PositionX) += SpeedX;

ReturnValue = CheckBorderMovement;
}
else ReturnValue = CheckBorderNoMovement;

return(ReturnValue);
}

uint8 CheckForOverWorldBorderY(TileStruct* TileData, float* PositionX, float* PositionY, float* ScreenPositionZ, float* StagePositionZ, float BaseSizeX, float* SizeX, float BaseSizeY, float* SizeY, float BaseSpeedX, float* SpeedX, float SpeedZ, TileMovementLogicStruct* TileMovementLogicData){

uint16 LayOutBufferArrayPositionCurrentX;
uint16 LayOutBufferArrayPositionCurrentZ;
uint16 LayOutBufferArrayPositionProposedZ;
sint16 LayOutBufferArrayPositionCheckZ;
uint8 PropositionImpossible;
uint8 ReturnValue;


LayOutBufferArrayPositionCurrentX = (((TileData->TileHeaderData->LayOutBuffer.LayOutSizeX*BitsPerByte)-1)/((float)(TileData->TileHeaderData->TileAbsoluteSizeX)))*(*PositionX);
LayOutBufferArrayPositionCurrentZ = ((TileData->TileHeaderData->LayOutBuffer.LayOutSizeY-1)/(TileData->TileHeaderData->StagePositionEndZ-TileData->TileHeaderData->StagePositionStartZ))*((*StagePositionZ)-TileData->TileHeaderData->StagePositionStartZ);


if((*StagePositionZ)+SpeedZ < TileData->TileHeaderData->StagePositionStartZ){
LayOutBufferArrayPositionProposedZ = 0;
SpeedZ = TileData->TileHeaderData->StagePositionStartZ-(*StagePositionZ);
}
else if((*StagePositionZ)+SpeedZ >= TileData->TileHeaderData->StagePositionEndZ){
LayOutBufferArrayPositionProposedZ = TileData->TileHeaderData->LayOutBuffer.LayOutSizeY-1;
SpeedZ = TileData->TileHeaderData->StagePositionEndZ-(*StagePositionZ);
}
else LayOutBufferArrayPositionProposedZ = ((TileData->TileHeaderData->LayOutBuffer.LayOutSizeY-1)/(TileData->TileHeaderData->StagePositionEndZ-TileData->TileHeaderData->StagePositionStartZ))*(((*StagePositionZ)+SpeedZ)-TileData->TileHeaderData->StagePositionStartZ);

PropositionImpossible = CheckForOverWorldBorderPropositionPossible;
LayOutBufferArrayPositionCheckZ = LayOutBufferArrayPositionCurrentZ;
while(
((SpeedZ >= 0 && LayOutBufferArrayPositionCheckZ <= LayOutBufferArrayPositionProposedZ) ||
(SpeedZ < 0 && LayOutBufferArrayPositionCheckZ >= LayOutBufferArrayPositionProposedZ)) &&
!PropositionImpossible
){

if(CheckForOverWorldBorderLayOutBufferParse(LayOutBufferArrayPositionCurrentX, LayOutBufferArrayPositionCheckZ)){
if(LayOutBufferArrayPositionCheckZ != LayOutBufferArrayPositionCurrentZ){
if(SpeedZ >= 0) LayOutBufferArrayPositionCheckZ--;
else LayOutBufferArrayPositionCheckZ++;
PropositionImpossible = CheckForOverWorldBorderPropositionImpossibleBlock;
}
else PropositionImpossible = CheckForOverWorldBorderPropositionImpossibleNoMovement;
}
else if(SpeedZ >= 0) LayOutBufferArrayPositionCheckZ++;
else LayOutBufferArrayPositionCheckZ--;
}


if(PropositionImpossible != CheckForOverWorldBorderPropositionImpossibleNoMovement){

if(PropositionImpossible == CheckForOverWorldBorderPropositionImpossibleBlock){ 
(*StagePositionZ) = ((TileData->TileHeaderData->StagePositionEndZ-TileData->TileHeaderData->StagePositionStartZ)/(TileData->TileHeaderData->LayOutBuffer.LayOutSizeY-1))*LayOutBufferArrayPositionCheckZ;
}
else (*StagePositionZ) += SpeedZ;

TileMovementFunction(TileData, (*StagePositionZ), BaseSpeedX, SpeedX, PositionY, ScreenPositionZ, BaseSizeX, SizeX, BaseSizeY, SizeY, TileMovementLogicData);

ReturnValue = CheckBorderMovement;
}
else ReturnValue = CheckBorderNoMovement;

return(ReturnValue);
}