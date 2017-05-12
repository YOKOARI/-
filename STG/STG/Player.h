#pragma once

#include "CharacterTask.h"

class Player : public CharacterTask {
public:
	Player();
	~Player();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;
	virtual void Move() override;

private:
	void MoveScript(int);
	//virtual void Shot() override;
};

