#pragma once

#include "CharacterTask.h"
#include "IBullet.h"

class YokoariBrue : public CharacterTask {
public:
	YokoariBrue();
	~YokoariBrue();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;
	virtual void Move() override;

private:
	void MoveScript(int);
	IBullet* mBullet[70];
	virtual void ShotUpdate() override;
	virtual void ShotRender() override;
	int i;
	int bulletY;
};


