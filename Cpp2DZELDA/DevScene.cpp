#include "pch.h"
#include "DevScene.h"

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	Super::Init();
}

void DevScene::Update()
{
	Super::Update();
}

void DevScene::Render(HDC hdc)
{
	Super::Render(hdc);

	Pos pos(300, 300);
	Utils::DrawCircle(hdc, pos, 30);
}
