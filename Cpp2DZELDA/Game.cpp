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

	// Double Buffering
	::GetClientRect(hwnd, &this->_rect);

	this->hdcBack = ::CreateCompatibleDC(this->hdc);
	this->_bmpBack = ::CreateCompatibleBitmap(this->hdc, this->_rect.right, this->_rect.bottom);
	HBITMAP prev = (HBITMAP)::SelectObject(this->hdcBack, this->_bmpBack);
	::DeleteObject(prev);
	

	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(hwnd);
	GET_SINGLE(SceneManager)->Init();

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Game);
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
		GET_SINGLE(SceneManager)->Render(this->hdcBack);
	}

	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		auto str = L"Mouse:" + to_wstring(mousePos.x) + L", " + to_wstring(mousePos.y);
		::TextOut(this->hdcBack, 10, 30, str.c_str(), static_cast<int>(str.length()));
	}

	{
		wstring str = L"FPS : " + to_wstring(fps) + L" DT : " + to_wstring(deltaTime);
		::TextOut(this->hdcBack, 10, 10, str.c_str(), static_cast<int>(str.length()));
	}

	{
		::BitBlt(this->hdc, 0, 0, this->_rect.right, this->_rect.bottom, this->hdcBack, 0, 0, SRCCOPY);
		::PatBlt(this->hdcBack, 0, 0, this->_rect.right, this->_rect.bottom, WHITENESS);
	}

}
