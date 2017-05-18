#include "FirstStage.h"
#include "DxLib.h"
#include "NewbeiEnemy.h"
#include "NormalEnemy.h"
#include "BossEnemy.h"
#include "ControlGameInstance.h"
#include <stdlib.h>
#include <time.h>

#define STAGE_PIC "Image/MapUI/stage.png"
#define NEWBEI_SOUND "Sound/NewbeiEnemy.mp3"
#define BOSS_SOUND "Sound/Boss.mp3"

FirstStage::FirstStage()
{
}


FirstStage::~FirstStage(){
}

int FirstStage::Initialize() {
	mGraphicHandle = LoadGraph(STAGE_PIC);
	mSoundPlayHandle = LoadSoundMem(NEWBEI_SOUND);

	spownInterval = 60;
	spownCount = 0;
	charaID = 0;
	spownFlag = false;
	StageTask::PlayingSound();
	StageTask::Initialize();

	return 0;
}

int FirstStage::Update() {
	srand((unsigned int)time(NULL));
	int x = rand() % 400 + 50;
	int y = rand() % 300 + 60;

	for (int i = 0; i < 20; i++) {
		if (mCharacter[i] != NULL) {
			if (ControlGameInstance::GetInstance()->GetEnemyDeadFlag(i) == true) {
				mCharacter[i]->Finalize();
				delete mCharacter[i];
				mCharacter[i] = NULL;
			}
			else {
				mCharacter[i]->Update();
			}
		}
	}
	StageTask::Update();
	spownCount++;

	spownFlag = spownCount > spownInterval ? true : false;

	if (spownFlag == true && charaID < 19) {
		if (charaID < 10) {

			mCharacter[charaID] = new NewbeiEnemy(x, y, charaID);
		}
		else if (charaID < 18) {
			mCharacter[charaID] = new NormalEnemy(charaID, y);
		}
		else if (charaID == 18) {
			ChangeSound(LoadSoundMem(BOSS_SOUND));
			StageTask::PlayingSound();
			mCharacter[charaID] = new BossEnemy(charaID);
		}
		mCharacter[charaID]->Initialize();
		spownCount = 0;
		charaID++;
	}

	return 0;
}

int FirstStage::Render() {
	StageTask::Render();
	for (int i = 0; i < 20; i++) {
		if (mCharacter[i] != NULL) {
			mCharacter[i]->Render();
		}
	}
	return 0;
}

int FirstStage::Finalize() {
	StageTask::Finalize();
	InitGraph();
	return 0;
}

