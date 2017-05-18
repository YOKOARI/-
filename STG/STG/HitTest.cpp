#include "HitTest.h"



HitTest::HitTest()
{
}


HitTest::~HitTest()
{
}

void HitTest::SetPlayerBulletNumber(int pBulletNumber) {
	playerBulletNumber = pBulletNumber;
}

void HitTest::SetEnemyNumber(int eNumber) {
	enemyNumber = eNumber;
}


int HitTest::GetPlayerBulletNumber() {
	return playerBulletNumber;
}

int HitTest::GetEnemyNumber() {
	return enemyNumber;
}