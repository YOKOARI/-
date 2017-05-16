#include "YokoariBrue.h"
#include "DxLib.h"
#include "PlayerBullet.h"
#include "ControlGameInstance.h"

#define PLAYER_PIC "Image/sample.png"


YokoariBrue::YokoariBrue() {

}


YokoariBrue::~YokoariBrue() {

}

void YokoariBrue::Initialize() {
	CharacterTask::Initialize();
	i = 0;
	for (int k = 0; k < 70; k++) {
		mBullet[k] = NULL;
	}
	mCharaGraphicHandle[0] = LoadGraph(PLAYER_PIC);

}

void YokoariBrue::Update() {
	ControlGameInstance::GetInstance()->SetPlayerPointX(this->x);
	ControlGameInstance::GetInstance()->SetPlayerPointY(this->y);
	Move();
	ShotUpdate();
	CharacterTask::Update();
}

void YokoariBrue::Render() {
	
	ShotRender();
	
	DrawExtendGraph(x, y, x + 10, y + 15, mCharaGraphicHandle[0], TRUE);
}

void YokoariBrue::Finalize() {
	DeleteGraph(mCharaGraphicHandle[0]);
}

void YokoariBrue::Move() {

	//シフトキーが押されている場合は遅くする
	if (CheckHitKey(KEY_INPUT_RSHIFT) != 0 || CheckHitKey(KEY_INPUT_LSHIFT) != 0) {
		MoveScript(5);
	}
	else {
		MoveScript(10);
	}

}

void YokoariBrue::MoveScript(int transfer) {
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

void YokoariBrue::ShotUpdate() {

	for (int j = 0; j < 70; j++) {
		if (mBullet[j] != 0) {
			mBullet[j]->Update();
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

void YokoariBrue::ShotRender() {

	for (int j = 0; j < 70; j++) {
		if (mBullet[j] != 0) {
			mBullet[j]->Render();
		}
	}
}