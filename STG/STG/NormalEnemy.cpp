#include "NormalEnemy.h"
#include "NormalEnemyBullet.h"
#include "DxLib.h"
#include "ControlGameInstance.h"
#include <stdlib.h>


#define SPOWN_X rand() % (24 + 1) * 10
#define SPOWN_Y -20
#define MOVING_POINT_Y 2
#define NORMAL_ENEMY_PIC "Image/EnemyUI/enemy‚Q.png"

NormalEnemy::NormalEnemy(int id, int y) {
	moveY = y;
	endShotFlag = false;
	thisId = id;
}


NormalEnemy::~NormalEnemy() {
}

void NormalEnemy::Initialize() {
	mBullet = NULL;
	i = 0;
	x = SPOWN_X;
	y = SPOWN_Y;
	mCharaGraphicHandle[0] = LoadGraph(NORMAL_ENEMY_PIC);
}

void NormalEnemy::Update() {
	Move();
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointX(this->x);
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointY(this->y);
	ShotUpdate();
	ControlGameInstance::GetInstance()->SetEnemyHitAria(x + 15, y + 23, 13);
	for (int j = 0; j < 70; j++) {
		if (ControlGameInstance::GetInstance()->PlayerBulletToEnemyHitTest(j) == true) {
			DrawString(0, 0, "hitP", GetColor(255, 255, 255));
			//hitTest.SetEnemyNumber(thisId);
			//ControlGameInstance::GetInstance()->SetEnemyHitFlag(thisId , j, true);
		}
		else {
			//ControlGameInstance::GetInstance()->SetEnemyHitFlag(thisId, j, false);
		}
	}	
	
 }

void NormalEnemy::Render() {
	DrawExtendGraph(x, y, x + 30, y + 46, mCharaGraphicHandle[0], TRUE);
	ShotRender();
}

void NormalEnemy::Finalize() {
	InitGraph();
}

void NormalEnemy::Move() {

	if (endShotFlag == false) {
		if (y < moveY) y += MOVING_POINT_Y;
		if (moveY - y < MOVING_POINT_Y && moveY - y > MOVING_POINT_Y - 4) y = moveY;
	}
	else if (endShotFlag == true) {
		y -= 4;
	}
	
	if (y == moveY && endShotFlag == false) {
		ShotFlg = true;
		endShotFlag = true;
	}
}

void NormalEnemy::ShotUpdate() {
	if (mBullet != NULL) {
		mBullet->Update();
	}

	if (ShotFlg == true) {

		mBullet = new NormalEnemyBullet;
		mBullet->Initialize();

		if (mBullet->GetBulletPointY() == -1 && mBullet->GetBulletPointX() == -1) {
			mBullet->Finalize();
			delete mBullet;
			mBullet = NULL;
		}
		i++;
		if (i == 20) i = 0;
		ShotFlg = false;
	}
}

void NormalEnemy::ShotRender() {
	if (mBullet != NULL) {
		mBullet->Render();
	}
}