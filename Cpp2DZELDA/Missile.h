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
};

