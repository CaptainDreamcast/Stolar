void* ComeOutSwingingInitiate(AbilityLoadFunctionArguments){
uint32 CurrentPointerPosition;
ComeOutSwingingStruct* ComeOutSwingingData;
uint8 WhichFrame;

ComeOutSwingingData = (ComeOutSwingingStruct*)malloc(sizeof(ComeOutSwingingStruct));

ComeOutSwingingData->Loadable = (ComeOutSwingingLoadableStruct*)OverWorldCrewFluxAbilityData->Loadable;
CurrentPointerPosition = (((uint32)OverWorldCrewFluxAbilityData->Loadable)+sizeof(ComeOutSwingingLoadableStruct));

LoadSetThisToThatPointer(FightCollisionDetectRectangleStruct2D*, ComeOutSwingingData->FluxData.OffsetData, sizeof(FightCollisionDetectRectangleStruct2D)*ComeOutSwingingData->Loadable->AnimationData.FrameAmount);

ComeOutSwingingData->Texture = (pvr_ptr_t*)malloc(sizeof(pvr_ptr_t)*ComeOutSwingingData->Loadable->AnimationData.FrameAmount);
for(WhichFrame = 0; WhichFrame < ComeOutSwingingData->Loadable->AnimationData.FrameAmount; WhichFrame++){
LoadTextureFromBufferPointer(CurrentPointerPosition, ComeOutSwingingData->Texture[WhichFrame]);
}

ComeOutSwingingData->LogicData.Active = FightLogicSingleActiveNot;
ComeOutSwingingData->LogicData.BoundEnemyProcessedAmount = LogicActiveNot;
ComeOutSwingingData->LogicData.EnemiesHitAlready = ListCreate();
ComeOutSwingingData->LogicData.BoundEnemyList = ListCreate();

return(ComeOutSwingingData);
}

