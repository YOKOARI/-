#include "DebugManager.h"
#include "DxLib.h"

/*************************************************************************************
*�@�@�\�@�F�@�R���X�g���N�^
*�@�����@�F�@NULL
*�@�߂�l�F�@NULL
**************************************************************************************/
DebugManager::DebugManager() {

	//�Q�[���̏I���t���O�̏�����
	errorEndFlag = false;
}

/*************************************************************************************
*�@�@�\�@�F�@�C���X�^���X�̃|�C���^���擾
*�@�����@�F�@NULL
*�@�߂�l�F�@&DebugManager::point
**************************************************************************************/
DebugManager* DebugManager::Instance() {

	//�N���X�����o�[�̐���
	static DebugManager point;

	//�C���X�^���X�̃|�C���^�����^�[��
	return &point;
}

/*************************************************************************************
*�@�@�\�@�F�@�Q�[���̏I���t���O���擾����
*�@�����@�F�@NULL
*�@�߂�l�F�@errorEndFlag
**************************************************************************************/
bool DebugManager::GetEndFlag() {

	//�Q�[���̏I���t���O�����^�[��
	return errorEndFlag;
}

/*************************************************************************************
*�@�@�\�@�F�@�V�X�e���̃G���[��\������
*�@�����@�F�@SystemErrorType errorType
*�@�߂�l�F�@NULL
**************************************************************************************/
void DebugManager::SystemErorr(SystemErrorType errorType) {

	//�G���[�̃^�C�v�ŕ���
	switch (errorType) {

		//���������s
		case SystemErrorType::FailedInitialize:

			//�����������s�������Ƃ�ʒm
			MessageBox(NULL, "FAILED_INITIALIZE", "SYSTEM_ERROR", MB_OK);

			//�Q�[���̏I���t���O��TRUE�ɂ���
			errorEndFlag = true;
			break;
	}
}


/*************************************************************************************
*�@�@�\�@�F�@�`��̃G���[��\������
*�@�����@�F�@RenderErrorType errorType
*�@�߂�l�F�@NULL
**************************************************************************************/
void DebugManager::RenderError(RenderErrorType errorCord) {

	//�G���[�̃^�C�v�ŕ���
	switch (errorCord) {

		//�ǂݍ��ݎ��s
		case RenderErrorType::FailedLord:

			//�ǂݍ��݂Ɏ��s�������Ƃ�ʒm
			MessageBox(NULL, "FAILED_LORD", "RENDER_ERROR", MB_OK);
			break;
	}
}

/*************************************************************************************
*�@�@�\�@�F�@���݂̃V�[����ʒm����
*�@�����@�F�@SceneType sceneType
*�@�߂�l�F�@NULL
**************************************************************************************/
void DebugManager::ReviewScene(SceneType sceneType) {
	 
	//�V�[���̃^�C�v�ŕ���
	switch (sceneType) {

		//�V�[�����Q�[���̏ꍇ
		case SceneType::Game:

			//�V�[�����Q�[���ɑJ�ڂł��Ȃ��������Ƃ�ʒm
			MessageBox(NULL, "FAILED ROAD TO GAME", "SCENE_ERROR", MB_OK);
			break;

		//�V�[�����ݒ�̏ꍇ
		case SceneType::Config:

			//�V�[�����ݒ�ɑJ�ڂł��Ȃ��������Ƃ�ʒm
			MessageBox(NULL, "FAILED ROAD TO CONFIG", "SCENE_ERROR", MB_OK);
			break;

			//�V�[�������j���[�̏ꍇ
		case SceneType::Menu:

			//�V�[�������j���[�ɑJ�ڂł��Ȃ��������Ƃ�ʒm
			MessageBox(NULL, "FAILED ROAD TO MENU", "SCENE_ERROR", MB_OK);
			break;

			//�V�[�����^�C�g���̏ꍇ
		case SceneType::Title:

			//�V�[�����^�C�g���ɑJ�ڂł��Ȃ��������Ƃ�ʒm
			MessageBox(NULL, "FAILED ROAD TO TITLE", "SCENE_ERROR", MB_OK);
			break;

			//�V�[�������U���g�̏ꍇ
		case SceneType::Resoult:

			//�V�[�����^�C�g���ɑJ�ڂł��Ȃ��������Ƃ�ʒm
			MessageBox(NULL, "FAILED ROAD TO RESOULT", "SCENE_ERROR", MB_OK);
			break;

	}
}