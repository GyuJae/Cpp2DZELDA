#pragma once
#include "Object.h"

class Player: public Object
{
	using Super = Object;
public:
	Player();
	virtual ~Player();
	void Init() override;
	void Update() override;
	void Render(HDC hdc) override;
};
