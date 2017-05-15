#include "SceneGameclear.h"
#include "DXlib.h"

#define RESULT_IMAGE LoadGraph("Image/Result.png") 
#define FONT_SIZE 30

Gameclear::Gameclear(ISceneChanger* changer) :SceneTask(changer){
	
}


Gameclear::~Gameclear(){

}

void Gameclear::Init() {


	//色の取得
	BlackColor = GetColor(0, 0, 0); //文字色(黒)

	mGraphicHandle = 0;
	//背景画像の取得
	imgBack = RESULT_IMAGE;

	//「スコア」のフォントサイズ
	fontSizeScore = FONT_SIZE;

	//「敵弾回避数」のフォントサイズ
	fontSizeEbullet = FONT_SIZE;
	
	//「残り残機数」のフォントサイズ
	fontSizePlayhp = FONT_SIZE;

}

void Gameclear::Final() {
	SceneTask::Final();
}

void Gameclear::Render() {
	SceneTask::Render();
	
	LoadGraphScreen(0, 0, "Image/Result.png", TRUE);
	SetFontSize(fontSizeScore);
	DrawString(400, 220, "スコア  ・・・%d", BlackColor);
	SetFontSize(fontSizeEbullet);
	DrawString(400, 320, "敵弾回避・・・%d", BlackColor);
	SetFontSize(fontSizePlayhp);
	DrawString(400, 420, "残り残機・・・%d", BlackColor);
}

void Gameclear::Update() {

	if (CheckHitKey(KEY_INPUT_RETURN) != 0) {
		mChangeScene->ChangeScene(eScene_Title);
	}
}
