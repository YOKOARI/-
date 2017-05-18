#include "BossEnemy.h"
#include "DxLib.h"
#include "ControlGameInstance.h"
#include "NormalEnemyBullet.h"
#define BOSS_PIC "Image/EnemyUI/Boss‚P.png"
#define HP_BAR "Image/HPBar/HealthBarIn.png"
#define HP_BAR_AROUND "Image/HPBar/HealthBarOut.png"
#define SPOWN_X 350
#define SPOWN_Y -20

BossEnemy::BossEnemy(int id){
	thisId = id;
}


BossEnemy::~BossEnemy()
{
}


void BossEnemy::Initialize() {
	for (i = 0; i < 20; i++) {
		mBullet[i] = NULL;
	}
	bulletFlag = false;
	bulletFlagCount = 0;
	x = SPOWN_X;
	y = SPOWN_Y;
	i = 0;
	hp = 680;
	cnt = 0;
	bulletCnt = 0;
	interval = 6;
	cntBulletTime = 0;
	hitCount = 0;
	moveFlag = 0;
	mCharaGraphicHandle[0] = LoadGraph(BOSS_PIC);
	mCharaGraphicHandle[1] = LoadGraph(HP_BAR);
	mCharaGraphicHandle[2] = LoadGraph(HP_BAR_AROUND);
}

void BossEnemy::Update() {
	
	Move();
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointX(this->x);
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointY(this->y);
	ShotUpdate();
	ControlGameInstance::GetInstance()->SetEnemyHitAria(x + 20, y + 28, 16);
	for (int j = 0; j < 70; j++) {
		if (ControlGameInstance::GetInstance()->PlayerBulletToEnemyHitTest(j) == true) {
			DrawString(0, 0, "hitP", GetColor(255, 255, 255));
			hp--;
			if(hp == 0)
				ControlGameInstance::GetInstance()->SetEnemyDeadFlag(thisId, true);
			}
		else {
			//ControlGameInstance::GetInstance()->SetEnemyHitFlag(thisId, j, false);
		}
	}

}

void BossEnemy::Render() {
	if (hp >= 0) {
		DrawExtendGraph(50, 50, 50 + hp, 50 + 40, mCharaGraphicHandle[1], TRUE);
		DrawExtendGraph(50, 50, 50 + 680, 50 + 40, mCharaGraphicHandle[2], TRUE);
	}
	DrawExtendGraph(x, y, x + 40, y + 56, mCharaGraphicHandle[0], TRUE);
	ShotRender();
}

void BossEnemy::Finalize() {
	x = 3000;
	y = 3000;
}

void BossEnemy::Move() {
	if (moveFlag == 0) {
		y += 2;
		if (cnt > 100) moveFlag = 1;
	}
	else if (moveFlag == 1) {
		y -= 1;
		x += rand() % 3 - 1;
		if (cnt % 50 == 0) moveFlag = 2;
	}
	else if(moveFlag == 2){
		y += 1;
		x += rand() % 3 - 1;
		if (cnt % 50 == 0) moveFlag = 3;
	}
	else {
		bulletFlag = true;
		if (cnt % 100 == 0) {
			moveFlag = 1;
			bulletFlag = false;
		}
	}
	cnt++;
}

void BossEnemy::ShotUpdate() {
	for (int i = 0; i < 20; i++) {
		if (mBullet[i] != NULL) {
			mBullet[i]->Update();
		}
	}
	if (interval < cntBulletTime && bulletFlag == true) {
		mBullet[bulletCnt] = new NormalEnemyBullet;
		mBullet[bulletCnt]->Initialize();
		cntBulletTime = 0;
	}
	cntBulletTime++;
	
	bulletCnt++;
	if (bulletCnt == 20) bulletCnt = 0;
}

void BossEnemy::ShotRender() {
	for (int i = 0; i < 20; i++) {
		if (mBullet[i] != NULL) {
			mBullet[i]->Render();
		}
	}
}
