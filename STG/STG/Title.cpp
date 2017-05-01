#include "Title.h"
#include "DxLib.h"
#include "DebugManager.h"


Title::Title(ISceneChanger* changer):SceneTask(changer){

}


Title::~Title()
{
}
void Title::Init() {
	
}

void Title::Update(){
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mChangeScene->ChangeScene(eScene_Scene_Menu);
		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::SucsseceLord);
	}
}

void Title::Render() {
	DrawString(0, 0, "Title", GetColor(255, 255, 255));
	SceneTask::Render();
	
}
void Title::Final() {
	SceneTask::Final();
}


