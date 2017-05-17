#pragma once
class IStage {
public:
	IStage() {};
	virtual ~IStage() = default;

	virtual int Initialize() = 0;
	virtual int Update() = 0;
	virtual int Render() = 0;
	virtual int Finalize() = 0;
};

