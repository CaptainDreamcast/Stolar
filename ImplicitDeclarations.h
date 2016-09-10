uint32 zlib_getlength(char FileDir[]);

void memcpy4(void* DestinationBuffer, void* SourceBuffer, uint32 Length);

void snd_init();

void mat_translate(float x, float y, float z);
void mat_scale(float x, float y, float z);
void mat_rotate_x(float x);
void mat_rotate_y(float y);
void mat_rotate_z(float z);

void HandleSingleEvent(ActiveEventStruct* ActiveEventData, TileStruct* TileData, OverWorldStruct* OverWorldData);
void EventHandler(TileStruct* TileData, OverWorldStruct* OverWorldData);
uint8 TileEventActivate(TileStruct* TileData, EventStruct* EventData, uint8 WhichPlayer);

void TileUpdateFlagsActive(TileStruct* TileData, OverWorldStruct* OverWorldData);

time_t rtc_unix_secs();

sfxhnd_t snd_sfx_load_buffer(void* Buffer);

uint8 FightObjectsSingleObjectSingleInstanceBlockage(FightStruct* FightData, uint8 WhichObject, uint8 WhichInstance, float PositionX, float StagePositionZ);