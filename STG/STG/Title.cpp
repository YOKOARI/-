#include "Title.h"
#include "DxLib.h"
#include "DebugManager.h"

#define TITLE_IMAGE LoadGraph("Image/Title.png") 
#define NOMAL_FONT_SIZE 40
#define BIG_FONT_SIZE 52

Title::Title(ISceneChanger* changer):SceneTask(changer){

}


Title::~Title()
{
}
void Title::Init() {

	selectFlag = true;

	//背景画像の取得
	imgBack = TITLE_IMAGE;

	//色の取得
	BlackColor = GetColor(0, 0, 0); //文字色(黒)
	blueColor = GetColor(0, 0, 255); //アイコン色(青)

	//フォントの取得
	ChangeFont("ニコモジ＋");
	fontSizeStart = BIG_FONT_SIZE;
	fontSizeEnd = NOMAL_FONT_SIZE;
	
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

	//矢印アイコンの座標値を変え,フォントサイズも変える
	if (selectFlag == true) {
		selectImageY = 322;
		selectImageTy = 342;

		fontSizeStart = BIG_FONT_SIZE;
		fontSizeEnd = NOMAL_FONT_SIZE;
	}
	else {
		selectImageY = 405;
		selectImageTy = 425;

		fontSizeStart = NOMAL_FONT_SIZE;
		fontSizeEnd = BIG_FONT_SIZE;
	}

	//Enterキーで決定
	if (CheckHitKey(KEY_INPUT_RETURN) != 0) {

		//ゲーム開始
		if (selectFlag == true) {
			mChangeScene->ChangeScene(eScene_CharSelectMenu);
		}
		//ゲーム終了
		else {
			DxLib_End();
		}
	}
}

void Title::Render() {
	//DrawString(0, 0, "Title", GetColor(255, 255, 255));

	DrawGraph(0, 0, imgBack, false);

	SetFontSize(fontSizeStart);
	DrawString(550, 320, "ゲームスタート！", BlackColor);

	SetFontSize(fontSizeEnd);
	DrawString(550, 400, "ゲーム終了！", BlackColor);

	DrawTriangle(500, selectImageY, 500, selectImageY + 40, 540, selectImageTy, blueColor, TRUE);


	SceneTask::Render();
	
}
void Title::Final() {
	SceneTask::Final();
}