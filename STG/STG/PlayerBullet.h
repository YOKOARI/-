#pragma once
#include "BulletTask.h"

class PlayerBullet : public BulletTask {
public:
	PlayerBullet();
	~PlayerBullet();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;
};

