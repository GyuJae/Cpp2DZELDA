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
	auto delta = GET_SINGLE(TimeManager)->GetDeltaTime();

	this->_pos.SetY(this->_pos.GetY() - 1000 * delta);

	// 충돌
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

	// 화면 밖으로 나가면 삭제
	if (this->_pos.GetY() < 0)
	{
		GET_SINGLE(ObjectManager)->Remove(this);
	}
}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, this->_pos, 10);
}
