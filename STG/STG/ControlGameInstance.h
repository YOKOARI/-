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
	void SetNewbeiEnemyPointX(int PointX);
	void SetNewbeiEnemyPointY(int PointY);

	void SetCharacterId(int charaId);
	void SetStageId(int stageId);
	void SetEnemyHitAria(int cx, int cy, int cr);
	void SetPlayerHitAria(int cx, int cy, int cr);
	void SetEnemyBulletHitAria(int cx, int cy, int cr);
	void SetPlayerBulletHitAria(int cx, int cy, int cr);

	int GetPlayerPointX();
	int GetPlayerPointY();
	int GetNewbeiEnemyPointX();
	int GetNewbeiEnemyPointY();
	int GetCharacterId();
	int GetStageId();

	bool GetPlayerDeadFlag();
	
	
	bool EnemyBulletToPlayerHitTest();
	bool PlayerBulletToEnemyHitTest();

private:
	ControlGameInstance();
	int characterId;	//キャラクターのID
	int StageSelectId;		//ステージのID

	int playerPointX;
	int playerPointY;
	int NewbeiEnemyPointX;
	int NewbeiEnemyPointY;

	int playerPointCenterX;
	int playerPointCenterY;
	int playerPointRadius;

	int enemyPointCenterX;
	int enemyPointCenterY;
	int enemyPointRadius;
	
	int playerBulletPointCenterX;
	int playerBulletPointCenterY;
	int playerBulletPointRadius;

	int enemyBulletPointCenterX;
	int enemyBulletPointCenterY;
	int enemyBulletPointRadius;

	bool playerDeadFlag = false;
	bool enemyDeadFlag = false;
};
#endif // !_CONTRIL_H_