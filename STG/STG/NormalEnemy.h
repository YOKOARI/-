#pragma once
#include "IBullet.h"
#include "CharacterTask.h"


class NormalEnemy : public CharacterTask {
public:
	NormalEnemy(int id,int y);
	~NormalEnemy();

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
	IBullet* mBullet;
	
	void ShotUpdate();
	void ShotRender();
	
};

