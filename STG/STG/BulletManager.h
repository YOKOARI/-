#pragma once
#include "IBullet.h"
class BulletManager : public IBullet
{
public:
	BulletManager();
	~BulletManager();
	
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;

private:
	//IBullet* mBullet;
};

