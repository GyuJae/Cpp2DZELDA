#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hWnd)
{
	this->_hwnd = hWnd;
	this->_keyStates.resize(KEY_TYPE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	this->ChangeButtonState();
	this->DrawMouseCursor();
}

void InputManager::ChangeButtonState()
{
	BYTE asciiKeys[KEY_TYPE_COUNT] = {};
	if (::GetKeyboardState(asciiKeys) == false)
		return;

	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// Ű�� ���� ������ true
		if (asciiKeys[key] & 0x80)
		{
			KeyState& state = this->_keyStates[key];

			// ���� �����ӿ� Ű�� ���� ���¶�� PRESS
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			else
				state = KeyState::Down;
		}
		else
		{
			KeyState& state = this->_keyStates[key];

			// ���� �����ӿ� Ű�� ���� ���¶�� UP
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Up;
			else
				state = KeyState::None;
		}
	}
}

void InputManager::DrawMouseCursor()
{
	::GetCursorPos(&this->_mousePos);
	::ScreenToClient(this->_hwnd, &this->_mousePos);
}


