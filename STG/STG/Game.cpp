#include "DxLib.h"
#include "Game.h"




Game::Game(ISceneChanger* changer) :SceneTask(changer) {

	return;
}


Game::~Game() {}

void Game::Init() {
	charaMgr.Initialize();
}
void Game::Update() {
	if (CheckHitKey(KEY_INPUT_P) == 1) {
		mChangeScene->ChangeScene(eScene_Scene_Menu);
	}
	charaMgr.Update();

}
void Game::Render() {
	DrawExtendGraph(0, 0, 800, 720, gHandle, TRUE);
	charaMgr.Render();
	SceneTask::Render();

	
}

void Game::Final() {
	charaMgr.Finalize();
	SceneTask::Final();

	
}