#pragma once
#include "IBullet.h"
#include "CharacterTask.h"
class NewbeiEnemy : public CharacterTask {
public:
	NewbeiEnemy(int);
	~NewbeiEnemy();
	void Initialize() override;
	void Update() override {};
	void Update(int, int) override;
	void Render() override;
	void Finalize() override;

private:
	int spwonPlaceFlag;
	void ShotUpdate();
	void ShotRender();
	IBullet* mBullet;
};

