#include "DXUT.h"
#include "Enemy.h"

Enemy::Enemy()
{
	HP = 3;
	movespeed = 10;
	scale = { 1,1 };
	position = { 9999,9999 };
	attackspeed = 1.1f;
	layer = 2; // 레이어 설정하고
	SetTexture(L"collisionbox.png"); // 텍스쳐 설정
	// 만약에 텍스쳐 설정하고 이후에 레이어 설정할 일이 있다?
	// 하면 그냥 Renderer 속 Sort 호출만 하면 된다!
	color.a = 0;
	objecttexture->layer = 3;
	Renderer::GetInstance()->Sort();
	objecttexture->scale = { 3,3 };

	type = ENEMY;
}

void Enemy::Enemy1Move()
{
	position.y += movespeed * DELTATIME;
}

void Enemy::Enemy1Attack()
{
	if (deltatime > attackspeed)
	{
		BulletManager::GetInstance()->ShootBullet(position, ENEMY);
		deltatime = 0;
	}
	else
		deltatime += DELTATIME;

	objecttexture->Animation(L"m1", 0.2f, 5);
}

void Enemy::Enemy2Move()
{
	direction = *playerpos - position;
	D3DXVec2Normalize(&direction, &direction);
	position += movespeed * DELTATIME * direction;
	objecttexture->Animation(L"m2", 0.2f, 5);
}

void Enemy::Enemy2Attack()
{
	//
	
}

void Enemy::Move()
{
	switch (etype)
	{
	case E1:
		Enemy1Move();
		break;
	case E2:
		Enemy2Move();
		break;
	}
}

void Enemy::Update()
{
	switch (etype)
	{
	case E1:
		Enemy1Attack();
		break;
	case E2:
		Enemy2Attack();
		break;
	}

	Base::Update();
}
