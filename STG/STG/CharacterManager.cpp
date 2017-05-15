#include "CharacterManager.h"
#include "ControlGameInstance.h"


CharacterManager::CharacterManager(){
	//iCharacter = ControlGameInstance::GetInstance()->GetCharacterId() == e_YokoariBrue ? (ICharacter*) new YokoariBrue : (ICharacter*) new YokoariRed;
	iCharacter = (ICharacter*) new YokoariBrue;
}


CharacterManager::~CharacterManager() {
	delete iCharacter;
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

