#pragma once

class IBullet {
public:
	IBullet();
	virtual ~IBullet() = default;

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Finalize() = 0;
};