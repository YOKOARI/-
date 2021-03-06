#pragma once
#include "IBullet.h"
#include "CharacterTask.h"

class NewbeiEnemy : public CharacterTask {
public:
	NewbeiEnemy(int, int, int);
	~NewbeiEnemy();
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
	int thisId;
	int hitCount;
	void ShotUpdate();
	void ShotRender();
	IBullet* mBullet;
};

