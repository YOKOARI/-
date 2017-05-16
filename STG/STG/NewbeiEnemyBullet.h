#pragma once
#include "BulletTask.h"
class NewbeiEnemyBullet : public BulletTask {

public:
	NewbeiEnemyBullet();
	~NewbeiEnemyBullet();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;
	virtual int GetBulletPointX() override;
	virtual int GetBulletPointY() override;

	int PointX[5];
	int PointY[5];
	int i;
};

