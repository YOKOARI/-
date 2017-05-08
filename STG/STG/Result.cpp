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
	

	DrawString(0, 20, "�X�y�[�X�L�[�������ƃ��j���[��ʂɐi�݂܂��B", GetColor(255, 255, 255));
}

void Result::Update() {

	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mChangeScene->ChangeScene(eScene_Scene_Menu);
	}
}
