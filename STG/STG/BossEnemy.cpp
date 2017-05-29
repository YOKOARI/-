#include "BossEnemy.h"
#include "DxLib.h"
#include "ControlGameInstance.h"
#include "NormalEnemyBullet.h"
#define BOSS_PIC "Image/EnemyUI/Boss�P.png"
#define HP_BAR "Image/HPBar/HealthBarIn.png"
#define HP_BAR_AROUND "Image/HPBar/HealthBarOut.png"
#define SPOWN_X 350
#define SPOWN_Y -20

/****�@BossEnemy(���g��ID)�@****/
BossEnemy::BossEnemy(int id){

	//�������ɐݒ肳�ꂽID�����g��ID�Ƃ��Ċi�[
	thisId = id;
}


BossEnemy::~BossEnemy()
{
}

/****�@�����������@****/
void BossEnemy::Initialize() {

	//�z��̏�����
	for (i = 0; i < 20; i++) {
		mBullet[i] = NULL;
	}
	//�ȉ��A�e�ϐ��̏�����
	bulletFlag = false;
	bulletFlagCount = 0;
	x = SPOWN_X;
	y = SPOWN_Y;
	i = 0;
	hp = 680;
	cnt = 0;
	bulletCnt = 0;
	interval = 6;
	cntBulletTime = 0;
	hitCount = 0;
	moveFlag = 0;
	mCharaGraphicHandle[0] = LoadGraph(BOSS_PIC);
	mCharaGraphicHandle[1] = LoadGraph(HP_BAR);
	mCharaGraphicHandle[2] = LoadGraph(HP_BAR_AROUND);
}

/****�@�X�V�����@****/
void BossEnemy::Update() {
	
	//���g�̍��W�X�V
	Move();

	//���g�̌��݂̂����W���A�����蔻����Ǘ�����N���X�ɓo�^
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointX(this->x);

	//���g�̌��݂̂����W���A�����蔻����Ǘ�����N���X�ɓo�^
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointY(this->y);

	//�e�̍��W���X�V
	ShotUpdate();

	//���g�̂����蔻��Ɏg�p�����`�������蔻����Ǘ�����N���X�ɓo�^
	ControlGameInstance::GetInstance()->SetEnemyHitAria(x + 20, y + 28, 16);

	//�v���C���[�����˂������ׂĂ̒e�ɂ����āA���̂��Âꂩ���������Ă��邩�ǂ����̏���
	for (int j = 0; j < 70; j++) {

		//�v���C���[�̒e�Ύ��g�̂����蔻����s�������@TRUE�F�������Ă���@FALSE�F�������Ă��Ȃ�
		if (ControlGameInstance::GetInstance()->PlayerBulletToEnemyHitTest(j) == true) {

			//�f�o�b�O�p�@�������Ă�����o��
			DrawString(0, 0, "hitP", GetColor(255, 255, 255));

			//���g��HP�����炷
			hp--;

			//����HP���O�ɂȂ�����
			if(hp == 0)

				//���g�����񂾂��Ƃ������蔻����Ǘ�����N���X�̓o�^
				//SetEnemyDeadFlag(���g��ID�TRUE)
				ControlGameInstance::GetInstance()->SetEnemyDeadFlag(thisId, true);
			}
		else {
			//ControlGameInstance::GetInstance()->SetEnemyHitFlag(thisId, j, false);
		}
	}

}

/****�@�`�揈���@*****/
void BossEnemy::Render() {

	//HP�o�[�̕`��
	if (hp >= 0) {
		DrawExtendGraph(50, 50, 50 + hp, 50 + 40, mCharaGraphicHandle[1], TRUE);
		DrawExtendGraph(50, 50, 50 + 680, 50 + 40, mCharaGraphicHandle[2], TRUE);
	}

	//���g�̕`��
	DrawExtendGraph(x, y, x + 40, y + 56, mCharaGraphicHandle[0], TRUE);

	//�e�̕`��
	ShotRender();
}

/****�@�I�������@****/
void BossEnemy::Finalize() {

	//��ʊO�ɍ��W���X�V
	x = 3000;
	y = 3000;
}

void BossEnemy::Move() {

	//�t���O�ňړ����郂�[�V������ύX
	if (moveFlag == 0) {
		y += 2;
		if (cnt > 100) moveFlag = 1;
	}
	else if (moveFlag == 1) {
		y -= 1;
		x += rand() % 3 - 1;
		if (cnt % 50 == 0) moveFlag = 2;
	}
	else if(moveFlag == 2){
		y += 1;
		x += rand() % 3 - 1;
		if (cnt % 50 == 0) moveFlag = 3;
	}

	//�ړ����I�������e�𔭎˂ł���悤�Ƀt���O���Z�b�g
	else {
		bulletFlag = true;
		//100�t���[����Ɉړ��J�n
		if (cnt % 100 == 0) {
			moveFlag = 1;
			bulletFlag = false;
		}
	}
	cnt++;
}

/****�@�e�̍X�V�����@****/
void BossEnemy::ShotUpdate() {

	//�z��ɃI�u�W�F�N�g������ꍇ�A�X�V����������
	for (int i = 0; i < 20; i++) {
		if (mBullet[i] != NULL) {
			mBullet[i]->Update();
		}
	}

	//�C���^�[�o�����o�߂��Ă��Ă��ړ����I����Ă�����e�𔭎�
	if (interval < cntBulletTime && bulletFlag == true) {
		mBullet[bulletCnt] = new NormalEnemyBullet;
		mBullet[bulletCnt]->Initialize();
		cntBulletTime = 0;
	}
	cntBulletTime++;
	
	bulletCnt++;
	if (bulletCnt == 20) bulletCnt = 0;
}

/****�@�e�̕`�揈���@****/
void BossEnemy::ShotRender() {

	//�z��ɃI�u�W�F�N�g������ꍇ�A�`�揈��������
	for (int i = 0; i < 20; i++) {
		if (mBullet[i] != NULL) {
			mBullet[i]->Render();
		}
	}
}
