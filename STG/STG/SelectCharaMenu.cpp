#include "SelectCharaMenu.h"
#include "DxLib.h"
#include "ISceneChanger.h"
#include "SceneTask.h"

#define CHARASELECT_IMAGE LoadGraph("Image/SelectBack.png")      //背景画像の読み込み
#define CHARAINFO_IMAGE LoadGraph("Image/CharaInfo.png")         //キャラ情報画像の読み込み

#define BLUE_YOKOARI LoadDivGraph("Image/YokoariBlue.png",2,2,1,290,280,modeYokoariBlue);
#define RED_YOKOARI LoadDivGraph("Image/YokoariRed.png",2,2,1,290,280,modeYokoariRed);

#define BLUE_X 235    //ヨコアリ君(青)のｘ座標
#define RED_X  810    //ヨコアリ君(赤)のｘ座標
#define YOKOARI_Y 250 //ヨコアリ君(両方)のｙ座標



SelectCharaMenu::SelectCharaMenu(ISceneChanger* changer) :SceneTask(changer) {
}

SelectCharaMenu::~SelectCharaMenu() {
}

void SelectCharaMenu::Init() {
	SceneTask::Init();

	//フラグの初期化
	charaSelect = true;

	//ヨコアリ君の状態を初期化(棒立ち)
	flgBlue = 0;
	flgRed = 0;

	//画像の取得
	imgBack = CHARASELECT_IMAGE;    //背景
	imgInfo = CHARAINFO_IMAGE;      //キャラ情報

	imgYokoariBlue = BLUE_YOKOARI;  //ヨコアリ君(青)
	imgYokoariRed = RED_YOKOARI;    //ヨコアリ君(赤)
	
	//色の取得
	blueColor = GetColor(0, 0, 255); //アイコン色(青)

} 

void SelectCharaMenu::Update() {
	SceneTask::Update();
	/*if (CheckHitKey(KEY_INPUT_G) != 0) {

		mChangeScene->ChangeScene(eScene_Game);
	}*/

	//左右キーでキャラクター選択
	if (CheckHitKey(KEY_INPUT_LEFT) != 0) {

		//青ヨコアリ君選択状態
		charaSelect = true;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {

		//赤ヨコアリ君選択状態
		charaSelect = false;
	}

	//選択キャラの判定
	if (charaSelect == true)
	{
		//選択アイコン移動
		selectImageX = 220;

		//Enterキーでキャラ決定
		if (CheckHitKey(KEY_INPUT_RETURN) != 0)
		{
			//キャラの手を挙げる(青)
			flgBlue = 1;

			//ゲーム画面へ
			mChangeScene->ChangeScene(eScene_Game);
		}
	}
	else
	{
		//選択アイコン移動
		selectImageX = 800;

		//Enterキーでキャラ決定
		if (CheckHitKey(KEY_INPUT_RETURN) != 0)
		{
			//キャラの手を挙げる(赤)
			flgRed = 1;

			//ゲーム画面へ
			mChangeScene->ChangeScene(eScene_Game);
		}
	}
}

void SelectCharaMenu::Render() {
	SceneTask::Render();
	//DrawString(0, 0,"SelectCharMenu" ,(255, 255, 255));

	//背景とキャラ情報の描画
	DrawGraph(0, 0, imgBack, false);
	DrawGraph(0, 0, imgInfo, true);

	//キャラクターの描画
	DrawGraph(BLUE_X, YOKOARI_Y, modeYokoariBlue[flgBlue], true);
	DrawGraph(RED_X, YOKOARI_Y, modeYokoariRed[flgRed], true);

	//選択アイコンの描画
	DrawTriangle(selectImageX, 540, selectImageX, 590, selectImageX + 40, 565, blueColor, TRUE);
}

void SelectCharaMenu::Final() {
	SceneTask::Final();
}