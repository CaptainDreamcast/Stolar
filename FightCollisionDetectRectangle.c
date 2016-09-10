FightCollisionDetectRectangleStruct2D FightCollisionDetectRectangleCreate2D(float PositionLeftX, float StagePositionUpZ, float PositionRightX, float StagePositionDownZ){
FightCollisionDetectRectangleStruct2D ReturnRectangle;

ReturnRectangle.TopLeft.PositionX = PositionLeftX;
ReturnRectangle.TopLeft.StagePositionZ = StagePositionUpZ;
ReturnRectangle.BottomRight.PositionX = PositionRightX;
ReturnRectangle.BottomRight.StagePositionZ = StagePositionDownZ;

return(ReturnRectangle);
}

uint8 FightCollisionDetectRectangleCheck2D(FightCollisionDetectRectangleStruct2D Rectangle, FightCollisionDetectRectangleStruct2D OtherRectangle){
uint8 ReturnValue;

/*
printf("Rectangle.TopLeft.PositionX: (%f)\n", Rectangle.TopLeft.PositionX);
printf("Rectangle.TopLeft.StagePositionZ: (%f)\n", Rectangle.TopLeft.StagePositionZ);
printf("Rectangle.BottomRight.PositionX: (%f)\n", Rectangle.BottomRight.PositionX);
printf("Rectangle.BottomRight.StagePositionZ: (%f)\n", Rectangle.BottomRight.StagePositionZ);

printf("OtherRectangle.TopLeft.PositionX: (%f)\n", OtherRectangle.TopLeft.PositionX);
printf("OtherRectangle.TopLeft.StagePositionZ: (%f)\n", OtherRectangle.TopLeft.StagePositionZ);
printf("OtherRectangle.BottomRight.PositionX: (%f)\n", OtherRectangle.BottomRight.PositionX);
printf("OtherRectangle.BottomRight.StagePositionZ: (%f)\n", OtherRectangle.BottomRight.StagePositionZ);
*/

if(
(Rectangle.TopLeft.PositionX <= OtherRectangle.BottomRight.PositionX && Rectangle.BottomRight.PositionX >= OtherRectangle.TopLeft.PositionX) &&
(Rectangle.TopLeft.StagePositionZ <= OtherRectangle.BottomRight.StagePositionZ && Rectangle.BottomRight.StagePositionZ >= OtherRectangle.TopLeft.StagePositionZ)
){
ReturnValue = 1;
}
else ReturnValue = 0;

return(ReturnValue);
}