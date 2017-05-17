#pragma once
#include "StageTask.h"
class FirstStage : public StageTask {
public:
	FirstStage();
	~FirstStage();

	virtual int Initialize() override;
	virtual int Update() override;
	virtual int Render() override;
	virtual int Finalize() override;
	virtual int SpownEnemy() override;
private:
};

