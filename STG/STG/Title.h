
#pragma once

#include"ISceneChanger.h"
#include"SceneTask.h"
#include "DxLib.h"

class Title:public SceneTask{

public:
	
	Title(ISceneChanger* changer);
	~Title();
	virtual void Init() override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Final()override;
	
};

