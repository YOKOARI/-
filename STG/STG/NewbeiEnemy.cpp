#include "NewbeiEnemy.h"
#include "DxLib.h"
#include "NewbeiEnemyBullet.h"
#include "ControlGameInstance.h"
#include <time.h>

#define ENEMY_PIC "Image/sample.png"
#define LEFT 0
#define RIGHT 1
#define SPOWN_X rand() % (6 + 1) * 20
#define SPOWN_Y -20
#define MOVING_POINT_Y 2
#define MOVING_POINT_X 2

NewbeiEnemy::NewbeiEnemy(int x,int y) {
	srand((unsigned int)time(NULL));
	moveX = x;
	moveY = y;
	endShotFlag = false;
}


NewbeiEnemy::~NewbeiEnemy() {

}

void NewbeiEnemy::Initialize() {
	
	mBullet = NULL;
	y = SPOWN_Y;
	x = SPOWN_X;
	mCharaGraphicHandle[0] = LoadGraph(ENEMY_PIC);
}

void NewbeiEnemy::Update() {
	Move();
	ShotUpdate();
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointX(this->x);
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointY(this->y);
	

	
}

void NewbeiEnemy::Render() {
	DrawExtendGraph(x, y, x + 10, y + 15, mCharaGraphicHandle[0], TRUE);
	ShotRender();
}

void NewbeiEnemy::Finalize() {
	InitGraph();
}

void NewbeiEnemy::Move() {
	if (endShotFlag == false) {
		if (y < moveY) y += MOVING_POINT_Y;	

		if (x > moveX) x -= MOVING_POINT_X;
		if (x < moveX) x += MOVING_POINT_X;

		if (moveX - x < MOVING_POINT_X && moveX - x > -2) x = moveX;
		if (moveY - y < MOVING_POINT_Y && moveY - y > MOVING_POINT_Y - 4) y = moveY;

	}
	else if(endShotFlag == true) {
		y -= 2;
	}
	if (x == moveX && y == moveY && endShotFlag == false) {
		ShotFlg = true;
		endShotFlag = true;
	}
}
void NewbeiEnemy::ShotUpdate() {
	if (mBullet != 0) {
		mBullet->Update();

		if (mBullet->GetBulletPointY() == -1) {
			mBullet->Finalize();
			delete mBullet;
		}
	}
	if (ShotFlg == true) {

		mBullet = new NewbeiEnemyBullet;

		mBullet->Initialize();
		ShotFlg = false;
	}
}

void NewbeiEnemy::ShotRender() {
	if (mBullet != 0) {
		mBullet->Render();
	}
}