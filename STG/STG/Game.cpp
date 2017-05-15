#include "DxLib.h"
#include "Game.h"
#include "DebugManager.h"



Game::Game(ISceneChanger* changer) :SceneTask(changer) {

}


Game::~Game() {}

void Game::Init() {
	
	charaMgr.Initialize();
}
void Game::Update() {

	charaMgr.Update();
	
}
void Game::Render() {
	//DrawExtendGraph(0, 0, 800, 720, gHandle, TRUE);

	charaMgr.Render();


	SceneTask::Render();
	
}

void Game::Final() {
	charaMgr.Finalize();
	SceneTask::Final();	
}