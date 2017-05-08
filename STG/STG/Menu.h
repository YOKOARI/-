#pragma once

#include "SceneTask.h"
#include "ISceneChanger.h"
class Menu :public SceneTask {
public:
	Menu(ISceneChanger* changer);
	~Menu();
	void Init() override;
	void Final() override;
	void Update() override;
	void Render() override;

private:


};
