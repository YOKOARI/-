#include "DebugManager.h"
#include "DxLib.h"

/*************************************************************************************
*　機能　：　コンストラクタ
*　引数　：　NULL
*　戻り値：　NULL
**************************************************************************************/
DebugManager::DebugManager() {

	//ゲームの終了フラグの初期化
	errorEndFlag = false;
}

/*************************************************************************************
*　機能　：　インスタンスのポインタを取得
*　引数　：　NULL
*　戻り値：　&DebugManager::point
**************************************************************************************/
DebugManager* DebugManager::Instance() {

	//クラスメンバーの生成
	static DebugManager point;

	//インスタンスのポインタをリターン
	return &point;
}

/*************************************************************************************
*　機能　：　ゲームの終了フラグを取得する
*　引数　：　NULL
*　戻り値：　errorEndFlag
**************************************************************************************/
bool DebugManager::GetEndFlag() {

	//ゲームの終了フラグをリターン
	return errorEndFlag;
}

/*************************************************************************************
*　機能　：　システムのエラーを表示する
*　引数　：　SystemErrorType errorType
*　戻り値：　NULL
**************************************************************************************/
void DebugManager::SystemErorr(SystemErrorType errorType) {

	//エラーのタイプで分岐
	switch (errorType) {

		//初期化失敗
		case SystemErrorType::FailedInitialize:

			//初期化が失敗したことを通知
			MessageBox(NULL, "FAILED_INITIALIZE", "SYSTEM_ERROR", MB_OK);

			//ゲームの終了フラグをTRUEにする
			errorEndFlag = true;
			break;
	}
}


/*************************************************************************************
*　機能　：　描画のエラーを表示する
*　引数　：　RenderErrorType errorType
*　戻り値：　NULL
**************************************************************************************/
void DebugManager::RenderError(RenderErrorType errorCord) {

	//エラーのタイプで分岐
	switch (errorCord) {

		//読み込み失敗
		case RenderErrorType::FailedLord:

			//読み込みに失敗したことを通知
			MessageBox(NULL, "FAILED_LORD", "RENDER_ERROR", MB_OK);
			break;
	}
}

/*************************************************************************************
*　機能　：　現在のシーンを通知する
*　引数　：　SceneType sceneType
*　戻り値：　NULL
**************************************************************************************/
void DebugManager::ReviewScene(SceneType sceneType) {
	 
	//シーンのタイプで分岐
	switch (sceneType) {

		//シーンがゲームの場合
		case SceneType::Game:

			//シーンがゲームに遷移できなかったことを通知
			MessageBox(NULL, "FAILED ROAD TO GAME", "SCENE_ERROR", MB_OK);
			break;

		//シーンが設定の場合
		case SceneType::Config:

			//シーンが設定に遷移できなかったことを通知
			MessageBox(NULL, "FAILED ROAD TO CONFIG", "SCENE_ERROR", MB_OK);
			break;

			//シーンがメニューの場合
		case SceneType::Menu:

			//シーンがメニューに遷移できなかったことを通知
			MessageBox(NULL, "FAILED ROAD TO MENU", "SCENE_ERROR", MB_OK);
			break;

			//シーンがタイトルの場合
		case SceneType::Title:

			//シーンがタイトルに遷移できなかったことを通知
			MessageBox(NULL, "FAILED ROAD TO TITLE", "SCENE_ERROR", MB_OK);
			break;

			//シーンがリザルトの場合
		case SceneType::Resoult:

			//シーンがタイトルに遷移できなかったことを通知
			MessageBox(NULL, "FAILED ROAD TO RESOULT", "SCENE_ERROR", MB_OK);
			break;

	}
}