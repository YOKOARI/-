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
	void Init() override;//初期化
	void Final() override;//終了処理
	void Update() override;//更新
	void Render() override;//描画
	
	 // 引数 nextScene にシーンを変更する
	void ChangeScene(eScene NextScene) override;


};

