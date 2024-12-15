#pragma once
#include "Scene.h"
class GameScene :
    public Scene
{
    void Init() override;
    void Update() override;
    void Render(HDC hdc) override;
};

