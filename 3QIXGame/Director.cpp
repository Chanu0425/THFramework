#include "DXUT.h"
#include "Renderer.h"
#include "Director.h"

void Director::Init()
{
	D3DXCreateSprite(DXUTGetD3D9Device(), &sprite);
	Camera::GetInstance()->CameraInit();
}

void Director::AddScene(SceneTag _sceneTag, Scene* _scene)
{
}

void Director::ChangeScene(SceneTag _sceneTag)
{
}

void Director::ChangeScene(Scene* _scene)
{
	if (currentScene != nullptr)
	{
		currentScene->Exit();
		delete currentScene;
	}
	Renderer::GetInstance()->Clear();
	currentScene = _scene;
	currentScene->Init();
}

void Director::UpdateScene()
{
	if (currentScene != nullptr)
	{
		currentScene->Update();
		Renderer::GetInstance()->Render();
	}
	Camera::GetInstance()->CameraUpdate();
	if (mouse == 1)
		mouse = 2;
	if (mouse == 3)
		mouse = 0;
}
