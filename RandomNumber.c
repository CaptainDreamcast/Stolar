sint32 RandomNumberInteger(sint32 Start, sint32 End){
srand(timer_ms_gettime64());
return(Start+((rand()%(End-Start))));
}