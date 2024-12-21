#include "pch.h"
#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Missile.h"
#include "ResourceManager.h"
#include "LineMesh.h"

Player::Player(): Object(ObjectType::Player)
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
	auto deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (GET_SINGLE(InputManager)->IsButton(KeyType::A))
	{
		this->_pos.SetX(this->_pos.GetX() - 1000 * deltaTime);
	}

	if (GET_SINGLE(InputManager)->IsButton(KeyType::D))
	{
		this->_pos.SetX(this->_pos.GetX() + 1000 * deltaTime);
	}

	if (GET_SINGLE(InputManager)->IsButton(KeyType::W))
	{
		this->_pos.SetY(this->_pos.GetY() - 1000 * deltaTime);
	}

	if (GET_SINGLE(InputManager)->IsButton(KeyType::S))
	{
		this->_pos.SetY(this->_pos.GetY() + 1000 * deltaTime);
	}

	if (GET_SINGLE(InputManager)->IsButton(KeyType::Q))
	{
		_barrelAngle += 10 * deltaTime;
	}

	if (GET_SINGLE(InputManager)->IsButton(KeyType::E))
	{
		_barrelAngle -= 10 * deltaTime;
	}

	if (GET_SINGLE(InputManager)->IsButtonDown(KeyType::SpaceBar))
	{
		Missile* missile = GET_SINGLE(ObjectManager)->CreateObject<Missile>();
		missile->SetPos(this->GetFirePos());
		missile->SetAngle(_barrelAngle);
		GET_SINGLE(ObjectManager)->Add(missile);
	}
}

void Player::Render(HDC hdc)
{
	const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(L"Player");
	if (mesh)
		mesh->Render(hdc, _pos);

	Pos firePos = GetFirePos();

	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)::SelectObject(hdc, (HGDIOBJ)pen);
	Utils::DrawLine(hdc, _pos, firePos);
	::SelectObject(hdc, oldPen);
	::DeleteObject(pen);
}

Pos Player::GetFirePos() const
{
	Pos firePos = this->_pos;
	firePos.SetX(firePos.GetX() + this->_barrelLength * cos(this->_barrelAngle));
	firePos.SetY(firePos.GetY() - this->_barrelLength * sin(this->_barrelAngle));
	return firePos;
}

