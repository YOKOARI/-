#include "NewbeiEnemyBullet.h"
#include "DxLib.h"
#include "ControlGameInstance.h"

#define ENEMY_BULLET_PIC "Image/BulletBox2.png"

NewbeiEnemyBullet::NewbeiEnemyBullet() {

}

NewbeiEnemyBullet::~NewbeiEnemyBullet() {

}

void NewbeiEnemyBullet::Initialize() {
	LoadDivGraph(ENEMY_BULLET_PIC, 16, 4, 4, 20.5f, 20.5f, bulletGraphicHandle);
	for (i = 0; i < 5; i++) {
		PointX[i] = ControlGameInstance::GetInstance()->GetNewbeiEnemyPointX();
		PointY[i] = ControlGameInstance::GetInstance()->GetNewbeiEnemyPointY();
	}
	ControlGameInstance::GetInstance()->SetEnemyBulletHitAria(10, 10, 6);
}


void NewbeiEnemyBullet::Update() {
	for (i = 0; i < 5; i++) {
		PointY[i] += 5;
		PointX[i] += (i - 2) * 2;
	}
}

void NewbeiEnemyBullet::Render() {
	for (i = 0; i < 5; i++) {
		DrawGraph(PointX[i], PointY[i], bulletGraphicHandle[4], TRUE);
	}
}

void NewbeiEnemyBullet::Finalize() {
	InitGraph();
}

int NewbeiEnemyBullet::GetBulletPointY() {
	for (int j = 0; j < 5; j++) {

		if (PointY[i] > 800) {
			if (i == 5) return -1;
			continue;
		}
		else {
			break;
		}
	}
}
int NewbeiEnemyBullet::GetBulletPointX() { return 0; }