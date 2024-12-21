#pragma once
#include "Scene.h"

class SceneManager
{
	DECLARE_SINGLE(SceneManager);
public:
	void Init();
	void Update();
	void Render(HDC hdc);

public:
	void ChangeScene(SceneType sceneType);
	Scene* GetScene() const { return _scene; }
	SceneType GetSceneType() const { return _sceneType; }

private:
	Scene* _scene;
	SceneType _sceneType;
public:
	Scene* GetCurrentScene();
};

