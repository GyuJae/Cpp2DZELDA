#pragma once
#include "Scene.h"
class FortressScene : public Scene
{
public:
	FortressScene();
	virtual ~FortressScene();
	void Init() override;
	void Update() override;
	void Render(HDC hdc) override;

};

