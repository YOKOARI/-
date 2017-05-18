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
	void SetPlayerBulletId(int bulletId);
	void SetEnemyHitAria(int cx, int cy, int cr);
	void SetPlayerHitAria(int cx, int cy, int cr);
	void SetEnemyBulletHitAria(int cx, int cy, int cr);
	void SetPlayerBulletHitAria(int id, int cx, int cy, int cr);
	void SetCurrentBulletNumber(int);
	void SetEnemyDeadFlag(int enemyNumber,bool deadFlag);
	void SetPlayerDeadFlag(bool deadFlag);
	void SetEnemyHitFlag(int,bool);

	int GetPlayerPointX();
	int GetPlayerPointY();
	int GetNewbeiEnemyPointX();
	int GetNewbeiEnemyPointY();
	int GetCharacterId();
	int GetStageId();
	int GetBulletId();
	int GetCurrentBulletNumber();
	bool GetEnemyDeadFlag(int EnemyID);
	bool GetPlayerDeadFlag();

	bool GetPlayerHitFlag();
	bool GetEnemyHitFlag(int);

	bool EnemyBulletToPlayerHitTest();
	bool PlayerBulletToEnemyHitTest(int playerBulletID);

private:
	ControlGameInstance();
	int characterId;	//キャラクターのID
	int StageSelectId;		//ステージのID
	int bulletId;

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

	bool enemyDradFlag[20];
	bool playerDeadFlag;
	
	int playerBulletPointCenterX[70];
	int playerBulletPointCenterY[70];
	int playerBulletPointRadius;

	int enemyBulletPointCenterX;
	int enemyBulletPointCenterY;
	int enemyBulletPointRadius;

	bool playerHitFlag;
	bool enemyHitFlag[70];	//プレイヤーの弾が敵に当たったかどうかのフラグ
	int currentNumber;
};
#endif // !_CONTRIL_H_