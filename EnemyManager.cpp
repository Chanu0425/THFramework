#include "DXUT.h"
#include "EnemyManager.h"

void EnemyManager::CreateEnemy()
{
	for (int i = 0; i < 20; ++i)
	{
		Enemy* en = new Enemy;
		en->isactive = false;
		enemys.emplace_back(en);
	}
}

void EnemyManager::SpawnEnemy(Vec2 pos, EnemyType type, Player* p)
{
	for (int i = 0; i < enemys.size(); ++i)
	{
		if (enemys[i]->isactive == false)
		{
			enemys[i]->HP = 3;
			enemys[i]->position = pos;
			enemys[i]->etype = type;
			enemys[i]->isactive = true;
			enemys[i]->movespeed = 30;
			if (p != nullptr)
				enemys[i]->playerpos = &p->position;
			enemys[i]->objecttexture->isactive = true;
			return;
		}
	}
}

void EnemyManager::DeleteEnemy()
{
	for (int i = 0; i < enemys.size(); ++i)
		delete enemys[i];
	enemys.clear();
}
