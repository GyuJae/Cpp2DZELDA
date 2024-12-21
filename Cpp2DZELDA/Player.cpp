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
	auto delta = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (GET_SINGLE(InputManager)->IsButton(KeyType::A))
	{
		this->_pos.SetX(this->_pos.GetX() - 1000 * delta);
	}

	if (GET_SINGLE(InputManager)->IsButton(KeyType::D))
	{
		this->_pos.SetX(this->_pos.GetX() + 1000 * delta);
	}

	if (GET_SINGLE(InputManager)->IsButton(KeyType::W))
	{
		this->_pos.SetY(this->_pos.GetY() - 1000 * delta);
	}

	if (GET_SINGLE(InputManager)->IsButton(KeyType::S))
	{
		this->_pos.SetY(this->_pos.GetY() + 1000 * delta);
	}

	if (GET_SINGLE(InputManager)->IsButtonDown(KeyType::SpaceBar))
	{
		Missile* missile = GET_SINGLE(ObjectManager)->CreateObject<Missile>();
		missile->SetPos(_pos);
		GET_SINGLE(ObjectManager)->Add(missile);
	}

}

void Player::Render(HDC hdc)
{
	const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(L"Player");
	if (mesh)
		mesh->Render(hdc, _pos);
}

