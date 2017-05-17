#include "PlayerBullet.h"
#include "DxLib.h"
#include "ControlGameInstance.h"

#define BULLET_PIC "Image/BulletBox3.png"

PlayerBullet::PlayerBullet()
{
}


PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Initialize() {
	shotVectorFlg = 0;
  	LoadDivGraph(BULLET_PIC, 9, 3, 3, 11.3f, 11.3f, gHandle);
	x = ControlGameInstance::GetInstance()->GetPlayerPointX() + 15;
	y = ControlGameInstance::GetInstance()->GetPlayerPointY() + 10;

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
			x -= 2;
			shotVectorFlg = 0;
		}
	}
	ControlGameInstance::GetInstance()->SetPlayerBulletHitAria(x + 5, y + 5, 5);
	if (ControlGameInstance::GetInstance()->PlayerBulletToEnemyHitTest() == true) {
		DrawString(0, 0, "hitP", GetColor(255, 255, 255));

	}
}

void PlayerBullet::Render() {
	DrawGraph(x, y, gHandle[0], TRUE);
}

void PlayerBullet::Finalize() {
	InitGraph();
}

