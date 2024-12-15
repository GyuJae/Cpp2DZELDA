#pragma once

using int8		= __int8;
using int16		= __int16;
using int32		= __int32;
using int64		= __int64;
using uint8		= unsigned __int8;
using uint16	= unsigned __int16;
using uint32	= unsigned __int32;
using uint64	= unsigned __int64;

class Pos
{
public:
	Pos(float y, float x) : _x(x), _y(y) {};

	float GetX() const { return _x; }
	float GetY() const { return _y; }

	void SetX(float x) { _x = x; }
	void SetY(float y) { _y = y; }
private:
	float _x;
	float _y;
};