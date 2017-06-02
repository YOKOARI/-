#include "YokoariRed.h"
#include "DxLib.h"
#include "PlayerBullet.h"
#include "ControlGameInstance.h"

#define PLAYER_PIC "Image/PlayerUI/YokoariRed.png"


YokoariRed::YokoariRed() {

}


YokoariRed::~YokoariRed() {

}

void YokoariRed::Initialize() {
	CharacterTask::Initialize();
	i = 0;
	for (int k = 0; k < 70; k++) {
		mBullet[k] = NULL;
		playerHitFlag[k] = false;
	}
	mCharaGraphicHandle[0] = LoadGraph(PLAYER_PIC);

}

void YokoariRed::Update() {
	ControlGameInstance::GetInstance()->SetPlayerPointX(this->x);
	ControlGameInstance::GetInstance()->SetPlayerPointY(this->y);
	Move();
	ShotUpdate();
	CharacterTask::Update();
}

void YokoariRed::Render() {

	ShotRender();

	DrawExtendGraph(x, y, x + 40, y + 60, mCharaGraphicHandle[0], TRUE);
}

void YokoariRed::Finalize() {
	DeleteGraph(mCharaGraphicHandle[0]);
}

void YokoariRed::Move() {

	//シフトキーが押されている場合は遅くする
	if (CheckHitKey(KEY_INPUT_RSHIFT) != 0 || CheckHitKey(KEY_INPUT_LSHIFT) != 0) {
		MoveScript(2);
	}
	else {
		MoveScript(5);
	}

}

void YokoariRed::MoveScript(int transfer) {
	if (CheckHitKey(KEY_INPUT_UP) != 0) {
		y -= transfer;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
		y += transfer;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
		x -= transfer;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
		x += transfer;
	}
	if (x <= 0) x = 0;
	if (x >= 1260) x = 1260;
	if (y <= 15) y = 15;
	if (y >= 715) y = 715;

}

void YokoariRed::ShotUpdate() {

	for (int j = 0; j < 70; j++) {
		ControlGameInstance::GetInstance()->SetPlayerBulletId(j);
		if (mBullet[j] != NULL) {
			if (ControlGameInstance::GetInstance()->GetEnemyHitFlag(j) == false) {
			mBullet[j]->Update();
		}
			else {
				mBullet[j]->Finalize();
				delete mBullet[j];
				mBullet[j] = NULL;
				ControlGameInstance::GetInstance()->SetEnemyHitFlag(j, false);
			}
		}
	}
	cntBulletTime++;

	ShotFlg = cntBulletTime > interval ? true : false;

	if (CheckHitKey(KEY_INPUT_SPACE) != 0 && ShotFlg == true) {

		mBullet[i] = (IBullet*) new PlayerBullet;
		mBullet[i]->Initialize();

		if (mBullet[i]->GetBulletPointY() <= 0) {
			mBullet[i]->Finalize();
			delete mBullet[i];
			mBullet[i] = NULL;
		}

		i++;
		if (i == 70) i = 0;
		cntBulletTime = 0;
	}

}

void YokoariRed::ShotRender() {

	for (int j = 0; j < 70; j++) {
		if (mBullet[j] != 0) {
			mBullet[j]->Render();
		}
	}
}