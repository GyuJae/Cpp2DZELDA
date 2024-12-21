#pragma once
#include "Object.h"
class Missile :
    public Object
{
public:
	Missile();
	virtual ~Missile();
    void Init() override;
    void Update() override;
    void Render(HDC hdc) override;

	void SetAngle(float angle) { _angle = angle; }
	float GetX() { return this->_pos.GetX(); }
	float GetY() { return this->_pos.GetY(); }

private:
	float _angle = 0.f;
};

