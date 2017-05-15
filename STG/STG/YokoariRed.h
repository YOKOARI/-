#pragma once

#include "CharacterTask.h"
#include "IBullet.h"

class YokoariRed : public CharacterTask {
public:
	YokoariRed();
	~YokoariRed();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;
	virtual void Move() override;

private:
	void MoveScript(int);
	IBullet* mBullet[10];
	virtual void ShotUpdate() override;
	virtual void ShotRender() override;
};
