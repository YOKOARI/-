#include "Player.h"
#include "DxLib.h"

#define PLAYER_PIC "Image/sample.png"

Player::Player() {
}


Player::~Player() {
}

void Player::Initialize() {
	x = 0;
	y = 0;
	mCharaGraphicHandle[0] =  LoadGraph(PLAYER_PIC);

}

void Player::Update() {
	Move();
}

void Player::Render() {

	DrawExtendGraph(x, y,x + 10, y + 15, mCharaGraphicHandle[0], TRUE);
}

void Player::Finalize() {
	DeleteGraph(mCharaGraphicHandle[0]);
}

void Player::Move() {

	//シフトキーが押されている場合は遅くする
	if (CheckHitKey(KEY_INPUT_RSHIFT) != 0 || CheckHitKey(KEY_INPUT_LSHIFT) != 0) {
		MoveScript(2);
	}
	else {
		MoveScript(5);
	}

}

void Player::MoveScript(int transfer) {
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
/*
void Player::Shot() {

}*/