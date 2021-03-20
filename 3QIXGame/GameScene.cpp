#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	b = new Board;
	b->position = { ScreenW / 2, ScreenH / 2 };
	b->difficulty = 2; // �������� 2��� ��
}

void GameScene::Update()
{
	if (DXUTWasKeyPressed('P'))
	{
		Director::GetInstance()->ChangeScene(MENUSCENE);
		return;
	}
}

void GameScene::Exit()
{
	delete b;
}
