#pragma once
#include "IBullet.h"
#include "CharacterTask.h"
class FirstBossEnemy :public CharacterTask {
public:
	FirstBossEnemy();
	~FirstBossEnemy();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Move() override;
	virtual void Render() override;
	virtual void Finalize() override;
	
private:

	int movePhase;
	int bulletPhase;

	void ShotUpdate();
	void ShotRender();

	IBullet* mBullet;
};

