#pragma once
#include "Scene.h"
class DevScene : public Scene
{
	using Super = Scene;
public:
	DevScene();
	virtual ~DevScene();

	void Init() override;

	void Update() override;

	void Render(HDC hdc) override;

private:
	Pos _pos = Pos(300, 300);
};

