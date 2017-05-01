#pragma once
#include "SceneTask.h"
class Result : public SceneTask{
public:
	Result(ISceneChanger* changer);
	~Result();
	virtual void Update()override;
	virtual void Render()override;
	
	int ResultUIGHandle[5] = { 0 };
private:
	virtual void Init() override;
	virtual void Final() override;
};

