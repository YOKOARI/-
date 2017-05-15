#include "NewbeiEnemy.h"
#include "DxLib.h"
#include "NewbeiEnemyBullet.h"
#include "ControlGameInstance.h"

#define ENEMY_PIC "Image/sample.png"

NewbeiEnemy::NewbeiEnemy(int SpownFlg) {
	
}


NewbeiEnemy::~NewbeiEnemy() {

}

void NewbeiEnemy::Initialize() {
	mBullet = NULL;
	x = 500;
	y = 0;
	mCharaGraphicHandle[0] = LoadGraph(ENEMY_PIC);
}

void NewbeiEnemy::Update(int EndPointX,int EndPointy) {
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointX(this->x);
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointY(this->y);
	if (mBullet->GetBulletPointY() >= 0) {
		mBullet->Finalize();
	}
	if (CheckHitKey(KEY_INPUT_S) != 0) {
		mBullet = new NewbeiEnemyBullet;
		mBullet->Initialize();
		
	}

	if (mBullet != 0) {
		mBullet->Update();
	}
}

void NewbeiEnemy::Render() {
	DrawExtendGraph(x, y, x + 10, y + 15, mCharaGraphicHandle[0], TRUE);
	if (mBullet != 0) {
		mBullet->Render();
	}
}

void NewbeiEnemy::Finalize() {
	InitGraph();
}

void NewbeiEnemy::ShotUpdate() {

}

void NewbeiEnemy::ShotRender() {

}