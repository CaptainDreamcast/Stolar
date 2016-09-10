void StolarOverWorldCalculateNewValues(TileStruct* TileData, StolarOverWorldStruct* StolarOverWorldData, float PositionX, float StagePositionZ){

float ChangeValue;
uint16 CheckValue;
uint8 Positive;

ChangeValue = StagePositionZ-StolarOverWorldData->StagePositionZ;
if(ChangeValue <= 0){
ChangeValue = -ChangeValue;
Positive = 0;
}
else Positive = 1;


for(CheckValue=0; CheckValue<=((uint16)ChangeValue)-1; CheckValue++){
if(!Positive){
StolarOverWorldData->SpeedX*=TileData->TileHeaderData->SlowDownXPerZ;
StolarOverWorldData->SpeedY*=TileData->TileHeaderData->SlowDownYPerZ;
StolarOverWorldData->PositionY-=TileData->TileHeaderData->SpeedY;
StolarOverWorldData->SizeX*=TileData->TileHeaderData->CharacterShrinkFactorPerZ;
StolarOverWorldData->SizeY*=TileData->TileHeaderData->CharacterShrinkFactorPerZ;
}
else{
StolarOverWorldData->PositionY+=TileData->TileHeaderData->SpeedY;
StolarOverWorldData->SpeedY/=TileData->TileHeaderData->SlowDownYPerZ;
StolarOverWorldData->SpeedX/=TileData->TileHeaderData->SlowDownXPerZ;
StolarOverWorldData->SizeX/=TileData->TileHeaderData->CharacterShrinkFactorPerZ;
StolarOverWorldData->SizeY/=TileData->TileHeaderData->CharacterShrinkFactorPerZ;
}
}

if(!Positive){
StolarOverWorldData->SpeedX*=pow(TileData->TileHeaderData->SlowDownXPerZ, (ChangeValue-CheckValue));
StolarOverWorldData->SpeedY*=pow(TileData->TileHeaderData->SlowDownYPerZ, (ChangeValue-CheckValue));
StolarOverWorldData->PositionY-=TileData->TileHeaderData->SpeedY*(ChangeValue-CheckValue);
StolarOverWorldData->SizeX*=pow(TileData->TileHeaderData->CharacterShrinkFactorPerZ, (ChangeValue-CheckValue));
StolarOverWorldData->SizeY*=pow(TileData->TileHeaderData->CharacterShrinkFactorPerZ, (ChangeValue-CheckValue));
}
else{
StolarOverWorldData->PositionY+=TileData->TileHeaderData->SpeedY*(ChangeValue-CheckValue);
StolarOverWorldData->SpeedY/=pow(TileData->TileHeaderData->SlowDownYPerZ, (ChangeValue-CheckValue));
StolarOverWorldData->SpeedX/=pow(TileData->TileHeaderData->SlowDownXPerZ, (ChangeValue-CheckValue));
StolarOverWorldData->SizeX/=pow(TileData->TileHeaderData->CharacterShrinkFactorPerZ, (ChangeValue-CheckValue));
StolarOverWorldData->SizeY/=pow(TileData->TileHeaderData->CharacterShrinkFactorPerZ, (ChangeValue-CheckValue));
}

StolarOverWorldData->PositionX = PositionX;
StolarOverWorldData->StagePositionZ = StagePositionZ;
StolarOverWorldData->ScreenPositionZ = TileData->TileHeaderData->TileStartZ+((StagePositionZ/TileData->TileHeaderData->TileAbsoluteStageSizeZ)*(TileData->TileHeaderData->TileEndZ-TileData->TileHeaderData->TileStartZ));

}