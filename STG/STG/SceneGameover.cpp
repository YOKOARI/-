#include "SceneGameover.h"
#include "DXlib.h"

#define GAMEOVER_IMAGE LoadGraph("Image/Gameover.png") 

Gameover::Gameover(ISceneChanger* changer) :SceneTask(changer){
}


Gameover::~Gameover(){
}

void Gameover::Init() {
	mGraphicHandle = 0;
	//�w�i�摜�̎擾
	imgBack = GAMEOVER_IMAGE;
}

void Gameover::Final() {
	SceneTask::Final();
}

void Gameover::Render() {
	SceneTask::Render();

	LoadGraphScreen(0, 0, "Image/Gameover.png", TRUE);

}

void Gameover::Update() {
	//�G���^�[�L�[�������ƃ^�C�g���֑J��
	if (CheckHitKey(KEY_INPUT_RETURN) != 0) {
		mChangeScene->ChangeScene(eScene_Title);
	}
}
