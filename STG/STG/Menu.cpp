#include "Menu.h"
#include "DxLib.h"
#include "DebugManager.h"
Menu::Menu(ISceneChanger* changer) :SceneTask(changer) {
}


Menu::~Menu()
{
}
void Menu::Init() {
	
}

//更新
void Menu::Update() {

	if (CheckHitKey(KEY_INPUT_G) != 0) {
			DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Game);
			mChangeScene->ChangeScene(eScene_Game);//シーンをゲーム画面に変更
			
	}
		
			//DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Config);
			//mChangeScene->ChangeScene(eScene_Config);//シーンを設定画面に変更s
			
	if (CheckHitKey(KEY_INPUT_A) != 0) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Title);
		mChangeScene->ChangeScene(eScene_Title);

	}/*
	if (CheckHitKey(KEY_INPUT_C) != 0) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Record);
		mChangeScene->ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}*/


}




//描画
void Menu::Render() {
	SceneTask::Render();//親クラスの描画メソッドを呼ぶ
	DrawString(0, 0, "Menu", GetColor(255, 255, 255));
}

void Menu::Final() {
	SceneTask::Final();
}

