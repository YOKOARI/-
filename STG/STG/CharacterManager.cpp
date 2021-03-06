#include "CharacterManager.h"
#include "ControlGameInstance.h"
#include <stdlib.h>

CharacterManager::CharacterManager(){
	//iCharacter[11] = ControlGameInstance::GetInstance()->GetCharacterId() == e_YokoariBrue ? (ICharacter*) new YokoariBrue : (ICharacter*) new YokoariRed;
	iCharacter[11] = new BossEnemy(11);
	iCharacter[10] = new YokoariBrue;
	for (int i = 0; i < 10; i++) {
		iCharacter[i] = 0;
		if (iCharacter[i] == 0) {
			iCharacter[i] = (ICharacter*) new NewbeiEnemy(rand() % 400 + 50, rand() % 300 + 60, i);
		}
	}
	
}


CharacterManager::~CharacterManager() {
	for (int i = 0; i < 12; i++) {
		delete iCharacter[i];
	}
}

void CharacterManager::Initialize() {
	for (int i = 0; i < 12; i++) {
		iCharacter[i]->Initialize();
	}
}

void CharacterManager::Update() {
	for (int i = 0; i < 12; i++) {
		iCharacter[i]->Update();
	}

}

void CharacterManager::Render() {
	for (int i = 0; i < 12; i++) {
		iCharacter[i]->Render();
	}

}

void CharacterManager::Finalize() {
	for (int i = 0; i < 12; i++) {
		iCharacter[i]->Finalize();
	}

}

