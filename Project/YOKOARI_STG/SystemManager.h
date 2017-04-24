#ifndef _SYSTEMMANAGER_H_
#define _SYSTEMMANAGER_H_

class SystemManager {

private:


	void Initialize();
	
	void Render() {};
	void Finalize();

	void SelectWindowMode(int, int);
	bool IsGameEnd();

	bool gameEndFlag;

public:
	SystemManager();
	~SystemManager();
	void Update();
};

#endif // !_SYSTEMMANAGER_H_