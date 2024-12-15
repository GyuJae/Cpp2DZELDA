#include "pch.h"
#include "DevScene.h"
#include "InputManager.h"
#include "TimeManager.h"

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
}

void DevScene::Update()
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
}

void DevScene::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, this->_pos, 30);
}
