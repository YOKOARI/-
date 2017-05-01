#ifndef _SYSTEM_MANAGER_H_
#define _SYSTEM_MANAGER_H_
#include "SceneManager.h"


class SystemManager{
private:
	int systemEndFlag;	//プログラムを終了させるかを判別する変数
	
	bool endFlag = false;	//ループから抜けるかどうかを判断する変数
	void GameIsInit();	
	void GameEnd();
	bool IsGameEnd();
	
	void GetWindowMode(int, int);
	
public:
	SystemManager();	
	~SystemManager();	
	SceneManager SceneMgr;
	int Update();
};


#endif // !_SYSTEM_MANAGER_H_