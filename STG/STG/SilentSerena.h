#pragma once
#include "BulletTask.h"
class SilentSerena : public BulletTask {
public:
	SilentSerena();
	~SilentSerena();
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;
	virtual int GetBulletPointX() override;
	virtual int GetBulletPointY() override;
private:
	int bulletPointX[680];
	int bulletPointY[680];
	int i;
	int j;
	int bulletPhase;
	int bulletInterval;
	int bulletTimeCount;

	int bulletSecondInterval;
	int bulletSecondTimeCount;

	bool shotFlg[2];
	int flg;
    float deg;
	float len;
	float rad;

};

