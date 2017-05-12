#include "CharacterManager.h"



CharacterManager::CharacterManager(){
	iCharacter = (ICharacter*) new Player;
}


CharacterManager::~CharacterManager()
{
}

void CharacterManager::Initialize() {
	iCharacter->Initialize();
}

void CharacterManager::Update() {
	iCharacter->Update();
}

void CharacterManager::Render() {
	iCharacter->Render();
}

void CharacterManager::Finalize() {
	iCharacter->Finalize();
}