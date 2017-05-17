#include "SilentSerena.h"
#include "DxLib.h"
#include <math.h>
#include "ControlGameInstance.h"

#define ENEMY_BULLET_PIC "Image/BulletBox2.png"
#define BULLET_SPEED 8
#define BULLET_SECOND_SPEED rand() % 8 + 4
#define PI 3.141592654f

SilentSerena::SilentSerena() {

}

SilentSerena::~SilentSerena() {

}

void SilentSerena::Initialize() {
	LoadDivGraph(ENEMY_BULLET_PIC, 16, 4, 4, 20.5f, 20.5f, bulletGraphicHandle, TRUE);
	for (i = 0; i < 680; i++) {
		if (i < 480) {
			bulletPointX[i] = ControlGameInstance::GetInstance()->GetNewbeiEnemyPointX();
			bulletPointY[i] = ControlGameInstance::GetInstance()->GetNewbeiEnemyPointY();
		}
		else {
			bulletPointX[i] = rand() % 128 + 1 * 10;
			bulletPointY[i] = 0;
		}
	}
		
		bulletInterval = 2;
		bulletTimeCount = 0;
		bulletSecondInterval = 3;
		bulletSecondTimeCount = 0;
		deg = 0;
		i = 0;
		len = BULLET_SPEED;
		bulletPhase = 0;
		flg = 0;
}

void SilentSerena::Update() {
	

	bulletTimeCount++;

	shotFlg[0] = bulletTimeCount > bulletInterval ? true : false;
	shotFlg[1] = bulletSecondTimeCount > bulletSecondInterval ? true : false;

	//if (shotFlg[0] == true) {
		
			for (int k = 0; k < 360; k++) {
				if ((int)deg % 30 == 0 && deg != 0) {
					rad = deg * PI / 180;
					if (bulletPhase % 5 == 0 && bulletPhase != 0) {
						flg = !flg;
						bulletPhase = 0;
					}
					//if (flg == 0) {
						bulletPointX[i] += (int)len * cos(rad);
						bulletPointY[i] += (int)len * sin(rad);
					//}
					//else if (flg == 1) {
					//	bulletPointX[i] += (int)len * cos(rad + 0.5659f);
					//	bulletPointY[i] += (int)len * sin(rad + 0.2588f);
				//	}
						i++;
				}
				bulletPhase++;
				bulletTimeCount = 0;
				deg++;
			}
		
	//}
	
	//if (shotFlg[1] == true) {
		for (int k = 480; k < 680; k++) {
			bulletPointY[k] += BULLET_SECOND_SPEED;
		}
	//}
}

void SilentSerena::Render() {
	for (int j = 0; j < 680; j++) {
		DrawGraph(bulletPointX[j], bulletPointY[j], bulletGraphicHandle[4], TRUE);
	}
}

void SilentSerena::Finalize() {
	InitGraph();
}

int SilentSerena::GetBulletPointX() {
	return 0;
}

int SilentSerena::GetBulletPointY() {
	return 0;
}