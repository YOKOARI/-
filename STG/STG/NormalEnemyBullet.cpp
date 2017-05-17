#include "NormalEnemyBullet.h"
#include "DxLib.h"
#include "ControlGameInstance.h"
#include <math.h>

#define ENEMY_BULLET_PIC "Image/BulletBox2.png"
#define PI 3.141592654f 
#define PI2 (PI*2) 
#define BULLET_SPEED 9
#

NormalEnemyBullet::NormalEnemyBullet() {
}


NormalEnemyBullet::~NormalEnemyBullet() {
}

void NormalEnemyBullet::Initialize() {
	LoadDivGraph(ENEMY_BULLET_PIC, 16, 4, 4, 20.5f, 20.5f, bulletGraphicHandle);
	for (i = 0; i < 12; i++) {
		PointX[i] = ControlGameInstance::GetInstance()->GetNewbeiEnemyPointX();
		PointY[i] = ControlGameInstance::GetInstance()->GetNewbeiEnemyPointY();
	}
	
	deg = 0;
	len = BULLET_SPEED;
	
}

void NormalEnemyBullet::Update() {
	i = 0;
	for (int k = 0; k < 360; k++) {
		if (deg % 30 == 0 && deg != 0) {
			rad = (float)deg * PI / 180;

			PointX[i] += (int)len * cos(rad);
			PointY[i] += (int)len * sin(rad);
			ControlGameInstance::GetInstance()->SetEnemyBulletHitAria(PointX[i] + 10, PointY[i] + 10, 6);
			if (ControlGameInstance::GetInstance()->EnemyBulletToPlayerHitTest() == true) {
				PointX[i] = -3000;
				PointY[i] = -3000;
				DrawString(0, 0, "hit", GetColor(255, 255, 255));
			}
			i++;
		}
		deg++;
	}
}

void NormalEnemyBullet::Render() {
	for (i = 0; i < 12; i++) {
		DrawGraph(PointX[i], PointY[i], bulletGraphicHandle[4], TRUE);
	}
}

void NormalEnemyBullet::Finalize() {
	InitGraph();
}

int NormalEnemyBullet::GetBulletPointX() {
	for (int j = 0; j < 12; j++) {

		if (PointX[i] > 1280 || PointX[i] < 0) {
			if (i == 12) return -1;
			continue;
		}
		else {
			break;
		}
	}
}

int NormalEnemyBullet::GetBulletPointY() {
	for (int j = 0; j < 12; j++) {

		if (PointY[i] > 800 || PointY[i] < 0) {
			if (i == 12) return -1;
			continue;
		}
		else {
			break;
		}

	}
}