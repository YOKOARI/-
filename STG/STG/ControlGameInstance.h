#ifndef _CONTRIL_H_
#define _CONTROL_H_
enum ControlID {
	e_StageFirst = 1,	//ステージ1
	e_StageSecond,		//ステージ２
	e_StageThird,		//ステージ３
	e_YokoariBrue,		//ヨコアリくんブルー
	e_YokoariRed,		//ヨコアリくんレッド
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
	int characterId;	//キャラクターのID
	int StageSelectId;		//ステージのID
	int playerPointX;
	int playerPointY;

	
};
#endif // !_CONTRIL_H_