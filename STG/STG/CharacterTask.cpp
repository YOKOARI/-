#include "CharacterTask.h"
#include "DxLib.h"
#include "ControlGameInstance.h"

CharacterTask::CharacterTask() {
}


CharacterTask::~CharacterTask() {
}

void CharacterTask::Initialize() {
	mCharaGraphicHandle[0] = 0;
	mCharaGraphicHandle[1] = 0;
	mCharaGraphicHandle[2] = 0;
	mCharaGraphicHandle[3] = 0;
	mCharaGraphicHandle[4] = 0;
	mSoundHandle = 0;
	mSoundPlayFlag = 0;
	cntBulletTime = 0;
	interval = 3;
	x = 0;
	y = 0;
}

void CharacterTask::Update() {
	ControlGameInstance::GetInstance()->SetPlayerPointX(this->x);
	ControlGameInstance::GetInstance()->SetPlayerPointY(this->y);
	ControlGameInstance::GetInstance()->SetPlayerHitAria(x + 20, y + 30, 5);

}

void CharacterTask::Render() {
	DrawGraph(0, 0, mCharaGraphicHandle[0], TRUE);
	DrawGraph(0, 0, mCharaGraphicHandle[1], TRUE);
	DrawGraph(0, 0, mCharaGraphicHandle[2], TRUE);
	DrawGraph(0, 0, mCharaGraphicHandle[3], TRUE);
	DrawGraph(0, 0, mCharaGraphicHandle[4], TRUE);


}

void CharacterTask::Finalize() {
	for (int i = 0; i < 5; i++) {
		DeleteGraph(mCharaGraphicHandle[i]);
	}
	StopSoundMem(mSoundHandle);
	DeleteSoundMem(mSoundHandle);
}

void CharacterTask::Move() {
	
}

void CharacterTask::ShotUpdate() {

}

void CharacterTask::ShotRender() {

}