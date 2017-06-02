/***********************************
*クラス名：SystemManager
*作成者：杉山　涼　
*概要：システムの根幹を担うクラス。
************************************/

#include "systemManager.h"
#include "SceneManager.h"
#include"DebugManager.h"
#include"DxLib.h"


/************************************
*関数名：SystemManager()
*概要：コンストラクタ。コンパイル時にGameIsInit()を呼び出す。
*引数：なし
*戻り値：なし
*備考：なし
*************************************/
SystemManager::SystemManager()
{
	this->GameIsInit();
}

/************************************
 * 関数名：~SystemManager()
 * 概要：デストラクタ・オブジェクト破棄時にGameEnd()を呼び出す
 * 引数：なし
 * 戻り値:なし
 * 備考：なし
 *************************************/
SystemManager::~SystemManager()
{
	this->GameEnd();
}

/************************************
*関数名：GameEnd()
*概要：DXライブラリの終了処理を実行。
*引数：なし
*戻り値：なし
*備考：デストラクタが呼び出されたときに実行
*************************************/
void SystemManager::GameEnd() {

	DxLib_End();

	return;
}

/************************************
*関数名：GetWindowMode()
*概要：ウインドウサイズ、ウインドウモードを取得する関数
*引数：width：ウインドウの横のサイズ　｜　height：ウインドウの縦のサイズ
*戻り値：なし
*備考：GameIsInit()で呼ばれる
*************************************/
void SystemManager::GetWindowMode(int width, int height) {

	    int flag;

		flag = MessageBox(NULL,"フルスクリーンモードで起動しますか？","スクリーン設定",MB_YESNO | MB_ICONQUESTION);
		if (flag == IDNO)
			ChangeWindowMode(TRUE);
			//SetWindowSize(width, height);
			SetGraphMode(width, height,32);
}

/**********************************
*関数名：IsGameEnd();
*概要：ゲーム終了時、本当にゲームを終了するか確認し、誤操作を防ぐ
*引数：なし
*戻り値：TRUE：終了　｜　FALSE：継続
*備考：
***********************************/
bool SystemManager::IsGameEnd() {

	//ホップアップウインドウの設定　戻り値　TRUE：終了　FALSE：継続
	systemEndFlag = MessageBox(GetMainWindowHandle() , "プログラムを終了しますか？", "END", MB_YESNO | MB_ICONQUESTION);

	if (systemEndFlag == IDNO) {

		endFlag = true;
	}
	else {
		endFlag = false;
	}
	
	return	endFlag;
}
 
/**********************************
*関数名：gameIsInit()
*概要：起動時一度だけ行うウインドウ関連の初期化処理
*引数：なし
*戻り値：なし
*戻り値　TRUE：成功　FALSE：失敗
**********************************/
void SystemManager::GameIsInit() {


	//ウインドウサイズ・ウインドウモードの取得
	GetWindowMode(1280, 720);

	//ウインドウテキストの取得
	SetMainWindowText("ヨコアリくん危機一髪");

	//マウスカーソルを表示するか設定する　TRUE：表示　FALSE：非表示
	GetMouseDispFlag();

	//ウインドウの二重生成ができるかを設定する　TRUE：可能　FALSE：不可能
	SetDoubleStartValidFlag(FALSE);

	//裏画面をセット
	SetDrawScreen(DX_SCREEN_BACK);


	//DXライブラリの初期化　返り値　TRUE：成功  FALSE：失敗
	if (DxLib_Init() == -1 ) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::FailedInit);
	}
}

int SystemManager::Update() {

	SceneMgr.Init();

	while (ProcessMessage() != -1 && DebugManager::Instance()->GetEndFlag() != false) {
		
		ClearDrawScreen();

		SceneMgr.Update();
		SceneMgr.Render();

		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			
			this->endFlag = this->IsGameEnd();
			if (this->endFlag == false) {
				SceneMgr.Final();
				break;
			}
		}
	}

	return 0;
}
