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
		mChangeScene->ChangeScene(eScene_Menu);
	}

}

void Config::Render() {
	SceneTask::Render();
	
}


void Config::Final() {
	SceneTask::Final();
}
void Config::DrawGroud(int x, int y) {

	DrawExtendGraph(x, y, x + 150, y + 100, cGraphicHandle[mIndex], TRUE);
	if (mIndex == 1) {
		if (cut == 25) {
			mIndex = 2;
		}
		cut++;
	}
	if (mIndex == 2) {
		if (cut == 0) {
			mIndex = 1;
		}
		cut--;
	}
}