#include <kos.h> 

KOS_INIT_FLAGS(INIT_DEFAULT);

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include <kmg/kmg.h> 
#include <zlib/zlib.h>
#include <oggvorbis/sndoggvorbis.h>

#include "MyDefinitions.h"
#include "MyStructs.h"
#include "MyMacros.h"
#include "ImplicitDeclarations.h"

#define FunFunFun
#define StreamingLoadWorks

// GLOBALS START

char FileSystemUsed[] = "/pc";
uint8 FrameRate = 60;
int VolumeSFX = 255;
int VolumeBGM = 15;

uint8 CurrentPortUsed = 'a';
uint8 CurrentSlotUsed = 1;

pvr_ptr_t WhiteTexture; //REMOVE
cont_state_t DummyControllerState;
SaveStruct SaveData;
FontStruct* FontData;

//GLOBALS END

#include "Square.c"
#include "Absolute.c"
#include "Sign.c"
#include "RandomNumber.c"
#include "InterPolation.c"
#include "VectorFunctions.c"
#include "BoxCheckIfPointInside.c"

#include "FileSystemTest.c"

#include "CountFilesInDirectory.c"
#include "CharArraysAreEqual.c"
#include "FileToBuffer.c"
#include "BufferToFile.c"
#include "CompressedFileToBuffer.c"
#include "DrawTexture.c"
#include "TextureTypeMultiplierDispatch.c"
#include "FillWithRepeatedTexture.c"
#include "SetupVectors.c"
#include "Transformation.c"
#include "CombineTransformationData.c"
#include "TextureAtlasDrawAdvanced.c"
#include "FileExists.c"
#include "FileDirToLCD.c"
#include "SaveGameExists.c"
#include "InitiatePowerVR.c"

#include "ListFunctions.c"
#include "TextureLoadBuffer.c"
#include "TextureLoadKMG.c"
#include "FrameBufferToTexture.c"
#include "FileDirToRomDisk.c"
#include "DrawFrame.c"
#include "StreamingLoad.c"
#include "StreamingLoadTimeCalculate.c"
#include "ThresholdToTexture.c"
#include "FileDirToPalette.c"
#include "DrawSingleLetterToScreen.c"
#include "DrawArrayToScreen.c"
#include "DrawArrayOverLineRepeated.c"
#include "CheckControllerLegitimacy.c"
#include "ReadInputAndCheckControllerLegitimacy.c"
#include "IconListScrollableDraw.c"
#include "AnimateWithAnimationFactor.c"

#include "HertzSelectScreenDeLoad.c"
#include "HertzSelectScreenLoad.c"
#include "HertzSelectScreenInput.c"
#include "HertzSelectScreenDraw.c"
#include "HertzSelectScreen.c"

#include "SetVideoMode.c"

#include "PaletteLoad.c"
#include "PaletteInitiateFightAbilityGauge.c"
#include "PalettesInitiate.c"

#include "FontLoadSingleFile.c"
#include "FontInitiate.c"

#include "SetDummyControllerState.c"

#include "InitiateSound.c"
#include "InitiateGraphic.c"
#include "InitiateGameLogic.c"

#include "ScreenZoomOut.c"
#include "WhiteFlash.c"

#include "quicklz.h"
#include "quicklz.c"
#include "FileFunctions.c"
#include "TextureLoadPKG.h"
#include "StoryBoardFunctions.c"
#include "LetsSeeTheStory.c"

#include "MusicIsPlaying.c"
#include "MusicStop.c"
#include "MusicPlay.c"

#include "FileCopyToOtherFileSystem.c"
#include "SoundPlay.c"

#include "SceneInitiate.c"

/*
#include "FightFloatingValueFunctions.c"

#include "FightStagePositionParseZ.c"
#include "FightMovement.c"

#include "FightCollisionResultMoved.c"
#include "FightCollisionResultDecreaseLife.c"
#include "FightCollisionResultEnemy.c"
#include "FightCollisionResultStolar.c"
#include "FightCollisionDetectRectangle.c"
#include "FightCollisionRegisterAddEnemyToHitAlreadyList.c"


#include "FightCollisionCheckStolar.c"

#include "FightArtificialIntelligencePhysics.c"
#include "FightArtificialIntelligenceFunction.c"

*/




#include "CrewIsPlayer.c"

#include "FightCollisionRegisterAddEnemyToHitAlreadyList.c"
#include "FightCollisionRegisterHit.c"
#include "FightCollisionRegisterEnemyHitAlready.c"
#include "FightCollisionDetectRectangle.c"
#include "FightCollisionCheckPlayerIncreaseAbilities.c"
#include "FightCollisionCheckPlayer.c"
#include "FightCollisionCheckEnemyToPlayerRectangle2D.c"
#include "FightObjectsSingleObjectSingleInstanceDrawOverride.c"
#include "FightObjectsSingleObjectSingleInstanceAnimateOverride.c"

#include "AbilitySingleLoad.c"
#include "ComeOutSwingingInitiate.c"
#include "ComeOutSwingingBoundEnemyLogic.c"
#include "ComeOutSwingingAddNewEnemiesToProcessingAddToProcessingListBoundEnemyDataCreate.c"
#include "ComeOutSwingingAddNewEnemiesToProcessingAddToProcessingListIncludes.c"
#include "ComeOutSwingingAddNewEnemiesToProcessingAddToProcessingList.c"
#include "ComeOutSwingingAddNewEnemiesToProcessing.c"
#include "ComeOutSwinging.c"
#include "AbilityFunction.c"
#include "AbilityLoadFunction.c"

#include "CrewMemberSingleLoad.c"

#include "FightDistanceSquaredCompareInstances.c"
#include "FightFromStagePositionReturnPositionY.c"
#include "FightStagePositionParseZ.c"
#include "FightPlayerGetWhichPlayerFromObjectAndInstance.c"
#include "FightMovementCheckLegitimacy.c"
#include "FightMovement.c"

#include "FightObjectsSingleObjectSingleInstanceBlockageFunction.c"
#include "FightObjectsSingleObjectSingleInstanceBlockage.c"
#include "FightObjectsSingleObjectSingleInstanceDraw.c"
#include "FightObjectsSingleObjectSingleInstanceAnimate.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicPlayer.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceHitLogicEnemy.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineWalkWithBias.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachinePlayerIsInAttackRangeRange.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachinePlayerIsInAttackMeleeRange.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineHit.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineDead.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachineChangeState.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceEnemyStateMachine.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceStairWayToHeaven.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligencePlayerGetInput.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceMovementPlayer.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceForcesToAcceleration.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceAccumulatedDamage.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceAbilities.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligenceFunction.c"
#include "FightObjectsSingleObjectSingleInstanceIntelligence.c"
#include "FightObjectsSingleObjectSingleInstancePhysicsFunction.c"
#include "FightObjectsSingleObjectSingleInstancePhysics.c"
#include "FightObjectsSingleObjectSingleInstance.c"
#include "FightObjectsSingleObjectFunctions.c"
#include "FightObjectsSingleObject.c"
#include "FightObjects.c"
#include "FightBackGroundsSingleObjectSingleInstanceDraw.c"
#include "FightBackGroundsSingleObjectSingleInstanceAnimate.c"
#include "FightBackGroundsSingleObjectSingleInstanceLogic.c"
#include "FightBackGroundsSingleObjectSingleInstance.c"
#include "FightBackGroundsSingleObjectFunctions.c"
#include "FightBackGroundsSingleObject.c"
#include "FightBackGrounds.c"
#include "FightStage.c"
#include "FightUserInterFaceAbilitiesSinglePlayerSingleAbilityDraw.c"
#include "FightUserInterFaceAbilitiesSinglePlayerSingleAbilityGenerateUpdate.c"
#include "FightUserInterFaceAbilitiesSinglePlayerSingleAbilityGenerateTextureThresholdToTexture.c"
#include "FightUserInterFaceAbilitiesSinglePlayerSingleAbilityGenerateTexture.c"
#include "FightUserInterFaceAbilitiesSinglePlayerSingleAbilityGenerateColor.c"
#include "FightUserInterFaceAbilitiesSinglePlayerSingleAbilityGenerate.c"
#include "FightUserInterFaceAbilitiesSinglePlayerSingleAbility.c"
#include "FightUserInterFaceAbilitiesSinglePlayer.c"
#include "FightUserInterFaceAbilities.c"
#include "FightUserInterFaceHealthSinglePlayerDraw.c"
#include "FightUserInterFaceHealthSinglePlayer.c"
#include "FightUserInterFaceHealth.c"
#include "FightUserInterFace.c"
#include "FightDrawFinish.c"
#include "FightDrawStart.c"
#include "FightLoadObjectInstanceCreateFluxDataBlockageDispatch.c"
#include "FightObjectInstanceFluxDataIntelligenceCreateDataLess.c"
#include "FightObjectInstanceFluxDataIntelligenceCreateHitLogicPlayer.c"
#include "FightObjectInstanceFluxDataIntelligenceCreateHitLogicEnemy.c"
#include "FightObjectInstanceFluxDataIntelligenceCreateEnemyStateMachineBuffer.c"
#include "FightObjectInstanceFluxDataIntelligenceCreateEnemyStateMachine.c"
#include "FightObjectInstanceFluxDataIntelligenceCreateStairWayToHeaven.c"
#include "FightObjectInstanceFluxDataIntelligenceCreatePlayerGetInput.c"
#include "FightObjectInstanceFluxDataIntelligenceCreateForcesToAcceleration.c"
#include "FightObjectInstanceFluxDataIntelligenceCreateAccumulatedDamage.c"
#include "FightObjectInstanceFluxDataIntelligenceCreateAbilities.c"
#include "FightObjectInstanceFluxDataIntelligenceCreateMovementPlayer.c"
#include "FightLoadObjectInstanceCreateFluxDataIntelligenceEnemy.c"
#include "FightLoadObjectInstanceCreateFluxDataIntelligencePlayer.c"
#include "FightLoadObjectInstanceCreateFluxData.c"
#include "FightLoadObjectInstanceCreateLoadable.c"
#include "FightLoadObjectCreateLoadable.c"
#include "FightLoadClassCreate.c"
#include "FightLoadSequence.c"
#include "FightLoad.c"
#include "FightDeLoad.c"
#include "Fight.c"

#include "TilePlayerGetWhichPlayerFromObjectAndInstance.c"
#include "TileMovementFunction.c"
#include "CheckForOverWorldBorder.c"

#include "TileGoSomeWhereDispatch.c"
#include "TileLogicOutroActive.c"
#include "TileLogicOutro.c"
#include "TileLogicIntro.c"

#include "EventFightStart.c"

#include "EventSpeechDrawSpeechBubbleGeneral.c"

#include "EventSpeechLoadableDeLoad.c"
#include "EventSpeechLogicDeLoad.c"
#include "EventSpeechInput.c"
#include "EventSpeechDrawSpeechBubble.c"
#include "EventSpeechDraw.c"
#include "EventSpeechLoad.c"
#include "EventSpeech.c"

#include "EventSpeechDynamicLogicDeLoad.c"
#include "EventSpeechDynamicLoadableDeLoad.c"
#include "EventSpeechDynamicLogic.c"
#include "EventSpeechDynamicDrawSpeechBubblePositionGet.c"
#include "EventSpeechDynamicDraw.c"
#include "EventSpeechDynamicLoad.c"
#include "EventSpeechDynamic.c"

#include "EventFunction.c"

#include "TileDistance.c"
#include "TileMusicIsPlaying.c"
#include "TileMusicStop.c"
#include "TileMusicPlay.c"
#include "TileUpdateFlagsCheckSingle.c"
#include "TileUpdateFlags.c"
#include "TileInputPost.c"
#include "TileLogicPost.c"

#include "TileMovementTypePlayer.c"
#include "TileMovementType.c"
#include "TileMovement.c"

#include "TileEventActivate.c"
#include "TileEventHandler.c"
#include "TileEventCheckButtons.c"
#include "TileEventCheck.c"
#include "TileLogicFrameInitiate.c"
#include "TileLogicPre.c"
#include "TileInputPre.c"
#include "TileDrawObjects.c"
#include "TileDrawBackGround.c"
#include "TileDrawFinish.c"
#include "TileDrawStart.c"
#include "TileDraw.c"
#include "TileDeLoadFlagsDeLoad.c"
#include "TileDeLoad.c"
#include "TileLoadClassCreate.c"
#include "TileLoadMovementPreCompute.c"
#include "TileLoadCalculateFromMap.c"
#include "TileLoadObjectLoadableCreate.c"
#include "TileLoadCreateNewStagePositionFromPlayerStartPosition.c"
#include "TileLoadFlagsLoad.c"
#include "TileLoad.c"
#include "TileAddNewTiles.c"
#include "TileCleanUpOldTiles.c"
#include "Tile.c"

#include "OverWorldDispatch.c"
#include "OverWorldDeLoad.c"
#include "OverWorldLoad.c"
#include "OverWorld.c"

#include "LoadGameInitiate.c"
#include "LoadGameDrawSaveData.c"
#include "LoadGameActivateVisualMemoryData.c"
#include "LoadGameDeleteSingleSaveData.c"
#include "LoadGameLoadSingleSaveData.c"
#include "LoadGameCheckAccessories.c"
#include "LoadGameDraw.c"
#include "LoadGame.c"
#include "StartNewGameSequence.c"
#include "StartNewGame.c"


#include "DogmaScreenInput.c"
#include "DogmaScreenLogic.c"
#include "DogmaScreenDraw.c"
#include "DogmaScreenDeLoad.c"
#include "DogmaScreenLoad.c"
#include "DogmaScreen.c"

#include "RedSpotScreenInput.c"
#include "RedSpotScreenLogic.c"
#include "RedSpotScreenDrawMovingLetters.c"
#include "RedSpotScreenDraw.c"
#include "RedSpotScreenDeLoad.c"
#include "RedSpotScreenLoad.c"
#include "RedSpotScreen.c"

#include "TitleScreenInput.c"
#include "TitleScreenLogic.c"
#include "TitleScreenDraw.c"
#include "TitleScreenDeLoad.c"
#include "TitleScreenLoad.c"
#include "TitleScreen.c"


int main(int argc, char* argv[]){

uint8 GameLoop;
uint8 GameStage;

void* TransitionData;

InitiateSound();
InitiateGameLogic();

if(InitiateGraphic() != StairWayToHeavenIdentifier){

GameStage = BootUpStage;
GameLoop = 1;


while(GameLoop){

if(GameStage == BootUpStage){ 
if(DogmaScreen() == BoringStage && RedSpotScreen() == BoringStage) GameStage = TitleScreenStage;
else GameStage = FinalExitStage;
}

if(GameStage == TitleScreenStage) GameStage = TitleScreen(&TransitionData);

if(GameStage == StartNewGameStage) GameStage = StartNewGame(&TransitionData);

if(GameStage == TheGameIsOnStage) GameStage = OverWorld(&TransitionData);

if(GameStage == FinalExitStage) GameLoop = 0;

}

}

if(FileSystemUsed[1] != 'p') arch_menu();
cdfs_test();
return(1);
}