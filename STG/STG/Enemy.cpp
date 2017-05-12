#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}


void Enemy::Initialize() {


	CharacterTask::Initialize();
	//mCharaGraphicHandle[0] = LoadGraph();
}

void Enemy::Update() {
	CharacterTask::Update();
}

void Enemy::Render() {
	CharacterTask::Render();

}

void Enemy::Finalize() {

	CharacterTask::Finalize();
}
