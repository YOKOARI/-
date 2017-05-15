#pragma once
#include "SceneTask.h"
class Gameover : public SceneTask
{
public:
	Gameover(ISceneChanger* changer);
	~Gameover();
	virtual void Update()override;
	virtual void Render()override;

	int GameoverUIGHandle[5] = { 0 };

private:
	virtual void Init() override;
	virtual void Final() override;
	int imgBack;         //”wŒi‰æ‘œ
};



