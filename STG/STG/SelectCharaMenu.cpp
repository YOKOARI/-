#include "SelectCharaMenu.h"
#include "DxLib.h"
#include "ISceneChanger.h"
#include "SceneTask.h"

SelectCharaMenu::SelectCharaMenu(ISceneChanger* changer) :SceneTask(changer) {
}

SelectCharaMenu::~SelectCharaMenu() {
}

void SelectCharaMenu::Init() {
	SceneTask::Init();
}

void SelectCharaMenu::Update() {
	SceneTask::Update();
	if (CheckHitKey(KEY_INPUT_G) != 0) {



		mChangeScene->ChangeScene(eScene_Game);
	}
}

void SelectCharaMenu::Render() {
	SceneTask::Render();
	DrawString(0, 0,"SelectCharMenu" ,(255, 255, 255));
}

void SelectCharaMenu::Final() {
	SceneTask::Final();
}