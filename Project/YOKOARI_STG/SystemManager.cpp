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
	SelectWindowMode(1280, 720);

	SetMainWindowText("�V���l����");

	SetDrawScreen(DX_SCREEN_BACK);

	if (DxLib_Init() == -1) {
		DebugManager::Instance()->SystemErorr(DebugManager::SystemErrorType::FailedInitialize);
		exit(-1);
	}
}

void SystemManager::Update() {

	Initialize();
	
	while(ProcessMessage() != -1 && DebugManager::Instance()->GetEndFlag() != false)

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