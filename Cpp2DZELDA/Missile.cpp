#include "pch.h"
#include "Missile.h"
#include "Object.h"
#include "TimeManager.h"
#include "ObjectManager.h"

Missile::Missile() : Object(ObjectType::Missile)
{
}

Missile::~Missile()
{
}

void Missile::Init()
{
}

void Missile::Update()
{
	auto deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	auto speed = 1000.f;

	//this->_pos.SetY(this->_pos.GetY() - speed * delta);
	this->_pos.SetX(this->GetX() + speed * deltaTime * ::cos(this->_angle));
	this->_pos.SetY(this->GetY() - speed * deltaTime * ::sin(this->_angle));


	// �浹
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		if (object == this)
			continue;

		if (object->GetType() != ObjectType::Enemy)
			continue;

		Pos misslePosition = this->GetPos();
		Pos enemyPosition = object->GetPos();

		const float dx = misslePosition.GetX() - enemyPosition.GetX();
		const float dy = misslePosition.GetY() - enemyPosition.GetY();
		float dist = sqrt(dx * dx + dy * dy);

		if (dist < 25)
		{
			GET_SINGLE(ObjectManager)->Remove(object); 
			GET_SINGLE(ObjectManager)->Remove(this);
			return;
		}
	}	

	// ȭ�� ������ ������ ����
	if (this->_pos.GetY() < 0)
	{
		GET_SINGLE(ObjectManager)->Remove(this);
	}
}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, this->_pos, 10);
}
