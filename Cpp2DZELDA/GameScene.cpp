#include "pch.h"
#include "GameScene.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Object.h"
#include "Missile.h"
#include "Monster.h"

void GameScene::Init()
{
	Monster* monster = GET_SINGLE(ObjectManager)->CreateObject<Monster>();
	monster->SetPos(Pos{ 400, 400 });
	GET_SINGLE(ObjectManager)->Add(monster);

	{
		/*Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
		player->SetPos(Pos{ 400, 400 });
		GET_SINGLE(ObjectManager)->Add(player);*/
	}

	{
		/*for (int i = 0; i < 5; i++)
		{
			Monster* monster = GET_SINGLE(ObjectManager)->CreateObject<Monster>();
			float index = static_cast<float>(i);
			monster->SetPos(Pos{  100.0f + index * 100.0f, 100.0f });
			GET_SINGLE(ObjectManager)->Add(monster);
		}*/
	}
}

void GameScene::Update()
{
	auto objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (auto object : objects)
	{
		object->Update();
	}
}

void GameScene::Render(HDC hdc)
{
	auto objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (auto object : objects)
	{
		object->Render(hdc);
	}
}
