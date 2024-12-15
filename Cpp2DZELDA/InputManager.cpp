#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hWnd)
{
	this->_hwnd = hWnd;
}

void InputManager::Update()
{
	this->drawMouseCursor();
}

void InputManager::drawMouseCursor()
{
	::GetCursorPos(&this->_mousePos);
	::ScreenToClient(this->_hwnd, &this->_mousePos);
}


