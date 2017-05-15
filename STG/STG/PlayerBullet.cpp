#include "PlayerBullet.h"
#include "DxLib.h"
#include "ControlGameInstance.h"

#define BULLET_PIC "Image/BulletBox.png"

PlayerBullet::PlayerBullet()
{
}


PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Initialize() {
	shotVectorFlg = 0;
	LoadDivGraph(BULLET_PIC, 9, 3, 3, 20, 20, gHandle);
	x = ControlGameInstance::GetInstance()->GetPlayerPointX();
	y = ControlGameInstance::GetInstance()->GetPlayerPointY();

}

void PlayerBullet::Update() {
	if (ControlGameInstance::GetInstance()->GetCharacterId() == e_YokoariBrue) {
		y -= 10;
	}
	else {
		if (shotVectorFlg == 0) {
			y -= 10;
			x += 2;
			shotVectorFlg = 1;
		}
		else {
			y -= 10;
			x += 2;
			shotVectorFlg = 0;
		}
	}
}

void PlayerBullet::Render() {
	DrawGraph(x, y, gHandle[0], TRUE);
}

void PlayerBullet::Finalize() {
	InitGraph();
}

