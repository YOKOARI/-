#pragma once
#include "ICharacter.h"
#include "Player.h"
#include "BossEnemy.h"
#include "NewbeiEnemy.h"


class CharacterManager : public ICharacter {
public:
	CharacterManager();
	~CharacterManager();
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;

private:
	ICharacter *iCharacter;

};

