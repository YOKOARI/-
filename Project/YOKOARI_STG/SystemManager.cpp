/**************************************************
* 作成者：杉山 涼
* 概要　：ゲームを立ち上げる際のすべての初期化・準備
* その他：ゲームループはここに存在します。
***************************************************/

#include "SystemManager.h"
#include "DebugManager.h"
#include "DxLib.h"

SystemManager::SystemManager() {
}


SystemManager::~SystemManager() {
}

void SystemManager::Initialize() {

	//ウインドウサイズ・ウインドウモードの取得
	SelectWindowMode(1280, 720);

	//ウインドウテキストの取得
	SetMainWindowText("新横浜物語");

	//マウスカーソルを表示するか設定する　TRUE：表示　FALSE：非表示
	GetMouseDispFlag();

	//ウインドウの二重生成ができるかを設定する　TRUE：可能　FALSE：不可能
	SetDoubleStartValidFlag(FALSE);

	//裏画面をセット
	SetDrawScreen(DX_SCREEN_BACK);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {

		//初期化に失敗した場合は即座にプログラム終了させる
		DebugManager::Instance()->SystemErorr(DebugManager::SystemErrorType::FailedInitialize);
		exit(-1);
	}
}

void SystemManager::Update() {

	//ゲームの初期化
	Initialize();
	
	//メインループ
	while (ProcessMessage() != -1) {


		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			if (IsGameEnd() == TRUE)break;
		}
	}

	//メモリの開放
	Finalize();

}


void SystemManager::Finalize() {

	DxLib_End();
}

void SystemManager::SelectWindowMode(int width, int height) {

	int windowModeFlag;

	windowModeFlag = MessageBox(NULL, "フルスクリーンモードで起動しますか？", "スクリーン設定", MB_YESNO | MB_ICONQUESTION);

	windowModeFlag == IDNO ? ChangeWindowMode(TRUE) : ChangeWindowMode(FALSE);

	SetGraphMode(width, height, 32);

}

bool SystemManager::IsGameEnd() {
	
	gameEndFlag = (MessageBox(GetMainWindowHandle(), "ゲームを終了しますか？", "", MB_YESNO | MB_ICONQUESTION) == IDNO) ? FALSE : TRUE;

	return gameEndFlag;
}