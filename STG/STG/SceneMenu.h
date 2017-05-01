#pragma once

#include "SceneTask.h"
#include "ISceneChanger.h"
class SceneMenu :public SceneTask {
public:
	SceneMenu(ISceneChanger* changer);
	~SceneMenu();
	void Init() override;    //初期化処理をオーバーライド
	void Final() override;   //終了処理をオーバーライド。
	void Update() override;        //更新処理をオーバーライド。
	void Render() override;       //描画処理をオーバーライド。

private:
	
	
};
