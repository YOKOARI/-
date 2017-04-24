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
	SelectWindowMode(1280, 720);

	SetMainWindowText("新横浜物語");

	SetDrawScreen(DX_SCREEN_BACK);

	if (DxLib_Init() == -1) {
		DebugManager::Instance()->SystemErorr(DebugManager::SystemErrorType::FailedInitialize);
		exit(-1);
	}
}

void SystemManager::Update() {

	Initialize();
	
	while(ProcessMessage() != -1 && DebugManager::Instance()->GetEndFlag() != false)

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