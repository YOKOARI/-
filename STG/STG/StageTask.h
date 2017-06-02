#pragma once
#include "IStage.h"
#include "ICharacter.h"

class StageTask : public IStage {
public:
	StageTask();
	~StageTask();
	virtual int Initialize()  override;
	virtual int Update() override;
	virtual int Render()override;
	virtual int Finalize()override;
	
protected:
	virtual void ChangeSound(int ID);
	virtual void PlayingSound();
	ICharacter* mCharacter[20];
	int charaID;
	int soundID;
	int mGraphicHandle;
	int mSoundPlayHandle;
	int mSoundPlayFlag = 0;
	int spownInterval;
	int spownCount;
	int hp = 5;
	bool spownFlag;
};

