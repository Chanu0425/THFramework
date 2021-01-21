#include "DXUT.h"
#include "Enemy1.h"

Enemy1::Enemy1()
{
	eType = E1;
	HP = 3;
	movespeed = 10;
	scale = { 3,3 };
	position = { ScreenW / 2,ScreenH / 2 };
	attackspeed = 0.1f;
	layer = 2; // 레이어 설정하고
	SetTexture(L"m1 (1).png"); // 텍스쳐 설정
	// 만약에 텍스쳐 설정하고 이후에 레이어 설정할 일이 있다?
	// 하면 그냥 Renderer 속 Sort 호출만 하면 된다!
	type = ENEMY;
}

void Enemy1::Move()
{
	position.y += movespeed * DELTATIME;
}

void Enemy1::Update()
{
	if (deltatime > attackspeed)
	{
		BulletManager::GetInstance()->ShootBullet(position, ENEMY);
		deltatime = 0;
	}
	else
		deltatime += DELTATIME;
	
	Animation(L"m1", 0.2f, 5);
	Base::Update();
}
