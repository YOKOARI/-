#include "Title.h"
#include "DxLib.h"
#include "DebugManager.h"


Title::Title(ISceneChanger* changer):SceneTask(changer){

}


Title::~Title()
{
}
void Title::Init() {
	//色の取得
	int whiteColor = GetColor(255, 255, 255); //文字色(白)
	int blueColor = GetColor(0, 0, 255); //アイコン色(青)
}

void Title::Update(){
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mChangeScene->ChangeScene(eScene_Scene_Menu);
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::SucsseceLord);
	}

	//上下キーで選択状況の変更
	if (CheckHitKey(KEY_INPUT_UP) != 0) {
		selectFlag = true;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
		selectFlag = false;
	}
}

void Title::Render() {
	//DrawString(0, 0, "Title", GetColor(255, 255, 255));

	TitleSelect();

	SceneTask::Render();
	
}
void Title::Final() {
	SceneTask::Final();
}

/***************************************************************
*関数名 : TitleSelect()
*製作者 :鈴木 正太
*概要 : ゲームスタートと終了を表示し、キーボードで選択させる。
*引数 : なし
*戻り値 : なし
*備考 : なし
****************************************************************/
void Title::TitleSelect() {

	

	SetFontSize(fontSizeStart);  //文字サイズ変更
	DrawString(550, 320, "ゲームスタート！", whiteColor);

	SetFontSize(fontSizeEnd);
	DrawString(550, 380, "ゲーム終了！", whiteColor);

	if (selectFlag == true) {
		selectImageY = 320;
		selectImageTy = 335;

		fontSizeStart = 30;
		fontSizeEnd = 24;
	}
	else {
		selectImageY = 380;
		selectImageTy = 395;

		fontSizeStart = 24;
		fontSizeEnd = 30;
	}
	DrawTriangle(500, selectImageY, 500, selectImageY+30, 530, selectImageTy, blueColor, TRUE);

	//Zキーで決定
	if (CheckHitKey(KEY_INPUT_Z) != 0) {
		//ゲーム開始
		if (selectFlag == true) {

		}
		//ゲーム終了
		else {
			DxLib_End();
		}
	}
}
