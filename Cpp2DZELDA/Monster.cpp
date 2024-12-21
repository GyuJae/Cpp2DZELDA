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

	
}

void Monster::Render(HDC hdc)
{
	//Utils::DrawCircle(hdc, this->_pos, 50);

	// 로밍 경로
	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)::SelectObject(hdc, (HGDIOBJ)pen);
	{
		Utils::DrawLine(hdc, _pt1, _pt2);
		Utils::DrawLine(hdc, _pt2, _pt3);
		Utils::DrawLine(hdc, _pt3, _pt1);
	}
	::SelectObject(hdc, oldPen);
	::DeleteObject(pen);

	// 
	Vector mousePos = GET_SINGLE(InputManager)->GetMousePos();
	_pos = mousePos;

	{
		Utils::DrawTextW(hdc, _pt1, L"P1");
		Utils::DrawTextW(hdc, _pt2, L"P2");
		Utils::DrawTextW(hdc, _pt3, L"P3");
		Utils::DrawLine(hdc, _pt1, mousePos);
	}

	Vector v12 = _pt2 - _pt1;
	Vector v1m = mousePos - _pt1;
	Vector v13 = _pt3 - _pt1;

	v12.Normalize();
	v1m.Normalize();
	v13.Normalize();

	float c1 = v12.Cross(v1m);
	float c2 = v1m.Cross(v13);

	if (c1 >= 0 && c2 >= 0)
	{
		_pos = mousePos;
	}
	else
	{
		_pos = { -1000, -1000 };
	}

	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"c1({0}) c2({1})", c1, c2);
		Utils::DrawTextW(hdc, { 20, 50 }, str);
	}

}
