#include "DXUT.h"
#include "gameScene.h"

void gameScene::Init()
{
	PlayerManager::GetInstance()->CreatePlayer();
	BulletManager::GetInstance()->CreateBullet();
	PlayerManager::GetInstance()->SpawnPlayer({ ScreenW / 2, ScreenH / 2 });
	ItemManager::GetInstance()->CreateItem();
}

void gameScene::Update()
{
	if (DXUTWasKeyPressed('P'))
		PlayerManager::GetInstance()->p->GetDamage(1);

	if (DXUTWasKeyPressed('O'))
		ItemManager::GetInstance()->SpawnItem(
			(PlayerManager::GetInstance()->p->position + Vec2(100, 0)),
			ItemType::BulletItem
		);
}

void gameScene::Exit()
{
	ItemManager::GetInstance()->DeleteItem();
	PlayerManager::GetInstance()->DeletePlayer();
	BulletManager::GetInstance()->DeleteBullet();
}
