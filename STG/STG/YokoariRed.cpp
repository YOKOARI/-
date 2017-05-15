#include "YokoariRed.h"
#include "DxLib.h"
#include "PlayerBullet.h"
#define PLAYER_PIC "Image/sample.png"

YokoariRed::YokoariRed() {

}


YokoariRed::~YokoariRed() {
}

void YokoariRed::Initialize() {
	mBullet[0] = (IBullet*) new PlayerBullet;
	x = 0;
	y = 0;
	mCharaGraphicHandle[0] = LoadGraph(PLAYER_PIC);

}

void YokoariRed::Update() {
	Move();
}

void YokoariRed::Render() {

	DrawExtendGraph(x, y, x + 10, y + 15, mCharaGraphicHandle[0], TRUE);
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
	if (x >= 1280) x = 1275;
	if (y <= 0) y = 0;
	if (y >= 720) y = 715;

}

void YokoariRed::ShotUpdate() {
	mBullet[0]->Update();

}
void YokoariRed::ShotRender() {
	mBullet[0]->Render();

}