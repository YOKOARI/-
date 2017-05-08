#include "Result.h"
#include "DXlib.h"


Result::Result(ISceneChanger* changer) :SceneTask(changer){
	
}


Result::~Result(){

}

void Result::Init() {
	mGraphicHandle = 0;
	
}

void Result::Final() {
	SceneTask::Final();
}

void Result::Render() {
	SceneTask::Render();
	

	DrawString(0, 20, "スペースキーを押すとメニュー画面に進みます。", GetColor(255, 255, 255));
}

void Result::Update() {

	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mChangeScene->ChangeScene(eScene_Scene_Menu);
	}
}
