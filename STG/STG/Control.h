#ifndef _CONTRIL_H_
#define _CONTROL_H

enum ControlID {
	e_StageFirst = 1,	//�X�e�[�W1
	e_StageSecond,		//�X�e�[�W�Q
	e_StageThird,		//�X�e�[�W�R
	e_YokoariBrue,		//���R�A������u���[
	e_YokoariRed,		//���R�A�����񃌃b�h
	
};

namespace Control {
	static int charactorId = e_YokoariBrue;	//�L�����N�^�[��ID
	static int StageId = e_StageFirst;		//�X�e�[�W��ID
}

#endif // !_CONTRIL_H_
