#pragma once

typedef enum eScene {

	eScene_Scene_Menu,
	eScene_Title,
	eScene_Game,
	eScene_Grow,
	eScene_Config,
	eScene_GameClear,
	eScene_GameOver,
	eScene_CharSelectMenu,
	eScene_NULL,

} eScene;

class ISceneChanger {	

public:	
	ISceneChanger() {};
	virtual ~ISceneChanger() = default;
	virtual void ChangeScene(eScene NextScene) = 0;
	
};

