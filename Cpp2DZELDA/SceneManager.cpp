#include "pch.h"
#include "SceneManager.h"
#include "DevScene.h"
#include "GameScene.h"
#include "EditScene.h"

void SceneManager::Init()
{

}

void SceneManager::Update()
{
	if (this->_scene)
	{
		this->_scene->Update();
	}
}

void SceneManager::Render(HDC hdc)
{
	if (this->_scene)
	{
		this->_scene->Render(hdc);
	}
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (sceneType == this->_sceneType) return;

	Scene* newScene = nullptr;

	switch (sceneType)
	{
	case SceneType::Game:
		newScene = new GameScene();
		break;
	case SceneType::Development:
		newScene = new DevScene();
		break;
	case SceneType::Edit:
		newScene = new EditScene();
		break;
	default:
		break;
	}

	SAFE_DELETE(this->_scene);
	this->_scene = newScene;
	this->_sceneType = sceneType;

	if (this->_scene)
	{
		this->_scene->Init();
	}
}
