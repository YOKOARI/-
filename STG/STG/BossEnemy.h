#pragma once

#include "CharacterTask.h"
#include "IBullet.h"
class BossEnemy :public CharacterTask {
public:
	BossEnemy(int id);
	~BossEnemy();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Move() override;
	virtual void Render() override;
	virtual void Finalize() override;

private:
	bool endShotFlag;
	int moveX;
	int moveY;
	int i;
	int hp;
	bool bulletFlag;
	int bulletFlagCount;

	int thisId;
	int hitCount;
	IBullet* mBullet[20];
	void ShotUpdate();
	void ShotRender();
	int moveFlag;
	int cnt;
	int bulletCnt;
};

