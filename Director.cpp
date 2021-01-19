#include "DXUT.h"
#include "Renderer.h"
#include "Director.h"

void Director::Init()
{
	D3DXCreateSprite(DXUTGetD3D9Device(), &sprite);
}

void Director::ChangeScene(Scene* _scene)
{
	if (currentScene != nullptr)
		currentScene->Exit();
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
	if (mouse == 1)
		mouse = 2;
	if (mouse == 3)
		mouse = 0;
}
