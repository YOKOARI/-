#include"Config.h"
#include"DxLib.h"


Config::Config(ISceneChanger* changer):SceneTask(changer){

}


Config::~Config(){
	
}

void Config::Init() {
	
}
void Config::Update() {
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mChangeScene->ChangeScene(eScene_Scene_Menu);
	}

}

void Config::Render() {
	SceneTask::Render();
	
}


void Config::Final() {
	SceneTask::Final();
}
