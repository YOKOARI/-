#pragma once
#include "IObj.h"

class CharacterTask :public IObj {

public:
	CharacterTask();
	~CharacterTask();
protected:
	int mCharaGraphicHandle[5];
	int mSoundHandle;
	int mSoundPlayFlag;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Final() override;
	virtual void Move();

	bool ShotFlag;

};

