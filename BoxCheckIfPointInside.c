uint8 BoxCheckIfPointInside(BoxStruct* Box, float PositionX, float PositionY){
uint8 ReturnValue;

if(
(PositionY >= (Box->TopLeft.y+((Box->TopRight.y-Box->TopLeft.y)*((PositionX-Box->TopLeft.x)/(Box->TopRight.x-Box->TopLeft.x))))) &&
(PositionY <= (Box->DownLeft.y+((Box->DownRight.y-Box->DownLeft.y)*((PositionX-Box->DownLeft.x)/(Box->DownRight.x-Box->DownLeft.x))))) &&
(PositionX >= (Box->TopLeft.x+((Box->DownLeft.x-Box->TopLeft.x)*((PositionY-Box->TopLeft.y)/(Box->DownLeft.y-Box->TopLeft.y))))) &&
(PositionX <= (Box->TopRight.x+((Box->DownRight.x-Box->TopRight.x)*((PositionY-Box->TopRight.y)/(Box->DownRight.y-Box->TopRight.y)))))
){
ReturnValue = LogicActive;
}
else ReturnValue = LogicActiveNot;

return(ReturnValue);
}