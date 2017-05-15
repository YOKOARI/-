#include "Title.h"
#include "DxLib.h"
#include "DebugManager.h"

#define TITLE_IMAGE LoadGraph("Image/Title.png") //�w�i�摜�̓ǂݍ���
#define NOMAL_FONT_SIZE 40  //�I������Ă���Ƃ��̃t�H���g�T�C�Y
#define BIG_FONT_SIZE 52    //�I������ĂȂ����Ƃ��̃t�H���g�T�C�Y

Title::Title(ISceneChanger* changer):SceneTask(changer){

}


Title::~Title(){

}

void Title::Init() {

	//�Q�[���J�n�E�I���t���O�̏�����
	selectFlag = true;

	//�w�i�摜�̎擾
	imgBack = TITLE_IMAGE;

	//�F�̎擾
	blackColor = GetColor(0, 0, 0); //�����F(��)
	blueColor = GetColor(0, 0, 255); //�A�C�R���F(��)

	//�t�H���g�̎擾
	ChangeFont("�j�R���W�{");
	fontSizeStart = BIG_FONT_SIZE;
	fontSizeEnd = NOMAL_FONT_SIZE;
	
}

void Title::Update(){
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mChangeScene->ChangeScene(eScene_Scene_Menu);
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::SucsseceLord);
	}

	//�㉺�L�[�őI���󋵂̕ύX
	if (CheckHitKey(KEY_INPUT_UP) != 0) {

		//�Q�[���X�^�[�g�I���
		selectFlag = true;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) != 0) {

		//�Q�[���I���I���
		selectFlag = false;
	}

	//���A�C�R���̍��W�l��ς�,�t�H���g�T�C�Y���ς���
	if (selectFlag == true) {
		selectImageY = 322;
		selectImageTy = 342;

		fontSizeStart = BIG_FONT_SIZE;
		fontSizeEnd = NOMAL_FONT_SIZE;
	}
	else {
		selectImageY = 405;
		selectImageTy = 425;

		fontSizeStart = NOMAL_FONT_SIZE;
		fontSizeEnd = BIG_FONT_SIZE;
	}

	//Enter�L�[�Ō���
	if (CheckHitKey(KEY_INPUT_RETURN) != 0) {

		//�Q�[���J�n
		if (selectFlag == true) {
			mChangeScene->ChangeScene(eScene_CharSelectMenu);
		}
		//�Q�[���I��
		else {
			DxLib_End();
		}
	}
}

void Title::Render() {
	//DrawString(0, 0, "Title", GetColor(255, 255, 255));

	//�w�i�̕`��
	DrawGraph(0, 0, imgBack, false);

	//�e�L�X�g�̕`��
	SetFontSize(fontSizeStart);
	DrawString(550, 320, "�Q�[���X�^�[�g�I", blackColor);

	SetFontSize(fontSizeEnd);
	DrawString(550, 400, "�Q�[���I���I", blackColor);

	//�I���A�C�R���̕`��
	DrawTriangle(500, selectImageY, 500, selectImageY + 40, 540, selectImageTy, blueColor, TRUE);


	SceneTask::Render();
	
}
void Title::Final() {
	SceneTask::Final();

	//�摜�̔j��
	InitGraph();
}