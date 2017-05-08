#pragma once
class IObj
{
public:
	IObj() {};
	virtual ~IObj() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Final() = 0;
};

