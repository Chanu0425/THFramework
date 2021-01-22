#include "DXUT.h"
#include "gameScene.h"

void gameScene::WaveOn(int wavenum)
{
	for (int i = 0; i < 4; ++i)
	{
		int r = rand() % 360;
		float x = (cos(r * (3.141592 / 180)));
		float y = (sin(r * (3.141592 / 180)));
		int ran = rand() % (int)EnemyType::EnemyNone;

		Vec2 epos = PlayerManager::GetInstance()->p->position + Vec2(x, y) * 600;
		EnemyManager::GetInstance()->SpawnEnemy(epos, (EnemyType)ran, wavenum);
	}
}

void gameScene::Init()
{
	PlayerManager::GetInstance()->CreatePlayer();
	BulletManager::GetInstance()->CreateBullet();
	PlayerManager::GetInstance()->SpawnPlayer({ ScreenW / 2, ScreenH / 2 });
	ItemManager::GetInstance()->CreateItem();
	EnemyManager::GetInstance()->CreateEnemy();
	//EnemyManager::GetInstance()->SpawnEnemy({ ScreenW / 2, ScreenH / 2 }, EnemyType::Enemy1, wave);
	//EnemyManager::GetInstance()->SpawnEnemy({ ScreenW / 2 + 100, ScreenH / 2 }, EnemyType::Enemy2, wave);
	//EnemyManager::GetInstance()->SpawnEnemy({ ScreenW / 2, ScreenH / 2 + 100 }, EnemyType::Enemy3, wave);
}

void gameScene::Update()
{
	delta += DELTATIME;
	if (delta > 3.5f)
	{
		WaveOn(wave++);
		delta = 0;
	}


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
	EnemyManager::GetInstance()->DeleteEnemy();
}
