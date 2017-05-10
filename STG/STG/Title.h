
#pragma once

#include"ISceneChanger.h"
#include"SceneTask.h"
#include "DxLib.h"

class Title:public SceneTask{
private:
	bool selectFlag;     //ゲーム開始か終了の判定フラグ
	int selectImageY;    //選択アイコンのｙ座標
	int selectImageTy;   //選択アイコンの先端ｙ座標
	int blueColor;       //選択アイコン色(青)
	int BlackColor;      //フォント色(黒)
	int fontSizeStart;   //「ゲームスタート！」のフォントサイズ
	int fontSizeEnd;     //「ゲーム終了！」のフォントサイズ	
	int imgBack;         //背景画像


public:
	
	Title(ISceneChanger* changer);
	~Title();
	virtual void Init() override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Final()override;
	
};

