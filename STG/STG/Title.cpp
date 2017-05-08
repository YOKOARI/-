#include "Title.h"
#include "DxLib.h"
#include "DebugManager.h"


Title::Title(ISceneChanger* changer):SceneTask(changer){

}


Title::~Title()
{
}
void Title::Init() {
	//�F�̎擾
	int whiteColor = GetColor(255, 255, 255); //�����F(��)
	int blueColor = GetColor(0, 0, 255); //�A�C�R���F(��)
}

void Title::Update(){
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mChangeScene->ChangeScene(eScene_Scene_Menu);
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::SucsseceLord);
	}

	//�㉺�L�[�őI���󋵂̕ύX
	if (CheckHitKey(KEY_INPUT_UP) != 0) {
		selectFlag = true;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
		selectFlag = false;
	}
}

void Title::Render() {
	//DrawString(0, 0, "Title", GetColor(255, 255, 255));

	TitleSelect();

	SceneTask::Render();
	
}
void Title::Final() {
	SceneTask::Final();
}

/***************************************************************
*�֐��� : TitleSelect()
*����� :��� ����
*�T�v : �Q�[���X�^�[�g�ƏI����\�����A�L�[�{�[�h�őI��������B
*���� : �Ȃ�
*�߂�l : �Ȃ�
*���l : �Ȃ�
****************************************************************/
void Title::TitleSelect() {

	

	SetFontSize(fontSizeStart);  //�����T�C�Y�ύX
	DrawString(550, 320, "�Q�[���X�^�[�g�I", whiteColor);

	SetFontSize(fontSizeEnd);
	DrawString(550, 380, "�Q�[���I���I", whiteColor);

	if (selectFlag == true) {
		selectImageY = 320;
		selectImageTy = 335;

		fontSizeStart = 30;
		fontSizeEnd = 24;
	}
	else {
		selectImageY = 380;
		selectImageTy = 395;

		fontSizeStart = 24;
		fontSizeEnd = 30;
	}
	DrawTriangle(500, selectImageY, 500, selectImageY+30, 530, selectImageTy, blueColor, TRUE);

	//Z�L�[�Ō���
	if (CheckHitKey(KEY_INPUT_Z) != 0) {
		//�Q�[���J�n
		if (selectFlag == true) {

		}
		//�Q�[���I��
		else {
			DxLib_End();
		}
	}
}
