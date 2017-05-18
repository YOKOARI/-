#include "StageTask.h"
#include "DxLib.h"
#include "ControlGameInstance.h"
#include "YokoariBrue.h"
#include "YokoariRed.h"


StageTask::StageTask()
{
}


StageTask::~StageTask()
{
}

int StageTask::Initialize() {
	soundID = 0;
	for (int i = 0; i < 20; i++) {
		mCharacter[i] = NULL;
	}
	mCharacter[19] = ControlGameInstance::GetInstance()->GetCharacterId() == e_YokoariBrue ? (ICharacter*) new YokoariBrue : (ICharacter*) new YokoariRed;
	mCharacter[19]->Initialize();
	return 0;
}

int StageTask::Update() {
	if (ControlGameInstance::GetInstance()->GetPlayerDeadFlag() == true) {
		mCharacter[19]->Finalize();
		delete mCharacter[19];
		mCharacter[19] = NULL;
	}
	if (mCharacter[19] == NULL) {
		mCharacter[19] = ControlGameInstance::GetInstance()->GetCharacterId() == e_YokoariBrue ? (ICharacter*) new YokoariBrue : (ICharacter*) new YokoariRed;
		mCharacter[19]->Initialize();
	}
	return 0;
}

int StageTask::Render() {
	DrawExtendGraph(0, 0, 1279, 719, mGraphicHandle, TRUE);
	return 0;
}

int StageTask::Finalize() {
	mSoundPlayFlag = CheckSoundMem(mSoundPlayHandle);
	if (mSoundPlayFlag == 1) {
		mSoundPlayFlag = 0;
		StopSoundMem(mSoundPlayHandle);
		DeleteSoundMem(mSoundPlayHandle);

		return 0;
	}
}

void StageTask::ChangeSound(int handle) {
	mSoundPlayFlag = CheckSoundMem(mSoundPlayHandle);
	if (mSoundPlayFlag == 1) {
		mSoundPlayFlag = 0;
		StopSoundMem(mSoundPlayHandle);
		DeleteSoundMem(mSoundPlayHandle);
	}
	mSoundPlayHandle = handle;
}

void StageTask::PlayingSound() {
	mSoundPlayFlag = CheckSoundMem(mSoundPlayHandle);
	if (mSoundPlayFlag == 0) {
		PlaySoundMem(mSoundPlayHandle, DX_PLAYTYPE_LOOP, TRUE);
		mSoundPlayFlag = 1;
	}
}