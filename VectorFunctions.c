void Vector2DReset(float* MainX, float* MainY){
(*MainX) = DummyValueFloat;
(*MainY) = DummyValueFloat;
}

void Vector2DAdd(float* MainX, float* MainY, float OtherX, float OtherY){
(*MainX) += OtherX;
(*MainY) += OtherY;
}

void Vector2DScale(float* MainX, float* MainY, float ScaleValue){
(*MainX) *= ScaleValue;
(*MainY) *= ScaleValue;
}

float Vector2DGetDistanceSquared(float MainX, float MainY, float OtherX, float OtherY){
return(Square(MainX-OtherX)+Square(MainY-OtherY));
}