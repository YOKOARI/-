#include "Title.h"
#include "DxLib.h"
#include "DebugManager.h"


Title::Title(ISceneChanger* changer):SceneTask(changer){

}


Title::~Title()
{
}
void Title::Init() {

	//�w�i�摜�̎擾
	imgBack = LoadGraph("Image/Title.png");

	//�F�̎擾
	BlackColor = GetColor(0, 0, 0); //�����F(��)
	blueColor = GetColor(0, 0, 255); //�A�C�R���F(��)
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

	//�I������Ă��镶���̃t�H���g�T�C�Y��ς���
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
}

void Title::Render() {
	//DrawString(0, 0, "Title", GetColor(255, 255, 255));

	DrawGraph(0, 0, imgBack, false);

	SetFontSize(fontSizeStart);  //�����T�C�Y�ύX
	DrawString(550, 320, "�Q�[���X�^�[�g�I", BlackColor);

	SetFontSize(fontSizeEnd);
	DrawString(550, 380, "�Q�[���I���I", BlackColor);

	DrawTriangle(500, selectImageY, 500, selectImageY + 30, 530, selectImageTy, blueColor, TRUE);

	TitleSelect();


	SceneTask::Render();
	
}
void Title::Final() {
	SceneTask::Final();
}

/***************************************************************
*�֐��� : TitleSelect()
*����� :��� ����
*�T�v : �Q�[���X�^�[�g�ƃQ�[���I�����y�L�[�Ō���
*���� : �Ȃ�
*�߂�l : �Ȃ�
*���l : �Ȃ�
****************************************************************/
void Title::TitleSelect() {

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
