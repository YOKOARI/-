#pragma once

#include "ISceneChanger.h"
#include "IScene.h"
#include <windows.h>


class SceneManager : public ISceneChanger, IScene {

private:
	IScene* mScene;
	eScene mNextScene;

	
	int gHandle;

public:
	SceneManager();
	~SceneManager();
	void Init() override;//������
	void Final() override;//�I������
	void Update() override;//�X�V
	void Render() override;//�`��
	
	 // ���� nextScene �ɃV�[����ύX����
	void ChangeScene(eScene NextScene) override;


};

