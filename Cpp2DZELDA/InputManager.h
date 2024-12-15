#pragma once

class InputManager
{
	DECLARE_SINGLE(InputManager);

public:
	void Init(HWND hWnd);
	void Update();

	POINT GetMousePos() const { return this->_mousePos; }


private:
	HWND _hwnd;
	POINT _mousePos;
	void drawMouseCursor();
};

