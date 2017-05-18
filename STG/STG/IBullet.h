#pragma once

class IBullet {
public:
	IBullet() {};
	virtual ~IBullet() = default;

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Finalize() = 0;
	
	virtual int GetBulletPointX() = 0;
	virtual int GetBulletPointY() = 0;
};