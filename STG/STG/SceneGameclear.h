#pragma once
#include "SceneTask.h"
class Gameclear : public SceneTask{
public:
	Gameclear(ISceneChanger* changer);
	~Gameclear();
	virtual void Update()override;
	virtual void Render()override;
	
	int ResultUIGHandle[5] = { 0 };
private:
	virtual void Init() override;
	virtual void Final() override;
	int BlackColor;      //フォント色(黒)
	int fontSizeScore;   //「スコア」のフォントサイズ
	int fontSizeEbullet; //「敵弾回避数」のフォントサイズ
	int fontSizePlayhp;  //「残り残機数」のフォントサイズ	
	int imgBack;         //背景画像
};

