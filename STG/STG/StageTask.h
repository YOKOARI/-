#pragma once
#include "IStage.h"
class StageTask : public IStage {
public:
	StageTask();
	~StageTask();
	virtual int Initialize() override;
	virtual int Update()override;
	virtual int Render()override;
	virtual int Finalize()override;
	
protected:
	virtual int SpownEnemy();
	
};

