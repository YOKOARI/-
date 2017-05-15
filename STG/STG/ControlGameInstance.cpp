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