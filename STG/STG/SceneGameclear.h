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
	int BlackColor;      //�t�H���g�F(��)
	int fontSizeScore;   //�u�X�R�A�v�̃t�H���g�T�C�Y
	int fontSizeEbullet; //�u�G�e��𐔁v�̃t�H���g�T�C�Y
	int fontSizePlayhp;  //�u�c��c�@���v�̃t�H���g�T�C�Y	
	int imgBack;         //�w�i�摜
};

