
#pragma once

#include"ISceneChanger.h"
#include"SceneTask.h"
#include "DxLib.h"

class Title:public SceneTask{
private:
	bool selectFlag;     //�Q�[���J�n���I���̔���t���O
	int selectImageY;    //�I���A�C�R���̂����W
	int selectImageTy;   //�I���A�C�R���̐�[�����W
	int fontSizeStart;   //�t�H���g�T�C�Y
	int fontSizeEnd;     //�t�H���g�T�C�Y
	int BlackColor;      //�t�H���g�F(��)
	int blueColor;       //���A�C�R���F(��)
	int imgBack;         //�w�i�摜


public:
	
	Title(ISceneChanger* changer);
	~Title();
	virtual void Init() override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Final()override;
	
};

