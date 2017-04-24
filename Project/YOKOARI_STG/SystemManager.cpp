/**************************************************
* �쐬�ҁF���R ��
* �T�v�@�F�Q�[���𗧂��グ��ۂ̂��ׂĂ̏������E����
* ���̑��F�Q�[�����[�v�͂����ɑ��݂��܂��B
***************************************************/

#include "SystemManager.h"
#include "DebugManager.h"
#include "DxLib.h"

SystemManager::SystemManager() {
}


SystemManager::~SystemManager() {
}

void SystemManager::Initialize() {

	//�E�C���h�E�T�C�Y�E�E�C���h�E���[�h�̎擾
	SelectWindowMode(1280, 720);

	//�E�C���h�E�e�L�X�g�̎擾
	SetMainWindowText("�V���l����");

	//�}�E�X�J�[�\����\�����邩�ݒ肷��@TRUE�F�\���@FALSE�F��\��
	GetMouseDispFlag();

	//�E�C���h�E�̓�d�������ł��邩��ݒ肷��@TRUE�F�\�@FALSE�F�s�\
	SetDoubleStartValidFlag(FALSE);

	//����ʂ��Z�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {

		//�������Ɏ��s�����ꍇ�͑����Ƀv���O�����I��������
		DebugManager::Instance()->SystemErorr(DebugManager::SystemErrorType::FailedInitialize);
		exit(-1);
	}
}

void SystemManager::Update() {

	//�Q�[���̏�����
	Initialize();
	
	//���C�����[�v
	while (ProcessMessage() != -1) {


		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			if (IsGameEnd() == TRUE)break;
		}
	}

	//�������̊J��
	Finalize();

}


void SystemManager::Finalize() {

	DxLib_End();
}

void SystemManager::SelectWindowMode(int width, int height) {

	int windowModeFlag;

	windowModeFlag = MessageBox(NULL, "�t���X�N���[�����[�h�ŋN�����܂����H", "�X�N���[���ݒ�", MB_YESNO | MB_ICONQUESTION);

	windowModeFlag == IDNO ? ChangeWindowMode(TRUE) : ChangeWindowMode(FALSE);

	SetGraphMode(width, height, 32);

}

bool SystemManager::IsGameEnd() {
	
	gameEndFlag = (MessageBox(GetMainWindowHandle(), "�Q�[�����I�����܂����H", "", MB_YESNO | MB_ICONQUESTION) == IDNO) ? FALSE : TRUE;

	return gameEndFlag;
}