#pragma once
#include "ICharacter.h"

class CharacterTask :public ICharacter {

public:
	CharacterTask();
	~CharacterTask();
protected:
	int mCharaGraphicHandle[5]; 
	int mSoundHandle;
	int mSoundPlayFlag;

	int x;
	int y;
	int width;
	int height;
	int center;
	int interval;
	int cntBulletTime;
	bool ShotFlg;
	int hp;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;
	virtual void Move();
	virtual void ShotUpdate();
	virtual void ShotRender();

	//virtual void RectAngle();

	//bool ShotFlag;

};

