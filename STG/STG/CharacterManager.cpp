#include "CharacterManager.h"
#include "ControlGameInstance.h"


CharacterManager::CharacterManager(){
	//iCharacter = ControlGameInstance::GetInstance()->GetCharacterId() == e_YokoariBrue ? (ICharacter*) new YokoariBrue : (ICharacter*) new YokoariRed;
	iCharacter[0] = (ICharacter*) new YokoariBrue;
	iCharacter[1] = (ICharacter*) new NewbeiEnemy(50,100);
}


CharacterManager::~CharacterManager() {
	delete iCharacter[0];
	delete iCharacter[1];
}

void CharacterManager::Initialize() {
	iCharacter[0]->Initialize();
	iCharacter[1]->Initialize();
}


void CharacterManager::Update() {
	iCharacter[0]->Update();
	iCharacter[1]->Update();
}

void CharacterManager::Render() {
	iCharacter[0]->Render();
	iCharacter[1]->Render();
}

void CharacterManager::Finalize() {
	iCharacter[0]->Finalize();
	iCharacter[1]->Finalize();
}

