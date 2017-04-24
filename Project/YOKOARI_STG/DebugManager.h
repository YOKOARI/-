/***********************************************
* �쐬�ҁF���R ��
* �T�v�@�F�e�N���X�̃f�o�b�O��S���N���X
* ���̑��F�V���O���g���N���X
************************************************/

#ifndef _DEBUGMANAGER_H_
#define _DEBUGMANAGER_H_

class DebugManager {

private:

	DebugManager();			//�R���X�g���N�^
	bool GetEndFlag();		//�Q�[���̏I���t���O�̎擾
	bool errorEndFlag;		//�Q�[���I���𔻒f����t���O

public:

	enum class SystemErrorType {	//�V�X�e���n�̃G���[���Ǘ�

		FailedInitialize = -1,	//�������G���[
	};

	enum class RenderErrorType {	//�`��n�̃G���[���Ǘ�

		FailedLord = -10			//�ǂݍ��݃G���[
	};

	enum class SceneType {			//�V�[���̖��O���Ǘ�

		null = 1,					//�V�[���Ȃ�
		Game,					//�Q�[���V�[��
		Config,					//�ݒ�V�[��
		Menu,					//���j���[�V�[��
		Title,					//�^�C�g���V�[��
		Resoult,				//���U���g���
	};

	~DebugManager() {};				//�f�X�g���N�^

	static DebugManager* Instance();	//���N���X����Q�Ƃ���Ƃ��Ɏg���|�C���^�֐�

	void SystemErorr(SystemErrorType);	//�V�X�e���G���[��\������֐�
	void RenderError(RenderErrorType);	//�`��G���[��\������֐�
	void ReviewScene(SceneType);		//���݂̃V�[����ʒm����֐�
};

#endif // !_DEBUGMANAGER_H_