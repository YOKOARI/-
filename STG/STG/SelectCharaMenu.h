#pragma once
#include "SceneTask.h"
#include "ISceneChanger.h"
class SelectCharaMenu :public SceneTask {
private:
	int imgBack;  //�w�i�摜
	int imgInfo;  //�L�������摜

	int imgYokoariBlue;      //���R�A���N�摜(��)
	int imgYokoariRed;       //���R�A���N�摜(��)
	int modeYokoariBlue[2];  //���R�A���N(��)�̃O���t�B�b�N�n���h���|�C���^
	int modeYokoariRed[2];   //���R�A���N(��)�̃O���t�B�b�N�n���h���|�C���^
	int flgBlue;             //���R�A���N(��)�̉摜�؂�ւ��t���O
	int flgRed;              //���R�A���N(��)�̉摜�؂�ւ��t���O

	int selectImageX;  //�I���A�C�R����x���W
	int selectImageTx; //�I���A�C�R���̐�[x���W
	int blueColor;     //�I���A�C�R���F(��)

	bool charaSelect;  //�L�����N�^�[�̑I���t���O

public:
	SelectCharaMenu(ISceneChanger* changer);
	~SelectCharaMenu();
	void Init() override;    //�������������I�[�o�[���C�h
	void Final() override;   //�I���������I�[�o�[���C�h�B
	void Update() override;  //�X�V�������I�[�o�[���C�h�B
	void Render() override;  //�`�揈�����I�[�o�[���C�h�B
};

