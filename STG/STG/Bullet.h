#pragma once

class Bullet {

public:

	Bullet();
	virtual ~Bullet() = default;

private:

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Finalize() = 0;

};

