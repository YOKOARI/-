#pragma once
#include "IStage.h"

class StageManager :public IStage {
public:
	StageManager();
	~StageManager();

	virtual int Initialize() override;
	virtual int Update()override;
	virtual int Render()override;
	virtual int Finalize()override;
private:
	IStage* mStage;
};

