#include "pch.h"
#include "Missile.h"

void Missile::Init()
{
}

void Missile::Update()
{
}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, this->_pos, 10);
}
