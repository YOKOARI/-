#pragma once



class DebugManager
{
private:
	DebugManager();
	bool errorEndFlag;

public:
	~DebugManager();

	enum  class RenderErrorType
	{
		FailedInit = 0,
		SucsseceLord = 1,
		Game,
		Config,
		Record,
		Title,
		
		Null,

	};

	static DebugManager* Instance();

	void RenderError(RenderErrorType);

	bool GetEndFlag();


};

