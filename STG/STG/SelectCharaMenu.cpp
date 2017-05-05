#include "SelectCharaMenu.h"
#include "DxLib.h"


SelectCharaMenu::SelectCharaMenu(ISceneChanger* changer) :SceneTask(changer) {
}

SelectCharaMenu::~SelectCharaMenu() {
}

void SelectCharaMenu::Init() {
	SceneTask::Init();
}

void SelectCharaMenu::Update() {
	SceneTask::Update;
}

void SelectCharaMenu::Render() {
	SceneTask::Render();
}

void SelectCharaMenu::Final() {
	SceneTask::Final();
}