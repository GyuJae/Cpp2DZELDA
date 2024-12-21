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

private: 
	// 추적 기능
	float _sumTime = 0.f;
	Object* _target = nullptr; // Warining: This is a pointer to an object that may be deleted.
};

