#pragma once

#include "SceneTask.h"
#include "ISceneChanger.h"
class Menu :public SceneTask {
public:
	Menu(ISceneChanger* changer);
	~Menu();
	void Init() override;    //�������������I�[�o�[���C�h
	void Final() override;   //�I���������I�[�o�[���C�h�B
	void Update() override;        //�X�V�������I�[�o�[���C�h�B
	void Render() override;       //�`�揈�����I�[�o�[���C�h�B

private:
	
	
};
