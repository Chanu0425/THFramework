#include "DXUT.h"
#include "Director.h"
#include "gameScene.h"
#include "menuScene.h"

void menuScene::Init()
{

}

void menuScene::Update()
{
	if (DXUTWasKeyPressed('P'))
		Director::GetInstance()->ChangeScene(new gameScene);
}

void menuScene::Exit()
{

}
