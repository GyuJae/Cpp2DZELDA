#include "pch.h"
#include "Monster.h"
#include "Object.h"

Monster::Monster() : Object(ObjectType::Enemy)
{
}

Monster::~Monster()
{
}

void Monster::Init()
{
}

void Monster::Update()
{
}

void Monster::Render(HDC hdc)
{
	Utils::DrawRect(hdc, this->_pos, 50, 50);
}
