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

	LoadDivGraph(BULLET_PIC, 9, 3, 3, 20, 20, gHandle);
	x = ControlGameInstance::GetInstance()->GetPlayerPointX();
	y = ControlGameInstance::GetInstance()->GetPlayerPointY();

}

void PlayerBullet::Update() {
	y -= 10;
}

void PlayerBullet::Render() {
	DrawGraph(x, y, gHandle[0], TRUE);
}

void PlayerBullet::Finalize() {
	InitGraph();
}

