#include "NewbeiEnemyBullet.h"
#include "DxLib.h"
#include "ControlGameInstance.h"

#define ENEMY_BULLET_PIC "Image/BulletBox.png"

NewbeiEnemyBullet::NewbeiEnemyBullet() {

}

NewbeiEnemyBullet::~NewbeiEnemyBullet() {

}

void NewbeiEnemyBullet::Initialize() {
	LoadDivGraph(ENEMY_BULLET_PIC, 25, 5, 5, 20, 20, bulletGraphicHandle);
	for (i = 0; i < 5; i++) {
		PointX[i] = ControlGameInstance::GetInstance()->GetNewbeiEnemyPointX();
		PointY[i] = ControlGameInstance::GetInstance()->GetNewbeiEnemyPointY();
	}
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
	if (PointY[0] > 1280 && PointY[1] > 1280 && PointY[2] > 1280 && PointY[3] > 1280 && PointY[4] > 1280) return -1;
}
int NewbeiEnemyBullet::GetBulletPointX() { return 0; }