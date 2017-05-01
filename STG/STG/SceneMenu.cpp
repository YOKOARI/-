#include "SceneMenu.h"
#include "DxLib.h"
#include "DebugManager.h"
SceneMenu::SceneMenu(ISceneChanger* changer) :SceneTask(changer) {
}


SceneMenu::~SceneMenu()
{
}
void SceneMenu::Init() {
	
}

//更新
void SceneMenu::Update() {

	if (CheckHitKey(KEY_INPUT_G) != 0) {
			DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Game);
			mChangeScene->ChangeScene(eScene_CharSelectMenu);//シーンをゲーム画面に変更
			
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Config);
		mChangeScene->ChangeScene(eScene_Config);//シーンを設定画面に変更s
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Title);
		mChangeScene->ChangeScene(eScene_Title);

	}
}




//描画
void SceneMenu::Render() {
	SceneTask::Render();//親クラスの描画メソッドを呼ぶ
	DrawString(0, 0, "Menu", GetColor(255, 255, 255));
}

void SceneMenu::Final() {
	SceneTask::Final();
}

