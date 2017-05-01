#include "SceneTask.h"
#include"DxLib.h"

SceneTask::SceneTask(ISceneChanger* changer) :mGraphicHandle(0){
	mChangeScene = changer;
	
}
void SceneTask::Final() {
	
	DeleteGraph(mGraphicHandle);
	mSoundPlayFlag = CheckSoundMem(mSoundPlayHandle);
	if (mSoundPlayFlag == 1) {
		mSoundPlayFlag = 0;
		StopSoundMem(mSoundPlayHandle);
		DeleteSoundMem(mSoundPlayHandle);

	}

}
void SceneTask::Render() {

	DrawExtendGraph(0, 0, 1279, 719, mGraphicHandle, FALSE);

	mSoundPlayFlag = CheckSoundMem(mSoundPlayHandle);
	if (mSoundPlayFlag == 0) {
		PlaySoundMem(mSoundPlayHandle, DX_PLAYTYPE_LOOP, TRUE);
		mSoundPlayFlag = 1;
	}
	
}
