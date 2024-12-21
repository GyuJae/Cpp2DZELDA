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

	auto speed = 600.f;

	if (this->_target == nullptr)
	{
		//this->_pos.SetY(this->_pos.GetY() - speed * delta);
		this->_pos.SetX(this->GetX() + speed * deltaTime * ::cos(this->_angle));
		this->_pos.SetY(this->GetY() - speed * deltaTime * ::sin(this->_angle));

		// 0.2초 후에 유도탄
		_sumTime += deltaTime;
		if (_sumTime >= 0.2f)
		{
			// 첫번째 타겟 서치
			const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObjects();
			for (Object* object : objects)
			{
				if (object->GetType() == ObjectType::Enemy)
				{
					_target = object;
					break;
				}
			}
		}
	}
	else 
	{
		Vector dir = this->_target->GetPos() - this->GetPos();
		dir.Normalize();

		// ????
		_target->SetPos(_target->GetPos());

		_pos += dir * deltaTime * speed;
	}




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
