
#pragma once

#include"ISceneChanger.h"
#include"SceneTask.h"
#include "DxLib.h"

class Title:public SceneTask{
private:
	bool selectFlag;     //�Q�[���J�n���I���̔���t���O
	int selectImageY;    //�I���A�C�R���̂����W
	int selectImageTy;   //�I���A�C�R���̐�[�����W
	int blueColor;       //�I���A�C�R���F(��)
	int BlackColor;      //�t�H���g�F(��)
	int fontSizeStart;   //�u�Q�[���X�^�[�g�I�v�̃t�H���g�T�C�Y
	int fontSizeEnd;     //�u�Q�[���I���I�v�̃t�H���g�T�C�Y	
	int imgBack;         //�w�i�摜


public:
	
	Title(ISceneChanger* changer);
	~Title();
	virtual void Init() override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Final()override;
	
};

