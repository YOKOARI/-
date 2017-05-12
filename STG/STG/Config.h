#pragma once
#include"SceneTask.h"

class Config : public SceneTask {

public:
	Config(ISceneChanger* changer);
	~Config();

private:
	virtual void Init() override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Final() override;

	int cGraphicHandle[5];
	int mIndex;
	int cut;

};

