#pragma once
#include <cmath>

using int8		= __int8;
using int16		= __int16;
using int32		= __int32;
using int64		= __int64;
using uint8		= unsigned __int8;
using uint16	= unsigned __int16;
using uint32	= unsigned __int32;
using uint64	= unsigned __int64;

struct Vector {
	Vector() : x(0), y(0) {};
	Vector(float x, float y) : x(x), y(y) {};

	Vector operator+ (const Vector& rhs) {
		return Vector(x + rhs.x, y + rhs.y);
	}

	Vector operator- (const Vector& rhs) {
		return Vector(x - rhs.x, y - rhs.y);
	}

	Vector operator* (float rhs) {
		return Vector(x * rhs, y * rhs);
	}

	Vector operator+= (const Vector& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vector operator-= (const Vector& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Vector operator*= (float rhs) {
		x *= rhs;
		y *= rhs;
		return *this;
	}

	float LengthSquared()
	{
		return x * x + y * y;
	}

	float Length()
	{
		return ::sqrt(LengthSquared());
	}

	void Normalize()
	{
		float length = Length();
		if (length < 0.00000000001f)
			return;

		x /= length;
		y /= length;
	}

	float x = 0;
	float y = 0;

	float GetX() const { return x; }
	float GetY() const { return y; }

	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }
};

using Pos = Vector;