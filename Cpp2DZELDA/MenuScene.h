#pragma once
#include "Scene.h"

class MenuScene : public Scene
{
	using Super = Scene;
public:
	MenuScene();
	virtual ~MenuScene();
	
	void Init() override;

	void Update() override;
	
	void Render(HDC hdc) override;
};

