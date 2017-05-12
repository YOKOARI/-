#pragma once

class ICharacter {
public:
	ICharacter() {};
	virtual ~ICharacter() = default;

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Finalize() = 0;
};

