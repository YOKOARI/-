#pragma once
#include "ICharacter.h"
#include "YokoariBrue.h"
#include "YokoariRed.h"
#include "BossEnemy.h"
#include "NewbeiEnemy.h"



class CharacterManager : public ICharacter {
public:
	CharacterManager();
	~CharacterManager();
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Update(int, int) override {};
	virtual void Render() override;
	virtual void Finalize() override;

private:
	ICharacter *iCharacter[3];
	int charaSelectId;
	//int GetCharaId(int charaId);

};

