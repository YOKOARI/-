#pragma once
#include "BulletTask.h"
class NormalEnemyBullet : public BulletTask {
public:
	NormalEnemyBullet();
	~NormalEnemyBullet();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;
	virtual int GetBulletPointX() override;
	virtual int GetBulletPointY() override;

private:
	int PointX[12];
	int PointY[12];
	int deg;
	float rad;
	float len;
	int i;
};

