
#pragma once

#include"ISceneChanger.h"
#include"SceneTask.h"
#include "DxLib.h"

class Title:public SceneTask{
private:
	bool selectFlag = true;  //ゲーム開始か終了の判定フラグ
	int selectImageY;  //選択アイコンのｙ座標
	int selectImageTy;  //選択アイコンの先端ｙ座標
	int fontSizeStart;  //フォントサイズ
	int fontSizeEnd;
	int whiteColor; 
	int blueColor; 

	void TitleSelect();

public:
	
	Title(ISceneChanger* changer);
	~Title();
	virtual void Init() override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Final()override;
	
};

