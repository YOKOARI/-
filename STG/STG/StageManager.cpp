#include "StageManager.h"
#include "FirstStage.h"


StageManager::StageManager()
{
}


StageManager::~StageManager()
{
}

int StageManager::Initialize() {
	mStage = new FirstStage;
	mStage->Initialize();
	return 0;
}

int StageManager::Update() {
	mStage->Update();
	return 0;
}

int StageManager::Render() {
	mStage->Render();
	return 0;
}

int StageManager::Finalize() {
	mStage->Finalize();
	return 0;

}