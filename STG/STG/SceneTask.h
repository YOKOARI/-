#pragma once

#include "ISceneChanger.h"
#include"IScene.h"


class SceneTask :public IScene {

protected:
	int mGraphicHandle;
	int mSoundPlayHandle;
	int mSoundPlayFlag = 0;
	ISceneChanger* mChangeScene;

public:
	SceneTask(ISceneChanger* changer);
	virtual ~SceneTask() {};
	virtual void Init() override {};
	virtual void Update()override {};
	virtual void Render()override;
	virtual void Final()override;
};
