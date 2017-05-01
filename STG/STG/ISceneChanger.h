#pragma once

typedef enum eScene {

	eScene_Menu,
	eScene_Title,
	eScene_Game,
	eScene_Grow,
	eScene_Config,
	eScene_Result,
	eScene_NULL,

}eScene;

class ISceneChanger {	

public:	
	ISceneChanger() {};
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(eScene NextScene) = 0;
	
};

