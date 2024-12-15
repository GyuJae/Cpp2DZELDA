#pragma once
#include "Object.h"

class Player: Object
{
public:
	Player();
	~Player();
	void Init() override;
	void Update() override;
	void Render(HDC hdc) override;
};

