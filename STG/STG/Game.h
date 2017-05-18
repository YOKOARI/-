#ifndef _GAME_H_
#define _GAME_H_

#include"SceneTask.h"
#include"ISceneChanger.h"
#include "Result.h"
#include "StageManager.h"


class Game :public SceneTask {
public:
	

	Game(ISceneChanger* changer);
	~Game();
private:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Final() override;
	int gHandle;
	StageManager stageMgr;
};

#endif
