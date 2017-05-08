#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}


void Enemy::Init() {


	CharacterTask::Init();
	//mCharaGraphicHandle[0] = LoadGraph();
}

void Enemy::Update() {
	CharacterTask::Update();
}

void Enemy::Render() {
	CharacterTask::Render();

}

void Enemy::Final() {

	CharacterTask::Final();
}
