#ifndef _SYSTEMMANAGER_H_
#define _SYSTEMMANAGER_H_

class SystemManager {

private:
	SystemManager();
	~SystemManager();

	void Initialize();
	void Update();
	void Render() {};
	void Finalize();

	void SelectWindowMode(int, int);
	bool IsGameEnd();

	bool gameEndFlag;
	 
};

#endif // !_SYSTEMMANAGER_H_