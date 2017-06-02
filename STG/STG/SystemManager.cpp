/***********************************
*�N���X���FSystemManager
*�쐬�ҁF���R�@���@
*�T�v�F�V�X�e���̍�����S���N���X�B
************************************/

#include "systemManager.h"
#include "SceneManager.h"
#include"DebugManager.h"
#include"DxLib.h"


/************************************
*�֐����FSystemManager()
*�T�v�F�R���X�g���N�^�B�R���p�C������GameIsInit()���Ăяo���B
*�����F�Ȃ�
*�߂�l�F�Ȃ�
*���l�F�Ȃ�
*************************************/
SystemManager::SystemManager()
{
	this->GameIsInit();
}

/************************************
 * �֐����F~SystemManager()
 * �T�v�F�f�X�g���N�^�E�I�u�W�F�N�g�j������GameEnd()���Ăяo��
 * �����F�Ȃ�
 * �߂�l:�Ȃ�
 * ���l�F�Ȃ�
 *************************************/
SystemManager::~SystemManager()
{
	this->GameEnd();
}

/************************************
*�֐����FGameEnd()
*�T�v�FDX���C�u�����̏I�����������s�B
*�����F�Ȃ�
*�߂�l�F�Ȃ�
*���l�F�f�X�g���N�^���Ăяo���ꂽ�Ƃ��Ɏ��s
*************************************/
void SystemManager::GameEnd() {

	DxLib_End();

	return;
}

/************************************
*�֐����FGetWindowMode()
*�T�v�F�E�C���h�E�T�C�Y�A�E�C���h�E���[�h���擾����֐�
*�����Fwidth�F�E�C���h�E�̉��̃T�C�Y�@�b�@height�F�E�C���h�E�̏c�̃T�C�Y
*�߂�l�F�Ȃ�
*���l�FGameIsInit()�ŌĂ΂��
*************************************/
void SystemManager::GetWindowMode(int width, int height) {

	    int flag;

		flag = MessageBox(NULL,"�t���X�N���[�����[�h�ŋN�����܂����H","�X�N���[���ݒ�",MB_YESNO | MB_ICONQUESTION);
		if (flag == IDNO)
			ChangeWindowMode(TRUE);
			//SetWindowSize(width, height);
			SetGraphMode(width, height,32);
}

/**********************************
*�֐����FIsGameEnd();
*�T�v�F�Q�[���I�����A�{���ɃQ�[�����I�����邩�m�F���A�둀���h��
*�����F�Ȃ�
*�߂�l�FTRUE�F�I���@�b�@FALSE�F�p��
*���l�F
***********************************/
bool SystemManager::IsGameEnd() {

	//�z�b�v�A�b�v�E�C���h�E�̐ݒ�@�߂�l�@TRUE�F�I���@FALSE�F�p��
	systemEndFlag = MessageBox(GetMainWindowHandle() , "�v���O�������I�����܂����H", "END", MB_YESNO | MB_ICONQUESTION);

	if (systemEndFlag == IDNO) {

		endFlag = true;
	}
	else {
		endFlag = false;
	}
	
	return	endFlag;
}
 
/**********************************
*�֐����FgameIsInit()
*�T�v�F�N������x�����s���E�C���h�E�֘A�̏���������
*�����F�Ȃ�
*�߂�l�F�Ȃ�
*�߂�l�@TRUE�F�����@FALSE�F���s
**********************************/
void SystemManager::GameIsInit() {


	//�E�C���h�E�T�C�Y�E�E�C���h�E���[�h�̎擾
	GetWindowMode(1280, 720);

	//�E�C���h�E�e�L�X�g�̎擾
	SetMainWindowText("���R�A�������@�ꔯ");

	//�}�E�X�J�[�\����\�����邩�ݒ肷��@TRUE�F�\���@FALSE�F��\��
	GetMouseDispFlag();

	//�E�C���h�E�̓�d�������ł��邩��ݒ肷��@TRUE�F�\�@FALSE�F�s�\
	SetDoubleStartValidFlag(FALSE);

	//����ʂ��Z�b�g
	SetDrawScreen(DX_SCREEN_BACK);


	//DX���C�u�����̏������@�Ԃ�l�@TRUE�F����  FALSE�F���s
	if (DxLib_Init() == -1 ) {
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::FailedInit);
	}
}

int SystemManager::Update() {

	SceneMgr.Init();

	while (ProcessMessage() != -1 && DebugManager::Instance()->GetEndFlag() != false) {
		
		ClearDrawScreen();

		SceneMgr.Update();
		SceneMgr.Render();

		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			
			this->endFlag = this->IsGameEnd();
			if (this->endFlag == false) {
				SceneMgr.Final();
				break;
			}
		}
	}

	return 0;
}
