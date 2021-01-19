#include "DXUT.h"
#include "Boss.h"

Boss::Boss()
{
	HP = 30;
	movespeed = 10;
	scale = { 2,4 };
	position = { 9999,9999 };
	attackspeed = 1.5f;
	layer = 0; 
	SetTexture(L"collisionbox.png"); 
	objecttexture->layer = 4;
	objecttexture->scale = { 6,6 };
	objecttexture->SetTexture(L"boss (1).png");
	type = ENEMY;
}

Boss::~Boss()
{
}

void Boss::ShootBullet()
{
	for (int r = 60; r <= 125; r += 10)
	{
		float x = (cos(r * (3.141592 / 180)));
		float y = (sin(r * (3.141592 / 180)));
		BulletManager::GetInstance()->ShootBullet(position, ENEMY, { x,y });
	}
}

void Boss::SpawnMonster()
{
	spawnmonster = true;
}

void Boss::Move()
{
	float cycle = 1; // 얼마나 빠르게
	float radius = 1; // 얼마나 넓게
	movementtime += DELTATIME * cycle;
	float posx = cos(movementtime) * radius;
	position.x += posx;
}

void Boss::Update()
{
	// rand() % 5 면 5 미만 놈들을 뽑아냄.
	// 0 1 2 3 4
	if (startpattern == true)
	{
		deltatime += DELTATIME;
		if (deltatime > attackspeed)
		{
			state = rand() % 2; // 패턴의 개수만큼
			if (state == 0)
			{
				ShootBullet();
			}
			else if (state == 1)
			{
				SpawnMonster();
			}
			deltatime = 0;
		}

		if (spawnmonster == true)
		{
			if (objecttexture->Animation(L"boss", 0.3f, 4))
			{
				EnemyManager::GetInstance()->SpawnEnemy(position, E1);
				objecttexture->SetTexture(L"boss (1).png");
				spawnmonster = false;
			}
		}
	}
	
	
	Base::Update();
}
