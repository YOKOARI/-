#include "DxLib.h"
#include "Game.h"
#include "DebugManager.h"
#include "ControlGameInstance.h"


Game::Game(ISceneChanger* changer) :SceneTask(changer) {

}


Game::~Game() {}

void Game::Init() {
	
	stageMgr.Initialize();
}
void Game::Update() {

	stageMgr.Update();
	if (ControlGameInstance::GetInstance()->GetEnemyDeadFlag(18) == true) {
		mChangeScene->ChangeScene(eScene_GameClear);
	}
}
void Game::Render() {
	//DrawExtendGraph(0, 0, 800, 720, gHandle, TRUE);

	stageMgr.Render();


	SceneTask::Render();
	
}

void Game::Final() {
	stageMgr.Finalize();
	SceneTask::Final();	
}