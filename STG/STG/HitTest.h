#pragma once
class HitTest {
public:
	HitTest();
	~HitTest();
	
	void SetPlayerBulletNumber(int);
	void SetEnemyNumber(int);
	
	int GetPlayerBulletNumber();
	int GetEnemyNumber();

private:
	int playerBulletNumber;
	int enemyNumber;

};

