#pragma once
#include "SceneTask.h"
#include "ISceneChanger.h"
class SelectCharaMenu :public SceneTask {
public:
	SelectCharaMenu(ISceneChanger* changer);
	~SelectCharaMenu();
	void Init() override;    //初期化処理をオーバーライド
	void Final() override;   //終了処理をオーバーライド。
	void Update() override;        //更新処理をオーバーライド。
	void Render() override;       //描画処理をオーバーライド。
};

