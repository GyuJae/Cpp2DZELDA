#pragma once
#include "Object.h"

class Monster: Object
{
	void Init() override;
	void Update() override;
	void Render(HDC hdc) override;
};

