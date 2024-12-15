#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Game::Game()
{
}

Game::~Game()
{
	_CrtDumpMemoryLeaks();
}

void Game::Init(HWND hwnd)
{
	this->_hwnd = hwnd;
	this->hdc = ::GetDC(hwnd);

	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(hwnd);
	GET_SINGLE(SceneManager)->Init();

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Development);
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(SceneManager)->Update();
}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	
	{
		GET_SINGLE(SceneManager)->Render(hdc);
	}

	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		auto str = L"Mouse:" + to_wstring(mousePos.x) + L", " + to_wstring(mousePos.y);
		::TextOut(hdc, 10, 30, str.c_str(), static_cast<int>(str.length()));
	}

	{
		wstring str = L"FPS : " + to_wstring(fps) + L" DT : " + to_wstring(deltaTime);
		::TextOut(hdc, 10, 10, str.c_str(), static_cast<int>(str.length()));
	}

	{
		// TODO Double Buffering
	}

}
