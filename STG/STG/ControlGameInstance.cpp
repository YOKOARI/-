#include "ControlGameInstance.h"



ControlGameInstance::ControlGameInstance()
{
}


ControlGameInstance::~ControlGameInstance()
{
}

ControlGameInstance* ControlGameInstance::GetInstance() {

	static ControlGameInstance point;
	return &point;
}
void ControlGameInstance::SetPlayerPointX(int PointX) {
	playerPointX = PointX;
}

void ControlGameInstance::SetPlayerPointY(int PointY) {
	playerPointY = PointY;
}

void ControlGameInstance::SetNewbeiEnemyPointX(int PointX) {
	NewbeiEnemyPointX = PointX;
}

void ControlGameInstance::SetNewbeiEnemyPointY(int PointY) {
	NewbeiEnemyPointY = PointY;
}


void ControlGameInstance::SetCharacterId(int charaId) {
	 characterId = charaId;
}

void ControlGameInstance::SetStageId(int stageId) {
	StageSelectId = stageId;
}

void ControlGameInstance::SetPlayerHitAria(int cx, int cy, int cr) {
	playerPointCenterX = cx;
	playerPointCenterY = cy;
	playerPointRadius = cr;
}

void ControlGameInstance::SetEnemyHitAria(int cx, int cy, int cr) {
	enemyPointCenterX = cx;
	enemyPointCenterY = cy;
	enemyPointRadius = cr;
}

void ControlGameInstance::SetPlayerBulletHitAria(int cx, int cy, int cr) {
	playerBulletPointCenterX = cx;
	playerBulletPointCenterY = cy;
	playerBulletPointRadius = cr;
}

void ControlGameInstance::SetEnemyBulletHitAria(int cx, int cy, int cr) {
	enemyBulletPointCenterX = cx;
	enemyBulletPointCenterY = cy;
	enemyBulletPointRadius = cr;
}




int ControlGameInstance::GetPlayerPointX() {
	return playerPointX;
}

int ControlGameInstance::GetPlayerPointY() {
	return playerPointY;
}

int ControlGameInstance::GetNewbeiEnemyPointX() {
	return NewbeiEnemyPointX;
}

int ControlGameInstance::GetNewbeiEnemyPointY() {
	return NewbeiEnemyPointY;
}



int ControlGameInstance::GetCharacterId() {
	return characterId;
}

int ControlGameInstance::GetStageId() {
	return StageSelectId;
}

bool ControlGameInstance::GetPlayerDeadFlag() {
	return playerDeadFlag;
}

bool ControlGameInstance::EnemyBulletToPlayerHitTest() {
	int xLength = enemyBulletPointCenterX - playerPointCenterX;
	int yLength = enemyBulletPointCenterY - playerPointCenterY;
	int rLength = enemyBulletPointRadius + playerPointRadius;

	
	if (rLength * rLength >= (xLength * xLength) + (yLength * yLength)) {
		playerDeadFlag = true;
		return true;
	}
	else {
		playerDeadFlag = false;
		return	false;
	}
}

bool ControlGameInstance::PlayerBulletToEnemyHitTest() {
	int xLength = playerBulletPointCenterX - enemyPointCenterX;
	int yLength = playerBulletPointCenterY - enemyPointCenterY;
	int rLength = playerBulletPointRadius + enemyPointRadius;

	if (rLength * rLength >= (xLength * xLength) + (yLength * yLength)) {
		return true;
	}
	else {
		return	false;
	}
}

