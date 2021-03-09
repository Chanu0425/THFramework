#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	b = new Board;
	b->position = { ScreenW / 2, ScreenH / 2 };
}

void GameScene::Update()
{

}

void GameScene::Exit()
{
	delete b;
}
