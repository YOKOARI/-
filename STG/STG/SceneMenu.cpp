#include "SceneMenu.h"
#include "DxLib.h"
#include "DebugManager.h"
SceneMenu::SceneMenu(ISceneChanger* changer) :SceneTask(changer) {
}


SceneMenu::~SceneMenu() {
}

/****************************************************
*�@����������
*�@�@�����ɉ摜�̃��[�h��A�ϐ��̏��������s���܂��B
*
*
****************************************************/
void SceneMenu::Init() {
	
}

//�X�V
void SceneMenu::Update() {

	if (CheckHitKey(KEY_INPUT_M) != 0) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::SucsseceLord);
		mChangeScene->ChangeScene(eScene_CharSelectMenu);//�V�[�����Q�[����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Config);
		mChangeScene->ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύXs
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::Title);
		mChangeScene->ChangeScene(eScene_Title);

	}
}




//�`��
void SceneMenu::Render() {
	SceneTask::Render();//�e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0, "SceneMenu", GetColor(255, 255, 255));
}

void SceneMenu::Final() {
	SceneTask::Final();
}

