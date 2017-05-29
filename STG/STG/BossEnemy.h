#pragma once

#include "CharacterTask.h"
#include "IBullet.h"
class BossEnemy :public CharacterTask {
public:
	BossEnemy(int id);	//�R���X�g���N�^�œG��ID��ݒ肵�Ǘ�
	~BossEnemy();

	virtual void Initialize() override;	//CharacterTask::Initialize()���I�[�o�[���C�h�i���������j
	virtual void Update() override;		//CharacterTask::Update()���I�[�o�[���C�h�i���������j
	virtual void Move() override;		//CharacterTask::Move()���I�[�o�[���C�h�i���������j
	virtual void Render() override;		//CharacterTask::Render()���I�[�o�[���C�h�i���������j
	virtual void Finalize() override;	//CharacterTask::Finalize()���I�[�o�[���C�h�i���������j

private:
	bool endShotFlag;		//�e�𔭎˂��������Ǘ�����t���O
	int moveX;				//�ŏI�I�Ȉړ����W
	int moveY;				//�ŏI�I�Ȉړ����W
	int i;					//�z��̊Ǘ�
	int hp;					//�G��HP
	bool bulletFlag;		//�e�𔭎˂ł��邩���Ǘ�����t���O
	int bulletFlagCount;	//

	int thisId;				//���g��ID
	int hitCount;			//�v���C���[�̒e�����x�q�b�g������
	IBullet* mBullet[20];	//�e�̃I�u�W�F�N�g���i�[����z��
	void ShotUpdate();		//�e�̍X�V����
	void ShotRender();		//�e�̕`�揈��
	int moveFlag;			//�ړ����邩���Ǘ�����t���O
	int cnt;				//�ړ������񐔂��J�E���g����ϐ�
	int bulletCnt;			//�e��ł�����̃C���^�[�o�����J�E���g����ϐ�
};

