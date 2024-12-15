#pragma once

enum class KeyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,
	SpaceBar = VK_SPACE,

	KEY_1 = '1',
	KEY_2 = '2',

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
	Q = 'Q',
	E = 'E'
};

enum class KeyState
{
	None,
	Press,
	Down,
	Up,

	End
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End)
};

class InputManager
{
	DECLARE_SINGLE(InputManager);

public:
	void Init(HWND hWnd);
	void Update();

	POINT GetMousePos() const { return this->_mousePos; }

	// 누르고 있을 때
	bool IsButton(KeyType key) { return GetState(key) == KeyState::Press; }

	// 맨 처음 눌렀을 때
	bool IsButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }

	// 맨 처음 눌렀다가 땔 때
	bool IsButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }


private:
	KeyState GetState(KeyType key) { return this->_keyStates[static_cast<uint8>(key)]; }
	void DrawMouseCursor();
	void ChangeButtonState();
private:
	HWND _hwnd;
	POINT _mousePos;
	vector<KeyState> _keyStates;
};

