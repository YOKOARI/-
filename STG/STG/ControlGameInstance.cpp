#include "ControlGameInstance.h"



ControlGameInstance::ControlGameInstance() {
}


ControlGameInstance::~ControlGameInstance() {
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

void ControlGameInstance::SetPlayerBulletId(int bulletID) {
	bulletId = bulletID;
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

void ControlGameInstance::SetPlayerBulletHitAria(int id, int cx, int cy, int cr) {
	playerBulletPointCenterX[id] = cx;
	playerBulletPointCenterY[id] = cy;
	playerBulletPointRadius = cr;
}

void ControlGameInstance::SetEnemyBulletHitAria(int cx, int cy, int cr) {
	enemyBulletPointCenterX = cx;
	enemyBulletPointCenterY = cy;
	enemyBulletPointRadius = cr;
}

void ControlGameInstance::SetCurrentBulletNumber(int number) {
	currentNumber = number;
}

//’e‚ª“–‚½‚Á‚½“G‚ÌID‚ðŠi”[
void ControlGameInstance::SetEnemyHitFlag(int playerBulletId,bool flag) {
	enemyHitFlag[playerBulletId] = flag;
}

int ControlGameInstance::GetBulletId() {
	return bulletId;
}

int ControlGameInstance::GetPlayerPointX() {
	return playerPointX;
}

int ControlGameInstance::GetCurrentBulletNumber() {
	return currentNumber;
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

bool ControlGameInstance::GetPlayerHitFlag() {
	return playerHitFlag;
}

//’e‚ª“–‚½‚Á‚½“G‚ÌID‚ðŽæ“¾
bool ControlGameInstance::GetEnemyHitFlag(int playerBulletNumber) {
	int flg = enemyHitFlag[playerBulletNumber];
	enemyHitFlag[playerBulletNumber] = false;
	return flg;
}

bool ControlGameInstance::EnemyBulletToPlayerHitTest() {
	int xLength = enemyBulletPointCenterX - playerPointCenterX;
	int yLength = enemyBulletPointCenterY - playerPointCenterY;
	int rLength = enemyBulletPointRadius + playerPointRadius;

	
	if (rLength * rLength >= (xLength * xLength) + (yLength * yLength)) {
		playerHitFlag = true;
		return true;
	}
	else {
		playerHitFlag = false;
		return	false;
	}
}

bool ControlGameInstance::PlayerBulletToEnemyHitTest(int playerBulletID) {
	int xLength = playerBulletPointCenterX[playerBulletID] - enemyPointCenterX;
	int yLength = playerBulletPointCenterY[playerBulletID] - enemyPointCenterY;
	int rLength = playerBulletPointRadius + enemyPointRadius;

	if (rLength * rLength >= (xLength * xLength) + (yLength * yLength)) {
		SetEnemyHitFlag(playerBulletID, true);
		return true;
	}
	else {
		SetEnemyHitFlag(playerBulletID,false);
		return	false;
	}
}

