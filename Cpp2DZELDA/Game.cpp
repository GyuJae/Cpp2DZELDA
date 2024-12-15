#include "pch.h"
#include "Game.h"
#include "TimeManager.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(HWND hwnd)
{
	this->_hwnd = hwnd;
	this->hdc = ::GetDC(hwnd);

	GET_SINGLE(TimeManager)->Init();
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	{
		// TODO Mouse Point Render
	}

	{
		wstring str = L"FPS : " + to_wstring(fps) + L" DT : " + to_wstring(deltaTime);
		::TextOut(hdc, 10, 10, str.c_str(), static_cast<int>(str.length()));
	}

	{
		// TODO Double Buffering
	}
}
