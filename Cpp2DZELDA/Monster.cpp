#include "pch.h"
#include "Monster.h"

void Monster::Init()
{
}

void Monster::Update()
{
}

void Monster::Render(HDC hdc)
{
	Utils::DrawRect(hdc, this->_pos, 20, 20);
}
