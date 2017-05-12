#pragma once
#include "SceneTask.h"
#include "ISceneChanger.h"
class SelectCharaMenu :public SceneTask {
private:
	int imgBack;  //背景画像
	int imgInfo;  //キャラ情報画像

	int imgYokoariBlue;      //ヨコアリ君画像(青)
	int imgYokoariRed;       //ヨコアリ君画像(赤)
	int modeYokoariBlue[2];  //ヨコアリ君(青)のグラフィックハンドルポインタ
	int modeYokoariRed[2];   //ヨコアリ君(赤)のグラフィックハンドルポインタ
	int flgBlue;             //ヨコアリ君(青)の画像切り替えフラグ
	int flgRed;              //ヨコアリ君(赤)の画像切り替えフラグ

	int selectImageX;  //選択アイコンのx座標
	int selectImageTx; //選択アイコンの先端x座標
	int blueColor;     //選択アイコン色(青)

	bool charaSelect;  //キャラクターの選択フラグ

public:
	SelectCharaMenu(ISceneChanger* changer);
	~SelectCharaMenu();
	void Init() override;    //初期化処理をオーバーライド
	void Final() override;   //終了処理をオーバーライド。
	void Update() override;  //更新処理をオーバーライド。
	void Render() override;  //描画処理をオーバーライド。
};

