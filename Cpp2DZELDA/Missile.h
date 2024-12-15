#pragma once
#include "Object.h"
class Missile :
    public Object
{
    void Init() override;
    void Update() override;
    void Render(HDC hdc) override;
};

