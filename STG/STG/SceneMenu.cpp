#include "SceneMenu.h"
#include "DxLib.h"
#include "DebugManager.h"
SceneMenu::SceneMenu(ISceneChanger* changer) :SceneTask(changer) {
}


SceneMenu::~SceneMenu() {
}

/****************************************************
*　初期化処理
*　　ここに画像のロードや、変数の初期化を行います。
*
*
****************************************************/
void SceneMenu::Init() {
	
}

//更新
void SceneMenu::Update() {

	if (CheckHitKey(KEY_INPUT_M) != 0) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::SucsseceLord);
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
	DrawString(0, 0, "SceneMenu", GetColor(255, 255, 255));
}

void SceneMenu::Final() {
	SceneTask::Final();
}

