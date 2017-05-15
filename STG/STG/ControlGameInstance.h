#ifndef _CONTRIL_H_
#define _CONTROL_H_
enum ControlID {
	e_StageFirst = 1,	//�X�e�[�W1
	e_StageSecond,		//�X�e�[�W�Q
	e_StageThird,		//�X�e�[�W�R
	e_YokoariBrue,		//���R�A������u���[
	e_YokoariRed,		//���R�A�����񃌃b�h
};
class ControlGameInstance {


public:
	~ControlGameInstance();
	static ControlGameInstance* GetInstance();
	void SetPlayerPointX(int PointX);
	void SetPlayerPointY(int PointY);
	void SetCharacterId(int charaId);
	void SetStageId(int stageId);

	int GetPlayerPointX();
	int GetPlayerPointY();
	int GetCharacterId();
	int GetStageId();
private:
	ControlGameInstance();
	int characterId;	//�L�����N�^�[��ID
	int StageSelectId;		//�X�e�[�W��ID
	int playerPointX;
	int playerPointY;

	
};
#endif // !_CONTRIL_H_