#include "NewbeiEnemy.h"
#include "DxLib.h"
#include "NewbeiEnemyBullet.h"
#include "SilentSerena.h"
#include "ControlGameInstance.h"
#include <stdlib.h>


#define ENEMY_PIC "Image/EnemyUI/enemy�P.png"
#define LEFT 0
#define RIGHT 1
#define SPOWN_X rand() % (24 + 1) * 30
#define SPOWN_Y -20
#define MOVING_POINT_Y 2
#define MOVING_POINT_X 2


NewbeiEnemy::NewbeiEnemy(int x,int y, int id) {
	
	moveX = x;
	moveY = y;
	endShotFlag = false;
	thisId = id;
	hitCount = 0;
}


NewbeiEnemy::~NewbeiEnemy() {

}

void NewbeiEnemy::Initialize() {
	mBullet = NULL;
	i = 0;
	y = SPOWN_Y;
	x = rand() % (45 + 1) * 10;
	mCharaGraphicHandle[0] = LoadGraph(ENEMY_PIC);
}

void NewbeiEnemy::Update() {
	Move();
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointX(this->x);
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointY(this->y);
	ShotUpdate();
	ControlGameInstance::GetInstance()->SetEnemyHitAria(x + 15, y + 23, 15);
	for (int j = 0; j < 70; j++) {
		if (ControlGameInstance::GetInstance()->PlayerBulletToEnemyHitTest(j) == true) {
			DrawString(0, 0, "hitP", GetColor(255, 255, 255));
			hitCount++;
			if (hitCount == 3)
				ControlGameInstance::GetInstance()->SetEnemyDeadFlag(thisId, true);
		}
		else {
			//ControlGameInstance::GetInstance()->SetEnemyHitFlag(thisId, j, false);
		}
	}
}

void NewbeiEnemy::Render() {
	DrawExtendGraph(x, y, x + 30, y + 46, mCharaGraphicHandle[0], TRUE);
	ShotRender();
}

void NewbeiEnemy::Finalize() {
	x = 3000;
	y = 3000;
}

void NewbeiEnemy::Move() {
	if (endShotFlag == false) {
		if (y < moveY) y += MOVING_POINT_Y;	

		if (x > moveX) x -= MOVING_POINT_X;
		if (x < moveX) x += MOVING_POINT_X;

		if (moveX - x < MOVING_POINT_X && moveX - x > -3) x = moveX;
		if (moveY - y < MOVING_POINT_Y && moveY - y > MOVING_POINT_Y - 4) y = moveY;

	}
	else if(endShotFlag == true) {
		y -= 4;
	}
	
	if (x == moveX && y == moveY && endShotFlag == false) {
		ShotFlg = true;
		endShotFlag = true;
	}
}
void NewbeiEnemy::ShotUpdate() {
	
	if (mBullet != NULL) {
		mBullet->Update();
	}
	
	if(ShotFlg == true) {

		mBullet = new NewbeiEnemyBullet;
		mBullet->Initialize();
		
		if (mBullet->GetBulletPointY() == -1) {
			mBullet->Finalize();
			delete mBullet;
			mBullet = NULL;
		}
		i++;
		if (i == 20) i = 0;
		ShotFlg = false;
	}
}

void NewbeiEnemy::ShotRender() {

	if (mBullet != NULL) {
		mBullet->Render();
	}

}