#pragma once
#include "SceneTask.h"
#include "ISceneChanger.h"
class SelectCharaMenu :public SceneTask {
public:
	SelectCharaMenu(ISceneChanger* changer);
	~SelectCharaMenu();
	void Init() override;    //�������������I�[�o�[���C�h
	void Final() override;   //�I���������I�[�o�[���C�h�B
	void Update() override;        //�X�V�������I�[�o�[���C�h�B
	void Render() override;       //�`�揈�����I�[�o�[���C�h�B
};

