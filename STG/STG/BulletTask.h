#pragma once
#include "IBullet.h"

class BulletTask : public IBullet {
public:
	BulletTask();
	~BulletTask();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;
	virtual int GetBulletPointX() override;
	virtual int GetBulletPointY() override;
	int bulletGraphicHandle[25];

	int x;
	int y;
};

