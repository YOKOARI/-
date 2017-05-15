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
	x = ControlGameInstance::GetInstance()->GetNewbeiEnemyPointX();
	y = ControlGameInstance::GetInstance()->GetNewbeiEnemyPointY();
	
}

void NewbeiEnemyBullet::Update() {
	y += 10;
}

void NewbeiEnemyBullet::Render() {
	DrawGraph(x, y, bulletGraphicHandle[4], TRUE);
}

void NewbeiEnemyBullet::Finalize() {
	InitGraph();
}