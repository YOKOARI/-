#pragma once
#include "ICharacter.h"
#include "YokoariBrue.h"
#include "YokoariRed.h"
//#include "FirstBossEnemy.h"
#include "NewbeiEnemy.h"
#include "NormalEnemy.h"



class CharacterManager : public ICharacter {
public:
	CharacterManager();
	~CharacterManager();
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;

private:
	ICharacter *iCharacter[12];
	int charaSelectId;
	

};

