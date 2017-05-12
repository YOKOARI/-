#include "SelectCharaMenu.h"
#include "DxLib.h"
#include "ISceneChanger.h"
#include "SceneTask.h"

#define CHARASELECT_IMAGE LoadGraph("Image/SelectBack.png")      //�w�i�摜�̓ǂݍ���
#define CHARAINFO_IMAGE LoadGraph("Image/CharaInfo.png")         //�L�������摜�̓ǂݍ���

#define BLUE_YOKOARI LoadDivGraph("Image/YokoariBlue.png",2,2,1,290,280,modeYokoariBlue);
#define RED_YOKOARI LoadDivGraph("Image/YokoariRed.png",2,2,1,290,280,modeYokoariRed);

#define BLUE_X 235    //���R�A���N(��)�̂����W
#define RED_X  810    //���R�A���N(��)�̂����W
#define YOKOARI_Y 250 //���R�A���N(����)�̂����W



SelectCharaMenu::SelectCharaMenu(ISceneChanger* changer) :SceneTask(changer) {
}

SelectCharaMenu::~SelectCharaMenu() {
}

void SelectCharaMenu::Init() {
	SceneTask::Init();

	//�t���O�̏�����
	charaSelect = true;

	//���R�A���N�̏�Ԃ�������(�_����)
	flgBlue = 0;
	flgRed = 0;

	//�摜�̎擾
	imgBack = CHARASELECT_IMAGE;    //�w�i
	imgInfo = CHARAINFO_IMAGE;      //�L�������

	imgYokoariBlue = BLUE_YOKOARI;  //���R�A���N(��)
	imgYokoariRed = RED_YOKOARI;    //���R�A���N(��)
	
	//�F�̎擾
	blueColor = GetColor(0, 0, 255); //�A�C�R���F(��)

} 

void SelectCharaMenu::Update() {
	SceneTask::Update();
	/*if (CheckHitKey(KEY_INPUT_G) != 0) {

		mChangeScene->ChangeScene(eScene_Game);
	}*/

	//���E�L�[�ŃL�����N�^�[�I��
	if (CheckHitKey(KEY_INPUT_LEFT) != 0) {

		//���R�A���N�I�����
		charaSelect = true;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {

		//�ԃ��R�A���N�I�����
		charaSelect = false;
	}

	//�I���L�����̔���
	if (charaSelect == true)
	{
		//�I���A�C�R���ړ�
		selectImageX = 220;

		//Enter�L�[�ŃL��������
		if (CheckHitKey(KEY_INPUT_RETURN) != 0)
		{
			//�L�����̎��������(��)
			flgBlue = 1;

			//�Q�[����ʂ�
			mChangeScene->ChangeScene(eScene_Game);
		}
	}
	else
	{
		//�I���A�C�R���ړ�
		selectImageX = 800;

		//Enter�L�[�ŃL��������
		if (CheckHitKey(KEY_INPUT_RETURN) != 0)
		{
			//�L�����̎��������(��)
			flgRed = 1;

			//�Q�[����ʂ�
			mChangeScene->ChangeScene(eScene_Game);
		}
	}
}

void SelectCharaMenu::Render() {
	SceneTask::Render();
	//DrawString(0, 0,"SelectCharMenu" ,(255, 255, 255));

	//�w�i�ƃL�������̕`��
	DrawGraph(0, 0, imgBack, false);
	DrawGraph(0, 0, imgInfo, true);

	//�L�����N�^�[�̕`��
	DrawGraph(BLUE_X, YOKOARI_Y, modeYokoariBlue[flgBlue], true);
	DrawGraph(RED_X, YOKOARI_Y, modeYokoariRed[flgRed], true);

	//�I���A�C�R���̕`��
	DrawTriangle(selectImageX, 540, selectImageX, 590, selectImageX + 40, 565, blueColor, TRUE);
}

void SelectCharaMenu::Final() {
	SceneTask::Final();
}