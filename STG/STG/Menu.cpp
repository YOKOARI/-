#include "Menu.h"
#include "DxLib.h"
#include "DebugManager.h"
Menu::Menu(ISceneChanger* changer) :SceneTask(changer) {
}


Menu::~Menu()
{
}
void Menu::Init() {
	
}

//�X�V
void Menu::Update() {

	if (CheckHitKey(KEY_INPUT_G) != 0) {
			DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Game);
			mChangeScene->ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
			
	}
		
			//DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Config);
			//mChangeScene->ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύXs
			
	if (CheckHitKey(KEY_INPUT_A) != 0) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Title);
		mChangeScene->ChangeScene(eScene_Title);

	}/*
	if (CheckHitKey(KEY_INPUT_C) != 0) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Record);
		mChangeScene->ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}*/


}




//�`��
void Menu::Render() {
	SceneTask::Render();//�e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0, "Menu", GetColor(255, 255, 255));
}

void Menu::Final() {
	SceneTask::Final();
}

