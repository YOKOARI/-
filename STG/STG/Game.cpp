#include "DxLib.h"
#include "Game.h"




Game::Game(ISceneChanger* changer) :SceneTask(changer) {

	return;
}


Game::~Game() {}

void Game::Init() {
	
}
void Game::Update() {
	if (CheckHitKey(KEY_INPUT_P) == 1) {
		mChangeScene->ChangeScene(eScene_Scene_Menu);
	}


}
void Game::Render() {
	DrawExtendGraph(0, 0, 800, 720, gHandle, TRUE);
	DrawString(0, 0, "ƒQ[ƒ€‰æ–Ê", GetColor(255, 255, 255));
	SceneTask::Render();
	
}

void Game::Final() {
	SceneTask::Final();

	
}