#pragma once
#include "IBullet.h"
#include "CharacterTask.h"

class NewbeiEnemy : public CharacterTask {
public:
	NewbeiEnemy(int ,int);
	~NewbeiEnemy();
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Move();
	virtual void Render() override;
	virtual void Finalize() override;

private:
	
	bool endShotFlag;
	int moveX;
	int moveY;
	void ShotUpdate();
	void ShotRender();
	IBullet* mBullet;
};

