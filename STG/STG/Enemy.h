#pragma once

#include "CharacterTask.h"
class Enemy :public CharacterTask {
public:
	Enemy();
	~Enemy();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Final() override;

private:
	
};

