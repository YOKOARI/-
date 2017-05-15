#include "SceneGameclear.h"
#include "DXlib.h"

#define RESULT_IMAGE LoadGraph("Image/Result.png") 
#define FONT_SIZE 30

Gameclear::Gameclear(ISceneChanger* changer) :SceneTask(changer){
	
}


Gameclear::~Gameclear(){

}

void Gameclear::Init() {


	//�F�̎擾
	BlackColor = GetColor(0, 0, 0); //�����F(��)

	mGraphicHandle = 0;
	//�w�i�摜�̎擾
	imgBack = RESULT_IMAGE;

	//�u�X�R�A�v�̃t�H���g�T�C�Y
	fontSizeScore = FONT_SIZE;

	//�u�G�e��𐔁v�̃t�H���g�T�C�Y
	fontSizeEbullet = FONT_SIZE;
	
	//�u�c��c�@���v�̃t�H���g�T�C�Y
	fontSizePlayhp = FONT_SIZE;

}

void Gameclear::Final() {
	SceneTask::Final();
}

void Gameclear::Render() {
	SceneTask::Render();
	
	LoadGraphScreen(0, 0, "Image/Result.png", TRUE);
	SetFontSize(fontSizeScore);
	DrawString(400, 220, "�X�R�A  �E�E�E%d", BlackColor);
	SetFontSize(fontSizeEbullet);
	DrawString(400, 320, "�G�e����E�E�E%d", BlackColor);
	SetFontSize(fontSizePlayhp);
	DrawString(400, 420, "�c��c�@�E�E�E%d", BlackColor);
}

void Gameclear::Update() {

	if (CheckHitKey(KEY_INPUT_RETURN) != 0) {
		mChangeScene->ChangeScene(eScene_Title);
	}
}
