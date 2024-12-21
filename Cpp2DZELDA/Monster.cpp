#include "pch.h"
#include "Monster.h"
#include "Object.h"
#include "InputManager.h"

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
	Vector mousePos = GET_SINGLE(InputManager)->GetMousePos();
	// start -> end
	Vector v1 = _end - _start;
	// start -> mousePos
	Vector v2 = mousePos - _start;

	float maxLength = v1.Length();
	v1.Normalize();

	float dot = v1.Dot(v2);
	Pos pos = _start + v1 * dot;

	if (dot < 0 || dot > maxLength)
		return;

	_pos = pos;
	
}

void Monster::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, this->_pos, 50);

	// 로밍 경로
	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)::SelectObject(hdc, (HGDIOBJ)pen);
	{
		Utils::DrawLine(hdc, this->_start, this->_end);
	}
	::SelectObject(hdc, oldPen);
	::DeleteObject(pen);
}
