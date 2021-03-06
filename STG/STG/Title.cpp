#include "Title.h"
#include "DxLib.h"
#include "DebugManager.h"

#define TITLE_IMAGE LoadGraph("Image/Title.png") //背景画像の読み込み
#define NOMAL_FONT_SIZE 40  //選択されているときのフォントサイズ
#define BIG_FONT_SIZE 52    //選択されてないいときのフォントサイズ

#define TITLE_BGM LoadSoundMem("Sound/TITLE.mp3");
#define SELECT_SE LoadSoundMem("Sound/cursor1.mp3")
#define START_SE LoadSoundMem("Sound/GameStart.mp3")
#define END_SE LoadSoundMem("Sound/GameEnd.mp3")

Title::Title(ISceneChanger* changer):SceneTask(changer){

}


Title::~Title(){

}

void Title::Init() {

	//ゲーム開始・終了フラグの初期化
	selectFlag = true;

	//背景画像の取得
	imgBack = TITLE_IMAGE;

	//色の取得
	blackColor = GetColor(0, 0, 0); //文字色(黒)
	blueColor = GetColor(0, 0, 255); //アイコン色(青)

	//フォントの取得
	ChangeFont("ニコモジ＋");
	fontSizeStart = BIG_FONT_SIZE;
	fontSizeEnd = NOMAL_FONT_SIZE;

	mSoundPlayHandle = TITLE_BGM;
	
}

void Title::Update(){
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mChangeScene->ChangeScene(eScene_Scene_Menu);
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::SucsseceLord);
	}

	SceneTask::Update();

	//上下キーで選択状況の変更
	if (CheckHitKey(KEY_INPUT_UP) != 0) {

		//効果音再生
		PlaySoundMem(SELECT_SE, DX_PLAYTYPE_BACK, FALSE);  

		//ゲームスタート！状態
		selectFlag = true;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) != 0) {

		//効果音再生
		PlaySoundMem(SELECT_SE, DX_PLAYTYPE_BACK, FALSE);

		//ゲーム終了！状態
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

			//効果音再生
			PlaySoundMem(START_SE, DX_PLAYTYPE_BACK, FALSE);

			mChangeScene->ChangeScene(eScene_CharSelectMenu);
		}
		//ゲーム終了
		else {

			//効果音再生
			PlaySoundMem(END_SE, DX_PLAYTYPE_BACK, FALSE);

			WaitTimer(300);

			DxLib_End();
		}
	}
}

void Title::Render() {
	//DrawString(0, 0, "Title", GetColor(255, 255, 255));

	//背景の描画
	DrawGraph(0, 0, imgBack, false);

	//テキストの描画
	SetFontSize(fontSizeStart);
	DrawString(550, 320, "ゲームスタート！", blackColor);

	SetFontSize(fontSizeEnd);
	DrawString(550, 400, "ゲーム終了！", blackColor);

	//選択アイコンの描画
	DrawTriangle(500, selectImageY, 500, selectImageY + 40, 540, selectImageTy, blueColor, TRUE);


	SceneTask::Render();
	
}
void Title::Final() {
	SceneTask::Final();

	//画像の破棄
	InitGraph();

	//音楽の破棄
	//InitSoundMem();
	DeleteSoundMem(SELECT_SE);
	DeleteSoundMem(START_SE);
	DeleteSoundMem(END_SE);
}